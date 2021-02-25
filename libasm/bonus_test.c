/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:59:43 by tcider            #+#    #+#             */
/*   Updated: 2021/02/02 12:12:40 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_list(t_list *tmp)
{
	printf("--Print elements of the list from the begining:--\n");
	while (tmp)
	{
		printf("\'%s\'\n", (char*)(tmp->data));
		tmp = tmp->next;
	}
}

void		test_atoi_base(void)
{
	printf("\n#################### BONUS ######################\n");
	printf("-----------ft_atoi_base------------\n");
	printf("Test 0 Wrong base: ft_atoi_base(\"2a\", \"0123456789abbdef\")\n");
	printf("%d\n", ft_atoi_base("2a", "0123456789abbdef"));
	printf("Test 1 Wrong base: ft_atoi_base(\"2a\", \"01-23456789abcdef\")\n");
	printf("%d\n", ft_atoi_base("2a", "01-23456789abcdef"));
	printf("Test 2 Wrong str: ft_atoi_base(\"2g\", \"0123456789abcdef\")\n");
	printf("%d\n", ft_atoi_base("2g", "0123456789abcdef"));
	printf("Test 3 Spaced: ft_atoi_base(\"    +2a\", \"0123456789abcdef\")\n");
	printf("%d\n", ft_atoi_base("   +2a", "0123456789abcdef"));
	printf("Test 4 Neg: ft_atoi_base(\"    -23a\", \"0123456789abcdef\")\n");
	printf("%d\n", ft_atoi_base("   -23a", "0123456789abcdef"));
	printf("Test 5 Cool base!: ft_atoi_base(\"    11111111\", \"01\")\n");
	printf("%d\n", ft_atoi_base("   11111111", "01"));
}

t_list		*test_list1(char **str)
{
	t_list		*list;

	printf("-----------ft_list_push_front and _size ------------\nlist=NULL;");
	list = NULL;
	printf("\nft_list_size(list) = %d\n", ft_list_size(list));
	ft_list_push_front(&list, str[0]);
	printf("ft_list_push_front\(&list, \'%s\')\n", str[0]);
	printf("ft_list_size(list) = %d\n", ft_list_size(list));
	ft_list_push_front(&list, str[2]);
	printf("ft_list_push_front\(&list, \'%s\')\n", str[2]);
	printf("ft_list_size(list) = %d\n", ft_list_size(list));
	ft_list_push_front(&list, str[3]);
	printf("ft_list_push_front\(&list, \'%s\')\n", str[3]);
	printf("ft_list_size(list) = %d\n", ft_list_size(list));
	ft_list_push_front(&list, str[2]);
	printf("ft_list_push_front\(&list, \'%s\')\n", str[2]);
	printf("ft_list_size(list) = %d\n", ft_list_size(list));
	print_list(list);
	return (list);
}

void		test_list2(t_list **list, char **str)
{
	printf("-----------ft_list_sort (same list)------------\n");
	ft_list_sort(NULL, NULL);
	printf("ft_list_sort(NULL, NULL) - check if not fail with NULL args\n");
	ft_list_sort(list, ft_strcmp);
	printf("ft_list_sort(list, ft_strcmp)\n");
	print_list(*list);
	printf("-----------ft_list_remove_if (same list)------------\n");
	ft_list_remove_if(NULL, NULL, NULL);
	printf("ft_list_remove_if(NULL, NULL, NULL) -check if not fail\n");
	ft_list_remove_if(list, str[0], ft_strcmp);
	printf("ft_list_remove_if(list, \'%s\', ft_strcmp) -remove head\n", str[0]);
	print_list(*list);
	ft_list_remove_if(list, str[2], ft_strcmp);
	printf("ft_list_remove_if(list, \'%s\', ft_strcmp) -remove dbl\n", str[2]);
	print_list(*list);
	ft_list_remove_if(list, str[1], ft_strcmp);
	printf("ft_list_remove_if(list, \'%s\', ft_strcmp) -remove last\n", str[1]);
	print_list(*list);
	printf("\n");
}
