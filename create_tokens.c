#include "minishell.h"

void add_token(t_input **tokens, t_input *new_token)
{
    t_input *current;

    current = *tokens;
    if (!current)
    {
        *tokens = new_token;
        return;
    }
    while (current->next)
        current = current->next;
    current->next = new_token;
}

void free_tokens(t_input *tokens)
{
    t_input *tmp;

    while (tokens)
    {
        tmp = tokens;
        tokens = tokens->next;
        free(tmp->value);
        free(tmp);
    }
}

void print_tokens(t_input *tokens)
{
    while (tokens)
    {
        printf("Type: %d, Value: %s\n", tokens->type, tokens->value);
        tokens = tokens->next;
    }
}
