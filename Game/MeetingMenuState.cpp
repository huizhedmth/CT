/** MeetingMenuState.cpp
 *
 * Implementation for class MeetingMenuState.
 *
 * by Huizhe Li
 */

# include "MeetingMenuState.hpp"
# include "SDL_CPP.hpp"

using tsubasa::MeetingMenuState;
using namespace sdl_cpp;
using std::cout;
using std::endl;

void MeetingMenuState::render(SDL_CRenderer &renderer)
{
  //  cout << "MeetingMenuState::render()" << endl;
}

void MeetingMenuState::update()
{
  //  cout << "MeetingMenuState::update()" << endl;
}

bool MeetingMenuState::onEnter()
{
  cout << "MeetingMenuState::onEnter()" << endl;
  return true;
}

bool MeetingMenuState::onExit()
{
  cout << "MeetingMenuState::onExit()" << endl;
  return true;
}

MeetingMenuState::~MeetingMenuState()
{
}



