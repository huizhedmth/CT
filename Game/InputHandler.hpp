/** InputHandler.hpp
 *
 * Declaration for class InputHandler.
 *
 * For now it handles only keyboard events.
 *
 * by Huizhe Li
 */

# ifndef INPUTHANDLER_HPP
# define INPUTHANDLER_HPP

# include <SDL2/SDL.h>

namespace sdl_game{
  class InputHandler;
}

class sdl_game::InputHandler{
public:
  static InputHandler* get_instance();
  void update();  /* read key states */
  bool is_key_down(SDL_Scancode key);
private:
  InputHandler();
  ~InputHandler();
  static InputHandler* s_theInputHandler;

protected:
  const Uint8* m_keyStates;

};

# endif // INPUTHANDLER_HPP
