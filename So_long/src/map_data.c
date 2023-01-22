/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:29:51 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/20 17:10:12 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	get_length_helper(int fd, int length_check)
{
	int		i;
	char	*str;

	str = gnl_so_long(fd);
	while (str != NULL)
	{
		i = 0;
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i != length_check)
			ft_display_error(2);
		free(str);
		str = gnl_so_long(fd);
	}
	free(str);
	close(fd);
	return (i);
}

//check and get map length
int	get_length(char *file_name)
{
	int		fd;
	int		i;
	int		x;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	str = gnl_so_long(fd);
	i = 0;
	while (str[i] != '\n')
		i++;
	free(str);
	x = i;
	i = get_length_helper(fd, i);
	return (i);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	str = gnl_so_long(fd);
	while (str != NULL)
	{
		height++;
		free(str);
		str = gnl_so_long(fd);
	}
	free(str);
	close(fd);
	return (height);
}

void	fill_matrix(char *to_fill, char *lines)
{
	int	i;

	i = 0;
	while (lines[i] != '\n' && lines[i] != '\0')
	{
		to_fill[i] = lines[i];
		i++;
	}
	to_fill[i] = '\0';
}

void	read_file(char *nome_file, t_coordinate *data)
{
	int		fd;
	int		i;

	fd = open(nome_file, O_RDONLY, 0);
	data->map_lenght = get_length(nome_file);
	data->map_height = get_height(nome_file);
	data->map_matrix = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map_matrix)
		exit (0);
	i = -1;
	fd = open(nome_file, O_RDONLY, 0);
	i = -1;
	while (i < data->map_height)
		data->map_matrix[++i] = gnl_so_long(fd);
	close (fd);
}
