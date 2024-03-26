IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src/obj
SDIR=src

_DEPS = mainlib.h admin.h textFileModules.h customer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o mainlib.o admin.o textFileModules.o customer.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BankManager: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o