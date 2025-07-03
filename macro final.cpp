#include <stdio.h> 
#define DEBUG 1 
#define FEATURE1 
#define FEATURE
int main() { 
#if DEBUG
printf("Debug mode is on.\n"); 
#else 
printf("Debug mode is off.\n");
#endif
#ifdef FEATURE
printf("Feature is enabled.\n"); 
#elif defined(FEATURE1)
printf("Feature1 is defined.\n");
#else 
printf("Feature1 is not defined.\n");
#endif
return 0;
}
