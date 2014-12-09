#include "generate_cfa.hpp"

#include <cctype>

#include <utility>
#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "TFile.h"
#include "TChain.h"
#include "TLeafObject.h"

int main(int argc, char *argv[]){
  try{
    if(argc<=2) throw std::runtime_error("At least two arguments required.");
    if(!(argc & 1)) throw std::runtime_error("Even number of arguments required.");

    {TTree t("a","b");}//Magically make ROOT link things correctly...

    std::vector<std::string> class_names(0);
    Dictionary full_varset;

    for(int arg = 1; (arg+1) < argc; arg+=2){
      TFile in_file(argv[arg], "read");
      if(!in_file.IsOpen() || in_file.IsZombie()) throw std::runtime_error(std::string("Could not open file ")+argv[arg]);
      
      std::string file_name = argv[arg];
      std::string dir_name = "cfA";
      if (file_name.find("cfa_file_8")!=std::string::npos) dir_name = "configurableAnalysis";
      TChain *ptr_chain_a(static_cast<TChain*>(in_file.Get((dir_name+"/eventA").c_str())));
      if(!ptr_chain_a){
        throw std::runtime_error(std::string("Could not find chainA in ")+argv[arg]);
      }

      TChain *ptr_chain_b(static_cast<TChain*>(in_file.Get((dir_name+"/eventB").c_str())));
      if(!ptr_chain_b){
        throw std::runtime_error(std::string("Could not find chainB in ")+argv[arg]);
      }
      
      GetVariables(*ptr_chain_a, true, (arg-1)/2, (argc-1)/2, full_varset);
      GetVariables(*ptr_chain_b, false, (arg-1)/2, (argc-1)/2, full_varset);

      class_names.push_back(argv[arg+1]);
    }

    std::vector<Variable> base_variables(0), virtual_variables(0);
    std::vector<std::vector<Variable> > file_variables(0);

    ClassifyVariables(full_varset, base_variables, virtual_variables, file_variables);

    WriteBaseHeader(base_variables, virtual_variables);
    WriteBaseSource(base_variables, virtual_variables);

    for(size_t file = 0; file<file_variables.size(); ++file){
      WriteDerivedHeader(class_names.at(file), file_variables.at(file));
      WriteDerivedSource(class_names.at(file), file_variables.at(file));
    }

    Typelist typelist;
    AddToTypelist(base_variables, typelist);
    AddToTypelist(virtual_variables, typelist);

    RepList patterns;
    GetRules(patterns);

    RepMap replacements;
    GetReplacements(typelist, patterns, replacements);

    RepMap overwrites, new_funcs;
    GetOverwritten(typelist, replacements, overwrites, new_funcs);

    WriteMergedHeader(typelist, overwrites, new_funcs);
    WriteMergedSource(typelist, overwrites, new_funcs, class_names);
  }
  catch(std::exception& ex){
    std::cerr << "An exception occurred: " << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  catch(...){
    std::cerr << "An unknown exception occurred." << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
