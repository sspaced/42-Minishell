#include <stdio.h>
#include <stdlib.h>
typedef enum {
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    DOLLAR,
    GREATER,
    SMALLER,
    PIPE,
    ASK,
    WORD,

} Lexer;

char    *args_to_string(int argc, char **argv, int size)
{
    int i;
    int j;
    int k;

    i = 1;
    k = 0;
    char *input;
    input = malloc(sizeof(char) * (size + argc) + 1 );
    while(i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
            input[k] = argv[i][j];
            j++;
            k++;
        }
        if(i < argc - 1)
            input[k++] = ' ';
        i++;
    }
    input[k] = '\0';
    return(input);
}
int count_args(int argc, char **input)
{
    int j;
    int i;
    int k;

    k = 0;
    i = 1;
    while(i < argc)
    {
        j = 0;
        while(input[i][j])
            {
                k++;
                j++;
            }
        i++;
    }
return(k);
}
int main(int argc, char **argv)
{
    int i;
    i = count_args(argc, argv);
    char *input = args_to_string(argc, argv, i);
    printf("%s", input);
return(0);  
}
