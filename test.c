#include "get_next_line.h"

char	*ft_trim(char *processer)
{
	char *ret;
	char *temp;
	int	len;

	len = ft_strlen_nl(processer);
	printf("len is %d\n", len);
	if (len != 0)
	{
		ret = (char*)malloc(sizeof(char)*(len + 1));
		if(!ret)
			return (NULL);
		temp = ft_strchr(processer, '\n') + 1  ; // + 1 to not include the new line
		ft_strlcpy(ret, temp, ft_strlen(temp) + 1);
		free(processer);
	}
	else // reaching the end of the file, no need to trim, just free
		free(processer);
	return (ret);
}


int	main(void)
{
	int	fd;
	int bufsize;
	char buf[5];
	char *processor;

	processor = malloc(100);
	processor = strcpy(processor, "0123456789\n");

	//bufsize = 5;
	////open the file
	//fd = open("t.txt", O_RDWR);
	//read(fd, buf, bufsize);
	//printf("%d\n", fd);
	//printf("%s\n", buf);


	//close the file
	printf("trim function result is %s\n", ft_trim(processor));
	return (0);
}
