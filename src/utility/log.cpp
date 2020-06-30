
#include <utility/log.hpp>

#include <iostream>
#include <string>

// Default logger to print all messages
Log::Level Log::level = Log::debug;

// Map enums to names
const char *LEVEL_NAMES[] = { " [DEBUG]  ", "[MESSAGE] ", "[WARNING] ", " [ERROR]  ", " [FORCE]  " };

// Used to omit log level on inline statements
static bool inl = false;

void Log::set(Level level)
{
    Log::level = level;
}

template <class T>
void Log::print( Level level, T message )
{
    if (level < Log::level)
        return;

    std::cout << ( inl ? "" : LEVEL_NAMES[level] );

    std::cout << message;
    inl = true;
}
template void Log::print(Level, const char * );
template void Log::print(Level, char * );
template void Log::print(Level, std::string );
template void Log::print(Level, float );
template void Log::print(Level, int );

template <class T>
void Log::println( Level level, T message )
{
    if (level < Log::level)
        return;

    std::cout << ( inl ? "" : LEVEL_NAMES[level] );

    std::cout << message << std::endl;
    inl = false;
}
template void Log::println(Level, const char * );
template void Log::println(Level, char * );
template void Log::println(Level, std::string );
template void Log::println(Level, float );
template void Log::println(Level, int );
