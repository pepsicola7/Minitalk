/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:29:11 by peli              #+#    #+#             */
/*   Updated: 2024/09/30 16:51:03 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(const char *message, int server_pid)
{
	int	i;
	int	len;
	int	len_message;

	len_message = ft_strlen(message);
	len = len_message;
	while (len >= 0)
	{
		i = 8;
		while (i--)
		{
			if ((message[len_message - len] >> i) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
		}
		len--;
	}
	usleep(10000);
}

void	print_message(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("The server received the message successfully\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	set;
	int					server_pid;
	const char			*info_client;

	if (argc != 3)
		return (0);
	server_pid = atoi(argv[1]);
	info_client = argv[2];
	set.sa_handler = print_message;
	sigemptyset(&set.sa_mask);
	set.sa_flags = 0;
	sigaction(SIGUSR2, &set, NULL);
	send_message(info_client, server_pid);
	return (0);
}

//Le client enverrait un message au serveur 
//en utilisant kill pour envoyer un signal.