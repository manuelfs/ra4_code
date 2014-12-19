#include <locale>
#include <iostream>
#include <iomanip>
#include <string>
#include <set>

#include "TChain.h"
#include "TBranch.h"
#include "TLeaf.h"

using namespace std;

struct Variable{
  string name;
  long zip_size, tot_size;

  bool operator<(const Variable &var) const{
    return zip_size<var.zip_size || (var.zip_size==zip_size && tot_size<var.tot_size);
  }
};

class comma_numpunct : public numpunct<char>{
protected:
  virtual char do_thousands_sep() const{
    return ',';
  }

  virtual string do_grouping() const{
    return "\03";
  }
};

int main(int argc, char *argv[]){
  cout.imbue(locale(locale(), new comma_numpunct));
  for(int arg = 1; arg < argc; ++arg){
    TChain chain;
    if(!chain.Add(argv[arg])) continue;

    long zip_sum(0), tot_sum(0);
    size_t max_length(0);
    
    set<Variable> vars;

    if(!chain.GetListOfLeaves()) continue;
    for(int i = 0; i < chain.GetListOfLeaves()->GetSize(); ++i){
      TBranch *b = static_cast<TLeaf*>(chain.GetListOfLeaves()->At(i))->GetBranch();
      if(!b) continue;
      Variable v;
      v.name = b->GetName();
      v.zip_size = b->GetZipBytes();
      v.tot_size = b->GetTotBytes();
      vars.insert(v);
      zip_sum += v.zip_size;
      tot_sum += v.tot_size;
      if(v.name.size() > max_length) max_length = v.name.size();
    }
    cout << "CCC" << endl;
    cout << argv[arg] << endl;
    cout << setw(max_length) << "Total" << " "
	 << setw(16) << zip_sum << " "
	 << setw(16) << tot_sum << endl;
    for(set<Variable>::const_reverse_iterator var = vars.rbegin(); var != vars.rend(); ++var){
      cout << setw(max_length) << var->name << " "
	   << setw(16) << var->zip_size << " "
	   << setw(16) << var->tot_size << endl;
    }
  }
}
