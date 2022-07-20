/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:58:10 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 12:00:05 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////for checking stack after operations and answer. remmbr to remove
void	print_stack(t_data *data)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = data->stacka;
	temp2 = data->stackb;
	printf("a\tb\n----------\n");
	while (ft_lstsize(temp1) || ft_lstsize(temp2))
	{
		if (temp1 && temp2)
		{
			printf("%d\t%d\n", temp1->content, temp2->content);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1 && temp2 == NULL)
		{
			printf("%d\t-\n", temp1->content);
			temp1 = temp1->next;
		}
		else if (temp1 == NULL && temp2)
		{
			printf("-\t%d\n", temp2->content);
			temp2 = temp2->next;
		}
	}
	printf("---------------\n");
}
/////////////////

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
		push_swap_big(data, 11);
}

int	find_index(t_list *lst, int pivot, int direction)
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

// int	find_index(t_list *lst, int min, int max)
// {
// 	int		low;
// 	int		high;
// 	int		i;
// 	t_list	*curr;

// 	curr = lst;
// 	low = ft_lstsize(lst);
// 	high = low;
// 	i = 0;
// 	while (curr)
// 	{
// 		if (curr->content >= min && curr->content < max)
// 		{
// 			if (low != ft_lstsize(lst))
// 				high = i;
// 			else
// 				low = i;
// 		}
// 		curr = curr->next;
// 		i++;
// 	}
// 	if (low <= high)
// 		return (low);
// 	else
// 		return (high);
// }

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

///////// third version
void	push_swap_big(t_data *data, int section)
{
	int	pivot;

	transform_list(data);
	pivot = ft_lstsize(data->stacka) / section;
	
	// int i = 0;
	
	while (data->stacka != NULL)
	{
		while (find_index(data->stacka, start, end) != ft_lstsize(data->stacka))
		{
			push_b_big(data, find_index(data->stacka, start, end));
			pb(data, 1);

			// if (i == 5)
			// {
			// 	i = 0;
			// 	rb(data, 1);
			// }
			// i++;
		}
		pivot += pivot;
	}
	while (data->stackb != NULL)
	{
		push_a_big(data, find_biggest(data->stackb));
		if (find_biggest(data->stackb) == 0)
			pa(data, 1);
	}
}


// void	push_swap_big(t_data *data, int section)
// {
// 	int	pivot;
// 	int	start;
// 	int	end;

// 	transform_list(data);
// 	start = 0;
// 	pivot = ft_lstsize(data->stacka) / section;
// 	end = pivot;
	
// 	// int i = 0;
	
// 	while (data->stacka != NULL)
// 	{
// 		while (find_index(data->stacka, start, end) != ft_lstsize(data->stacka))
// 		{
// 			push_b_big(data, find_index(data->stacka, start, end));
// 			pb(data, 1);

// 			// if (i == 5)
// 			// {
// 			// 	i = 0;
// 			// 	rb(data, 1);
// 			// }
// 			// i++;
// 		}
// 		start = end;
// 		end = end + pivot;
// 	}
// 	while (data->stackb != NULL)
// 	{
// 		push_a_big(data, find_biggest(data->stackb));
// 		if (find_biggest(data->stackb) == 0)
// 			pa(data, 1);
// 	}
// }

/////////// second version
// void	push_swap_big(t_data *data, int section)
// {
// 	int	pivot;
// 	int	start;
// 	int	end;

// 	transform_list(data);
// 	start = 0;
// 	pivot = ft_lstsize(data->stacka) / section;
// 	end = pivot;
// 	while (data->stacka != NULL)
// 	{
// 		while (find_index(data->stacka, start, end) != ft_lstsize(data->stacka))
// 		{
// 			push_b_big(data, find_index(data->stacka, start, end));
// 			pb(data, 1);
// 		}
// 		start = end;
// 		end = end + pivot;
// 	}
// 	while (data->stackb != NULL)
// 	{
// 		push_a_big(data, find_biggest(data->stackb));
// 		if (find_biggest(data->stackb) == 0)
// 			pa(data, 1);
// 	}
// }

////////////first version
// void	push_swap_big(t_data *data, int section)
// {
// 	int	pivot;
// 	int	start;
// 	int	end;

// 	transform_list(data);
// 	start = 0;
// 	pivot = ft_lstsize(data->stacka) / section;
// 	end = start + pivot;
// 	while (data->stacka != NULL)
// 	{
// 		while (find_index(data->stacka, start, end) != ft_lstsize(data->stacka))
// 		{
// 			push_b_big(data, find_index(data->stacka, start, end));
// 			if (find_index(data->stacka, start, end) == 0)
// 				pb(data, 1);
// 		}
// 		start = end;
// 		end = end + pivot;
// 	}
// 	end = ft_lstsize(data->stackb);
// 	start = end - 1;
// 	while (data->stackb != NULL)
// 	{
// 		while (find_index(data->stackb, start, end) != ft_lstsize(data->stackb))
// 		{
// 			push_a_big(data, find_index(data->stackb, start, end));
// 			if (find_index(data->stackb, start, end) == 0)
// 				pa(data, 1);
// 		}
// 		end--;
// 		start--;
// 	}
// }
