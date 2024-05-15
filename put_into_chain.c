#include "minishell.h"

t_input *create_token(lexer type, char *value)
{
    t_input *token =  (t_input *)malloc(sizeof(t_input));
    if(!token)
        return(NULL);
    token->type = type;
    token->value = value;
    token->next = NULL;
    return(token);
}

void add_token_to_list(t_input **head, lexer type, char *value)
{
    t_input *new_token = create_token(type, value);
    if(*head == NULL)
        *head = new_token;
    else
    {
        t_input *current = *head;
        while(current->next)
        {
            current = current->next;
        }
        current->next = new_token;
    }

}