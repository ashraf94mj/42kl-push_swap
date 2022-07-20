/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:19:20 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 11:19:34 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* for rotating either stack A or B and increment
	the respective counter to keep track */
void	rotate(t_data *data, char c)
{
	if (c == 'A')
	{
		ra(data, 1);
		data->counter_a++;
	}
	else if (c == 'B')
	{
		rb(data, 1);
		data->counter_b++;
	}
}

void	rotate_back_a(t_data *data)
{
	if (data->counter_a > ft_lstsize(data->stacka) / 2)
	{
		data->counter_a = ft_lstsize(data->stacka) - data->counter_a;
		while (data->counter_a > 0)
		{
			ra(data, 1);
			data->counter_a--;
		}
	}
	else
	{
		while (data->counter_a > 0)
		{
			rra(data, 1);
			data->counter_a--;
		}
	}
}

void	rotate_back_b(t_data *data)
{
	if (data->counter_b > ft_lstsize(data->stackb) / 2)
	{
		data->counter_b = ft_lstsize(data->stackb) - data->counter_b;
		while (data->counter_b > 0)
		{
			rb(data, 1);
			data->counter_b--;
		}
	}
	else
	{
		while (data->counter_b > 0)
		{
			rrb(data, 1);
			data->counter_b--;
		}
	}
}
