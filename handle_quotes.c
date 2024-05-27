#include "minishell.h"

void handle_quotes(char *input, int *i, t_input **tokens, char quote_type)
{
    int start = ++(*i);
    while (input[*i] && input[*i] != quote_type)
    {
        (*i)++;
    }
    if (input[*i] == quote_type)
    {
        char *word = strndup(&input[start], *i - start)
        add_token(tokens, create_token(WORD, word));
        free(word);
        (*i)++;
    }
}