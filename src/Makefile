# Object files
OBJS = tokenizer.o lab1.o history.o

# Flags 
CFLAGS = -g -O3

# Our first target built
all: Tokenizer

Tokenizer: $(OBJS)
	cc -o Tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o Tokenizer

run: Tokenizer
	./Tokenizer
