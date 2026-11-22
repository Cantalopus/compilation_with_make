#############################################################
# There are two flavors of variables:

# recursive (use =) - only looks for the variables when the 
# command is used, not when it's defined.

# simply expanded (use :=) - like normal imperative 
# programming -- only those defined so far get expanded
#############################################################
#Recursive variable. This will print "later" below
one = one ${later_variable}
#Simply expanded variable. This will not print "later" below
two := two ${later_variable}

later_variable = later

all:
	@echo $(one)
	@echo $(two)
#############################################################





#############################################################
# Simply expanded (using :=) allows you to append to a 
# variable. Recursive definitions will give an infinite 
#loop error.
#############################################################
#one = hello
## one gets defined as a simply expanded variable (:=) and 
## thus can handle appending
#one := ${one} there
#
#all: 
#	@echo $(one)
#############################################################

  


#############################################################
# ?= only sets variables if they have not yet been set
#############################################################
#
#one = hello
#one ?= will not be set
#two ?= will be set
#
#all:
#	@echo $(one)
#	@echo $(two)
#############################################################





#############################################################
# Spaces at the end of a line are not stripped, but those at 
# the start are. To make a variable with a single space, use 
# $(nullstring)
#############################################################
#with_spaces = hello    # with_spaces has many spaces 
#                       # after "hello"
#after = $(with_spaces)there
#
#nullstring = 
#space = $(nullstring) # Make a variable with a single space.
#
#all:
#	@echo "$(after)"
#	@echo start"$(space)"end 
#############################################################





#############################################################
# An undefined variable is actually an empty string!
#############################################################
#all:
## undefined variables are just empty strings.
#	@echo $(nowhere)
#############################################################





#############################################################
# Use += to append
#############################################################
#foo := start
#foo += more
#
#all:
#	@echo $(foo)
#############################################################