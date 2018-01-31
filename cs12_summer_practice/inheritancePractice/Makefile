#Payroll makefile

#Variables
COMPILE = g++
FLAGS = -W -Wall -Werror
OBJS = Employee.o Lecturer.o StudentEmpl.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) ($FLAGS) -o a.out main.cpp $(OBJS)
	
Employee.o: Employee.cpp Employee.h
	$(COMPILE) $(FLAGS) -c Employee.cpp
	
StudentEmpl.o: StudentEmpl.cpp StudentEmpl.h Employee.h
	$(COMPILE) $(FLAGS) -c StudentEmpl.cpp
	
Lecturer.o: Lecturer.cpp Leecturer.h Employee.h
	$(COMPILE) $(FLAGS) -c Lecturer.cpp
	
clean:
	rm -rf *~ *.o a.out