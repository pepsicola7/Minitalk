/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:29:11 by peli              #+#    #+#             */
/*   Updated: 2024/09/27 18:30:35 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	send_message(const char *message, pid_t server_pid)
{
	int	len;
	int	i;

	i = 8;
	len = ft_strlen(message);
	message = malloc (sizeof(char *) * (len + 1));
	while(len > 0)
	{
		while (i--)
		{
			if (message[len]>> i == 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
		}
		len--;
	}
}

int	main (int argc, char **argv)
{
	pid_t	server_pid;
	const char	*info_client;

	server_pid = atoi(argv[1]);
	if (argc != 3)
		return (0);
	info_client = argv[2];
	send_message(info_client, server_pid);
}

//Le client enverrait un message au serveur 
//en utilisant kill pour envoyer un signal.