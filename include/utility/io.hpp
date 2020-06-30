
#pragma once

#include <vector>
#include <string>
#include <map>

/** Split string into string vector with delimiter */
std::vector<std::string> split( std::string line, char d1 );

/** Split string into string vector with 2 delimiters */
std::vector<std::string> split( std::string line, char d1, char d2 );

/** Read key-value file into a hashmap */
std::map<std::string, std::string> readKVAL(const char *filename);

/** Read vertex data file into float vector */
std::vector<float> readVDAT(const char *filename);
