/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:08:18 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 12:02:03 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_four_a(t_data *data);
static void	solve_four_aa(t_data *data);

/* moves set that can reduce the number of total steps, 
	see if got improvement or not */
void	optimize_moves_a(t_data *data)
{
	t_list	*top_1;
	t_list	*top_2;
	t_list	*top_3;
	t_list	*top_4;

	check_new_top(data);
	top_1 = data->stacka;
	top_2 = data->stacka->next;
	top_3 = data->stacka->next->next;
	top_4 = data->stacka->next->next->next;
	if (top_2 == NULL || top_3 == NULL || top_4 == NULL)
		return ;
	if (top_1->content - top_2->content == 1
		&& top_3->content == data->top_a)
	{
		sa(data, 1);
		check_new_top(data);
	}
	if (top_4->content == data->top_a)
		solve_four_a(data);
}

void	optimize_moves_b(t_data *data)
{
	check_new_top(data);
	if (!data->stackb)
		return ;
	if (data->top_a - data->stackb->content == 1)
	{
		pa(data, 1);
		optimize_moves_b(data);
	}
}

static void	solve_four_aa(t_data *data)
{
	const int	num1 = data->stacka->content;
	const int	num2 = data->stacka->next->content;
	const int	num3 = data->stacka->next->next->content;

	if (num1 > num2 && num2 > num3)
	{
		sa(data, 1);
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
		sa(data, 1);
	}
	else if (num1 > num2 && num3 > num2)
	{
		sa(data, 1);
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
	}
}

/* solve when stack a has 3 elements left for that partition */
static void	solve_four_a(t_data *data)
{
	const int	num1 = data->stacka->content;
	const int	num2 = data->stacka->next->content;
	const int	num3 = data->stacka->next->next->content;

	solve_four_aa(data);
	if (num2 > num3 && num3 > num1)
	{
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
	}
	else if (num2 > num1 && num1 > num3)
	{
		ra(data, 1);
		sa(data, 1);
		rra(data, 1);
		sa(data, 1);
	}
	else if (num1 > num2 && num3 > num1)
		sa(data, 1);
	check_new_top(data);
}
