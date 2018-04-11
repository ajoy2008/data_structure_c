RDIR=../..
## C compiler
CC=gcc
ADD_FLAGS = -g -Wall -Werror -Wno-uninitialized -Wno-unused-function -Wno-unused-but-set-variable

# Select underlying stack implementation mechanism(Do you want Array based stack or linked list based stack ??)
ADD_FLAGS += -D__ARR_STK_U8__
#ADD_FLAGS += -D__LIST_STK_U8__

# Include path
INC_PATH = -I$(RDIR)/driver/include

# Libraries used for stack application
INC_LIB += $(RDIR)/driver/lib/libstack.a

# Output binary
OUTPUT_DIR = ./bin
# Create output directory if not available
$(shell mkdir -p $(OUTPUT_DIR))

all:
	$(CC) infix_evaluation_single_pass.c $(INC_PATH) -o $(OUTPUT_DIR)/infix_evaluation_single_pass $(INC_LIB) $(ADD_FLAGS)
clean:
	rm -rf $(OUTPUT_DIR)

