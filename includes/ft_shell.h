/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:49:56 by jpasty            #+#    #+#             */
/*   Updated: 2021/03/08 17:57:02 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FT_SHELL_H
#define MINISHELL_FT_SHELL_H

#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>

int		cmd_exec(char **cmd);

#endif
