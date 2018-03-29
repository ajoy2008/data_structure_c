CC=gcc
RDIR=.
VSRCS += $(wildcard $(RDIR)/src/*.c)
LSRCS = $(notdir $(VSRCS))
LOCALDIR = $(RDIR)/src
BLDDIR = $(RDIR)/src/obj
LIBDIR = $(RDIR)/lib
LOBJS = $(addsuffix .o, $(basename $(LSRCS)))
BOBJS = $(addprefix $(BLDDIR)/,$(LOBJS))
LIBNAME = libstack
LIBSUFFIX = a
CFLAGS = -g -Wall -Werror -Wno-uninitialized

$(shell mkdir -p $(BLDDIR))
$(shell mkdir -p $(LIBDIR))

INCLUDE = -I $(RDIR)/include
ECHO = echo

$(BLDDIR)/%.o: $(LOCALDIR)/%.c 
	@$(ECHO) 'Compiling $(LOCALDIR)/$<'
	$(CC) $< $(INCLUDE) $(CFLAGS) -c -g  -o $@

$(LIBDIR)/$(LIBNAME).$(LIBSUFFIX): $(BOBJS) 
	@$(ECHO) 'Building library $(LIBNAME)...'
	$(Q)$(AR) $(ARFLAGS) $@ $(BOBJS)

BLIBNAME = $(LIBDIR)/$(LIBNAME).$(LIBSUFFIX)

all:: $(BLIBNAME)

clean::
	@$(ECHO) Cleaning objects for $(notdir $(BLIBNAME))
	$(RM) $(BOBJS) $(BLIBNAME)
	$(RM) -rf $(BLDDIR) $(LIBDIR)