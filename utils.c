/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:14:48 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/19 18:22:10 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	function to find the second last element of 
the linked list */
t_list	*ft_lstlast_sec(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

/*	function to return the index of biggest element 
in the linked list	NOT SURE YET IF WANT USE*/
int	find_biggest(t_list *lst)
{
	int		big;
	int		count;
	int		i;
	t_list	*curr;

	curr = lst;
	if (curr == NULL)
		return (-1);
	count = 0;
	i = 0;
	big = curr->content;
	while (curr)
	{
		if (curr->content > big)
		{
			big = curr->content;
			count = i;
		}
		curr = curr->next;
		i++;
	}
	return (count);
}

/*	function to return the index of smallest element 
in the linked list	*/
int	find_smallest(t_list *lst)
{
	int		small;
	int		count;
	int		i;
	t_list	*curr;

	curr = lst;
	count = 0;
	i = 0;
	small = curr->content;
	if (curr == NULL)
		return (0);
	while (curr)
	{
		if (curr->content < small)
		{
			small = curr->content;
			count = i;
		}
		curr = curr->next;
		i++;
	}
	return (count);
}

/* transform the linked list contents to the order number */
void	transform_list(t_data *data)
{
	int		count;
	int		compare;
	t_list	*first;
	t_list	*hold;
	t_list	*temp;

	data->stackb = data->stacka;
	data->stacka = NULL;
	first = data->stackb;
	hold = first;
	while (hold)
	{
		count = 0;
		temp = first;
		compare = hold->content;
		while (temp)
		{
			if (compare > temp->content)
				count++;
			temp = temp->next;
		}
		ft_lstadd_back(&data->stacka, ft_lstnew(count));
		hold = hold->next;
	}
	ft_lstclear(&data->stackb);
}

/*	function to check if a stack is fully sorted, 
	return 1 if the list is fully sorted and 
	0 if not	*/
int	check_stack(t_list *lst)
{
	int		val;
	t_list	*temp;

	if (lst == NULL)
		return (1);
	val = lst->content;
	temp = lst->next;
	while (temp)
	{
		if (val > temp->content)
			return (0);
		val = temp->content;
		temp = temp->next;
	}
	return (1);
}
