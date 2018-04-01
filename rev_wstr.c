#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int b;
	int n;
	char *rev;
	int tmp;
	int pos;

	b = 1;
	pos = 0;
	tmp = 0;
	n = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][n])
		++n;
	rev = malloc(sizeof(char) * (n + 1));
	while (n > 0)
	{
		--n;
		rev[n] = 0;
	}
	while (argv[1][n])
		++n;
	--n;
	while (argv[1][n])
	{
		if (argv[1][n] == ' ')
		{
			if (b == 0)
			{
				tmp = n;
				++n;
				while (argv[1][n] && argv[1][n] != ' ')
				{
					rev[pos] = argv[1][n];
					++n;
					++pos;
				}
				rev[pos++] = ' ';
				n = tmp;
			}
			b = 1;
		}
		else
			b = 0;
		--n;
	}
	if (b == 0)
	{
		tmp = n;
		++n;
		while (argv[1][n] && argv[1][n] != ' ')
		{
			rev[pos] = argv[1][n];
			++n;
			++pos;
		}
		rev[pos++] = '\0';
		n = tmp;
	}
	++n;
	while(rev[n])
	{
		write(1, &rev[n], 1);
		++n;
	}
	write(1, "\n", 1);
	return (0);
}
