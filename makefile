CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Menu.o Grid.o Critter.o Ant.o Doodlebug.o main.o

SRCS = Menu.cpp Grid.cpp Critter.cpp Ant.cpp Doodlebug.cpp main.cpp

HEADERS = Menu.hpp Grid.hpp Critter.hpp Ant.hpp Doodlebug.hpp


#target dependencies
#	rule to build

default: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o predatorPrey
	
main.o: main.cpp Grid.hpp Menu.hpp
	${CXX} ${CXXFLAGS} -c main.cpp
	
Menu.cpp: Menu.hpp

Grid.cpp: Menu.hpp Grid.hpp

Critter.cpp: Critter.hpp

Doodlebug.cpp: Doodlebug.hpp

Ant.cpp: Ant.ghpp
	
clean:
	rm predatorPrey ${OBJS}
