#include "minishell.h"

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