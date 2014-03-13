/** Field.hpp
 *
 * Declaration for class Field.
 *
 * Represents the field in a FBGame.
 *
 * by Huizhe Li.
 */

# ifndef FIELD_HPP
# define FIELD_HPP

# include <map>
# include "Vector2D.hpp"

namespace tsubasa{
  class Field;
}

class tsubasa::Field{
public:
  Field(int w, int h);

private:
  /* size of a field */
  int m_width;
  int m_height;

  /* maps from number to vector2D */
  std::map<int, sdl_game::Vector2D> m_friendPositions;
  std::map<int, sdl_game::Vector2D> m_enemyPositions;
  
  Vector2D m_ballPosition;
  
};
# endif // FIELD_HPP
