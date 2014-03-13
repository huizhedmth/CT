# include "FBGame.hpp"
# include <string>
# include <SDL2/SDL.h>
# include <iostream>

using namespace std;
using namespace tsubasa;

int main()
{
  FBGame game;
  
  game.init("Tsubasa", 0, 0, 770, 680, SDL_WINDOW_SHOWN);
  if (!game.load_resource()){
    std::cout << " failed loading resource." << std::endl;
  }
  game.loading_check();

  // main loop
  const int FPS = 24;
  const float DELAY_TIME = 1000.0f / FPS;
  Uint32 frameStart, frameTime;
 
  game.start();
  while(game.is_running()){
    frameStart = SDL_GetTicks();

    game.handle_events();

    game.update();
    game.render();
    frameTime = SDL_GetTicks() - frameStart;

    if (frameTime < DELAY_TIME){
      SDL_Delay((int)(DELAY_TIME-frameTime));
    }

  }
  
  game.quit();
  
  return 0;
}
  
