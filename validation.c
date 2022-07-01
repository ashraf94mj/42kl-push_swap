/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:58:02 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/30 18:03:25 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Errors checking for: some arguments aren’t integers, 
						some arguments are bigger than an integer and/or
						there are duplicates */

static int	is_int(const char *str);
static int	is_dup(int *arr, int size);

int	check_input(t_data *data, char **str, int size)
{
	int	i;

	i = 0;
	data->array = malloc(sizeof(int) * size);
	if (!data->array)
		return (1);
	while (*str)
	{
		if (is_int(*str))
			return (1);
		if (ft_atoi(*str) < INT_MIN || ft_atoi(*str) > INT_MAX)
			return (1);
		data->array[i++] = ft_atoi(*str++);
	}
	if (is_dup(data->array, size))
		return (1);
	return (0);
}

static int	is_int(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_dup(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
