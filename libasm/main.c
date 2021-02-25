/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcider <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:21:54 by tcider            #+#    #+#             */
/*   Updated: 2021/02/02 10:57:00 by tcider           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_read(void)
{
	int		fd;
	char	bf[BUF_SIZE];

	if ((fd = open("test_text", O_RDONLY)) == -1)
		return ;
	printf("-----------ft_read------------\nOpen \'test_text\' with 22chars");
	printf("\nTest 0: Read 15 bytes from open fd\n");
	errno = 0;
	memset(bf, 0, BUF_SIZE);
	printf("ft_read\(%d, buf, 15) = %zd, \'%s\'", fd, ft_read(fd, bf, 15), bf);
	printf("\nset errno = 0, after ft_read errno = %d\n", errno);
	printf("\nTest 1: Read next 15 bytes from open fd\n");
	errno = 0;
	memset(bf, 0, BUF_SIZE);
	printf("ft_read\(%d, buf, 15) = %zd, \'%s\'", fd, ft_read(fd, bf, 15), bf);
	printf("\nset errno = 0, after ft_read errno = %d\n", errno);
	printf("\nTest 2: Read 15 bytes from not existed fd\n");
	errno = 0;
	memset(bf, 0, BUF_SIZE);
	printf("ft_read\(100, buf, 15) = %zd, \'%s\'", ft_read(100, bf, 15), bf);
	printf("\nset errno = 0, after ft_read errno = %d\n", errno);
	close(fd);
}

static void	test_write(char **str)
{
	printf("-----------ft_write------------\nTest 0: *str = \'%s\'\n", str[0]);
	errno = 0;
	printf(" - ft_write\(1, str, ft_strlen\(str)) = %zd\n", ft_write(1, str[0],\
		ft_strlen(str[0])));
	printf("set errno = 0, after ft_write errno = %d\n", errno);
	errno = 0;
	printf(" -    write\(1, str,    strlen\(str)) = %zd\n", write(1, str[0], \
		strlen(str[0])));
	printf("set errno = 0, after    write errno = %d\n", errno);
	printf("\nTest 1: *str = \'%s\'\n", str[1]);
	errno = 0;
	printf(" - ft_write\(1, str, ft_strlen\(str)) = %zd\n", ft_write(1, str[1],\
		ft_strlen(str[1])));
	printf("set errno = 0, after ft_write errno = %d\n", errno);
	errno = 0;
	printf(" -    write\(1, str,    strlen\(str)) = %zd\n", write(1, str[1], \
		strlen(str[1])));
	printf("set errno = 0, after    write errno = %d\n", errno);
	printf("\nTest 2: *str = \'%s\' with negative size\n", str[1]);
	errno = 0;
	printf(" - ft_write\(1, str, -10) = %zd\n", ft_write(1, str[1], -10));
	printf("set errno = 0, after ft_write errno = %d\n", errno);
	errno = 0;
	printf(" -    write\(1, str, -10) = %zd\n", write(1, str[1], -10));
	printf("set errno = 0, after    write errno = %d\n", errno);
}

static void	test_cmp(char **str)
{
	char		*res;

	printf("-----------ft_strcmp------------");
	printf("\nTest 0 equal: \'%s\' \'%s\'\n", str[1], str[3]);
	printf("ft_strcmp: %d\n", ft_strcmp(str[1], str[3]));
	printf("\nTest 1 not equal: \'%s\' \'%s\'\n", str[1], str[2]);
	printf("ft_strcmp: %d\n", ft_strcmp(str[1], str[2]));
	printf("\nTest 2 with zero str: \'%s\' \'%s\'\n", str[1], str[0]);
	printf("ft_strcmp: %d\n", ft_strcmp(str[1], str[0]));
	printf("-----------ft_strdup------------");
	printf("\nTest 0 NULL: \'%s\'\n", NULL);
	res = ft_strdup(NULL);
	printf("ft_strdup: \'%s\'\n", res);
	printf("\nTest 1 normal: \'%s\'\n", str[1]);
	res = ft_strdup(str[1]);
	printf("ft_strdup: \'%s\'\n", res);
	free(res);
	printf("\nTest 2 empty str: \'%s\'\n", str[0]);
	res = ft_strdup(str[0]);
	printf("ft_strdup: \'%s\'\n", res);
	free(res);
}

static void	test_str(char **str, int size)
{
	char	buf[BUF_SIZE];
	int		i;

	i = -1;
	printf("-----------ft_strlen------------");
	while (++i < size)
	{
		printf("\nTest string %d: \'%s\'\n", i, str[i]);
		printf("ft_strlen: %lu\n", ft_strlen(str[i]));
		printf("   strlen: %lu\n", strlen(str[i]));
	}
	printf("-----------ft_strcpy------------");
	i = -1;
	while (++i < size)
	{
		memset(buf, 0, BUF_SIZE);
		printf("\nTest string %d: \'%s\'\n", i, str[i]);
		printf("ft_strcpy: \'%s\'\n", ft_strcpy(buf, str[i]));
	}
}

int			main(void)
{
	char	**str;
	int		size;
	int		buf_size;
	t_list	*list;

	size = 5;
	buf_size = 100;
	str = (char**)malloc(sizeof(char*) * size);
	str[0] = "";
	str[1] = "Hello word!";
	str[2] = "Long, very long long long string";
	str[3] = "Hello word!";
	str[4] = "\n";
	test_str(str, size);
	test_cmp(str);
	test_write(str);
	test_read();
	test_atoi_base();
	list = test_list1(str);
	test_list2(&list, str);
	free(str);
	return (0);
}
