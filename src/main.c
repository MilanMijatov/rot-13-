#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc = 1)
    {
        printf("Expected 1 or more arguments\nProper usage %s \"text here\"\nAlternatively %s text here"
                    , argv[0], argv[0]);
        return 0;
    }

    return 0;
}