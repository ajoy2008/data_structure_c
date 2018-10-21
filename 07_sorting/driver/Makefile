CC=gcc
RDIR=.
LOCALDIR = obj
BLDDIR = $(RDIR)/lib
# Define standard targets, etc.
ifdef LOCALDIR
override BLDDIR := $(BLDDIR)/$(LOCALDIR)
endif
LIBDIR := $(RDIR)/lib

# Default suffix for object files
OBJSUFFIX = o
# Default suffix for library files
LIBSUFFIX = a

ifndef LSRCS
LSRCS = $(wildcard *.c)
endif
ifndef LOBJS
LOBJS = $(addsuffix .$(OBJSUFFIX), $(basename $(LSRCS)))
endif
ifndef BOBJS
BOBJS = $(addprefix $(BLDDIR)/,$(LOBJS))
endif

# try building using standard UNIX utilities
RM      = rm -f
MKDIR   = mkdir -p
CP      = cp -d
ECHO    = echo
PRINTF  = printf

# Define rules for creating object directories
.PRECIOUS: $(BLDDIR)/.tree

%/.tree:
	@$(ECHO) 'Creating build directory $(dir $@)'
	$(Q)$(MKDIR) $(dir $@)
	@$(ECHO) "Build Directory for $(LOCALDIR) created" > $@

VPATH += src/sort_common
VSRCS += $(wildcard src/sort_common/*.c)
VPATH += src/bubble_sort
VSRCS += $(wildcard src/bubble_sort/*.c)

INC_PATH += -I include/sort_common
INC_PATH += -I include/bubble_sort


LSRCS = $(notdir $(VSRCS))
LOBJS = $(addsuffix .o, $(basename $(LSRCS)))
BOBJS = $(addprefix $(BLDDIR)/,$(LOBJS))

LIBNAME = libsort
CFLAGS = -Wall -Werror -Wno-uninitialized

$(BLDDIR)/%.$(OBJSUFFIX): %.c $(BLDDIR)/.tree
	@$(ECHO) 'Compiling $(LOCALDIR)/$<'
	$(Q)$(CC) $(INC_PATH) $(CFLAGS) -c -g $< -o $@

$(LIBDIR)/$(LIBNAME).$(LIBSUFFIX): $(BOBJS) $(BLDDIR)/.tree 
	@$(ECHO) 'Building library $(LIBNAME)...'
	$(Q)$(AR) $(ARFLAGS) $@ $(BOBJS)
	
BLIBNAME = $(LIBDIR)/$(LIBNAME).$(LIBSUFFIX)

.SECONDARY:: $(BOBJS)

all:: $(BLDDIR)/.tree $(BLIBNAME)

clean::
	@$(ECHO) Cleaning objects for $(notdir $(BLIBNAME))
	$(Q)$(RM) $(BLDDIR)/.tree $(BOBJS) $(BLIBNAME)
