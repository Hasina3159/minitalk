#include "client.h"

void    ft_str_to_signal(char *s, int pid)
{
    int_to_signal(ft_strlen(s), pid);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_str_to_signal(ft_atoi(argv[1]), argv[2]);
	}
    return (0);
} 