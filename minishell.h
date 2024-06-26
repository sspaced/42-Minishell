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
} t_lexer;

typedef enum e_node_type
{
    NODE_COMMAND,
    NODE_PIPE,
    NODE_REDIRECTION_IN,
    NODE_REDIRECTION_OUT,
    NODE_REDIRECTION_APPEND,
    NODE_HEREDOC
} t_node_type;

typedef struct s_ast_node
{
    t_node_type type;
    char **command;
    struct s_ast_node *left;
    struct s_ast_node *right;
} t_ast_node;


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
t_input	*create_token(t_lexer type, char *value);
void add_token(t_input **tokens, t_input *new_token);
void free_tokens(t_input *tokens);
int count_args(t_input *tokens);
t_ast_node *create_commande_node(char **command);
t_ast_node *create_pipe_node(t_ast_node *left, t_ast_node *right);
t_ast_node *create_redirection_node(t_node_type type, t_ast_node *left, t_ast_node *right);
char *expand_variable(const char *var);
t_ast_node	*parse_command(t_input **tokens);
t_ast_node *parse(t_input *tokens);
t_ast_node *parse_redirection(t_input **tokens);
void free_stock_args(char **stock_args, int i);
void free_command_node(t_ast_node *node);
void free_ast_node(t_ast_node *node);
t_ast_node *tokenize_and_parse(char *input);
t_ast_node *parse_pipeline(t_input **tokens);
char	*ft_strdup(const char *str);
char *extract_env_name(const char *str);
int is_env_variable(const char *str);
t_node_type get_redirection_type(t_lexer token);
int is_redirection(t_lexer type);
char *concatenate_values(char *value1, char *value2);
char *extract_double_quoted_value(char *input, int *i);
char *extract_single_quoted_value(char *input, int *i);


#endif
