// pipex bonus

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strcmp(argv[1], "here_doc") == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
        //revisar esto de aqui
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	usage();
}

//quiero hacer esto pero creando mi archivo here_doc, como en el ultimo de los hijos

void    here_doc(char *limit, int argc)
{
    pid_t   read;
    int     file[2];
    char    *line;
    if (argc < 6)
        return (error);
    if (pipe(file) < 0)
        error();
    read = fork();
    if (read == 0)
	{
		close(file[0]);
		while (get_next_line(&line))
		{
			if (ft_strcmp(line, limit) == 0)
				exit(EXIT_SUCCESS);
			write(file[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(file[1]);
		dup2(file[0], STDIN_FILENO);
		wait(NULL);
	}
    
}