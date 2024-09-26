/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:29:11 by peli              #+#    #+#             */
/*   Updated: 2024/09/26 20:19:12 by peli             ###   ########.fr       */
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
void	send_message(const char *message, __pid_t server_pid)
{
	int	len;

	len = ft_strlen(message);
	while(len > 0)
	{
		if ()
	}
}

int	main (int argc, char **argv)
{
	__pid_t	server_pid;
	const char	*message;

	if (argc != 3)
		return (0);
	server_pid = atoi(argv[1]);
	message = argv[2];
	send_message(message, server_pid);
}

//Le client enverrait un message au serveur 
//en utilisant kill pour envoyer un signal.