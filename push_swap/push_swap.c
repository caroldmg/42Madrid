/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:20:49 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/16 16:39:55 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
    int main(int argc, char **argv)
    {
        t_stack_node    *a;
        t_stack_node    *b;

        a = NULL;
        b = NULL;

        if (srgc == 1 || (argc == 2 && !argv[1][0]))
            return (1); //erro
        else if (argc == 2)
            argv = ft_split(argv[1], ' ');

        stack_init(&a, argv + 1, argc == 2);
        if (!stack_sorted(a))
        {
            if (stack_len(a) == 2)
                sa(&a, false);
            else if (stack_len(a) == 3)
                tiny_sort(&a);
            else
                push_swap(&a, &b);
        }
        free_stack(&a);
    }
*/

//for the split function I will use my libft's one. 