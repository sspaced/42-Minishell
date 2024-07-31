#include "minishell.h"

int is_same_string(char *input, char *builtin)
{
    int i;
    int j;

    j = 0;
    i = 0;

    while(input[i]) 
        i++;
    while (builtin[j])
        j++;
    if(i != j)
        return(0);
    i = 0;
    while(input[i] && builtin[i])
    {
        if(input[i] != builtin[i])
            return(0);
        i++;
    }
    return(1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

char **create_builtins_array(void)
{
    char **builtins_array;
    builtins_array = malloc(sizeof(char *) * 8);

    builtins_array[0] = "echo";
    builtins_array[1] = "cd";
    builtins_array[2] = "pwd";
    builtins_array[3] = "export";
    builtins_array[4] = "unset";
    builtins_array[5] = "env";
    builtins_array[6] = "exit";
    builtins_array[7] =  NULL;
    return(builtins_array);
}

int is_builtin(t_input *tokens)
{ 
    int i;

    i = 0;
    char **builtins_array = create_builtins_array();
    while(tokens)
    {
            i = 0;
            while(builtins_array[i])
            {
            if((is_same_string(tokens->value, builtins_array[i])))
                {   
                    add_token(&tokens, create_token(BUILTIN, tokens->value));
                }
                i++;
            }
            tokens = tokens -> next;
        }
    return(0);
}

