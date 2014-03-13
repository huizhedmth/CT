/** FBGame.hpp
 *
 * Declaration for class FBGame.
 * Represents the Tsubasa Game.
 *
 * by Huizhe Li
 */

# ifndef FBGAME_HPP
# define FBGAME_HPP

# include "SDL_CPP.hpp"
# include "ObjectManager.hpp"
# include "TextureManager.hpp"
# include <string>
# include <vector>
# include "StateMachine.hpp"
# include "MatchState.hpp"
# include "MeetingMenuState.hpp"
# include "TsubasaInputHandler.hpp"

namespace tsubasa{
  class FBGame;
}

class tsubasa::FBGame{
public:
  FBGame();

  /* init SDL, the window, and the renderer */
  bool init(std::string title, int x, int y, int w, int h, Uint32 flags);
  /* load all resources available */
  bool load_resource();

  /* game engine */
  void handle_events();
  void update();
  void render();

  /* quit SDL */
  void quit();

  static std::string CLASS;

  void loading_check();
  bool is_running();
  bool start();
private:
  sdl_cpp::SDL_Manager* m_SDLManager;

  sdl_cpp::SDL_CWindow m_window;
  sdl_cpp::SDL_CRenderer m_renderer;
  
  bool m_isRunning;

  std::vector<tsubasa::Drawable*> m_matchObj;

  enum GameState{
    GAME_STATE_MATCH,
    GAME_STATE_MEETING 
  };

  GameState m_currentState;
  sdl_game::StateMachine m_stateMachine;

  sdl_game::TextureManager* m_textureManager;
  tsubasa::ObjectManager* m_objectManager;
  tsubasa::TsubasaInputHandler* m_inputHandler;
  
};

# endif // FBGAME_HPP  
