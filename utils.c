/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:14:48 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/30 18:55:38 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast_sec(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

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

int	find_smallest(t_list *lst)
{
	int		small;
	int		count;
	int		i;
	t_list	*curr;

	curr = lst;
	if (curr == NULL)
		return (-1);
	count = 0;
	i = 0;
	small = curr->content;
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
