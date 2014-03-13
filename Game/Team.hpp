/** Team.hpp
 *
 * Declaration for class Team.
 *
 * Represents a football team consisting of existing Player's.
 *
 * by Huizhe Li
 */

# ifndef TEAM_HPP
# define TEAM_HPP

# include <map>
# include <string>
# include "Player.hpp"

namespace tsubasa{
  class Team;
}

class tsubasa::Team{
public:
  bool load(std::string filename);

  static std::string CLASS;
private:
  /* maps from number to Player */
  std::map<int, Player*> m_members;
};

# endif // TEAM_HPP
