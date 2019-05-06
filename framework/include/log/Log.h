
#include <stdio.h>

#define DEBUG 1
#ifdef DEBUG
    #define Log(...)printf(__VA_ARGS__);
#else
    #define Log(...)
#endif 
