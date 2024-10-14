#include "pipex.h"
#include <stdlib.h>
#include <string.h>

// int main()
// {
// 	char *const args[] = {"ls", "-la",NULL};
// 	char *const envp[] = { NULL };

// 	execve("/usr/bin/ls", args, envp);

// 	perror("execve");
// 	return (1);
// }

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	c;

	c = 0;
	if (dstsize > 0)
	{
		while (c < dstsize - 1 && src[c] != '\0')
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (strlen(src));
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	x;

	x = 0;
	while (x < n && (s1[x] != '\0' || s2[x] != '\0'))
	{
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}

static void	free_all(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
}

static size_t	strchrlen(size_t start, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	return (i);
}

static	size_t	count_str(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (count + 1);
}

static	int	input_strings(char **arr, char const *s, size_t count, char c)
{
	size_t	i;
	int		j;
	size_t	len;	

	i = 0;
	j = 0;
	while (j < (int)count - 1)
	{
		while (s[i] == c)
			i++;
		len = strchrlen(i, s, c);
		arr[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!arr[j])
		{
			free_all(arr, j);
			return (0);
		}
		ft_strlcpy(arr[j], s + i, len + 1);
		i = i + len;
		j++;
	}
	arr[count - 1] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		count;

	if (!s)
		return (NULL);
	count = count_str(s, c);
	arr = (char **)malloc(count * sizeof(char *));
	if (!arr)
		return (0);
	if (!input_strings(arr, s, count, c))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

int main(int argc, char **argv, char **envp)
{
	if (argc >= 2)
	{
		int i = 0;
		while (i < argc)
		{
			printf("argv[%d] --> \t  %s \n", i, argv[i]);
			i++;
		}
		i = 0;
		printf(" \n >>>>>>>>>>>>>>>>>ENVP<<<<<<<<<< \n");
		while (envp[i] && (ft_strncmp(envp[i], "PATH=", 5) != 0))
			i++;
		printf("res --> %s", envp[i]);
		char **my_paths;
		my_paths = ft_split(envp[i] + 5, ':');
		int j = 0;
		while (my_paths[j])
		{
			printf(" \t my paths ---> %s \n",my_paths[j]);
			j++;
		}
	}
}

// int	main()
// {
// 	__pid_t pid;
// 	int		pfd[2];

// 	pipe(pfd);

// 	printf(">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<< \n");
// 	printf("I am a main process before fork. MyPId is -> %d \n", getpid());
// 			// create a chid process (fork)
// 	pid = fork();
// 	printf("--------------------    --------------- \n");
// 	printf("I am main process after fork. My PID is -> %d \n", getpid());
// 	if (pid < 0)
// 	{
// 		fprintf(stderr, "Fork2 failed \n");
// 		return 1;
// 	}
// 	else if (pid == 0)
// 	{
// 		printf("I am the child process! my PID is %d  and my childs PID is %d \n ", getpid(), pid);
// 		close(pfd[0]);
// 		write(pfd[1], "hola holita vecinitosss", 24);
// 		close(pfd[1]);
// 			exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		printf("I am the parent process, and my PID is %d, and the childs is %d \n", getpid(), pid);
// 		char str[24];
// 		close(pfd[1]);
// 		read(pfd[0], str, 24);
// 		printf("parent received --> %s \n", str);
// 		close(pfd[0]);
// 		wait(NULL);
// 	}
// 	return 0;
// }
