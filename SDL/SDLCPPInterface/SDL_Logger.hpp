/** SDL_Logger.hpp
 *
 * Declaration for class SDL_Logger.
 *
 * by Huizhe Li
 */

# ifndef SDL_LOGGER_HPP
# define SDL_LOGGER_HPP

# include <iostream>
# include <string>

namespace sdl_cpp{
  class SDL_Logger;
}

class sdl_cpp::SDL_Logger{
 public:

  /* write 'msg' to 'out' 
   * if 'err' set, grab SDL error 
   */
  void log(std::ostream &out, const std::string &msg, bool err = 0);
};

# endif // SDL_LOGGER_HPP
