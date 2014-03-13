/** Vector2D.hpp
 *
 * Implementation of class Vector2D.
 *
 * by Huizhe Li.
 */

# include "Vector2D.hpp"

using sdl_game::Vector2D;

Vector2D::Vector2D(int x, int y):m_x(x), m_y(y){}

int Vector2D::get_x()
{
  return m_x;
}

int Vector2D::get_y()
{
  return m_y;
}

void Vector2D::set_x(int x)
{
  m_x = x;
}

void Vector2D::set_y(int y)
{
  m_y = y;
}


  
