/** SDL_CWindow.hpp
 *
 * Declaration for class SDL_CWindow, which handles
 * general operation concering a SDL_CWindow structure.
 *
 * by Huizhe Li
 */

# ifndef SDL_CWINDOW_HPP
# define SDL_CWINDOW_HPP

# include <SDL2/SDL.h>

namespace sdl_cpp{
  class SDL_CWindow;
}

class sdl_cpp::SDL_CWindow{
 public:
  /* constructors */
  SDL_CWindow();

  /* wrappers */
  bool create(const char* title,
	      int x, int y, int w, int h,
	      Uint32 flags);

  SDL_Window* get_window() const;
  ~SDL_CWindow();    /* necessary de-allocation */
 private:
  SDL_Window* m_win; /* pointer to the actual window */ 
};

#endif // SDL_CWINDOW_HPP
