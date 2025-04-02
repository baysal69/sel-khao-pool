/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:11 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/02 18:21:01 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_lst(t_ps *swap)
{
	t_ps	*tmp;

	tmp = swap;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			printf("%d\n", tmp -> num);
			break ;
		}
		printf("%d--", tmp -> num);
		tmp = tmp -> next;
	}
}

char	**split_arg(char **av)
{
	char	**mat;
	int		i;
	
	i = 0;
	mat = ft_split(av[1], 32);
	if(mat == NULL)
		return(NULL);

	while(mat[i])
		i++;
	if(check_two(mat) == 1)
		return (free_mat(mat),mat = NULL, NULL);
	return (mat);
}

int	main(int argc, char *argv[])
{
	t_ps	*stack_a;
	t_ps	*stack_b;
	int		j;
	int		i;
	int		n;
	char	**matrix;
	
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	matrix = NULL;
	if (argc == 2)
	{
		matrix = split_arg(argv);
		if (!matrix)
			return (1);
		while(matrix[i])
		{
			n = fft_atoi(matrix[i]);
			fft_lstadd_back(&stack_a, fft_lstnew(n));
			i++;	
		}
		if (i == 1)
			return  (free_mat(matrix) ,fft_lstclear(&stack_a), 0);
	}
	else
	{	
		j = 1;
		if (checkdup(argc, argv) != 0)
			return (1);
		while (j < argc)
		{
			n = fft_atoi(argv[j]);
			fft_lstadd_back(&stack_a, fft_lstnew(n));
			j++;
		}
	}
	if (is_sorted(stack_a) == 1)
		return (0);
	if (argc == 3 || i == 2)
		return (two_sort((&stack_a)), 0);
	if (argc == 4 || i == 3)
		three_args(&stack_a);
	else if (argc <= 11 || i <= 10)
		five_algo(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	print_lst(stack_a);
	if ((is_sorted(stack_a) != 1))
		return (write(2, "Not sorted\n", 11), 1);
	fft_lstclear(&stack_a);
	return (0);
}
