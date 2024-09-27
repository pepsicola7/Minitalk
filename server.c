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

void	cover_binary(int current_bits)
{
	message 
}

void	handler_message(int signal) // fonction pour couvertir de binaire a otctet
{
	int current_bits;
	int	i;
	
	current_bits = 8;
	i = 0;
	while (message[i] != '\0')
	{
		message = malloc(sizeof(char *) * (i + 1));
		while (current_bits > 0)
		{
			if (signal == SIGUSR1)
			// {
			// 	message[i] = message[i] + 2 * // la puissance de 2 (* current_bits - 1)
			// }
				cover_binary(current_bits);
			current_bits--;
		}
		i++;
	}
	free (message);
	// printf("Signal reçu : Le serveur confirme la réception du message.\n");
}

int	main (void)
{
	struct sigaction set;
	printf ("%i\n", getpid());
	set.sa_handler = handler_message;
	sigemptyset(&set.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &set, NULL);
		sigaction(SIGUSR2, &set, NULL);
	}
	return (0);
}