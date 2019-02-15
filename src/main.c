#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "rot.h"

void error(char * msg)
{
        fprintf(stderr, "Error: %s\n", msg);
        exit(EXIT_FAILURE);
}

char *(*return_rot(int argc, char *argv[])) (char*)
{
        int i;
        char *(*rot) (char*) = NULL;
        for(i = 0; i < argc; i++)
        {
                if(*argv[i] == '-' && !rot)
                {
                        if(*(argv[i] + 1) == 'l' && !*(argv[i] + 2))
                                rot = rot13;
                        else if(*(argv[i] + 1) == 'a' && !*(argv[i] + 2))
                                rot = rot47;
                }
                else if(*argv[i] == '-' && rot)
                        error("Multiple \'-\' parameters detected");
        }
        if(!rot)
                rot = rot18;
        return rot;
}

int main(int argc, char *argv[])
{
        int i;
        char *(*rot) (char*);
        if(argc == 1)
        {
                printf("Expected 1 or more arguments\nProper usage %s \"text here\"\nAlternatively %s text here"
                        , argv[0], argv[0]);
                return 0;
        }
        else if (argc == 2)
        {
                printf("%s\n",rot18(argv[1]));
        }
        else if (argc > 2)
        {
                rot = return_rot(argc - 1, argv + 1);

                for(i = 1; i < argc; i++)
                {
                        if(*argv[i] == '-')
                                continue;
                        printf("%s ", rot(argv[i]));
                }
                printf("\n");
        }

        return 0;
}