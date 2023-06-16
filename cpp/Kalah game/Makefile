output: kala.o p8.o
	g++ kala.o p8.o -o kala
	rm *.o

kala.o: kala.cpp kala.h
	g++ -c kala.cpp -std=c++20

p8.o: p8.cpp kala.h
	g++ -c p8.cpp

clean:
	rm kala

