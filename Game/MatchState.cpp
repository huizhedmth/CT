/** MatchState.cpp
 *
 * Implementation for class MatchState.
 *
 * by Huizhe Li
 */

# include "MatchState.hpp"
# include "Drawable.hpp"
# include "Player.hpp"
# include "ObjectManager.hpp"
# include "SDL_CPP.hpp"
# include "FileReader.hpp"
# include <vector>
# include <string>

using tsubasa::MatchState;
using tsubasa::Drawable;
using tsubasa::Player;
using tsubasa::FileReader;
using namespace sdl_cpp;
using namespace sdl_game;
using std::cout;
using std::endl;
using std::vector;
using std::string;

string MatchState::CLASS = "MatchState";
void MatchState::render(SDL_CRenderer &renderer)
{
  for (vector<Drawable*>::iterator it = m_bgrObjects.begin();
       it != m_bgrObjects.end();
       it ++){
    (*it)->draw(renderer);
  }

}

void MatchState::update()
{
  for (vector<Drawable*>::iterator it = m_bgrObjects.begin();
       it != m_bgrObjects.end();
       it ++){
    (*it)->update();
    //(*it)->update();
  }
}

bool MatchState::onEnter()
{
  std::cout << "MatchState::onEnter" << std::endl;
  return true;
}

bool MatchState::onExit()
{
  std::cout << "MatchState::onExit" << std::endl;
  return true;
}

MatchState::~MatchState()
{
}

MatchState::MatchState()
{
  // the following code are for testing use only
  // will be removed later
  
  // load background objects
  ObjectManager* objectManager = ObjectManager::get_instance();
  Drawable* p_object;

  p_object = objectManager->get_object("aud_sky");
  if (p_object != nullptr){
    m_bgrObjects.push_back(p_object);
  } else {
    std::cout << "object does not exist " << endl;
  }

  p_object = objectManager->get_object("field");
  if (p_object != nullptr){
    m_bgrObjects.push_back(p_object);
  } else {
    std::cout << "object does not exist " << endl;
  }

  p_object = objectManager->get_object("mini_field");
  if (p_object != nullptr){
    m_bgrObjects.push_back(p_object);
  } else {
    std::cout << "object does not exist " << endl;
  }

  p_object = objectManager->get_object("state_bar");
  if (p_object != nullptr){
    m_bgrObjects.push_back(p_object);
  } else {
    std::cout << "object does not exist " << endl;
  }
}

bool MatchState::load(string filename)
{
  SDL_Logger logger;
  static string func = CLASS + "::load";
  FileReader reader;
  char delim = '=';

  if (!reader.open(filename)){
    logger.log(std::cout, func + ": failed loading match from file: " + filename);
    return false;
  }
  
  string teamID;
  string teamFilename;

  teamID = reader.next_string(delim);
  teamFilename = "./Config/Team/" + teamID + ".txt";
  if (!m_friendTeam.load(teamFilename)){
    logger.log(std::cout, func + ": failed loading team from file: " + teamFilename);
    return false;
  }

  teamID = reader.next_string(delim);
  teamFilename = "./Config/Team/" + teamID + ".txt";

  if (!m_enemyTeam.load(teamFilename)){
    logger.log(std::cout, func + ": failed loading team from file: " + teamFilename);
    return false;
  }

  m_timeFirstHalf = reader.next_int(delim);
  m_timeSecondHalf = reader.next_int(delim); 

  reader.close();
  return true;
}
