/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 02:13:46 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/19 16:43:59 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_big(t_data *data);

/*	the function to execute the push_swap algortihm	*/
void	push_swap(t_data *data)
{
	if (ft_lstsize(data->stacka) <= 10)
	{
		push_swap_small(data);
		while (ft_lstsize(data->stackb) != 0)
			pa(data, 1);
	}
	else
		push_swap_big(data);
}

/*	check if integer below or above median is in the stack	*/
int	int_in_stack(t_list *list, int median, int direction)
{
	t_list	*curr;

	curr = list;
	while (list)
	{
		if (direction == -1 && list->content <= median)
			return (1);
		else if (direction == 1 && list->content > median)
			return (1);
		list = list->next;
	}
	return (0);
}

/*	returns 1 if list is in order and 0 if not in order
this is different than check_stack function where it doesnt 
use the transform list*/
int	check_order(t_list *lst)
{
	int		val;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	val = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (val - temp->content != -1)
			return (0);
		val = temp->content;
		temp = temp->next;
	}
	return (1);
}

/*almost similar to the other function but no time to change it dy*/
int	partition(t_data *data, int len, t_list **list)
{
	int		median;
	t_list	*new;

	len /= 2;
	median = data->max_len - len;
	while (int_in_stack(data->stacka, median, -1) == 1)
	{
		if (data->stacka->content <= median)
			pb(data, 1);
		else
			ra(data, 1);
	}
	if (*list == NULL)
		*list = ft_lstnew(median);
	else
		ft_lstadd_front(list, ft_lstnew(median));
	return (len);
}

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
// 	while (data->counter_a > 0)
// 	{
// 		rra(data, 1);
// 		data->counter_a--;
// 	}
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

// void	rotate_back_a(t_data *data)
// {
// 	while (data->counter_a > 0)
// 	{
// 		rra(data, 1);
// 		data->counter_a--;
// 	}
// }

void	rotate_back_b(t_data *data)
{
	if (data->counter_b == 0)
		return ;
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

/*	to find new top for sorted part of stack A*/
void	check_new_top(t_data *data)
{
	t_list	*curr;
	int		top;

	print_stack(data);
	curr = data->stacka;
	ft_putnbr_fd(curr->content, 1);
	ft_putstr_fd("====\n", 1);
	while (curr)
	{
		top = curr->content; //
		if (top == data->top_a)
			return ;
		if (check_order(curr) == 1)
		{
			data->top_a = top;
			return ;
		}
		curr = curr->next;
	}
}

/*	find the smallest number in stack to get next median pivot*/
int 	smallest_in_stacka(t_data *data)
{
	t_list	*curr;
	int		small;

	curr = data->stacka;
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
int 	biggest_in_stackb(t_data *data)
{
	t_list	*curr;
	int		big;

	curr = data->stackb;
	big = curr->content;
	while (curr)
	{
		if (curr->content > big)
			big = curr->content;
		curr = curr->next;
	}
	return (big);
}

/*	add a list with the content of int number 
	inside the **lst just before the *after list 
	then returns pointer to that new list */
t_list	*ft_lstadd_prev(t_list **lst, t_list *after, int number)
{
	t_list	*temp;

	if (*lst == NULL || after == NULL)
		return (NULL);
	temp = *lst;
	while (temp)
	{
		if (temp->next == after)
		{
			temp->next = ft_lstnew(number);
			temp->next->next = after;
			return (temp->next);
		}
		temp = temp->next;
	}
	return (NULL);
}

/* solve when stack a has 3 elements left for that partition */
void	solve_small_a(t_data *data)
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
	else if (num2 > num3 && num3 > num1)
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
	else
		sa(data, 1);
	check_new_top(data);
}

/* moves set that can reduce the number of total steps, 
	see if got improvement or not */
void	optimize_moves(t_data *data)
{
	t_list	*top_1;
	t_list	*top_2;
	t_list	*top_3;
	t_list	*top_4;

	check_new_top(data);
	top_1 = data->stacka;
	top_2 = data->stacka->next;
	// top_3 = data->stacka->next->next;
	// // top_4 = data->stacka->next->next->next;
	// if (top_2 == NULL || top_3 == NULL || top_4 == NULL)
	// 	return ;
	// if (top_1->content - top_2->content == 1
	// 	&& top_3->content == data->top_a)
	// {
	// 	sa(data, 1);
	// 	check_new_top(data);
	// }
	// if (top_4->content == data->top_a)
	// 	solve_small_a(data);
}

void	second_part(t_data *data, t_list *list)
{
	if (data->top_a - data->stackb->content == 1)
	{
		pa(data, 1);
		check_new_top(data);
	}
	if (biggest_in_stackb(data) - list->content <= 2)
		data->median_b = list->content;
	else
	{
		data->median_b = (list->content + biggest_in_stackb(data)) / 2;
		list = ft_lstadd_prev(&data->track, list, data->median_b);
	}
	while (int_in_stack(data->stackb, data->median_b, 1) == 1)
	{
		if (data->stackb->content > data->median_b)
			pa(data, 1);
		else
			rotate(data, 'B');
	}
	rotate_back_b(data);
	optimize_moves(data);
	while (check_order(data->stacka) == 0)
	{
		optimize_moves(data);
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

	second_part(data, list);
}

void	push_swap_big(t_data *data)
{
	int		len;
	t_list	*list;

	data->max_len = ft_lstsize(data->stacka);
	len = data->max_len;
	transform_list(data);
	while (ft_lstsize(data->stacka) > 3)
		len = partition(data, len, &data->track);
	push_swap_small(data);
	ft_lstadd_back(&data->track, ft_lstnew(0));
	data->top_a = data->stacka->content;
	list = data->track;
	second_part(data, list->next);
	pa(data, 1);
	if (check_order(data->stacka) == 1 && data->stackb == NULL) //////
		printf("STACK STORTED\n");/////

}
