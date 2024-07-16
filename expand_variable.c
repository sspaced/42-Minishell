#include "minishell.h"
char *expand_variable(const char *str)
{
    char *result;
    const char *start;

    result = strdup("");
    start = str;
    while (*str)
    {
        if (*str == '$')
        {
            str++;
            char *env_name;
            env_name = extract_env_name(str);
            char *env_value;
            env_value = getenv(env_name) ? getenv(env_name) : "";
            str += strlen(env_name);
            char *new_result;
            new_result = malloc(strlen(result) + strlen(env_value) + 1);
            strcpy(new_result, result);
            strcat(new_result, env_value);
            free(result);
            free(env_name);
            result = new_result;
            start = str;
        }
        else
        {
            str++;
        }
    }
    char *suffix;
    suffix = strdup(start);
    char *final_result;
    final_result = malloc(strlen(result) + strlen(suffix) + 1);
    strcpy(final_result, result);
    strcat(final_result, suffix);
    free(result);
    free(suffix);
    return (final_result);
}

int is_env_variable(const char *str)
{
    return (str[0] == '$' && (isalnum(str[1]) || str[1] == '_'));
}

char *extract_env_name(const char *str)
{ 
    int len;

    len = 0;
    while (str[len] && (isalnum(str[len]) || str[len] == '_'))
        len++;
    return strndup(str, len);
}