all: BSTree_main.o BSTree.o
	g++ -g BSTree.o BSTree_main.o -o run-trees

custom: BSTree.o custommain.cpp BSTree.cpp
	g++ -g BSTree.o custommain.cpp -o custom

BSTree.o: BSTree.h BSTree.cpp
	g++ -g -std=c++11 -c BSTree.cpp

BSTree_main.o: BSTree.o BSTree_main.cpp BSTree.cpp
	g++ -g -std=c++11 -c BSTree_main.cpp

run-trees: BSTree_main.o BSTree.o
	g++ -g BSTree.o BSTree_main.o -o run-trees

run2: custom
	./custom

run: run-trees
	./run-trees

clean:
	rm *.o custom
