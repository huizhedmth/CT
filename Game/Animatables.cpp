/** Animatables.cpp
 *
 * Implementation.
 *
 * by Huizhe Li
 */

# include "Animatables.hpp"
# include "TsubasaInputHandler.hpp"

using tsubasa::Animatable;
using tsubasa::TsubasaInputHandler;
using tsubasa::FieldBGR;
using tsubasa::SkyBGR;

void FieldBGR::update()
{
  TsubasaInputHandler* inputHandler = 
    TsubasaInputHandler::get_instance();

    if (inputHandler->is_vkey_down(VKEY_RIGHT) ||
	inputHandler->is_vkey_down(VKEY_UP)    ||
	inputHandler->is_vkey_down(VKEY_LEFT) ||
	inputHandler->is_vkey_down(VKEY_DOWN) )
      {
	m_updateCount++;
      }

    if (m_updateCount >= m_newFrame){
      m_updateCount = 0;
      m_currentFrame = (m_currentFrame + 1) % m_frames;
    }

}


void SkyBGR::update()
{

  TsubasaInputHandler* inputHandler = 
    TsubasaInputHandler::get_instance();
  
  int direction = -1;
  if (inputHandler->is_vkey_down(VKEY_RIGHT))
    direction = 1;
  else if (inputHandler->is_vkey_down(VKEY_LEFT))
    direction = 0;
  else if (inputHandler->is_vkey_down(VKEY_UP))
    direction = 1;
  else if (inputHandler->is_vkey_down(VKEY_DOWN))
    direction = 0;

  if (direction == 1){
    m_updateCount ++;
    if (m_updateCount >= m_newFrame){
      int step = m_updateCount / m_newFrame;
      m_updateCount = m_updateCount % m_newFrame;

      // update frame
      m_currentFrame = (m_currentFrame + step) % m_frames;
    }

  } 
  if (direction == 0){
    m_updateCount ++;
    if (m_updateCount >= m_newFrame){
      int step = m_updateCount / m_newFrame;
      m_updateCount = m_updateCount % m_newFrame;

      // update frame
      m_currentFrame -= step;
      if (m_currentFrame < 0){
	m_currentFrame = (-m_currentFrame/m_frames+1)*m_frames
	  + m_currentFrame; 
      }
    }
  }
  
}
