/** StateMachine.cpp
 *
 * Implementation of class StateMachine.
 *
 * by Huizhe Li
 */

# include "StateMachine.hpp"
# include "GameState.hpp"
# include "SDL_CPP.hpp"

using sdl_game::StateMachine;
using sdl_game::GameState;
using namespace sdl_cpp;

void StateMachine::update()
{
  if (!m_states.empty()){
    m_states.back()->update();
  }
}

void StateMachine::render(SDL_CRenderer &renderer)
{
  if (!m_states.empty()){
    m_states.back()->render(renderer);
  }
}

void StateMachine::push_state(GameState* state)
{
  m_states.push_back(state);
  state->onEnter();
}

void StateMachine::pop_state()
{
  if (!m_states.empty()){
    if (m_states.back()->onExit()){
      delete m_states.back();
      m_states.pop_back();
    }
  }
}


  
