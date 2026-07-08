/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofarhat <mofarhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:02:27 by mofarhat          #+#    #+#             */
/*   Updated: 2026/07/08 13:51:20 by mofarhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buf_pos = 0;
	static int	buf_size = 0;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	return (read_line(fd, buffer, &buf_pos, &buf_size));
}
