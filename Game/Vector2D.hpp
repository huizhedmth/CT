/** Vector2D.hpp
 *
 * Declaration for class Vector2D.
 *
 * Represents a 2-D vector instance.
 *
 * by Huizhe Li.
 */

# ifndef VECTOR2D_HPP
# define VECTOR2D_HPP

namespace sdl_game{
  class Vector2D;
}

class sdl_game::Vector2D{
public:
  Vector2D(int x, int y);

  int get_x();
  int get_y();
  void set_x(int x);
  void set_y(int y);
protected:
  int m_x;
  int m_y;
  
};

# endif // VECTOR2D_HPP
