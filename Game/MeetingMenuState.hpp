/** MeetingMenuState.hpp
 *
 * Declaration for class MeetingMenuState.
 *
 * Main menu during pre-match meeting
 *
 * by Huizhe Li
 */

# ifndef MEETINGMENUSTATE_HPP
# define MEETINGMENUSTATE_HPP

# include "GameState.hpp"
# include "SDL_CPP.hpp"

namespace tsubasa{
  class MeetingMenuState;
}

class tsubasa::MeetingMenuState : public sdl_game::GameState{
public:
  ~MeetingMenuState();
  virtual void render(sdl_cpp::SDL_CRenderer &renderer);
  virtual void update();
  virtual bool onEnter();
  virtual bool onExit();
};

# endif // MEETINGMENUSTATE_HPP
