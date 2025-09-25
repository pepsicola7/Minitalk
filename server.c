/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:01:02 by peli              #+#    #+#             */
/*   Updated: 2024/09/30 16:48:11 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_message = NULL;

int	end_phrase(siginfo_t *pid, char *temp)
{
	int	init_bits;

	ft_printf("%s\n", g_message);
	kill(pid->si_pid, SIGUSR2);
	free(g_message);
	free(temp);
	g_message = NULL;
	init_bits = 7;
	return (init_bits);
}

void	handler_message(int signal, siginfo_t *pid, void *ZERO)
{
	char		*temp;
	static int	current_bits = 7;
	static char	c = 0;

	(void)ZERO;
	if (signal == SIGUSR1)
		c |= 1 << current_bits;
	current_bits--;
	if (current_bits < 0)
	{
		temp = malloc(2);
		if (!temp)
			return ;
		temp[0] = c;
		temp[1] = '\0';
		if (c == '\0')
		{
			current_bits = end_phrase(pid, temp);
			return ;
		}
		current_bits = 7;
		g_message = ft_strjoin(g_message, temp);
		c = 0;
		free (temp);
	}
}

int	main(void)
{
	struct sigaction	set;

	g_message = NULL;
	set.sa_sigaction = handler_message;
	set.sa_flags = SA_SIGINFO;
	ft_printf ("%i\n", getpid());
	sigemptyset(&set.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &set, NULL);
		sigaction(SIGUSR2, &set, NULL);
	}
	return (0);
}
