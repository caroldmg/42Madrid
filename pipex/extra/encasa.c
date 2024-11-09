// pipex bonus

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	/* 
		Resumen de cómo gestiona las entradas y salidas:
El proceso hijo ejecuta un comando y su salida estándar se redirige al pipe (gracias a dup2(fd[1], STDOUT_FILENO)).
El proceso padre toma la salida del pipe (que es la entrada estándar para él, gracias a dup2(fd[0], STDIN_FILENO)) y puede leerla o procesarla.
	 */

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0) //proceso hijo
	{
		/* 
			close(fd[0]): En el proceso hijo, cerramos el extremo de lectura del pipe (fd[0]), ya que solo nos interesa escribir en el pipe. El proceso hijo no va a leer del pipe, solo va a escribir.

dup2(fd[1], STDOUT_FILENO): Usamos dup2 para redirigir la salida estándar (STDOUT_FILENO, que normalmente es la pantalla) hacia el extremo de escritura del pipe (fd[1]). Esto significa que cualquier cosa que el comando que se ejecute en el hijo imprima en la salida estándar, se enviará al pipe.

execute(argv, envp): Esta función ejecuta el comando que se le pasa en argv (y el entorno de variables de entorno en envp). Al haber redirigido la salida estándar al pipe, la salida de este comando no irá a la pantalla, sino al pipe.
		 */
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else //proceso padre
	{
		/* 
			close(fd[1]): En el proceso padre, cerramos el extremo de escritura del pipe (fd[1]), ya que solo nos interesa leer de él, no escribir. El proceso padre no va a escribir en el pipe, solo leer.

dup2(fd[0], STDIN_FILENO): Usamos dup2 nuevamente, pero ahora para redirigir la entrada estándar (STDIN_FILENO, que normalmente proviene del teclado) hacia el extremo de lectura del pipe (fd[0]). Esto significa que cualquier entrada que el proceso padre reciba de la entrada estándar vendrá del pipe (es decir, la salida del comando ejecutado por el hijo).

waitpid(pid, NULL, 0): El padre espera a que el hijo termine de ejecutar antes de continuar. Esto es importante para que el proceso padre no termine antes que el hijo, y también para evitar dejar procesos huérfanos
		 */
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