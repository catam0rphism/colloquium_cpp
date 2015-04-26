all:
	g++ main.cpp -Wall -std=c++1y -o foo
t:
	g++ ./tests/bar.cpp -std=c++1y -o test

clean:
	rm foo
