/** SDL_CTexture.cpp
 *
 * Implementaton for class SDL_CTexture.
 *
 * by Huizhe Li
 */

# include <SDL2/SDL.h>
# include "SDL_CWindow.hpp"
# include "SDL_Logger.hpp"
# include "SDL_CRenderer.hpp"
# include <SDL_image.h>
# include <string>
# include <iostream>

using sdl_cpp::SDL_CTexture;
using sdl_cpp::SDL_Logger;
using sdl_cpp::SDL_CRenderer;
using std::string;

string SDL_CTexture::CLASS = "SDL_CTexture";

SDL_CTexture::SDL_CTexture()
{
  m_texture = nullptr;
  m_w = m_h = 0;
}

SDL_CTexture::~SDL_CTexture()
{
  SDL_DestroyTexture(m_texture);
}

bool SDL_CTexture::load(string filename, 
			const SDL_CRenderer &renderer)
{
  SDL_Logger logger;
  static string func = CLASS + "::load";
  
  // attempt to load image 
  SDL_Surface* surface = IMG_Load(filename.c_str());
  if (surface == nullptr){
    logger.log(std::cerr, func, true);
    return false;
  }

  // image loaded, create texture 
  SDL_Texture* texture = 
    SDL_CreateTextureFromSurface(renderer.get_renderer(), surface);
  SDL_FreeSurface(surface); // free temporary surface
  if (texture == nullptr){
    logger.log(std::cerr, func, true);
    return false;
  }


  // texture created, query attributes
  if (SDL_QueryTexture(texture, 0, 0, &m_w, &m_h) != 0){
    logger.log(std::cerr, func, true);
    return false;
  }
 
  if (m_texture != nullptr){
    SDL_DestroyTexture(m_texture);
  }
  m_texture = texture;
 
  return true;
}

SDL_Texture* SDL_CTexture::get_texture() const
{
  return m_texture;
}

int SDL_CTexture::get_width() const
{
  return m_w;
}

int SDL_CTexture::get_height() const
{
  return m_h;
}  




