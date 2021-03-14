all: run-dll

run-dll: DLList.o DLList-main.o
	c++ -g -std=c++11 DLList.o DLList-main.o -o run-dll

DLList.o: DLList.cpp DLList.h
	c++ -g -std=c++11 -c DLList.cpp

DLList-main.o: DLList-main.cpp DLList.h
	c++ -g -std=c++11 -c DLList-main.cpp

clean:
	rm *.o run-dll


allt: run-tdll

run-tdll: TDLList-main.o 
	c++ -std=c++11 TDLList-main.o -o run-tdll

TDLList-main.o: TDLList-main.cpp TemplatedDLList.h
	c++ -std=c++11 -c TDLList-main.cpp

cleant:
	rm *.o run-tdll
