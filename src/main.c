#include <stdio.h>
#include <ctype.h>

char getletter(char let)
{
        const char lt13[][52] = { {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}, 
                {'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m'} };
        int i;
        for(i = 0; i < 52; i++)
                if(lt13[0][i] == let)
                        return lt13[1][i];
}

char * rot13(char * text)
{
int i;
        for(i = 0; text[i] != '\0'; i++)
        {
                if(isalpha(text[i]))
                text[i] = getletter(text[i]);
        }
        return text;
}

int main(int argc, char *argv[])
{
        int i;
        if(argc == 1)
        {
                printf("Expected 1 or more arguments\nProper usage %s \"text here\"\nAlternatively %s text here"
                        , argv[0], argv[0]);
                return 0;
        }
        else if (argc == 2)
        {
                printf("%s\n",rot13(argv[1]));
        }
        else if (argc > 2)
        {
                for(i = 1; i < argc; i++)
                {
                        printf("%s ",rot13(argv[i]));
                }
                printf("\n");
        }

        return 0;
}