
CC = gcc
CFLAGS = -O2 -Wall -I ./include

OBJDIR = obj
OBJS = $(OBJDIR)/load_inferior.o

OUTDIR = bin

default:
	make -r all

all: $(OUTDIR) $(OUTDIR)/kuso_dbg

$(OUTDIR)/kuso_dbg: $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: */%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

$(OUTDIR):
	mkdir $(OUTDIR)
clean:
	rm -rf obj

CLEAN:
	rm -rf obj
	rm -rf bin
