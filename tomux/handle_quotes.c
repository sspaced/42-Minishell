
#include "../headers/minishell.h"

char *extract_single_quoted_value(char *input, int *i)
{
    int start = ++(*i);
    char *value;
    while (input[*i] && input[*i] != '\'')
        (*i)++;
    value = strndup(input + start, *i - start);
    (*i)++;
    return value;
}

void handle_env_var_in_quotes(char *input, int *i)
{
    (*i)++;
    while (isalnum(input[*i]) || input[*i] == '_')
        (*i)++;
}

char *extract_double_quoted_value(char *input, int *i)
{
    int start;

    start = ++(*i);
    while (input[*i] && input[*i] != '"')
    {
        if (input[*i] == '$')
        {
            handle_env_var_in_quotes(input, i);
        }
        else
            (*i)++;
    }
    char *value = strndup(input + start, *i - start);
    (*i)++;
    return (value);
}

char *concatenate_values(char *value1, char *value2)
{
    char *new_value;

    new_value = malloc(strlen(value1) + strlen(value2) + 1);
    if (!new_value)
        return NULL;
    strcpy(new_value, value1);
    strcat(new_value, value2);
    return new_value;
}

void handle_quotes(char *input, int *i, t_input **tokens, char quote_type)
{
    char *value;
    t_input *token;

    if (quote_type == '\'')
        value = extract_single_quoted_value(input, i);
    else
        value = extract_double_quoted_value(input, i);

    while (input[*i] == '"' || input[*i] == '\'')
    {
        char next_quote_type;
        next_quote_type = input[*i];
        char *next_value = (next_quote_type == '\'') ?
                            extract_single_quoted_value(input, i) :
                            extract_double_quoted_value(input, i);
        char *new_value;
        new_value = concatenate_values(value, next_value);
        free(value);
        free(next_value);
        value = new_value;
    }
    
    token = create_token(WORD, value);
    add_token(tokens, token);
    free(value);
}