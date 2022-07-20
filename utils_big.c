/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:19:31 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 12:02:55 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*	to find new top of the sorted part of stack A*/
void	check_new_top(t_data *data)
{
	t_list	*curr;
	int		top;

	curr = data->stacka;
	while (curr)
	{
		top = curr->content;
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

/*	check if integer below or above median is in the stack	*/
int	int_in_stack(t_list *list, int median, int direction)
{
	t_list	*curr;

	curr = list;
	while (curr)
	{
		if (direction == -1 && curr->content <= median)
			return (1);
		else if (direction == 1 && curr->content > median)
			return (1);
		curr = curr->next;
	}
	return (0);
}
