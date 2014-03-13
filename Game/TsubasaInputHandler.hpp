/** TsubasaInputHandler.hpp
 *
 * Declaration for class TsubasaInputHandler : public InputHandler
 *
 * Added ability to map keys into vkeys
 *
 * by Huizhe Li
 */

# ifndef TSUBASAINPUTHANDLER_HPP
# define TSUBASAINPUTHANDLER_HPP

# include <SDL2/SDL.h>
# include "InputHandler.hpp"

namespace tsubasa{
  class TsubasaInputHandler;
}

typedef enum CTRL_VKEY{
    VKEY_RIGHT = 0,
    VKEY_UP = 1,
    VKEY_LEFT = 2,
    VKEY_DOWN = 3,
    VKEY_A = 4,
    VKEY_B = 5,
    VKEY_SELECT = 6,
    VKEY_START = 7,
    VKEY_END = 8
}CTRL_VKEY;

class tsubasa::TsubasaInputHandler{

public:
  static TsubasaInputHandler* get_instance();

  
  void update();  /* read key states */
  bool is_vkey_down(CTRL_VKEY vkey);
  bool is_key_down(SDL_Scancode key);

private:  
  TsubasaInputHandler();
  ~TsubasaInputHandler();

  SDL_Scancode m_vkeyMap[VKEY_END];
  static TsubasaInputHandler* s_theTsubasaInputHandler;
  sdl_game::InputHandler* m_theInputHandler;
};


# endif // TSUBASAINPUTHANDLER_HPP
