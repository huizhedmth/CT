# include <stdio.h>
# include <SDL2/SDL.h>

int main()
{
  if (SDL_Init(SDL_INIT_EVERYTHING)){
    printf("wtf\n");
    exit(1);
  }

  SDL_Window* window;
  if (!(window = 
	SDL_CreateWindow("Flip", 0, 0, 100, 100, SDL_WINDOW_SHOWN))){
    printf("wtf\n");
    exit(1);
  }

  SDL_Renderer* renderer;
  renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_Texture* texture;
  SDL_Surface* surface = SDL_LoadBMP("./arrow.bmp");
  if (surface == 0){
    printf("wtf, %s\n", SDL_GetError());
  }
  
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  SDL_RenderCopy(renderer, texture, 0, 0);
  SDL_RenderPresent(renderer);
  SDL_Delay(1000);

  SDL_RenderClear(renderer);
  SDL_RenderCopyEx(renderer, texture, 0, 0, 0, 0,
		   SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
  SDL_RenderPresent(renderer);

  
  SDL_Delay(1000);

  


  SDL_Quit();

  return 0;
}
    

