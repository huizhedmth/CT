/** SDL_Window.cpp
 *
 * Implementation of class SDL_CWindow.
 *
 * by Huizhe Li
 */

# include "SDL_CWindow.hpp"
# include "SDL_Logger.hpp"
# include <SDL2/SDL.h>

using sdl_cpp::SDL_CWindow;
using sdl_cpp::SDL_Logger;

/* constructor */
SDL_CWindow::SDL_CWindow()
{
  m_win = nullptr;
}

/* destructor */
SDL_CWindow::~SDL_CWindow()
{
  SDL_DestroyWindow(m_win);
}

bool SDL_CWindow::create(const char* title,
			 int x, int y, int w, int h,
			 Uint32 flags)
{
  static std::string func = "SDL_CWindow::create_window";
  SDL_Logger logger;

  
  if (m_win == nullptr){// first time calling this function 
    m_win = SDL_CreateWindow(title, x, y, w, h, flags);
    if (m_win == nullptr){// SDL failure 
      logger.log(std::cerr, func, true);
      return false;
    } else {// success 
      return true;
    }

  } else { // ignore mltiple assignments 
    SDL_Logger logger;
    logger.log(std::cout, func + ": multiple assignments detected. No Operations performed. ");
    return false;
  }

}

SDL_Window* SDL_CWindow::get_window() const
{
  return m_win;
}
