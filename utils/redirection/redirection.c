/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:20:49 by root              #+#    #+#             */
/*   Updated: 2024/08/07 19:23:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int open_or_check_fd(char *target, int mode)
{
	int target_fd;
	
	target_fd = ft_atoi(target);
	if (ft_isdigit(target_fd))
		return target_fd;
	if (mode == 0)
		target_fd = open(target, R_OK);
	else if (mode == 1)
		target_fd = open(target, O_WRONLY | O_CREAT | O_TRUNC);
	else if (mode == 2)
		target_fd = open(target, O_WRONLY | O_CREAT | O_APPEND);
	else
		return (-1);
	if (target_fd == -1)
		return (-1);
	return (target_fd);
}

int redirect_input(char *target, int source)
{
	int target_fd;

	target_fd = open_or_check_fd(target, 0);
	if (target_fd == -1)
		return (-1);
	if (dup2(target_fd, source) == -1)
		return (close(target_fd), -1);
	close(target_fd);
	return (1);
}

int redirect_output(char *target, int source, int mode)
{
	int target_fd;
	target_fd = open_or_check_fd(target, mode);
	if (target_fd == -1)
		return (-1);
	if (dup2(target_fd, source) == -1)
		return (close(target_fd), -1);
	close(target_fd);
	return (1);
}