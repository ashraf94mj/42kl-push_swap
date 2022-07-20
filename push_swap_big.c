/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:57:14 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 12:02:32 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smallest_in_stacka(t_data *data);
static int	biggest_in_stackb(t_data *data);
static void	find_median_b(t_data *data, t_list **list);
static void	push_median_b(t_data *data);

void	recursion_sort(t_data *data, t_list *list)
{
	optimize_moves_b(data);
	find_median_b(data, &list);
	push_median_b(data);
	optimize_moves_a(data);
	while (check_order(data->stacka) == 0)
	{
		optimize_moves_a(data);
		data->median_a = (data->top_a + smallest_in_stacka(data)) / 2;
		list = ft_lstadd_prev(&data->track, list, data->median_a);
		while (int_in_stack(data->stacka, data->median_a, -1) == 1)
		{
			if (data->stacka->content <= data->median_a)
				pb(data, 1);
			else
				rotate(data, 'A');
			if (check_order(data->stacka) == 1)
				break ;
		}
		rotate_back_a(data);
	}
	if (data->top_a <= list->content + 1)
		list = list->next;
	if (list == NULL)
		return ;
	recursion_sort(data, list);
}

/*	find the smallest number in stack to get next median pivot*/
static int	smallest_in_stacka(t_data *data)
{
	t_list	*curr;
	int		small;

	curr = data->stacka;
	if (!curr)
		return (-1);
	small = curr->content;
	while (curr)
	{
		if (curr->content < small)
			small = curr->content;
		curr = curr->next;
	}
	return (small);
}

/*	find the biggest number in stack B to get next median pivot*/
static int	biggest_in_stackb(t_data *data)
{
	t_list	*curr;
	int		big;

	curr = data->stackb;
	if (!curr)
		return (-1);
	big = curr->content;
	while (curr)
	{
		if (curr->content > big)
			big = curr->content;
		curr = curr->next;
	}
	return (big);
}

static void	find_median_b(t_data *data, t_list **list)
{
	if (biggest_in_stackb(data) - (*list)->content <= 2)
		data->median_b = (*list)->content;
	else
	{
		data->median_b = ((*list)->content + biggest_in_stackb(data)) / 2;
		*list = ft_lstadd_prev(&data->track, *list, data->median_b);
	}
}

static void	push_median_b(t_data *data)
{
	while (int_in_stack(data->stackb, data->median_b, 1) == 1)
	{
		if (data->stackb->content > data->median_b)
			pa(data, 1);
		else
			rotate(data, 'B');
	}
	rotate_back_b(data);
}
