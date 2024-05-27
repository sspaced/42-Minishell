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
    if (input[*i] == '>')
        handle_greater(input, i, tokens);
    else if (input[*i] == '<')
        handle_smaller(input, i, tokens);
    else if (input[*i] == '|')
    {
        add_token(tokens, create_token(PIPE, "|"));
        *i += 1;
    }
    else if (input[*i] == ';')
    {
        add_token(tokens, create_token(SEMICOLON, ";"));
        *i += 1;
    }
    else if (input[*i] == '&')
    {
        if (input[*i + 1] == '&')
        {
            add_token(tokens, create_token(AND, "&&"));
            *i += 2;
        }
        else
            *i += 1;
    }
    else if (input[*i] == '$')
    {
        add_token(tokens, create_token(DOLLAR, "$"));
        *i += 1;
    }
}