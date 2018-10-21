RDIR=../../..
## C compiler
CC=gcc
ADD_FLAGS = -g -Wall -Werror -Wno-uninitialized -Wno-unused-function -Wno-unused-but-set-variable

# Include path
INC_PATH = -I$(RDIR)/driver/include/sort_common
INC_PATH += -I$(RDIR)/driver/include/bubble_sort

# Libraries used for stack application
INC_LIB += $(RDIR)/driver/lib/libsort.a

# Output binary
OUTPUT_DIR = ./bin
# Create output directory if not available
$(shell mkdir -p $(OUTPUT_DIR))

all:
	$(CC) bubble_sort_optimized_demo.c $(INC_PATH) -o $(OUTPUT_DIR)/bubble_sort_optimized_demo $(INC_LIB) $(ADD_FLAGS)
clean:
	rm -rf $(OUTPUT_DIR)

