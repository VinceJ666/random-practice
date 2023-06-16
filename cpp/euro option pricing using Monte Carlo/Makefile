output: option.o rdnorm.o euro_option.o
	g++ option.o rdnorm.o euro_option.o -o option_pricing
	rm *.o

euro_option.o: euro_option.cpp option.h 
	       g++ -c euro_option.cpp 

option.o: option.cpp option.h rdnorm.h
	  g++ -c option.cpp 

rdnorm.o: rdnorm.cpp rdnorm.h
	  g++ -c rdnorm.cpp

clean:
	rm option_pricing

