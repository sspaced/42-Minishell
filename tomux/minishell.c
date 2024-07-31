#include "../headers/minishell.h"
void print_tokens(t_input *tokens)
{
    while (tokens)
    {
        printf("Type: %d, Value: %s\n", tokens->type, tokens->value);
        tokens = tokens->next;
    }
}

// int main()
// {    
//         "grep                         home < input.txt > output.txt",
       
//   
//         printf("Testing: %s\n", test_cases[i]);
//         t_input *tokens = NULL;
//         tokenize_input(test_cases[i], &tokens);
//         print_tokens(tokens);
//         //count_tokens(tokens);
//         free_tokens(tokens);
//         printf("\n");
//     }

//     return 0;
// }
