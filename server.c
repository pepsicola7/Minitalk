/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:01:02 by peli              #+#    #+#             */
/*   Updated: 2024/09/26 19:15:53 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include <signal.h>

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		ft_printf ("Signal reçu : Le serveur confirme la réception du message.");
}

void	set_signal_action(void)
{
	struct sigaction *set;

	sigemptyset(set);
	sigaddset(set);
	set->sa_handler = &sigint_handler;
	if (sigaction(SIGINT, set, NULL == -1))
		exit (1);
}

int	main (void)
{
	ft_printf ("%d", getpid());
	while (1)
	{
		set_signal_action() ;
	}
	return (0);
}