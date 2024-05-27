#include "minishell.h"

void handle_word(char *input, int *i, t_input **tokens)
{
    int start = *i;
    while (input[*i] && !isspace(input[*i]) && input[*i] != '>' &&
           input[*i] != '<' && input[*i] != '|' && input[*i] != ';' &&
           input[*i] != '&' && input[*i] != '$')
    {
        (*i)++;
    }
    char *word = strndup(&input[start], *i - start);
    add_token(tokens, create_token(WORD, word));
    free(word);
}

void tokenize_input(char *input, t_input **tokens)
{
    int i = 0;
    while (input[i])
    {
        if (isspace(input[i]))
        {
            i++;
            continue;
        }
        if (input[i] == '\'' || input[i] == '"')
        {
            handle_quotes(input, &i, tokens, input[i]);
        }
        else
        {
            handle_special_chars(input, &i, tokens);
            if (input[i] && !isspace(input[i]) && input[i] != '>' &&
                input[i] != '<' && input[i] != '|' && input[i] != ';' &&
                input[i] != '&' && input[i] != '$')
            {
                handle_word(input, &i, tokens);
            }
        }
    }
}

int main(void)
{
    char *input;
    t_input *tokens;

    tokens = NULL;
    while ((input = readline("minishell> ")) != NULL)
    {
        tokenize_input(input, &tokens);
        print_tokens(tokens);
        free_tokens(tokens);
        tokens = NULL;
        free(input);
    }
    return (0);
}