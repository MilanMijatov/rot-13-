char getlt5(char let)
{
        const char lt5[][10] = { {'0','1','2','3','4','5','6','7','8','9'},
        {'5','6','7','8','9','0','1','2','3','4'} };
        int i;
        for(i = 0; i < 10; i++)
                if(lt5[0][i] == let)
                        return lt5[1][i];
        return 0;
}

char getrot13(char let)
{
        const char lt13[][52] = { {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}, 
                {'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m'} };
        int i;
        for(i = 0; i < 52; i++)
                if(lt13[0][i] == let)
                        return lt13[1][i];
        return 0;
}

char getrot18(char let)
{
        return (getrot13(let) | getlt5(let));
}

char getrot47(char let)
{
        const int lt47[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79};
        return lt47[let];
}

int isrot13(char a)
{
        return isalpha(a);
}

int isrot18(char a)
{
        return (isalpha(a) || isdigit(a));
}

int isrot47(char a)
{
        return (a > 32 && a < 127);
}

char * encrypt(char * text, int (*rcond) (char), char (*getsymbol) (char))
{
        int i;
        for(i = 0; text[i] != '\0'; i++)
                if(rcond(text[i]))
                        text[i] = getsymbol(text[i]);
        return text;
}

char * rot13(char * text)
{
        return encrypt(text, isrot13, getrot13);
}

char * rot18(char * text)
{
        return encrypt(text, isrot18, getrot18);
}

char * rot47(char * text)
{
        return encrypt(text, isrot47, getrot47);
}