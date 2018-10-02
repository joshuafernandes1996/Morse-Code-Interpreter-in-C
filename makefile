morse.exe:morse_main.o morse_func.o
	gcc morse_main.o morse_func.o -o morse.exe

morse_main.o:morse_main.c 
	gcc -c  morse_main.c

morse_func.o:morse_func.c
	gcc -c  morse_func.c
