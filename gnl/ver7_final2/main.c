#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

#ifndef FD_LIM
#define FD_LIM 0
#endif

int		main(void)
{
	int		fd;
	char	*str;
	int		res;
	printf("buffer - %d\n", FD_LIM);
	printf("buffer - %d\n", BUFFER_SIZE);

	//str = (char*)malloc(10);
	//free(str);

	//*str = 'a';	
	fd = open("test", O_RDONLY);
	str = NULL;
	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &str);
		printf("line - '%s' ret - %d\n", str, res);
		if (str)
		{
			//printf("freestr\n");
			free(str);
		}
		str = NULL;
	}
	printf("After\n");
	res = get_next_line(fd, &str);
	printf("line - '%s' ret - %d\n", str, res);
	if (str)
	{
		//printf("freestr\n");
		free(str);
	}
	close(fd);

	str = NULL;
	
	/*while (1)
	{
		str = NULL;
		get_next_line(open("test", O_RDONLY), &str);
		printf("a");
		free (str);
	}*/
		
	printf("--------------------------------\n");
	fd = open("test2", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		if (str)
		{
			//printf("freestr\n");
			free(str);
		}
	}
	printf("After\n");
	res = get_next_line(fd, &str);
	printf("line - '%s' ret - %d\n", str, res);
	if (str)
	{
		//printf("freestr\n");
		free(str);
	}
	close(fd);

	printf("--------------------------------\n");
	fd = open("test3", O_RDONLY);
	str = NULL;
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("line - '%s' res - %d\n", str, res);
		if (str)
		{
			//printf("freestr\n");
			free(str);
		}
	}
	printf("After\n");
	res = get_next_line(fd, &str);
	printf("line - '%s' ret - %d\n", str, res);
	if (str)
	{
		//printf("freestr\n");
		free(str);
	}
	close(fd);

	/*
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
