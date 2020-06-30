
#pragma once

class Log
{
public:
    enum Level { debug=0, message=1, warning=2, error=3, force=4 };

private:
    static Level level;

public:
    /** Set minimum level needed to print to console */
    static void set(Level level);

    /** Print message to console depending on severity level */
    template <class T>
    static void print(Level level, T message);

    /** Print message and newline to console depending on severity level */
    template <class T>
    static void println(Level level, T message);

    /** Print warning if given anything other than 0 */
    static inline void check(int result, const char *op)
    {
        if (result != 0)
        {
            print( warning, "Operation failed: " );
            println( warning, op );
        }
    }
};
