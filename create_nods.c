#include "minishell.h"

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


