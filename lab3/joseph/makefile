inc =  -lm 

all: my_fun.o main.o
	gcc -w -o my_game my_fun.o main.o -Wno-deprecated -I ${inc} 

main.o: main.c
	gcc -c main.c -Wno-deprecated -I ${inc}

my_fun.o: my_lib.h my_fun.c
	gcc -c my_fun.c -Wno-deprecated -I ${inc}
clean:
	rm -f *.o