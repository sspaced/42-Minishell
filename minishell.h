/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:35:53 by loic              #+#    #+#             */
/*   Updated: 2024/05/11 14:43:58 by loic             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum 
{
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    DOLLAR,
    GREATER,
    SMALLER,
    PIPE,
    WORD,

} lexer;

typedef enum
{
    OUTSIDE,
    INSIDE_SINGLE,
    INSIDE_DOUBLE,
} quote_state;

typedef struct s_input
{
    lexer type;
    char *value;
    struct input *next;
 } t_input;

//parser

quote_state update_state(char c, quote_state state);
lexer detect_token(char c, quote_state state);
void tokeniser(char *str);
void parse_args(int argc, char **argv);


#endif