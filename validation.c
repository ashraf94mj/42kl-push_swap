/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:58:02 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/19 18:19:29 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(const char *str);
static void	ft_free_temp(char **str);
static int	is_dup(t_data *data);

/* Errors checking for: some arguments aren’t integers, 
						some arguments are bigger than an integer and/or
						there are duplicates
						return 1 if invalid input
						and return 0 if input arguments valid
	and at same time creating the stack A*/
int	create_stack(t_data *data, char **str)
{
	char	**temp;
	int		i;
	int		output;

	output = 0;
	while (*str)
	{
		temp = ft_split(*str++, ' ');
		i = 0;
		while (temp[i])
		{
			if (is_int(temp[i]))
				output = 1;
			if (ft_atol(temp[i]) < INT_MIN || ft_atol(temp[i]) > INT_MAX)
				output = 1;
			ft_lstadd_back(&data->stacka, ft_lstnew((int)ft_atol(temp[i])));
			i++;
		}
		ft_free_temp(temp);
	}
	if (is_dup(data) == 1)
		output = 1;
	return (output);
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

static void	ft_free_temp(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str[i]);
		free(str);
	}
}

static int	is_dup(t_data *data)
{
	t_list	*first;
	t_list	*second;
	int		number;

	first = data->stacka;
	while (first)
	{
		number = first->content;
		second = first->next;
		while (second)
		{
			if (number == second->content)
				return (1);
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}
