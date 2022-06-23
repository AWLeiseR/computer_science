PROJ_NAME=exame
 
C_SOURCE=$(wildcard *.c)
 
H_SOURCE=$(wildcard *.h)
 
OBJ=$(C_SOURCE:.c=.o)
 
CC=gcc
 
CC_FLAGS=-c         \
         -W         \
         -Wall      \
	 -std=c99	\
	 -fstack-protector-all
 
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ -lm
 
%.o: %.c %.h

	$(CC) -o $@ $< $(CC_FLAGS)
 
main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)
 
clean:
	rm -rf *.o $(PROJ_NAME) *~