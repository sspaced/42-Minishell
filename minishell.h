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
}t_lexer;

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
t_input *create_token(t_lexer type, char *value);
void add_token(t_input **tokens, t_input *new_token);
void free_tokens(t_input *tokens);
char *expand_variable(const char *var);
char *extract_env_name(const char *str);
int is_env_variable(const char *str);
void expand_variables_in_tokens(t_input *tokens);
char *concatenate_values(char *value1, char *value2);
char *extract_double_quoted_value(char *input, int *i);
char *extract_single_quoted_value(char *input, int *i);
char ***tokens_to_array(t_input *tokens);
int count_tokens(t_input *tokens);

#endif