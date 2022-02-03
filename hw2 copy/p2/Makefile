CXX=g++
CXXFLAGS=-Wall

assigntables: assigntables.cpp Restaurant.cpp Table.cpp
	$(CXX) -o $@ $^

execs = assigntables

clean: 
	rm -f $(execs) *.o