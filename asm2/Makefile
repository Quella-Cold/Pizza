CC = g++ -g
exe_file = test
$(exe_file):menu.o pizza.o restaurant.o main.o
	$(CC) menu.o pizza.o restaurant.o main.o -o $(exe_file)
menu.o:menu.cpp
	$(CC) -c menu.cpp
pizza.o:pizza.cpp
	$(CC) -c pizza.cpp
restaurant.o:restaurant.cpp
	$(CC) -c restaurant.cpp
main.o:main.cpp
	$(CC) -c main.cpp




clean:
	rm -f *.out *.o $(exe_file)
