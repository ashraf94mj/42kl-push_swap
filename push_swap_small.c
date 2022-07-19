/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:55:06 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/19 14:38:43 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_small(t_data *data);
static void	push_swap_three(t_data *data);

/*	push swap for small numbers		*/
void	push_swap_small(t_data *data)
{
	if (check_stack(data->stacka) == 1)
		return ;
	if (ft_lstsize(data->stacka) == 2)
	{
		sa(data, 1);
		return ;
	}
	while (ft_lstsize(data->stacka) > 3)
		push_b_small(data);
	push_swap_three(data);
}

/*	for sorting 3 random numbers. there are only 
	5 possbile 	scenarios*/
static void	push_swap_three(t_data *data)
{
	const int	num1 = data->stacka->content;
	const int	num2 = data->stacka->next->content;
	const int	num3 = data->stacka->next->next->content;

	if (check_stack(data->stacka) == 1)
		return ;
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

/*	find smallest number in stack A then push it to stack B	
	by either ra or rra */
static void	push_b_small(t_data *data)
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
