# Makefile for CS455 Lab 10
#
#     gmake getfiles
#        Copies or links assignment files to current directory
#
#

# need to use gmake

HOME = /auto/home-scf-06/csci455/
ASSGTS = $(HOME)/assgts
ASSGTDIR = $(HOME)/labs/lab10

getfiles:
	-ln -s $(ASSGTDIR)/melville.txt .
	-ln -s $(ASSGTDIR)/poe.txt .
	-$(ASSGTS)/bin/safecopy $(ASSGTDIR)/Concord.java	
	-$(ASSGTS)/bin/safecopy $(ASSGTDIR)/ConcordDriver.java
	-$(ASSGTS)/bin/safecopy $(ASSGTDIR)/ConcordDriver3.java
	-$(ASSGTS)/bin/safecopy $(ASSGTDIR)/Predicate.java
	-$(ASSGTS)/bin/safecopy $(ASSGTDIR)/Makefile


#-----------------------------------------------------------------------
# DEN students: You will need to change the submit rule below to add
# the output files you created in Ex. 3 to the list of files to be
# submitted.  Just add them after where it says README below, on the
# same line as the word README.  
# Note: Do not add line-breaks in the middle of the submit command. Do
# not remove the leading <tab> in the command given below.

submit:
	submit -user csci455 -tag lab10 Concord.java ConcordDriver3.java poe.out melville.out README
