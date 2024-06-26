#include "minishell.h"
int count_args(t_input *tokens)
{
    int count;

    count = 0;
    while(tokens != NULL)
        {
            if(tokens->type == DOLLAR || tokens->type == WORD)
                count++;
            else if(tokens->type == PIPE || tokens->type == GREATER2 ||
                    tokens->type == GREATER ||tokens->type == SMALLER2 ||
                    tokens->type == SMALLER)
                    return(count);
            tokens = tokens->next;
        }
        return(count);
}