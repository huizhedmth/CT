CXX = g++

SDL_LIB = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2
SDL_IMAGE_LIB = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2_image
SDL_INCLUDE = -I/usr/local/include/SDL2 -D_REENTRANT

MY_LIB = -L/home/diaz/lib -Wl,-rpath,/home/diaz/lib -lsdlcpp
MY_INCLUDE = -I/home/diaz/include


CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE) $(MY_INCLUDE)
LDFLAGS = $(MY_LIB) $(SDL_LIB) $(SDL_IMAGE_LIB)

TARGET = tsubasa 

all: $(TARGET)

$(TARGET): main.o TextureManager.o Player.o FBGame.o FileReader.o Drawable.o\
	ObjectManager.o  MatchState.o MeetingMenuState.o \
	StateMachine.o InputHandler.o Texture.o Animatable.o\
	TsubasaInputHandler.o Animatables.o Vector2D.o\
	Team.o

	$(CXX) $^ $(LDFLAGS) -o $(TARGET)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

TextureManager.o: TextureManager.cpp TextureManager.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

ObjectManager.o: ObjectManager.cpp ObjectManager.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

Player.o: Player.cpp Player.hpp 
	$(CXX) $(CXXFLAGS) $< -o $@

FileReader.o: FileReader.cpp FileReader.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

FBGame.o: FBGame.cpp FBGame.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

Drawable.o: Drawable.cpp Drawable.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

Animatable.o: Animatable.cpp Animatable.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

Animatables.o: Animatables.cpp Animatables.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

Texture.o: Texture.cpp Texture.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

MatchState.o: MatchState.cpp MatchState.hpp GameState.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

MeetingMenuState.o: MeetingMenuState.cpp MeetingMenuState.hpp GameState.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

StateMachine.o: StateMachine.cpp StateMachine.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

InputHandler.o: InputHandler.cpp InputHandler.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

TsubasaInputHandler.o: TsubasaInputHandler.cpp TsubasaInputHandler.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

Vector2D.o: Vector2D.cpp Vector2D.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

Team.o: Team.cpp Team.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGET)