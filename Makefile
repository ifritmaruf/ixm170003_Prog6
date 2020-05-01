#!/usr/bin/make -f
#
# Filename:		Makefile
# Date:			04/16/2020
# Author:		Ifrit Maruf
# Email:		ixm170003@utdallas.edu
# Course:		CS 3377.501 Spring 2020
# Version:		1.0
# Copyright:		2020, All Rights Reserved
#
# Description:
#	A moderately complex makefile that takes care of cdk using bin file
#

# Set up needed values to support make's implicit commands
# for compiling C++ source files.

# The compiler to use
CXX = g++

CXXFLAGS=

# C pre-processor flags
CPPFLAGS = -Wall -g -I/scratch/perkins/include

# linker flags
LDFLAGS = -L/scratch/perkins/lib
LDLIBS= -lcdk -lcurses

# Project name.  This is used in building the file name for the backup target
PROJECTNAME = cdkex


# Enter the names of the C++ source files that you want to compile
# with this project

# Auto include all .cc files
SOURCES := $(wildcard *.cc)

# Enter the name for the executable to be created
EXEC = cdkexample

# You normally don't need to change anything below here.
# ======================================================
#
#
OBJS = $(SOURCES:cc=o)

.PHONY: all clean 

all: $(EXEC)
clean:
	rm -f $(OBJS) *.d *.o *~ $(EXEC)


#  This is a rule to link the files.  Pretty standard
$(EXEC): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

# Backup Target
backup:	clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!


# Include the dependency files created by the PreProcessor.  The
# dash in front of the command keeps the system from complaining
# if the files do not exist.
