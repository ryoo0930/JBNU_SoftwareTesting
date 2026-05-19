CXX = g++
CXXFLAGS = -std=c++17 -Wall
LIBS = -lgtest -lgtest_main -pthread

TARGET = test_triangle

$(TARGET): triangle.cpp test_triangle.cpp triangle.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) triangle.cpp test_triangle.cpp $(LIBS)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
