ra4_code
==========

Analysis code for Single Lepton searches of Supersymmetry with new cfA. 

#### Running the code
The definition of RA4 objects is in `src/ra4_objects.cpp`.
Issue the following commands to produce a reduced tree with analysis quantities:

    git clone git@github.com:manuelfs/ra4_code
    cd ra4_code
    ./compile.sh
    ./scripts/analyze_tree.exe -f example_cfa_file.root 
    ./run/make_tree.exe -i <cfa.root> -n <nevents>

The compile step creates the files `inc/cfa.hpp` and `src/cfa.cpp` with a wrapper class based on 
`example_cfa_file.root`. If the structure of the cfA ntuple changes, just copy an example
file onto `example_cfa_file.root` (1 event is enough), and compile again.

The compilation also automatically generates `inc/small_tree.hpp` and `src/small_tree.cpp`
with the variables specified in `src/generate_small_tree.cxx`. 