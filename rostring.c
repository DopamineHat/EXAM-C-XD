# include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int space;
	int b;

	b = 1;
	space = 0;
	i = 0;
	if (argc > 1)
	{
		while(argv[1][i] == ' ' || argv[1][i] == '\t')
			++i;
		while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			++i;
		while(argv[1][i] == ' ' || argv[1][i] == '\t')
			++i;
		if (!(argv[1][i]))
			b = 0;
		while(argv[1][i])
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				++i;
				space = 1;
			}
			if (space == 1)
			{
				if (argv[1][i])
					write(1, " ", 1);
				--i;
			}
			else if (argv[1][i])
				write(1, &argv[1][i], 1);
			++i;
			space = 0;
		}
		i = 0;
		while(argv[1][i] == ' ' || argv[1][i] == '\t')
			++i;
		if (b == 1)
			write(1, " ", 1);
		while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}
