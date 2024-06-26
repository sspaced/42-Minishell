#include "minishell.h"
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
