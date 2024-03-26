#include "server.h"

char	*message;

static void	signal_to_str(int sig)
{
	static int	n = 0;
	static char	c = 0;
	static int	size;

	if (n < 8*4)
	{
		if (sig == SIGUSR2)
			size = size | 1;
		size = size << 1;
	}
	else if (n == 8*4)
	{
		ft_putnbr(size);
		message = (char *)malloc(sizeof(char) * (size + 1));
		message[size] = 0;
	}
	else
	{
		if (n % 8 == 0)
		{
			message[(n / 8) - 1] = c;
			c = 0;
		}
		if (sig == SIGUSR2)
			c = c | 1;
		c = c << 1;
	}
	n++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID : ");
	ft_putnbr(pid);
	ft_printf("\n");
	signal(SIGUSR1, signal_to_str);
	signal(SIGUSR2, signal_to_str);
	pause();
}