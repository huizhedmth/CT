/** SDL_Manager.hpp
 *
 * Declaration for class SDL_Manager, which wraps up
 * initializing functions provided by SDL2.
 *
 * by Huizhe Li
 */

# ifndef SDL_MANAGER_HPP
# define SDL_MANAGER_HPP

# include <SDL2/SDL.h>

namespace sdl_cpp{
  class SDL_Manager;
}

class sdl_cpp::SDL_Manager{
public:
  bool init(Uint32 flags); /* initialize SDL according to 'flags' */
  void delay(int miliseconds); /* delay 'miliseconds' */
  void quit();

  const Uint8* get_key_states();

  static SDL_Manager* get_instance();
    
private:
  SDL_Manager(){};
  ~SDL_Manager(){};

  static SDL_Manager* s_theManager;

};

# endif // SDL_MANAGER_HPP
