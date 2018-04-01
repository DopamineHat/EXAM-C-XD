void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int x;
	int tmp;

	i = 0;
	tmp = 0;
	x = 0;
	while (x < size)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
			   	tab[i + 1] = tmp;
			}
			++i;
		}
		i = 0;
		++x;
	}
}
