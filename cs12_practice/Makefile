#Example of a makefile using Rectangle makefile

COMPILE=g++
OBJS = Point.o Rectangle.o
FLAGS = -Wall -Werror -Wuninitialized

all: lec001.cpp $(OBJS)
	$(COMPILE) $(FLAGS) lec001.cpp $(OBJS) -o a.out
		
Rectangle.o: Rectangle.h Rectangle.cpp Point.cpp
	$(COMPILE) $(FLAGS) -c Rectangle.cpp -o Rectangle.o
		
Point.o: Point.h Point.cpp
	$(COMPILE) $(FLAGS) -c Point.cpp -o Point.o
	
clean:
	rm a.out *.o