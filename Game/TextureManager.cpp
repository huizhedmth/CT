/** TextureManager.cpp
 *
 * Implementation for class TextureManager.
 *
 * by Huizhe Li
 * 
 * Reference: "SDL Game Development",  Shaun, R, Mithell
 */

# include "TextureManager.hpp"
# include "SDL_Logger.hpp"
# include <string>
# include <iostream>

using std::string;
using std::map;
using sdl_game::TextureManager;
using sdl_cpp::SDL_CRenderer;
using sdl_cpp::SDL_CTexture;
using sdl_cpp::SDL_Logger;

string TextureManager::CLASS = "TextureManager";
string TextureManager::INDENT = " -- ";

TextureManager* TextureManager::m_theManager = nullptr;

// empty private constructor
TextureManager::TextureManager(){}

TextureManager* TextureManager::get_instance()
{
  if (m_theManager == nullptr){
    m_theManager = new TextureManager();
    return m_theManager;
  }

  return m_theManager;
}

bool TextureManager::load(string filename,
			  const SDL_CRenderer &renderer)
{
  SDL_CTexture* newTexture = new SDL_CTexture();
  SDL_Logger logger;
  static string func = CLASS + "::load";
  
  if (!newTexture->load(filename, renderer)){
    logger.log(std::cerr, INDENT + func);
    delete newTexture;
    return false;
  }

  string id;
  // trim filename to get id
  int index = filename.find_last_of("/");
  int length = filename.find_last_of(".") - index - 1;
  id = filename.substr(index+1, length);
  
  m_textureMap[id] = newTexture;
  //  std::cout << "filename:" + filename + " texture:" << id << " loaded" << std::endl;
  return true;
}

bool TextureManager::draw(string id,
			  SDL_CRenderer &renderer,
			  int x, int y,

			  const int flip, 
			  const SDL_Point* center,
			  const double angle)

{
  // find texture
  static string func = CLASS + "::draw";
  SDL_Logger logger;
  
  if (m_textureMap.count(id) == 0){
    logger.log(std::cerr, func + " texture:" + id + " not loaded.");
    return false;
  }

  // draw texture
  SDL_CTexture* target = m_textureMap[id];
  if (renderer.copyEx(*target, x, y, flip, center, angle) == false){
    logger.log(std::cerr, INDENT + func, true);
    return false;
  }

  return true;
}

bool TextureManager::draw(string id,
			  SDL_CRenderer &renderer,
			  int x, int y, int w, int h,

			  const int flip, 
			  const SDL_Point* center,
			  const double angle)

{
  // find texture
  static string func = CLASS + "::draw";
  SDL_Logger logger;
  
  if (m_textureMap.count(id) == 0){
    logger.log(std::cerr, func + " texture:" + id + " not loaded.");
    return false;
  }

  // draw texture
  SDL_CTexture* target = m_textureMap[id];
  if (renderer.copyEx(*target, 
		      0, 0, target->get_width(), target->get_height(),
		      x, y, w, h,
		      flip, center, angle) == false){
    logger.log(std::cerr, INDENT + func, true);
    return false;
  }

  return true;
}

bool TextureManager::draw_frame(string id,
				SDL_CRenderer &renderer,
				int srcw, int srch,
				int dstx, int dsty,
				int dstw, int dsth,
				int animateType, /* 1 = row, 2 = col */
				int currentFrame,
				int step,

				const int flip, 
				const SDL_Point* center,
				const double angle)

{
  // find texture
  static string func = CLASS + "::drawFrame";
  SDL_Logger logger;
  
  if (m_textureMap.count(id) == 0){
    logger.log(std::cerr, func + " texture not loaded.");
    return false;
  }

  // draw texture
  SDL_CTexture* target = m_textureMap[id];
  int srcx = 0, srcy = 0;
  if (animateType == 1){
    srcx = (int)(currentFrame*step);
  } else {
    srcy = (int)(currentFrame*step);
  }

  if (renderer.copyEx(*target, 
		      srcx, srcy,                 // srcx, srcy
		      srcw, srch,                 // srcw, srch
		      dstx, dsty,                 // dstx, dsty
		      dstw, dsth,                 // dstw, dsth
		      flip, center, angle) == false)
    {
      logger.log(std::cerr, INDENT + func, true);
      return false;
    }

  return true;
}

  
TextureManager::~TextureManager()
{
  // clean up all loaded textures 
  map<string, SDL_CTexture*>::iterator it = m_textureMap.begin();
  while(it != m_textureMap.end()){
    delete it->second;
    it++;
  }

  // clear the map 
  m_textureMap.clear();

}
    
std::map<std::string, sdl_cpp::SDL_CTexture*> TextureManager::get_map()
{
  return m_textureMap;
}

int TextureManager::get_width(string textureID)
{
  return m_textureMap[textureID]->get_width();
}

int TextureManager::get_height(string textureID)
{
  return m_textureMap[textureID]->get_height();
}
