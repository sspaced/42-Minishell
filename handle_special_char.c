#include "minishell.h"

void handle_greater(char *input, int *i, t_input **tokens)
{
    if (input[*i + 1] == '>')
    {
        add_token(tokens, create_token(GREATER2, ">>"));
        *i += 2;
    }
    else
    {
        add_token(tokens, create_token(GREATER, ">"));
        *i += 1;
    }
}

void handle_smaller(char *input, int *i, t_input **tokens)
{
    if (input[*i + 1] == '<')
    {
        add_token(tokens, create_token(SMALLER2, "<<"));
        *i += 2;
    }
    else
    {
        add_token(tokens, create_token(SMALLER, "<"));
        *i += 1;
    }
}

void handle_special_chars(char *input, int *i, t_input **tokens)
{
    char special_char[3] = {0, 0, 0};
    special_char[0] = input[*i];
    if ((input[*i] == '>' && input[*i + 1] == '>') || (input[*i] == '<' && input[*i + 1] == '<'))
    {
        special_char[1] = input[*i + 1];
        (*i)++;
    }
    (*i)++;
    t_lexer type = (special_char[0] == '|') ? PIPE : (special_char[0] == '>') ? (special_char[1] == '>') ? GREATER2 : GREATER : (special_char[1] == '<') ? SMALLER2 : SMALLER;
    t_input *token = create_token(type, special_char);
    add_token(tokens, token);
}
