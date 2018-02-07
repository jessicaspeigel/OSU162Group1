CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -03
#LDFLAGS = -lboost_date_time

OBJS = Menu.o Grid.o main.o

SRCS = Menu.cpp Grid.cpp main.cpp

HEADERS = SRCS = Menu.hpp Grid.hpp main.hpp


#target dependencies
#	rule to build

default: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o predatorPrey
	
main.o: main.cpp Grid.hpp
	${CXX} ${CXXFLAGS} -c main.cpp
	
Menu.cpp: Menu.hpp

Grid.cpp: Menu.hpp Grid.hpp
	
clean:
	rm predatorPrey ${OBJS}