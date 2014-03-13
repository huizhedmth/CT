/** MatchState.hpp
 *
 * Declaration for class MatchState.
 *
 * State where a football match is going on
 *
 * by Huizhe Li
 */

# ifndef MATCHSTATE_HPP
# define MATCHSTATE_HPP

# include "GameState.hpp"
# include "SDL_CPP.hpp"
# include "Drawable.hpp"
# include "Player.hpp"
# include "Team.hpp"
# include <map>
# include <vector>
# include <string>

namespace tsubasa{
  class MatchState;
}

class tsubasa::MatchState : public sdl_game::GameState{
public:
  ~MatchState();
  MatchState();

  virtual void render(sdl_cpp::SDL_CRenderer &renderer);
  virtual void update();
  virtual bool onEnter();
  virtual bool onExit();
  /* load a match from file */
  virtual bool load(std::string filename);
  static std::string CLASS;

private:
  std::vector<tsubasa::Drawable*> m_bgrObjects;

  tsubasa::Team m_friendTeam;
  tsubasa::Team m_enemyTeam;

  int m_timeFirstHalf;
  int m_timeSecondHalf;
};

# endif // MATCHSTATE_HPP
