#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>

void	on_error()
{
	//write error to fd=2
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	//arg != int || arg>int_max || duplicates => error
	//	error => display "Error\n" (error output : fd=2)

	// no params => display nothing
	if(ac == 1)
	{
		return 0;
	}

	// split eache arg
	else
  {
		printf("there is some arguments !");
  }
}
