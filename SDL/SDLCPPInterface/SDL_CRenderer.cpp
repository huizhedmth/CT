/** SDL_CRenderer.cpp
 *
 * Implementation for class SDL_CRenderer.
 *
 * by Huizhe Li
 */

# include <SDL2/SDL.h>
# include "SDL_CRenderer.hpp"
# include "SDL_Logger.hpp"
# include "SDL_CWindow.hpp"
# include <iostream>
# include <string>

using sdl_cpp::SDL_CRenderer;
using sdl_cpp::SDL_Logger;
using sdl_cpp::SDL_CWindow;

std::string SDL_CRenderer::CLASS = "SDL_CRenderer";

SDL_CRenderer::SDL_CRenderer()
{
  m_renderer = nullptr;
}

SDL_CRenderer::~SDL_CRenderer()
{
  SDL_DestroyRenderer(m_renderer);
}

bool SDL_CRenderer::create(const SDL_CWindow &window, int index, Uint32 flags)
{
  SDL_Logger logger;
  static std::string func = CLASS + "::create";

  SDL_Renderer* renderer = 
    SDL_CreateRenderer(window.get_window(), index, flags);
  if (renderer == nullptr){
    logger.log(std::cerr, func, true);
    return false;
  }

  if (m_renderer != nullptr){
    SDL_DestroyRenderer(m_renderer);
  }
  m_renderer = renderer;
  
  return true;
}

/* set to black/solid by default */
void SDL_CRenderer::set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void SDL_CRenderer::clear()
{
  SDL_RenderClear(m_renderer);
}

void SDL_CRenderer::present()
{
  SDL_RenderPresent(m_renderer);
}

bool SDL_CRenderer::copy(const SDL_CTexture &texture, int x, int y)
{
  SDL_Rect srcRect, dstRect;
  
  srcRect.x = 0; dstRect.x = x;
  srcRect.y = 0; dstRect.y = y;
  srcRect.w = dstRect.w = texture.get_width();
  srcRect.h = dstRect.h = texture.get_height();
  
  return this->copy(texture, srcRect, dstRect);
}

bool SDL_CRenderer::copy(const sdl_cpp::SDL_CTexture &texture,
			 int srcx, int srcy, int srcw, int srch,
			 int dstx, int dsty, int dstw, int dsth)
{
  SDL_Rect srcRect, dstRect;
  
  srcRect.x = srcx;dstRect.x = dstx;
  srcRect.y = srcy;dstRect.y = dsty;
  srcRect.w = srcw;dstRect.w = dstw;
  srcRect.h = srch;dstRect.h = dsth;

  return this->copy(texture, srcRect, dstRect);
}

bool SDL_CRenderer::copy(const sdl_cpp::SDL_CTexture &texture,
			 SDL_Rect &srcRect, SDL_Rect &dstRect)
{
  SDL_Logger logger;
  int rc;
  static std::string func = CLASS + ":copy";

  SDL_Texture* tex = texture.get_texture();
 
  rc = SDL_RenderCopy(m_renderer, tex, &srcRect, &dstRect);
  if (rc != 0){
    logger.log(std::cerr, func, true);
    return false;
  }
  
  return true;
}

bool SDL_CRenderer::copyEx(const SDL_CTexture &texture, int x, int y,

			   int flip,
			   const SDL_Point* center,
			   const double angle)


{
  SDL_Rect srcRect, dstRect;
    
  srcRect.x = 0; dstRect.x = x;
  srcRect.y = 0; dstRect.y = y;
  srcRect.w = dstRect.w = texture.get_width();
  srcRect.h = dstRect.h = texture.get_height();

  return this->copyEx(texture, srcRect, dstRect, flip, center, angle);
}

bool SDL_CRenderer::copyEx(const SDL_CTexture &texture,
			   int srcx, int srcy, int srcw, int srch,
			   int dstx, int dsty, int dstw, int dsth,

			   int flip,
			   const SDL_Point* center,
			   const double angle)

{
  SDL_Rect srcRect, dstRect;
  
  srcRect.x = srcx;dstRect.x = dstx;
  srcRect.y = srcy;dstRect.y = dsty;
  srcRect.w = srcw;dstRect.w = dstw;
  srcRect.h = srch;dstRect.h = dsth;

  return this->copyEx(texture, srcRect, dstRect, flip, center, angle);

}

bool SDL_CRenderer::copyEx(const sdl_cpp::SDL_CTexture &texture,
			   SDL_Rect &srcRect, SDL_Rect &dstRect,

			   int flip,
			   const SDL_Point* center,
			   const double angle)

{
  SDL_Logger logger;
  int rc;
  static std::string func = CLASS + ":copyEx";

  SDL_Texture* tex = texture.get_texture();
  rc = SDL_RenderCopyEx(m_renderer, tex, &srcRect, &dstRect,
			angle, center,
			SDL_RendererFlip(flip));
  if (rc != 0){
    logger.log(std::cerr, func, true);
    return false;
  }
  
  return true;
}

SDL_Renderer* SDL_CRenderer::get_renderer() const
{
  return m_renderer;
}
