CXX = g++
CXXFLAGS = -std=c++17 -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lboost_system -lboost_filesystem -lpthread

TARGET = calculator

all: $(TARGET)

$(TARGET): main.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) *.o