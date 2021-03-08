/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 23:03:15 by jpasty            #+#    #+#             */
/*   Updated: 2021/03/08 21:23:25 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void trim_whitespace(char * restrict trimmed, const char * restrict untrimmed)
{
	int	do_space;

	while (*untrimmed)
	{
		if (!ft_isspace(*untrimmed))
		{
			*trimmed++ = *untrimmed;
			do_space = 1;
		}
		if (do_space && *(untrimmed + 1) && ft_isspace(*(untrimmed + 1)))
		{
			*trimmed++ = ' ';
			do_space = 0;
		}
		*untrimmed++;
	}
	*trimmed = '\0';
}

void	handle_sigtstp(int sig)
{
	printf("Stop not allowed\n");
}

void	handle_sigcont(int sig)
{
	printf("Input number: ");
	fflush(stdout);
}

void	prepare_env(void)
{

}

void	print_prompt(void)
{
	write(1, "$>", 2);
}

char		**parse_command()
{
	char	*line;
	char 	*trim_line;
	char	**cmd_and_args;

	get_next_line(STDIN_FILENO, &line);
	trim_line = ft_strtrim(line);
	trim_whitespace(trim_line, line);
	cmd_and_args = ft_strsplit(trim_line, ' ');
	free(trim_line);
	free(line);
	return (cmd_and_args);

}

int			main(int argc, char *argv[])
{
	int		x;
	int		live;
	char 	**cmd;
	struct	sigaction s;

	prepare_env();
	live = 1;
	while (live)
	{
		print_prompt();
		cmd = parse_command();
		live = cmd_exec(cmd);
		free(cmd);
	}
	s.sa_handler = &handle_sigcont;
	s.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &s, NULL);
//	signal(SIGTSTP, &handle_sigtstp);
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}