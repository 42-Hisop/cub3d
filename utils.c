#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void	*error(void)
{
	write(1, "error", 5);
	exit(1);
}

int		ft_atoi(char *s)
{
	unsigned long long		num;	
	int		i;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (!('0' <= s[i] && s[i] <= '9'))
			error();
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (num < 0)
		error();
	if (num > INT_MAX)
		error();
	return (num);
}

int		itorgb(int r, int g, int b)
{
	int		num;

	num = 0;
	if (256 <= r || 256 <= g || 256 <= b)
		error();
	num = num + (r << 16);
	num = num + (g << 8);
	num = num + b;
	return (num);
}
