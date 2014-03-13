/** GameState.hpp
 *
 * Declaration for abstract class GameState.
 *
 * Represents a generic state in game.
 *
 * by Huizhe Li
 */

# ifndef GAMESTATE_HPP
# define GAMESTATE_HPP

# include "SDL_CPP.hpp"
# include "Drawable.hpp"
# include <vector>

namespace sdl_game{
  class GameState;
}

class sdl_game::GameState{
public:
  virtual ~GameState(){};
  virtual void render(sdl_cpp::SDL_CRenderer &renderer) = 0;
  virtual void update() = 0;
  virtual bool onEnter() = 0;
  virtual bool onExit() = 0;

protected:
  /* list of objects in this state */
  std::vector<tsubasa::Drawable*> m_objects;
};


# endif // GAMESTATE_HPP
