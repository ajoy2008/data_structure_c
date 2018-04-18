RDIR=../..
## C compiler
CC=gcc
ADD_FLAGS = -g -Wall -Werror -Wno-uninitialized -Wno-unused-function -Wno-unused-but-set-variable

# Select underlying stack implementation mechanism(Do you want Array based stack or linked list based stack ??)
ADD_FLAGS += -D__ARR_STK_S32__
#ADD_FLAGS += -D__LIST_STK_S32__

# Include path
INC_PATH = -I$(RDIR)/driver/include

# Libraries used for stack application
INC_LIB += $(RDIR)/driver/lib/libstack.a

# Output binary
OUTPUT_DIR = ./bin
# Create output directory if not available
$(shell mkdir -p $(OUTPUT_DIR))

all:
	$(CC) queue_using_stack_1.c $(INC_PATH) -o $(OUTPUT_DIR)/queue_using_stack_1 $(INC_LIB) $(ADD_FLAGS)
	$(CC) queue_using_stack_2.c $(INC_PATH) -o $(OUTPUT_DIR)/queue_using_stack_2 $(INC_LIB) $(ADD_FLAGS)
clean:
	rm -rf $(OUTPUT_DIR)

