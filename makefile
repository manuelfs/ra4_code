EXEDIR := run
OBJDIR := bin
SRCDIR := src
INCDIR := inc
MAKEDIR := bin
LIBFILE := $(OBJDIR)/libStatObj.a
EX8FILE := example_cfa_file_8.root
EX13FILE := example_cfa_file_13.root

CXX := $(shell root-config --cxx)
EXTRA_WARNINGS := -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k -Winit-self -Winvalid-pch -Wlong-long -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpointer-arith -Wredundant-decls -Wstack-protector -Wswitch-default -Wswitch-enum -Wundef -Wunused -Wvariadic-macros -Wwrite-strings -Wabi -Wctor-dtor-privacy -Wnon-virtual-dtor -Wsign-promo -Wsign-compare #-Wunsafe-loop-optimizations -Wfloat-equal -Wsign-conversion -Wunreachable-code
CXXFLAGS := -isystem $(shell root-config --incdir) -Wall -Wextra -pedantic -Werror -Wshadow -Woverloaded-virtual -Wold-style-cast $(EXTRA_WARNINGS) $(shell root-config --cflags) -O2 -I $(INCDIR)
LD := $(shell root-config --ld)
LDFLAGS := $(shell root-config --ldflags)
LDLIBS := $(shell root-config --libs) -lMinuit

EXECUTABLES := $(addprefix $(EXEDIR)/, $(addsuffix .exe, $(notdir $(basename $(wildcard $(SRCDIR)/*.cxx)))))
OBJECTS := $(addprefix $(OBJDIR)/, $(addsuffix .o, $(notdir $(basename $(wildcard $(SRCDIR)/*.cpp))))) $(OBJDIR)/small_tree.o $(OBJDIR)/cfa_base.o $(OBJDIR)/cfa_8.o $(OBJDIR)/cfa_13.o $(OBJDIR)/cfa.o

FIND_DEPS = $(CXX) $(CXXFLAGS) -MM -MG -MF $@ $<
EXPAND_DEPS = perl -pi -e 's|$*.o|$(OBJDIR)/$*.o $(MAKEDIR)/$*.d|g' $@
GET_DEPS = $(FIND_DEPS) && $(EXPAND_DEPS)
COMPILE = $(CXX) $(CXXFLAGS) -o $@ -c $<
LINK = $(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

vpath %.cpp $(SRCDIR)
vpath %.cxx $(SRCDIR)
vpath %.hpp $(INCDIR)
vpath %.o $(OBJDIR)
vpath %.exe $(EXEDIR)
vpath %.d $(MAKEDIR)

all: $(EXECUTABLES)

-include $(addsuffix .d,$(addprefix $(MAKEDIR)/,$(notdir $(basename $(wildcard $(SRCDIR)/*.cpp)))))
-include $(addsuffix .d,$(addprefix $(MAKEDIR)/,$(notdir $(basename $(wildcard $(SRCDIR)/*.cxx)))))
-include $(MAKEDIR)/small_tree.d $(MAKEDIR)/cfa_base.d $(MAKEDIR)/cfa_8.d $(MAKEDIR)/cfa_13.d $(MAKEDIR)/cfa.d

$(LIBFILE): $(OBJECTS)

$(MAKEDIR)/%.d: $(SRCDIR)/%.cpp
	$(GET_DEPS)

$(MAKEDIR)/%.d: $(SRCDIR)/%.cxx
	$(GET_DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(COMPILE)

$(OBJDIR)/%.o: $(SRCDIR)/%.cxx
	$(COMPILE)

$(OBJDIR)/%.a:
	ar rcsv $@ $^

$(EXEDIR)/generate_small_tree.exe: $(OBJDIR)/generate_small_tree.o
	$(LINK)

$(EXEDIR)/generate_cfa_class.exe: $(OBJDIR)/generate_cfa_class.o
	$(LINK)

$(EXEDIR)/%.exe: $(OBJDIR)/%.o $(LIBFILE)
	$(LINK)

# Auto-generated code
.SECONDARY: dummy_small_tree.all dummy_cfa.all
.PRECIOUS: generate_small_tree.o generate_cfa_class.o

$(SRCDIR)/small_tree.cpp $(INCDIR)/small_tree.hpp: dummy_small_tree.all
dummy_small_tree.all: $(EXEDIR)/generate_small_tree.exe 
	./$< 

$(SRCDIR)/cfa_base.cpp $(INCDIR)/cfa_base.hpp $(SRCDIR)/cfa_8.cpp $(INCDIR)/cfa_8.hpp $(SRCDIR)/cfa_13.cpp $(INCDIR)/cfa_13.hpp $(SRCDIR)/cfa.cpp $(INCDIR)/cfa.hpp: dummy_cfa.all
dummy_cfa.all: $(EXEDIR)/generate_cfa_class.exe $(EX8FILE) $(EX13FILE)
	./$< $(word 2,$^) cfa_8 $(word 3,$^) cfa_13

.DELETE_ON_ERROR:
