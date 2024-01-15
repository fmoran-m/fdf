int	count_words(char const *s, unsigned char c)
{
	int	flag;
	int	i;
	int n;

	flag = 1;
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
		{
			n++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (n);
}
