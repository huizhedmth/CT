/** Team.cpp
 *
 * Implementation for class Team.
 *
 * by Huizhe Li
 */

# include "Team.hpp"
# include <string>
# include "SDL_CPP.hpp"
# include "FileReader.hpp"
# include "ObjectManager.hpp"

using namespace sdl_cpp;
using tsubasa::FileReader;
using tsubasa::Team;
using tsubasa::ObjectManager;
using std::string;

string Team::CLASS = "Team";

bool Team::load(string filename)
{
  SDL_Logger logger;
  FileReader reader;
  static string func = CLASS + "::load";
  char delim = '=';

  if (!reader.open(filename)){
    logger.log(std::cout, func + ": failed loading team from file: " + filename);
    return false;
  }
  

  string playerName;
  ObjectManager* objectManager = ObjectManager::get_instance();
  Player* player;

  for (int number = 0;;number++){
    try{
      // read players from current number, by default
      playerName = reader.next_string(delim);
      if (playerName.compare("END") == 0)
	break;
      player = (Player*)objectManager->get_object(playerName);
      m_members[number] = player;
      number++;
    
    }catch(...){
      logger.log(std::cout, func + "unrecognized file format");
      break;
    }
  }

  reader.close();
  return true;
    
}
