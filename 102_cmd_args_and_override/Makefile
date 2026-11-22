#################################################
# You can override variables that come from the
# command line by using overide. here we ran make
# with: RUN >>>>> make option_one=hi
#       RUN >>>>> make option_two=hi
#################################################
# Overrides command line arguments
override option_one = did_override
# Does not override command line arguments
option_two = not_override

all:
	@echo $(option_one)
	@echo $(option_two)
#################################################