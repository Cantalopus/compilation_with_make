#ifdef HAS_STDIO
    #include <stdio.h>
#endif

#ifdef HAS_WINDOWS
    #include <window.h>
#endif

int main(void)
{
    #ifdef HAS_STDIO
        printf("HAS_STDIO = %d\n", HAS_STDIO);
    #endif

    #ifdef HAS_WINDOWS
        printf("Windows API is available.\n");
    #endif

    return 0;
}