all:
	g++ main.cpp -Wall -g -std=c++1y -o foo
t:
	g++ ./tests/tests.cpp -std=c++1y -o test

clean:
	rm foo
