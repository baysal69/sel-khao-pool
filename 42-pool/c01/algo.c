/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:27:41 by sara              #+#    #+#             */
/*   Updated: 2025/03/28 21:33:04 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index(t_ps **stack_a)
{
    t_ps *head;
    t_ps *small;
    int i;

    head = *stack_a;
    while (head)
    {
        head->index = -1;
        head = head->next;
    }
    i = 0;
    while (i < fft_lstsize(*stack_a))
    {
        head = *stack_a;
        small = NULL;
        while (head)
        {
            if (head->index == -1 && (!small || head->num < small->num))
                small = head;
            head = head->next;
        }
        if (small)
            small->index = i++;
    }
}

int max_len(int max)
{
    int len;

    len = 0;
    while(max)
    {
        max >>= 1;
        len++;
    }
    return (len);
}

void    radix_sort(t_ps **stack_a, t_ps **stack_b)
{
    int i;
    int max;
    int ith;
    int size;

    ith = -1;
	set_index(stack_a);
    size = fft_lstsize(*stack_a);
    max = max_len(size);
    while (++ith < max)
    {
        i = -1;
        while(++i < size)
        {
            if(is_sorted((*stack_a)) == 1 && fft_lstsize(*stack_b) == 0)
                return ;
            if ((((*stack_a)->index >> ith) & 1) == 1)
                ft_ra(stack_a, 1);
            else
                ft_pb(stack_b, stack_a);
        }
        while(fft_lstsize(*stack_b) != 0)
            ft_pa(stack_a, stack_b);
    }
}

void	three_args(t_ps **stack)
{
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
	{
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	else if ((*stack)->next->num > (*stack)->num
	&& (*stack)->num > (*stack)->next->next->num)
		ft_rra(stack, 1);
	else if ((*stack)->num > (*stack)->next->next->num
	&& (*stack)->next->next->num > (*stack)->next->num)
		ft_ra(stack, 1);
	else if ((*stack)->next->num > (*stack)->next->next->num
	&& (*stack)->next->next->num > (*stack)->num)
	{
		ft_sa(stack, 1);
		ft_ra(stack, 1);
	}
	else if ((*stack)->next->next->num > (*stack)->num
	&& (*stack)->num > (*stack)->next->num)
		ft_sa(stack, 1);
}

void five_algo(t_ps **stack_a, t_ps **stack_b)
{
    int len;
    int min_pos;

    len = fft_lstsize((*stack_a));// Push 2 smallest numbers to stack_b
    while (len > 3)
    {
        min_pos = find_min_position(*stack_a);// Move the minimum value to the top of stack_a
        if (min_pos <= len / 2)
        {// Use rotate if position is in the first half
            while (min_pos > 0)
            {
                ft_ra(stack_a, 1);
                min_pos--;
            }
        }
        else
        {// Use reverse rotate if position is in the second half
            while (min_pos < len)
            {
                ft_rra(stack_a, 1);
                min_pos++;
            }
        }// Push the minimum value to stack_b
        ft_pb(stack_b, stack_a);
        len--;
    }// Sort the remaining 3 numbers in stack_a
    three_args(stack_a);// Push back the 2 numbers from stack_b to stack_a
    while (*stack_b)
        ft_pa(stack_a, stack_b);
}
