CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

track: code.cpp TrackLibrary.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

TrackLibrary.o: TrackLibrary.cpp TrackLibrary.h
	$(CXX) $(CXXFLAGS) -c $<


.PHONY: clean

clean:
	$(RM)  *.o converter
