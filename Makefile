CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11

TARGET := add-nbo
SRCS := add-nbo.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

