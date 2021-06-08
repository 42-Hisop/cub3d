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

void	make_hex(char *hex)
{
	int		i;
	char	a;

	i = 0;
	a = '0';
	while (i < 16)
	{
		hex[i] = a;
		i++;
		a++;
		if (i == 10)
			a = 'A';
	}
}

char	*ft_itoh(int num, char *rgb, int i)
{
	char	hex[16];

	make_hex(hex);
	if (num <= 16)
	{
		rgb[i - 1] = '0';
	}
	if (num == 0)
	{
		rgb[i] = '0';
		return (rgb);
	}
	while (num > 0)
	{
		rgb[i] = hex[num % 16];
		num = num / 16;
		i--;
	}
	return (rgb);
}


char	*itorgb(int r, int g, int b)
{
	char	*rgb;

	if (256 <= r || 256 <= g || 256 <= b)
		error();
	if (!(rgb = (char *)malloc(sizeof(char) * 9)))
		error();
	rgb[0] = '0';
	rgb[1] = 'x';
	rgb = ft_itoh(r, rgb, 3);
	rgb = ft_itoh(g, rgb, 5);
	rgb = ft_itoh(b, rgb, 7);
	rgb[8] = '\0';
	return (rgb);
}
