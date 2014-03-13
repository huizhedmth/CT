/** Animatables.hpp
 *
 * Declarations for classes that derive from Animatable.
 * These classes are supposed to differ only in update().
 *
 * by Huizhe Li
 */

# ifndef ANIMATABLES_HPP
# define ANIMATABLES_HPP

# include "Animatable.hpp"

namespace tsubasa{
  class FieldBGR;
  class SkyBGR;
}

class tsubasa::FieldBGR : public tsubasa::Animatable{
public:
  virtual void update();
};

class tsubasa::SkyBGR : public tsubasa::Animatable{
public:
  virtual void update();
};

# endif // ANIMATABLES_HPP
