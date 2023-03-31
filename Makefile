CFLAGS := -std=c++14 -fvisibility=hidden -lpthread

SOURCES := src/*.cpp
HEADERS := src/*.h

TARGETBIN := connect5
all: $(TARGETBIN)
$(TARGETBIN): $(SOURCES) $(HEADERS)
	$(CXX) -o $@ $(CFLAGS) $(SOURCES) 

clean: 
	rm -rf ./connect5

format:
	clang-format -i src/*.cpp src/*.h