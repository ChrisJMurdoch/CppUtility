
#include <utility/io.hpp>

#include <fstream>

std::vector<std::string> split( std::string line, char d1 ) { return split(line, d1, d1); }
std::vector<std::string> split( std::string line, char d1, char d2 )
{
    // Get character array
    const char *array = line.c_str();

    // Collect delimited words in line
    std::vector<std::string> words;

    // Iterate through characters
    int i = 0;
    char c = array[i++];
    while ( true )
    {
        std::vector<char> word;

        // Build up word
        while ( c != d1 && c != d2 && c != '\0' )
        {
            word.push_back(c);
            c = array[i++];
        }

        // End string with null terminator
        word.push_back('\0');

        // Add word to vector if not just null terminator
        if ( word.size() > 1 )
            words.push_back( std::string( &word[0] ) );

        // Escape if end of string
        if ( c == '\0' )
            break;

        c = array[i++];
    }

    return words;
}

std::map<std::string, std::string> readKVAL(const char *filename)
{
    // Open file
    std::ifstream file (filename);
    if ( !file.is_open() )
        throw "Error opening file";
    
    // Parse file into map
    std::string line;
    static std::map<std::string, std::string> map;
    while ( getline (file, line) )
    {
        try
        {
            std::vector<std::string> kv = split( line, ':' );
            map[ kv[0] ] = kv[1];
        }
        catch ( char const* e ) {} // Ignore empty or invalid lines
    }
    file.close();

    return map;
}

std::vector<float> readVDAT(const char *filename)
{
    // Open file
    std::ifstream file (filename);
    if ( !file.is_open() )
        throw "Error opening file";
    
    // Parse file into map
    std::string line;
    std::vector<float> floats;
    while ( getline (file, line) )
    {
        // Skip comments and empty lines
        if ( line.size() == 0 || line.at(0) == '/' )
            continue;

        std::vector<std::string> words = split( line, ',', ' ' );
        for (std::string s : words)
        {
            floats.push_back( stof( s ) );
        }
    }
    file.close();

    return floats;
}
