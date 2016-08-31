inc = $(pkg-config --libs --cflags glib-2.0) -lm
inc1 = -lm;

all: my_fun.o main.o
	gcc -w -o my_exe my_fun.o main.o $$(pkg-config --libs --cflags glib-2.0) -lm

main.o: main.c
	gcc -c main.c $$(pkg-config --libs --cflags glib-2.0) -lm

my_fun.o: my_lib.h my_fun.c
	gcc -c my_fun.c $$(pkg-config --libs --cflags glib-2.0) -lm
	
clean:
	rm -f *.o