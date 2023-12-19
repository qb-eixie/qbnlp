#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::string filename = "word_list_MIT.txt";
  
  std::vector<std::string> lines;
  std::ifstream file(filename);
  std::ofstream output_file("words_in_list.txt");

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      lines.push_back(line);
    }
  } 
  else {
    std::cerr << "Error opening file: " << filename << std::endl;
    return 1;
  }

  if(output_file.is_open()) {
    for(const auto& line : lines) {
       output_file << '\'' << line << '\'' << ',';
    }
  }
  else {
    std::cerr << "Error opening file: " << filename << std::endl;
    return 1;
  }

  output_file.close();
  file.close();

  return 0;
}
