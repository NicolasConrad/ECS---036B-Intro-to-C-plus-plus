CXX=g++
CXXFLAGS=-Wall

robot: robot.cpp Angle.cpp
	g++ -o $@ $^ 

execs = robot

clean:
	rm -f $(execs) *.o