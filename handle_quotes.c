#include "minishell.h"
char *extract_single_quoted_value(char *input, int *i)
{
    int start = ++(*i);
    while (input[*i] && input[*i] != '\'')
        (*i)++;
    char *value = strndup(input + start, *i - start);
    (*i)++;  // Avancer après le guillemet de fermeture
    return value;
}

char *extract_double_quoted_value(char *input, int *i)
{
    int start = ++(*i);
    while (input[*i] && input[*i] != '"')
    {
        if (input[*i] == '$')
        {
            (*i)++;
            while (isalnum(input[*i]) || input[*i] == '_')
                (*i)++;
        }
        else
            (*i)++;
    }
    char *value = strndup(input + start, *i - start);
    (*i)++;  // Avancer après le guillemet de fermeture
    return value;
}

char *concatenate_values(char *value1, char *value2)
{
    char *new_value = malloc(strlen(value1) + strlen(value2) + 1);
    if (!new_value)
        return NULL;
    strcpy(new_value, value1);
    strcat(new_value, value2);
    return new_value;
}

void handle_quotes(char *input, int *i, t_input **tokens, char quote_type)
{
    char *value;
    if (quote_type == '\'')
        value = extract_single_quoted_value(input, i);
    else
        value = extract_double_quoted_value(input, i);
    while (input[*i] == '"' || input[*i] == '\'')
    {
        char next_quote_type = input[*i];
        char *next_value = (next_quote_type == '\'') ?
                            extract_single_quoted_value(input, i) :
                            extract_double_quoted_value(input, i);
        char *new_value = concatenate_values(value, next_value);
        free(value);
        free(next_value);
        value = new_value;
    }
    t_input *token = create_token(WORD, value);
    add_token(tokens, token);
    free(value);
}



