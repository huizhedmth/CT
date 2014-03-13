/** Texture.cpp
 *
 * Implementation of class Texture
 *
 * by Huizhe Li
 */

# include "Texture.hpp"
# include "SDL_CPP.hpp"
# include "TextureManager.hpp"

# include <string>

using tsubasa::Texture;
using namespace sdl_cpp;
using namespace sdl_game;
using std::string;

string Texture::CLASS = "Texture";

void Texture::update()
{
  // a 'Texture' is static
}

void Texture::draw(SDL_CRenderer &renderer)
{
  TextureManager::get_instance()->draw(m_textureID, renderer,
				     m_x, m_y, m_dw, m_dh);
}

bool Texture::load(FileReader &reader)
{
  SDL_Logger logger;
  static string func = CLASS + "::load";
  char delim = '=';
  func = CLASS + "::load:";
  try{
    // read name
    m_name = reader.next_string(delim);
    // read texture ID
    m_textureID = reader.next_string(delim);
    // read x and y 
    m_x = reader.next_int(delim);
    m_y = reader.next_int(delim);
    m_w = TextureManager::get_instance()->get_width(m_textureID);
    m_h = TextureManager::get_instance()->get_height(m_textureID);
    // read dw and dh
    m_dw = reader.next_int(delim);
    m_dh = reader.next_int(delim);
  }catch(...){
    logger.log(std::cout, func + " unrecognized file format.");
    return false;
  }

  return true;
}

string Texture::to_string()
{
  // stub
  string str = "Texture";
  return str;
}
