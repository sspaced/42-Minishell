#include "../headers/minishell.h"
void handle_word(char *input, int *i, t_input **tokens)
{
    int start;

    start = *i;
    while (input[*i] && !isspace(input[*i]) && input[*i] != '>' && input[*i] != '<' && input[*i] != '|')
    {
        if (input[*i] == '$')
        {
            (*i)++;
            while (isalnum(input[*i]) || input[*i] == '_')
                (*i)++;
        }
        else
        {
            (*i)++;
        }
    }
    char *value = strndup(input + start, *i - start);
    t_input *token = create_token(WORD, value);
    add_token(tokens, token);
    free(value);
}

void tokenize_input(char *input, t_input **tokens)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (isspace(input[i]))
            i++;
        else if (input[i] == '\'' || input[i] == '"')
            handle_quotes(input, &i, tokens, input[i]);
        else if (input[i] == '>' || input[i] == '<' || input[i] == '|')
            handle_special_chars(input, &i, tokens);
        else
            handle_word(input, &i, tokens);
    }
}
