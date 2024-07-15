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
        free_tokens(tokens);
        printf("\n");
    }

    return 0;
}
