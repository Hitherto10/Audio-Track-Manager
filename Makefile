# calling c++ compiler
CXX = g++

# compiler flags:
CXXFLAGS = -g -Wall -Wextra
objects = main.o Track.o TrackLibrary.o TrackList.o TrackNode.o BinarySearchTree.o
target = program

# Assigning the target for building to all
.PHONY: all
all: $(target)

# rule for building main
$(target): $(objects)
	$(CXX) -o $@ $^

# rule for building main
main.o: main.cpp main.h
	$(CXX) $(CXXFLAGS) -c $<

# rule for building Track class
Track.o: Track.cpp Track.h
	$(CXX) $(CXXFLAGS) -c $<

# rule for building MusicLibrary class
TrackLibrary.o: TrackLibrary.cpp TrackLibrary.h
	$(CXX) $(CXXFLAGS) -c $<

# rule for building TrackList class
TrackList.o: TrackList.cpp TrackList.h
	$(CXX) $(CXXFLAGS) -c $<

# rule for building TrackNode class
TrackNode.o: TrackNode.cpp TrackNode.h
	$(CXX) $(CXXFLAGS) -c $<

# rule for building BinarySearchTree used in code
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	$(CXX) $(CXXFLAGS) -c $<

# Delete all object, executable and dump files after compilation
.PHONY: clean
clean:
	rm -rf *.o *.exe *.stackdump $(target)
