#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>

typedef enum e_lexer
{
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    DOLLAR,
    GREATER,
    GREATER2,
    SMALLER,
    SMALLER2,
    PIPE,
    WORD,
    SEMICOLON,
    AND,
} t_lexer;

typedef struct s_input
{
    t_lexer type;
    char *value;
    struct s_input *next;
} t_input;

void handle_greater(char *input, int *i, t_input **tokens);
void handle_smaller(char *input, int *i, t_input **tokens);
void handle_special_chars(char *input, int *i, t_input **tokens);
void handle_quotes(char *input, int *i, t_input **tokens, char quote_type);
void handle_word(char *input, int *i, t_input **tokens);
void tokenize_input(char *input, t_input **tokens);
void add_token(t_input **tokens, t_input *new_token);
void free_tokens(t_input *tokens);
void print_tokens(t_input *tokens);


#endif
