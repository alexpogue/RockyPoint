TOOLCHAIN := ./toolchain
BIN := $(TOOLCHAIN)/bin

MSYS := C:/Apps/MinGW/msys/1.0/bin

EMULATOR := ./emulator

BUILDDIR := ./build
SRCDIR := ./src
OUTDIR := ./bin

SRCDIRS := $(shell $(MSYS)/find $(SRCDIR) -type d -print)
BUILDDIRS := $(patsubst $(SRCDIR)%,$(BUILDDIR)%,$(SRCDIRS))

CSRCS := $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.c))
HEADERS := -I ./include -I $(TOOLCHAIN)/arg-agb-elf/include -I $(TOOLCHAIN)/lib/gcc-lib/arm-agb-elf/3.2.2/include

OBJS := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(CSRCS))
LIBOBJS := $(wildcard $(TOOLCHAIN)/arg-agb-elf/*.o)

OUTELF := $(OUTDIR)/RockyPoint.elf
OUTROM := $(OUTDIR)/RockyPoint.gba

CFLAGS := -Wall -Werror -std=c99
LDFLAGS := -o $(OUTDIR)/RockyPoint.elf

CC := $(BIN)/gcc
AS := $(BIN)/as
AR := $(BIN)/ar
LD := $(BIN)/ld
OBJCOPY := $(BIN)/objcopy

env:
	-mkdir $(BUILDDIRS)
	-mkdir $(OUTDIR)
	
$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ $^
	
$(OUTELF): $(CSRCS)
	$(CC) $(CFLAGS) $(HEADERS) -o $(OUTELF) $(CSRCS)

$(OUTROM) : $(OUTELF)
	$(OBJCOPY) -O binary $(OUTELF) $(OUTROM)

all: env $(OUTROM)

run: all
	(cd $(EMULATOR) && ./VisualBoyAdvance-SDL.exe ../$(OUTROM))

clean:
	rm -r $(BUILDDIR)
	rm -r $(OUTDIR)
