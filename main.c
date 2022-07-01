/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:47:26 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/30 18:58:37 by mmohamma         ###   ########.fr       */
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

void	init_data(t_data *data)
{
	data->stacka = NULL;
	data->stackb = NULL;
	data->array = NULL;
	return ;
}

void	free_data(t_data *data)
{
	if (data->stacka)
		ft_lstclear(&data->stacka);
	if (data->stackb)
		ft_lstclear(&data->stackb);
	if (data->array)
	{
		free(data->array);
		data->array = NULL;
	}
}

void	error(t_data *data)
{
	free_data(data);
	ft_putendl_fd("error", 2);
	exit(EXIT_FAILURE);
}

t_list	*create_stack(t_data *data, char **str)
{
	t_list	*first;
	t_list	*new;

	first = ft_lstnew(ft_atoi(*str++));
	while (*str)
	{
		new = ft_lstnew((int)ft_atoi(*str++));
		ft_lstadd_back(&first, new);
	}
	return (first);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		return (0);
	}

	init_data(&data);
	if (check_input(&data, ++argv, argc - 1))
		error(&data);
	data.stacka = create_stack(&data, argv);
	check_stacks
	push_swap(&data);



	print_stack(&data);
	

	// pb(&data, 1);
	// pb(&data, 1);
	// pb(&data, 1);
	// pb(&data, 1);
	// print_stack(&data);


	// rra(&data, 1);
	// print_stack(&data);
	// rra(&data, 1);
	// print_stack(&data);
	// rra(&data, 1);
	// print_stack(&data);
	// rrb(&data, 1);
	// print_stack(&data);
	// rrr(&data, 1);

	
	printf("%d\n", find_biggest(data.stacka));
	printf("%d\n", find_smallest(data.stacka));
	
	check_stacks(&data);
	free_data(&data);

	return (0);
}


