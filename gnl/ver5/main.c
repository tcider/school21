#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int		main(void)
{
	int		fd;
	char	*str;
	int		res;
	
	printf("%d - buffer - %d\n", OPEN_MAX, BUFFER_SIZE);
	
	fd = open("test", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		free(str);
	}
	close(fd);
	printf("--------------------------------\n");

	fd = open("test1", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		free(str);
	}
	close(fd);
	printf("--------------------------------\n");

	fd = open("test2", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		free(str);
	}
	close(fd);
	printf("--------------------------------\n");

	fd = open("test3", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		free(str);
	}
	close(fd);
	printf("--------------------------------\n");

	fd = open("test4", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		free(str);
	}
	close(fd);
	printf("--------------------------------\n");

	fd = open("test6", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		free(str);
	}
	close(fd);
	printf("--------------------------------\n");

	while ((res = get_next_line(0, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		free(str);
	}
	printf("--------------------------------\n");












	/*
	printf("After1 line - '%s' res - %d\n", str, res);
	res = get_next_line(fd, &str);
	printf("After2 line - '%s' res - %d\n", str, res);
	free(str);
	close(fd);
	
	
	printf("--------\n\n-------------\n");
	fd = open("test2", O_RDONLY);
	str = NULL;
	//res = get_next_line(fd, &str);
	//printf("%s\n%d\n", str, res);
	
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("'%s'\n%d\n", str, res);
		free(str);
	}
	printf("'%s'\n%d\n", str, res);
	res = get_next_line(fd, &str);
	printf("'%s'\n%d\n", str, res);
	close(fd);
	
	printf("--------\n\n-------------\n");
	fd = open("test3", O_RDONLY);
	str = NULL;
	//res = get_next_line(fd, &str);
	//printf("%s\n%d\n", str, res);
	
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("'%s'\n%d\n", str, res);
		free(str);
	}
	printf("'%s'\n%d\n", str, res);
	res = get_next_line(fd, &str);
	printf("'%s'\n%d\n", str, res);
	close(fd);
	*/
	
	return (0);
}
