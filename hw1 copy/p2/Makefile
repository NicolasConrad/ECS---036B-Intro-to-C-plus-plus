CXX=g++
CXXFLAGS=-Wall

useFraction: useFraction.cpp Fraction.cpp
	g++ -o $@ $^ 

calculator: calculator.cpp Fraction.cpp
	g++ -o $@ $^ 
	
execs = useFraction calculator

clean:
	rm -f $(execs) *.o