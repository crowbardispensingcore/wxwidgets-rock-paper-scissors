WX_CXXFLAGS := $(shell wx-config --cxxflags)
WX_LIBS := $(shell wx-config --libs)

# game: rps_game.o main_frame.o
# 	g++ -o game rps_game.o main_frame.o $(WX_LIBS)

# rps_game.o: rps_game.cpp
# 	g++ -c rps_game.cpp $(WX_CXXFLAGS)

# main_frame.o: main_frame.cpp
# 	g++ -c main_frame.cpp $(WX_CXXFLAGS)
game: *.o
	g++ -o game $^ $(WX_LIBS)

%.o: %.cpp
	g++ -c *.cpp $< $(WX_CXXFLAGS) 

clean:
	rm *.o game