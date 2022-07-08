/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:58:10 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/08 11:00:01 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_big(t_data *data, int section);

/*	the function to execute the push_swap algortihm	*/
void	push_swap(t_data *data)
{
	const int	size = ft_lstsize(data->stacka);

	if (size == 2)
		sa(data, 1);
	else if (size == 3)
		push_swap_three(data);
	else if (size <= 10)
		push_swap_small(data);
	else if (size <= 100)
		push_swap_big(data, 5);
	else
		push_swap_big(data, 10);
}

int	find_index(t_list *lst, int min, int max)
{
	int		low;
	int		high;
	int		i;
	t_list	*curr;

	curr = lst;
	low = ft_lstsize(lst);
	high = low;
	i = 0;
	while (curr)
	{
		if (curr->content >= min && curr->content < max)
		{
			if (low != ft_lstsize(lst))
				high = i;
			else
				low = i;
		}
		curr = curr->next;
		i++;
	}
	if (low <= high)
		return (low);
	else
		return (high);
}

void	push_b_big(t_data *data, int index)
{
	if (index > ft_lstsize(data->stacka) / 2)
		rra(data, 1);
	else
		ra(data, 1);
}

void	push_a_big(t_data *data, int index)
{
	if (index > ft_lstsize(data->stackb) / 2)
		rrb(data, 1);
	else
		rb(data, 1);
}

/* for sorting big size */
void	push_swap_big(t_data *data, int section)
{
	int	pivot;
	int	start;
	int	end;

	transform_list(data);
	start = 0;
	pivot = ft_lstsize(data->stacka) / section;
	end = start + pivot;
	// print_stack(data); //
	while (ft_lstsize(data->stacka) != 0)
	{
		while (find_index(data->stacka, start, end) != ft_lstsize(data->stacka))
		{
			push_b_big(data, find_index(data->stacka, start, end));
			if (find_index(data->stacka, start, end) == 0)
				pb(data, 1);
		}
		start = end;
		end = end + pivot;
	}
	end = ft_lstsize(data->stackb);
	start =ft_lstsize(data->stackb) - 1;
	while (ft_lstsize(data->stackb) != 0)
	{
		while (find_index(data->stackb, start, end) != ft_lstsize(data->stackb))
		{
			push_a_big(data, find_index(data->stackb, start, end));
			if (find_index(data->stackb, start, end) == 0)
				pa(data, 1);
		}
		end--;
		start--;
	}

}


