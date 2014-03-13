/** TsubasaInputHandler.cpp
 *
 * Implementation for class TsubasaInputHandler : public InputHandler
 *
 * by Huizhe Li
 */

# include "TsubasaInputHandler.hpp"
# include "InputHandler.hpp"
# include <SDL2/SDL.h>
# include "SDL_CPP.hpp"

using tsubasa::TsubasaInputHandler;
using sdl_game::InputHandler;
using namespace sdl_cpp;

TsubasaInputHandler* 
TsubasaInputHandler::s_theTsubasaInputHandler = nullptr;

bool TsubasaInputHandler::is_vkey_down(CTRL_VKEY vkey)
{
  SDL_Scancode key = m_vkeyMap[vkey];
  return is_key_down(key);
}

TsubasaInputHandler* TsubasaInputHandler::get_instance()
{
  if (s_theTsubasaInputHandler == nullptr){
    s_theTsubasaInputHandler = new TsubasaInputHandler();
  }

  return s_theTsubasaInputHandler;
}

TsubasaInputHandler::TsubasaInputHandler()
{
  m_theInputHandler = InputHandler::get_instance();
  // initialize vkeyMap
  m_vkeyMap[VKEY_RIGHT] = SDL_SCANCODE_L;
  m_vkeyMap[VKEY_UP] = SDL_SCANCODE_I;
  m_vkeyMap[VKEY_LEFT] = SDL_SCANCODE_J;
  m_vkeyMap[VKEY_DOWN] = SDL_SCANCODE_K;
  m_vkeyMap[VKEY_A] = SDL_SCANCODE_D;
  m_vkeyMap[VKEY_B] = SDL_SCANCODE_S;
  m_vkeyMap[VKEY_SELECT] = SDL_SCANCODE_1;
  m_vkeyMap[VKEY_START] = SDL_SCANCODE_2;
}

void TsubasaInputHandler::update()
{
  m_theInputHandler->update();
}

bool TsubasaInputHandler::is_key_down(SDL_Scancode key)
{
  return m_theInputHandler->is_key_down(key);
}
