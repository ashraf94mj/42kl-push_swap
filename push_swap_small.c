/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:55:06 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/08 02:40:00 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_small(t_data *data);

/*	for sorting 3 random numbers. there are only 
	5 possbile 	scenarios*/
void	push_swap_three(t_data *data)
{
	const int	num1 = data->stacka->content;
	const int	num2 = data->stacka->next->content;
	const int	num3 = data->stacka->next->next->content;

	if (num1 > num2 && num3 > num1)
		sa(data, 1);
	else if (num1 > num2 && num2 > num3)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (num1 > num2 && num3 > num2 && num1 > num3)
		ra(data, 1);
	else if (num2 > num1 && num3 > num1 && num2 > num3)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else
		rra(data, 1);
}

/*	push swap for small numbers		*/
void	push_swap_small(t_data *data)
{
	while (ft_lstsize(data->stacka) > 3)
		push_b_small(data);
	if (check_stacks(data->stacka) != 1)
		push_swap_three(data);
	while (ft_lstsize(data->stackb) != 0)
		pa(data, 1);
}

/*	find smallest number in stack A then push it to stack B	
	by either ra or rra */
void	push_b_small(t_data *data)
{
	int	index;

	index = find_smallest(data->stacka);
	while (index != 0)
	{
		if (index > ft_lstsize(data->stacka) / 2)
			rra(data, 1);
		else
			ra(data, 1);
		index = find_smallest(data->stacka);
	}
	pb(data, 1);
}
