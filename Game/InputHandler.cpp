/** InputHandler.cpp
 *
 * Implementation of  class InputHandler.
 *
 * by Huizhe Li
 */

# include "InputHandler.hpp"
# include "SDL_CPP.hpp"
# include <SDL2/SDL.h>
# include <iostream>

using sdl_game::InputHandler;
using namespace sdl_cpp;

InputHandler* InputHandler::s_theInputHandler = nullptr;

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::update()
{
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    m_keyStates = SDL_Manager::get_instance()->get_key_states();
  }

  //  std::cout << "m_keyStates updated" << std::endl;
}

InputHandler* InputHandler::get_instance()
{
  if(s_theInputHandler == nullptr){
    s_theInputHandler = new InputHandler();
  }
  return s_theInputHandler;
}

bool InputHandler::is_key_down(SDL_Scancode key)
{
  if (m_keyStates != nullptr){
    //  std::cout << "m_keyStates not null" << std::endl;
    if (m_keyStates[key] == 1)
      return true;
    else 
      return false;
  }
  //  std::cout << "m_keyStates null" << std::endl;
  return false;
}

