#include "minishell.h"
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
