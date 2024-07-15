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
void expand_variables_in_tokens(t_input *tokens);
char *extract_double_quoted_segment(const char *input, int *index);
char *replace_env_variables(char *segment);
char *process_double_quoted_string(char *input);
void expand_variables_in_ast(t_ast_node *node);
char *handle_double_quotes(char *input, int *i);
char *expand_variables(const char *input);
char *handle_double_quotes(char *input, int *i);


t_ast_node *create_commande_node(char **command)
{
    t_ast_node *node;
    node =malloc(sizeof(t_ast_node));
    if(!node)
        return(NULL);
    node->type = NODE_COMMAND;
    node->command = command;
    node->left = NULL;
    node->right =NULL;
    return(node);
}

t_ast_node *create_pipe_node(t_ast_node *left, t_ast_node *right)
{
    t_ast_node *node = (t_ast_node *)malloc(sizeof(t_ast_node));
    if (!node)
        return NULL;
    node->type = NODE_PIPE;
    node->left = left;
    node->right = right;
    node->command = NULL;
    return node;
}

t_ast_node *create_redirection_node(t_node_type type, t_ast_node *left, t_ast_node *right)
{
    t_ast_node *node = (t_ast_node *)malloc(sizeof(t_ast_node));
    if (!node)
        return NULL;
    node->type = type;
    node->left = left;
    node->right = right;
    node->command = NULL;
    return node;
}

t_input	*create_token(t_lexer type, char *value)
{
	t_input	*token;

	token = (t_input *)malloc(sizeof(t_input));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = strdup(value);
	token->next = NULL;
	return (token);
}

void add_token(t_input **tokens, t_input *new_token)
{
    t_input *current;

    current = *tokens;
    if (!current)
    {
        *tokens = new_token;
        return;
    }
    while (current->next)
        current = current->next;
    current->next = new_token;
}

void free_tokens(t_input *tokens)
{
    t_input *tmp;

    while (tokens)
    {
        tmp = tokens;
        tokens = tokens->next;
        free(tmp->value);
        free(tmp);
    }
}


int is_env_variable(const char *str)
{
    return (str[0] == '$' && (isalnum(str[1]) || str[1] == '_'));
}
char *extract_env_name(const char *str)
{
    int len = 0;
    while (str[len] && (isalnum(str[len]) || str[len] == '_'))
        len++;
    return strndup(str, len);
}
char *expand_variables(const char *input)
{
    char *result = malloc(1);
    result[0] = '\0';
    int i = 0;
    while (input[i])
    {
        if (input[i] == '$' && (isalnum(input[i + 1]) || input[i + 1] == '_'))
        {
            i++;
            int start = i;
            while (isalnum(input[i]) || input[i] == '_')
                i++;
            char *var_name = strndup(&input[start], i - start);
            char *var_value = getenv(var_name);
            if (!var_value)
                var_value = "";
            char *new_result = malloc(strlen(result) + strlen(var_value) + 1);
            strcpy(new_result, result);
            strcat(new_result, var_value);
            free(result);
            free(var_name);
            result = new_result;
        }
        else
        {
            int len = strlen(result);
            result = realloc(result, len + 2);
            result[len] = input[i];
            result[len + 1] = '\0';
            i++;
        }
    }
    return result;
}

char *expand_variable(const char *str)
{
    char *result = strdup("");
    const char *start = str;
    while (*str)
    {
        if (*str == '$')
        {
            str++;
            char *env_name = extract_env_name(str);
            char *env_value = getenv(env_name) ? getenv(env_name) : "";
            str += strlen(env_name);
            char *new_result = malloc(strlen(result) + strlen(env_value) + 1);
            strcpy(new_result, result);
            strcat(new_result, env_value);
            free(result);
            free(env_name);
            result = new_result;
            start = str;
        }
        else
        {
            str++;
        }
    }

    char *suffix = strdup(start);
    char *final_result = malloc(strlen(result) + strlen(suffix) + 1);
    strcpy(final_result, result);
    strcat(final_result, suffix);
    free(result);
    free(suffix);
    return final_result;
}

