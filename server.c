/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:01:02 by peli              #+#    #+#             */
/*   Updated: 2024/09/27 18:56:10 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <sys/types.h>

int	cover_binary(int current_bits)
{
	int message;

	message = 1;
	while (current_bits > 1)
	{
		message = 2 * message;
		current_bits--;
	}
	return (message);
}

void	handler_message(int signal) // fonction pour couvertir de binaire a otctet
{
	int current_bits;
	int	i;
	
	current_bits = 8;
	i = 0;
	while (message[i] != '\0')
	{
		message[i] = 0;
		while (current_bits > 1)
		{
			if (signal == SIGUSR1)
				message[i] += cover_binary(current_bits);
			current_bits--;
		}
		if (current_bits == 1)
			message[i] += 1;
		i++;
	}
	message[i] = '\0';
	ft_printf("%s", message);
	free (message);
	ft_printf("Signal reçu : Le serveur confirme la réception du message.\n");
}

int	main (void)
{
	struct sigaction set;
	ft_printf ("%i\n", getpid());
	set.sa_handler = handler_message;
	sigemptyset(&set.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &set, NULL);
		sigaction(SIGUSR2, &set, NULL);
	}
	return (0);
}