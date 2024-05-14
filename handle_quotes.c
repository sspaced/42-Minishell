#include <stdio.h>
#include <stdlib.h>
typedef enum 
{
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    DOLLAR,
    GREATER,
    SMALLER,
    PIPE,
    WORD,

} lexer;

typedef enum
{
    OUTSIDE,
    INSIDE_SINGLE,
    INSIDE_DOUBLE,
} quote_state;


quote_state update_state(char c, quote_state state) 
{
    if (c == '\'') 
    {
        if (state == OUTSIDE) 
        {
            return INSIDE_SINGLE;
        } 
        else if (state == INSIDE_SINGLE) 
        {
            return OUTSIDE;
        }
    } else if (c == '"') 
    {
        if (state == OUTSIDE) 
        {
            return INSIDE_DOUBLE;
        } 
        else if (state == INSIDE_DOUBLE) 
        {
            return OUTSIDE;
        }
    }
    return state;
}

lexer detect_token(char c, quote_state state) 
{
    if (state == OUTSIDE) 
    {
        if (c == '$') return DOLLAR;
        if (c == '>') return GREATER;
        if (c == '<') return SMALLER;
        if (c == '|') return PIPE;
        if (c == '\'') return SINGLE_QUOTE;
        if (c == '"') return DOUBLE_QUOTE;
    }
    return WORD;
}

void tokeniser(char *str) 
{
    int j;
    quote_state state;
    lexer type;

    j = 0;
    state = OUTSIDE;
    while (str[j]) 
    {
        state = update_state(str[j], state);
        type = detect_token(str[j], state);
        if (type != WORD || (type == WORD && state == OUTSIDE)) 
        {
            printf("Token: %d\n", type);
        }
        j++;
    }
}



void    parse_args(int argc, char **argv)
{
    int i;
    i = 1;
    while(i < argc)
    {
        tokeniser(argv[i]);
        i++;
    }
}
int main(int argc, char **argv)
{
    parse_args(argc, argv);
return(0);  
}