void handle_word(char *input, int *i, t_input **tokens)
{
    int start = *i;
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
    int i = 0;
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



void	free_stock_args(char **stock_args, int i)
{
	while (i > 0)
		free(stock_args[--i]);
	free(stock_args);
}

void free_command_node(t_ast_node *node)
{
    int i = 0;

    if (node->command)
    {
        while (node->command[i])
        {
            free(node->command[i]);
            i++;
        }
        free(node->command);
    }
    free(node);
}

void free_ast_node(t_ast_node *node)
{
    if (!node)
        return;
    if (node->left)
        free_ast_node(node->left);
    if (node->right)
        free_ast_node(node->right);
    if (node->type == NODE_COMMAND)
        free_command_node(node);
    else
        free(node);
}

void expand_variables_in_tokens(t_input *tokens)
{
    t_input *current = tokens;
    while (current)
    {
        if (current->type == DOLLAR)
        {
            char *expanded_value = expand_variable(current->value + 1); // Ignorer le '$'
            free(current->value);
            current->value = expanded_value;
            current->type = WORD; // Changer le type après l'expansion
        }
        current = current->next;
    }
}

char *extract_single_quoted_value(char *input, int *i)
{
    int start = ++(*i);
    while (input[*i] && input[*i] != '\'')
        (*i)++;
    char *value = strndup(input + start, *i - start);
    (*i)++;  //
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
    int start = ++(*i);
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

size_t ft_strlen(char *str)
{
	size_t i;
	i = 0;

	while(str[i])
	{
		i++;
	}
	return(i);
}
char	*ft_strdup(const char *str)
{
	char	*str_b;
	int		str_len;

	str_len = ft_strlen((char *)str);
	str_b = (char *)malloc(str_len * sizeof(char) + 1);
	if (!str_b)
		return (NULL);
	while (*str)
		*str_b++ = *str++;
	*str_b = '\0';
	return (str_b -= str_len);
}
t_ast_node *parse_command(t_input **tokens)
{
    int count = count_args(*tokens);
    char **stock_args = malloc(sizeof(char *) * (count + 1));
    if (!stock_args)
        return NULL;

    int i = 0;
    char *value;
    while (*tokens && ((*tokens)->type == WORD || (*tokens)->type == DOLLAR))
    {
        if (is_env_variable((*tokens)->value))
        {
            value = expand_variable((*tokens)->value);
            printf("Expanded variable: %s\n", value);
        }
        else
        {
            value = strdup((*tokens)->value);
        }

        if (!value)
        {
            free_stock_args(stock_args, i);
            return NULL;
        }
        stock_args[i++] = value;
        *tokens = (*tokens)->next;
    }
    stock_args[i] = NULL;
    return create_commande_node(stock_args);
}

t_ast_node *parse_pipeline(t_input **tokens)
{
    t_ast_node *left = parse_command(tokens);
    t_ast_node *right = NULL;

    while (*tokens && (*tokens)->type == PIPE)
    {
        *tokens = (*tokens)->next;
        right = parse_command(tokens);
        if (!right)
        {
            free_ast_node(left);
            return NULL;
        }
        left = create_pipe_node(left, right);
    }
    return left;
}

t_ast_node *parse_redirection(t_input **tokens)
{
    t_ast_node *command = parse_command(tokens);
    t_ast_node *node = command;
    t_node_type type;

    while (*tokens && is_redirection((*tokens)->type))
    {
        type = get_redirection_type((*tokens)->type);
        *tokens = (*tokens)->next;  // Avancer au token suivant

        t_ast_node *file = parse_command(tokens); // On suppose que le fichier est aussi une commande
        if (!file)
        {
            free_ast_node(command);
            return NULL;
        }

        t_ast_node *new_node = create_redirection_node(type, node, file);
        if (!new_node)
        {
            free_ast_node(file);
            free_ast_node(command);
            return NULL;
        }
        node = new_node;
    }

    return node;
}

int is_redirection(t_lexer type)
{
    return (type == GREATER || type == GREATER2 || type == SMALLER || type == SMALLER2);
}

t_node_type get_redirection_type(t_lexer token)
{
    if (token == GREATER)
        return NODE_REDIRECTION_OUT;
    if (token == GREATER2)
        return NODE_REDIRECTION_APPEND;
    if (token == SMALLER)
        return NODE_REDIRECTION_IN;
    if (token == SMALLER2)
        return NODE_HEREDOC;
    return NODE_COMMAND;
}

t_ast_node *parse(t_input *tokens)
{
    return parse_pipeline(&tokens);
}

t_ast_node *tokenize_and_parse(char *input)
{
    t_input *tokens = NULL;
    t_ast_node *ast;

    tokenize_input(input, &tokens);
    if (!tokens)
        return NULL;

    ast = parse(tokens);

    free_tokens(tokens);

    return ast;
}

int count_args(t_input *tokens)
{
    int count;

    count = 0;
    while(tokens != NULL)
        {
            if(tokens->type == DOLLAR || tokens->type == WORD)
                count++;
            else if(tokens->type == PIPE || tokens->type == GREATER2 ||
                    tokens->type == GREATER ||tokens->type == SMALLER2 ||
                    tokens->type == SMALLER)
                    return(count);
            tokens = tokens->next;
        }
        return(count);
}

void print_tokens(t_input *tokens)
{
    while (tokens)
    {
        printf("Type: %d, Value: %s\n", tokens->type, tokens->value);
        tokens = tokens->next;
    }
}


 // Assurez-vous que tous les headers nécessaires sont inclus

// Fonction pour afficher les nœuds AST (pour les tests)
void print_ast_node(t_ast_node *node)
{
    if (!node)
        return;

    switch (node->type)
    {
    case NODE_COMMAND:
        printf("Command: ");
        for (int i = 0; node->command[i]; i++)
            printf("%s ", node->command[i]);
        printf("\n");
        break;
    case NODE_PIPE:
        printf("Pipe:\n  Left:\n");
        print_ast_node(node->left);
        printf("  Right:\n");
        print_ast_node(node->right);
        break;
    case NODE_REDIRECTION_IN:
        printf("Redirection In (<):\n  Command:\n");
        print_ast_node(node->left);
        printf("  File: %s\n", node->right->command[0]);
        break;
    case NODE_REDIRECTION_OUT:
        printf("Redirection Out (>):\n  Command:\n");
        print_ast_node(node->left);
        printf("  File: %s\n", node->right->command[0]);
        break;
    case NODE_REDIRECTION_APPEND:
        printf("Redirection Append (>>):\n  Command:\n");
        print_ast_node(node->left);
        printf("  File: %s\n", node->right->command[0]);
        break;
    case NODE_HEREDOC:
        printf("Heredoc (<<):\n  Command:\n");
        print_ast_node(node->left);
        printf("  Delimiter: %s\n", node->right->command[0]);
        break;
    default:
        break;
    }
}
int main()
{
    char *test_cases[] = {
        "echo $HOME",
        "echo $HOME > output.txt",
        "echo $HOME >> output.txt",
        "cat < input.txt",
        "echo $HOME | grep /home",
        "grep home < input.txt > output.txt",
        "echo \"New line\" >> output.txt",
        "cat input.txt | grep home > output.txt",
        "grep home < input.txt | sort",
        "echo $USER > user.txt",
        "cat < input.txt > output.txt >> log.txt",
        "\"m\"\"a\"\"k\"\"e\"",
        "\"Hello\"\" \"\"World\"",
        "\"echo\"\" \"\"$USER\"",
        "'echo' 'Hello'",
        "'echo' \"$HOME\"",
        "\"echo\" 'Hello'",
        "\"echo $USER\"",
        "cat <<EOF\nHello\nEOF",
        "cat <<EOF\nLine 1\nLine 2\nEOF"
    };

    for(int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        printf("Testing: %s\n", test_cases[i]);
        t_input *tokens = NULL;
        tokenize_input(test_cases[i], &tokens);
        print_tokens(tokens);

        t_ast_node *ast = parse_pipeline(&tokens);
        if (ast)
        {
            print_ast_node(ast);
            free_ast_node(ast);
        }
        else
        {
            printf("Failed to parse input.\n");
        }
        free_tokens(tokens);
        printf("\n");
    }

    return 0;
}
