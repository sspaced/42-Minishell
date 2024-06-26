#include "minishell.h"
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
