CC = gcc

SDL_LIB = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2
SDL_MIXER_LIB = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL2_mixer
SDL_INCLUDE = -I/usr/local/include/SDL2 -D_REENTRANT

CFLAGS = -Wall -c $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB) $(SDL_MIXER_LIB)

EXE = playwav

all: $(EXE) 

$(EXE): playwav.o
	$(CC) $< $(LDFLAGS) -o $@

playwav.o: playwav.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXE)