/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:05:30 by peli              #+#    #+#             */
/*   Updated: 2024/09/30 11:58:47 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define SIGUSR1 1
# define SIGUSR2 0

# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

size_t	ft_strlen(const char *s);
void	send_message(const char *message, int server_pid);
void	handler_message(int signal, siginfo_t *pid, void *ZERO);
void	print_message(int signal);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		end_phrase(siginfo_t *pid, char *temp);

#endif