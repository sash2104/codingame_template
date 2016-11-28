CXX = g++
TARGET = run
CXXFLAGS = -std=c++11
SRCS = main.cpp game.cpp
OBJS := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)
