#include "minishell.h"

t_input	*create_token(t_lexer type, char *value)
{
	t_input	*token;

	token = (t_input *)malloc(sizeof(t_input));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = strdup(value);
	token->next = NULL;
	return (token);
}

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
