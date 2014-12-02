susy_cfa
==========

Analysis code for searches of Supersymmetry with based on cfA ntuples created in 
CMSSW 7.X.X. 

#### Compiling the code
Issue the following commands in a cmsx machine:

    git clone git@github.com:manuelfs/susy_cfa
    cd susy_cfa
    ./compile.sh

The compile step creates the files `cfa_base.cpp/hpp`, `cfa_8.cpp/hpp`, `cfa_13.cpp/hpp`, 
`cfa.cpp/hpp` containing a wrapper class with functions that access all the cfA branches.
These functions are automatically created based on `example_cfa_file_8.root` and
`example_cfa_file_13.root`. If the structure of the cfA ntuple changes, just copy an example
file onto `example_cfa_file_XX.root` (0 events is enough), and compile again.

#### Multiplexing 8 TeV and 13 TeV branch names
The code allows for the same function to refer to branches with different names in 8 TeV and 13 TeV
cfA ntuples. By filling out the file `txt/mux_rules.cfg` as follows

   New Name        8 TeV Name      13 TeV Name
   -------------------------------------------
   jets            jets_AK5PF      jets_AK4
   fjets           not_used        fastjets_AK4_R1p2_R0p5pT30

all the branch names that in 8 TeV start with `jets_AK5PF` and in 13 TeV start with
`jets_AK4` can be called just with `jets`. For instance, `jets_pt()` calls
`jets_AK5PF_pt()` in 8 TeV and `jets_AK4_pt()` in 13 TeV.

This multiplexer can also be used to give nicknames to branches with long names,
e.g. `fjets_pt()` instead of `fastjets_AK4_R1p2_R0p5pT30_pt()`.

#### Running the code
The definition of physics objects is in `src/phys_objects.cpp`.
Issue the following commands to produce a reduced tree with analysis quantities:

    ./scripts/analyze_tree.exe -f example_cfa_file.root 
    ./run/make_tree.exe -i <cfa.root> -n <nevents>

The compilation also automatically generates `inc/small_tree.hpp` and `src/small_tree.cpp`
with the variables specified in `src/generate_small_tree.cxx`. 