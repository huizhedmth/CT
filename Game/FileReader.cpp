/** FileReader.cpp
 *
 * Implementation of class FileReader.
 *
 * by Huizhe Li
 */

# include "FileReader.hpp"
# include "SDL_CPP.hpp"
# include <cstring>
# include <string>
# include <sys/types.h>
# include <dirent.h>

using tsubasa::FileReader;
using std::string;
using std::fstream;
using namespace sdl_cpp;

string FileReader::CLASS = "FileReader";

bool FileReader::open(string filename)
{
  SDL_Logger logger;
  static string func = CLASS + "::open";

  infile.open(filename);
  if (!infile.is_open()){
    logger.log(std::cerr, func + " failed opening file " + filename);
    return false;
  }

  return true;
}

void FileReader::close()
{
  infile.close();
}

int FileReader::next_int(char delim)
{
  string line;

  getline(infile, line, delim);
  getline(infile, line);

  return atoi(line.c_str());
}

float FileReader::next_float(char delim)
{
  string line;

  getline(infile, line, delim);
  getline(infile, line);

  return atof(line.c_str());
}

int FileReader::next_int_array(int* arr, char delim)
{
  char* str;
  char* cstr;
  string line;

  getline(infile, line, delim);
  getline(infile, line);
  cstr = new char[line.length() + 1];
  std::strcpy(cstr, line.c_str());

  str = std::strtok(cstr, ", ");
  int cnt = 0;
  while(str != nullptr){
    *(arr+cnt) = atoi(str);
    cnt++;
    str = std::strtok(nullptr, ", ");
  }
  delete cstr;

  return cnt;
}

string FileReader::next_string(char delim)
{
  string line;
  getline(infile, line, delim);
  getline(infile, line);
  return line;
}

bool FileReader::readdir(string dir, std::vector<string> &filenames)
{
  DIR *dp;
  struct dirent *dirp;
  SDL_Logger logger;
  static string func = CLASS + "::readdir";
  if((dp  = ::opendir(dir.c_str())) == NULL) {
    logger.log(std::cout, func + ": failed opening " + dir);
    return false;
  }

  while ((dirp = ::readdir(dp)) != NULL) {
    string s = (string)(dirp->d_name);
    if (s.compare(".") != 0 && s.compare("..") != 0 && s[s.length()-1] != '~'){
      s = dir + s;
      filenames.push_back(s);
    }
  }
  closedir(dp);
  return true;
}
