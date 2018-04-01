#include <unistd.h>

int main (int argc, char **argv)
{
	int tmp;
	int i;
	int cnt;
	int cntt;
	int cnttt;
	int last[2000000];
	int x;
	int er;

	x = 0;
	last[x] = 0;
	tmp = 0;
	i = 0;
	cnt = 0;
	cntt = 0;
	cnttt = 0;
	if (argc > 1)
	{
		while (++tmp < argc)
		{
			x = -1;	
			while (last[++x] < 2000000)
			last[x] = 0;	
			x = 0;
			i = 0;
			cnt = 0;
			cntt = 0;
			cnttt = 0;
			er = 0;

			while (argv[tmp][i])
			{
				if (argv[tmp][i] == '(')
				{
					cnt++;
					last[x++] = 1;				
				}
				if (argv[tmp][i] == '{')
				{
					cntt++;
					last[x++] = 2;
				}
				if (argv[tmp][i] == '[')
				{
					cnttt++;
					last[x++] = 3;
				}
				if (argv[tmp][i] == ')')
				{
					cnt--;
					if (last[--x] != 1)
						er = 1;
				}
				if (argv[tmp][i] == '}')
				{
					cntt--;
					if (last[--x] != 2)
						er = 1;
				}
				if (argv[tmp][i] == ']')
				{
					cnttt--;
					if (last[--x] != 3)
						er = 1;
				}
			++i;
			}
			if (cnt == 0 && cntt == 0 && cnttt == 0 && er == 0)
				write(1, "OK", 2);
			else
				write(1, "Error", 5);
			write(1, "\n", 1);
		}
		return (0);
	}
	else
	{
		write(1, "\n", 1);
		return (0);
	}
}
