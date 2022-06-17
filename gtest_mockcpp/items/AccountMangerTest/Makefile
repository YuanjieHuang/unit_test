# Makefile for Mr.H CSDN blog - Do a research on Gtest/Gmock 2017.12.14
# Make command to use for dependencies
MAKE=make
RM=rm
MKDIR=mkdir

# Only "Debug" version for test
CFG=Debug

#
# Configuration: Debug
#
ifeq "$(CFG)" "Debug"
OUTDIR=Debug
OUTFILE=$(OUTDIR)/test
CFG_INC=-I../gmock-1.7.0/include -I../gmock-1.7.0/gtest/include 
CFG_LIB=-lpthread -lc -lm -lrt -lgtest -lgmock -L ../gmock-1.7.0/lib/.libs \
    -L ../gmock-1.7.0/gtest/lib/.libs 
CFG_OBJ=
COMMON_OBJ=$(OUTDIR)/AccountHelper.o $(OUTDIR)/AccountService.o $(OUTDIR)/main.o 
OBJ=$(COMMON_OBJ) $(CFG_OBJ)
ALL_OBJ=$(OUTDIR)/AccountHelper.o $(OUTDIR)/AccountService.o \
    $(OUTDIR)/main.o -lpthread -lc -lm -lrt -lgtest -lgmock -L ../gmock-1.7.0/lib/.libs \
    -L ../gmock-1.7.0/gtest/lib/.libs 

COMPILE=g++ -c   -g -o "$(OUTDIR)/$(*F).o" $(CFG_INC) $<
LINK=g++  -g -o "$(OUTFILE)" $(ALL_OBJ)

# Pattern rules
$(OUTDIR)/%.o : %.cpp
    $(COMPILE)

# Build rules
all: $(OUTFILE)

$(OUTFILE): $(OUTDIR)  $(OBJ)
    $(LINK)
    -cp Debug/test ./

$(OUTDIR):
    $(MKDIR) -p "$(OUTDIR)"

# Rebuild this project
rebuild: cleanall all

# Clean this project
clean:
    $(RM) -f $(OUTFILE)
    $(RM) -f $(OBJ)

# Clean this project and all dependencies
cleanall: clean
endif