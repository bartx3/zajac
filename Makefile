#makefile

CXX = g++

CXXFLAGS = -O3 -std=c++20 -pedantic -Wall -Wextra

all: main

main: main.o Zajac.o Wsporzedne.o func.o
	$(CXX) -o main $(CXXFLAGS) main.o Zajac.o Wsporzedne.o func.o
	
main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

Zajac.o: Zajac.cc
	$(CXX) $(CXXFLAGS) -c Zajac.cc

Wsporzedne.o: Wsporzedne.cc
	$(CXX) $(CXXFLAGS) -c Wsporzedne.cc

func.o: func.cc
	$(CXX) $(CXXFLAGS) -c func.cc

clean:
	rm *.o main

