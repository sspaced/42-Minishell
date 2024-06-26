#include "minishell.h"

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
