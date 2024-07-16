#include "minishell.h"

int count_tokens(t_input *tokens)
{
    int i = 1;
    if(!tokens)
    {
        return(0);
    }
    while(tokens->next)
    {
        (*tokens) = *tokens->next;
        i++;
    }
    //printf("%d", i);
    return(i);
}

char ***allocates_tokens_array(int size)
{
    int i;
    char ***tokens_array;
    //char **type_and_value;

    i = 0;
    tokens_array = (char ***)malloc(sizeof (char **) * size );
    if(!tokens_array)
    {
        return(NULL);
    }
    while(i < size)
    {
        tokens_array[i] = malloc(sizeof (char *) * 2);
        if(!tokens_array[i])
        {
            return(NULL);
        }
        i++;
        
    }
    printf("%d \n", i);

    return(tokens_array);
}

/*char *tokens_to_string(t_lexer *type)
{

}*/
/**
void fill_array(char ***array, t_input tokens)
{
    while(tokens->next)
    {

    }
}*/

char ***tokens_to_array(t_input *tokens)
{
    int i;
    char ***tokens_array; 

    i = count_tokens(tokens);
    tokens_array = allocates_tokens_array(i);

    return(tokens_array);
}