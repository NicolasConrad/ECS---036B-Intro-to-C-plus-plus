CXXFLAGS=-WALL
CXX=g++

all = checkpack testPoint testShape

checkpack: checkpack.cpp Point.cpp Domain.cpp Shape.cpp
	$(CXX) -o $@ $^

testPoint: testPoint.cpp Point.cpp Domain.cpp Shape.cpp
	$(CXX) -o $@ $^

testShape: testShape.cpp Point.cpp Domain.cpp Shape.cpp
	$(CXX) -o $@ $^

clean:
	rm -f $(all) *.o