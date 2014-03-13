/** Drawable.hpp
 *
 * Declaration for class Drawable: public class Object
 *
 * Represents a visible object in this game.
 *
 * by Huizhe Li
 */

# ifndef DRAWABLE_HPP
# define DRAWABLE_HPP

# include "SDL_CPP.hpp"
# include <string>


# include "FileReader.hpp"

namespace tsubasa{
  class Drawable;
}

class tsubasa::Drawable{
public:
  virtual ~Drawable();
  virtual bool load(tsubasa::FileReader &reader) = 0;
  virtual void draw(sdl_cpp::SDL_CRenderer &renderer) = 0;
  virtual void update();
  
  /* return a string representation of the object */
  virtual std::string to_string() = 0;
  
  /* return the unique name that identified an object in the program */
  std::string get_name();

protected:

  std::string m_textureID;
  std::string m_name;
};

# endif // DRAWABLE_HPP
