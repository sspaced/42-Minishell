#include "minishell.h"
void print_tokens(t_input *tokens)
{
    while (tokens)
    {
        printf("Type: %d, Value: %s\n", tokens->type, tokens->value);
        tokens = tokens->next;
    }
}

int main()
{
    char *test_cases[] = {
    
        "grep                         home < input.txt > output.txt",
       
    };

    for(unsigned long i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {   
        
        printf("Testing: %s\n", test_cases[i]);
        t_input *tokens = NULL;
        tokenize_input(test_cases[i], &tokens);
        print_tokens(tokens);
        //count_tokens(tokens);
        tokens_to_array(tokens);
        free_tokens(tokens);
        printf("\n");
    }

    return 0;
}
