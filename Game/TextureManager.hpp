/** TextureManager.hpp
 *
 * Declaration for singleton class TextureManager.
 * TextureManager allows easy access to all textures available via
 * their unique id represented by a string.
 *
 * by Huizhe Li
 * 
 * Reference: "SDL Game Development",  Shaun, R, Mithell
 */

# ifndef TEXTUREMANAGER_HPP
# define TEXTUREMANAGER_HPP

# include <string>
# include <map>
# include <SDL2/SDL.h>
# include "SDL_CRenderer.hpp"

namespace sdl_game{
  class TextureManager;
}

class sdl_game::TextureManager{
public:
  static TextureManager* get_instance();
  
  /* release all textures */
  ~TextureManager();

  /* load a texture from file */
  bool load(std::string filename, 
	    const sdl_cpp::SDL_CRenderer &renderer);/* specified renderer*/

  /* draw specified texture using renderer */
  bool draw(std::string id, /* id of texture to be drawn */
	    sdl_cpp::SDL_CRenderer &renderer, /* associated renderer, i.e window */
	    int x, int y,   /* destination */

	    /* extension params */
	    const int flip = SDL_FLIP_NONE,
	    const SDL_Point* center = nullptr,
	    const double angle = 0
	    );

  bool draw(std::string id, /* id of texture to be drawn */
	    sdl_cpp::SDL_CRenderer &renderer, /* associated renderer, i.e window */
	    int x, int y,   /* destination */
	    int w, int h,   /* appeared size */
	    /* extension params */
	    const int flip = SDL_FLIP_NONE,
	    const SDL_Point* center = nullptr,
	    const double angle = 0
	    );

  /* draw specified texture at specified frame */
  bool draw_frame(std::string id,
		  sdl_cpp::SDL_CRenderer &renderer,
		  int srcw, int srch,
		  int dstx, int dsty,
		  int dstw, int dsth,
		  int animateType,
		  int currentFrame,
		  int step, /* number of pixels as interval */

		  const int flip = SDL_FLIP_NONE,
		  const SDL_Point* center = nullptr,
		  const double angle = 0
		  );

  static std::string CLASS;
  /* return a copy of internal map */
  std::map <std::string, sdl_cpp::SDL_CTexture*> get_map();
  int get_width(std::string textureID);/* get width of specified texture*/
  int get_height(std::string textureID);/* get width of specified texture*/
protected:
  /* internal map that stores pointers to loaded SDL_STexture objects */
  std::map <std::string, sdl_cpp::SDL_CTexture*> m_textureMap; 
  static std::string INDENT;

private:
  /* hide constructor */
  TextureManager();
  static TextureManager* m_theManager;
};

# endif // TEXTUREMANAGER_HPP
