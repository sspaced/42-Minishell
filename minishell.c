#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
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

// Fonction principale pour les tests
int main()
{
    int i;
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
