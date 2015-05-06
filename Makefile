all:
	g++ main.cpp -Wall -g -std=c++1y -o foo
t:
	g++ ./tests/bar.cpp -std=c++1y -o test

clean:
	rm foo
