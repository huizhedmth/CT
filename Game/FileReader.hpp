/** FileReader.hpp
 *
 * Declaration for class FileReader.
 *
 * Assist reading a value (values) from file.
 *
 * by Huizhe Li
 */

# ifndef FILEREADER_HPP
# define FILEREADER_HPP

# include <string>
# include <fstream>
# include <vector>

namespace tsubasa{
  class FileReader;
}

class tsubasa::FileReader{
public:
  bool open(std::string filename);
  void close();

  int next_int(char delim);
  float next_float(char delim);
  /* read integers into 'arr', return number of integers read */
  int next_int_array(int* arr, char delim); 
  
  bool readdir(std::string dir, std::vector<std::string> &filenames);
  std::string next_string(char delim);
  static std::string CLASS;

private:
  std::ifstream infile;
};
# endif
