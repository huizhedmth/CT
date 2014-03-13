/** SDL_Logger.cpp
 *
 * Implementation of class SDL_Logger
 *
 * by Huizhe Li
 */

# include <SDL2/SDL.h>
# include "SDL_Logger.hpp"
# include <iostream>
# include <string>

using sdl_cpp::SDL_Logger;
using std::string;

void SDL_Logger::log(std::ostream &out, const string &msg, 
		     bool err)
{
  if (err){
    out << msg << " error: " << SDL_GetError() << std::endl;
  }
  else {
    out << msg << std::endl;
  }
}
