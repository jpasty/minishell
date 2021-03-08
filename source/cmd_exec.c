/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:23:27 by jpasty            #+#    #+#             */
/*   Updated: 2021/03/08 21:52:26 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static int cmd_validate(char *cmd_name)
{
	return 1;
}

int			cmd_exec(char **cmd)
{
	pid_t	pid;
	int 	status;

	if (!cmd_validate(cmd[0]))
		return (0);
	printf("Start from proc PID[%d]\n", getpid());
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		printf("In child proc with PID[%d]\n", getpid());
		printf("Try exec cmd - %s\n", cmd[0]);
	}
	else
	{
		printf("hi\n");
	}
	printf("Return from %s proc PID[%d]\n", pid == 0 ? "child" : "parent", getpid());
//	wait(&status);
	return (1);
}
