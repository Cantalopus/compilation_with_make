CC = gcc

BUILD_DIR := ./build
SRC_DIRS := ./src
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

list-all: 
	@echo $(BUILD_DIR)\
	      $(SRC_DIRS) \
		  $(SRCS) \
		  $(OBJS) \
		  $(DEPS) \
		  $(INC_DIRS) \
		  $(INC_FLAGS)

list-build:
	@echo $(BUILD_DIR)

list-src_dirs:
	@echo $(SRC_DIRS)

list-srcs:
	@echo $(SRCS)

list-objs:
	@echo $(OBJS)

list-deps:
	@echo $(DEPS)

list-inc_dirs:
	@echo $(INC_DIRS)

list-inc_flags:
	@echo $(INC_FLAGS)