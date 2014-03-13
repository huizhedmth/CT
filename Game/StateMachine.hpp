/** StateMachine.hpp
 *
 * Declaration for class StateMachine.
 *
 * A finite state machine that manages states in a game.
 *
 * by Huizhe Li
 */

# ifndef STATEMACHINE_HPP
# define STATEMACHINE_HPP

# include <vector>
# include "SDL_CPP.hpp"
# include "GameState.hpp"

namespace sdl_game{
  class StateMachine;
}

class sdl_game::StateMachine{
public:
  void push_state(sdl_game::GameState*);
  void pop_state();
  void change_state(sdl_game::GameState*);
  
  void render(sdl_cpp::SDL_CRenderer &renderer);
  void update();
  
protected:
  std::vector<sdl_game::GameState*> m_states;
};
# endif // STATEMACHINE_HPP
