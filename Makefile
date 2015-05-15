all:
	g++ main.cpp -Wall -g -std=c++1y -o foo
t:
	g++ ./tests/tests.cpp -std=c++1y -o test

demo:
	g++ ./demo/demo.cpp -std=c++1y -o demo

clean:
	rm foo test
