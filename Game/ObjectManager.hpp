/** ObjectManager.hpp
 *
 * Declaration for class ObjectManager.
 *
 * Stores all Object instances used in this game, 
 * similar with TextureManager
 * 
 * by Huizhe Li
 */

# ifndef OBJECTMANAGER_HPP
# define OBJECTMANAGER_HPP

# include <string>
# include <map>
# include "Drawable.hpp"
# include "Player.hpp"

namespace tsubasa{
  class ObjectManager;
}

class tsubasa::ObjectManager{
public:
  static ObjectManager* get_instance();

  /* release all objects */
  ~ObjectManager();

  /* inflate an object from reading given file */
  bool load_object(std::string filename);
  
  /* return look-up result for an object */
  tsubasa::Drawable* get_object(std::string name);

  /* return a copy of internal map */
  std::map <std::string ,tsubasa::Drawable*> get_map();

  static std::string CLASS;
protected:
  std::map <std::string, tsubasa::Drawable*> m_objectMap;

private:
  /* hide constructor */
  ObjectManager();
  static ObjectManager* m_theManager;

  /* dispatch a FileReader to correct loader */
  tsubasa::Drawable* 
  load_object_by_className(std::string className,
			   tsubasa::FileReader &reader);

};

# endif // OBJECTANAGER_HPP
		   
