susy_cfa
==========

Analysis code for searches of Supersymmetry  based on cfA ntuples created in 
CMSSW 7.X.X. 

#### ROOT version
This code requires RooStats, so we made a special ROOT installation that can be
used issuing `source /cms5r0/ald77/root/bin/thisroot.sh`.

#### Compiling the code
Issue the following commands in one of the UCSB cmsx machines:

    git clone git@github.com:manuelfs/susy_cfa
    cd susy_cfa
    ./compile.sh

The compile step creates the files `cfa_base.cpp/hpp`, `cfa_8.cpp/hpp`, `cfa_13.cpp/hpp`, 
and `cfa.cpp/hpp` containing a wrapper class with functions that access all the cfA branches.
These functions are automatically created based on `example_cfa_file_8.root` and
`example_cfa_file_13.root`. 

If the structure of the cfA ntuple changes, just copy an example
file onto `example_cfa_file_XX.root` and compile again. You can make a 0 event copy with

```
.L plot/skim_ntuples.C+
skim_one("<new_cfa_file.root>")
```


#### Multiplexing 8 TeV and 13 TeV branch names
The code allows for the same function to refer to branches with different names in 8 TeV and 13 TeV
cfA ntuples. By filling out the file `txt/mux_rules.cfg` as follows

```
   New Name        8 TeV Name      13 TeV Name
   -------------------------------------------
   jets            jets_AK5PF      jets_AK4
   fjets           not_used        fastjets_AK4_R1p2_R0p5pT30
```

all the branch names that in 8 TeV start with `jets_AK5PF` and in 13 TeV start with
`jets_AK4` can be called just with `jets`. For instance, `jets_pt()` would call
`jets_AK5PF_pt()` in 8 TeV and `jets_AK4_pt()` in 13 TeV.

#### Running the code
The definition of physics objects is in `src/phys_objects.cpp`.
Issue the following commands to produce a reduced tree with analysis quantities:

    ./run/make_tree.exe -i <cfa.root> -n <nevents>

The compilation also automatically generates `inc/small_tree.hpp` and `src/small_tree.cpp`
with the variables specified in `src/generate_small_tree.cxx`. This defines the branches 
of the small tree.