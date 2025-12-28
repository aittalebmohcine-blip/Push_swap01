#include <limits.h>

//this file is for checking whether a token is valid
//meaning, is it a vlid int representation
//would it overflow if passed to atoi()
int	valid_representation(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '-' || token[i] == '+')
		i++;
	if (!token[i])
		return (0);
	while(token[i] >= '0' && token[i] <= '9')
		i++;
	if (!token[i])
		return (1);
	return (0);
}

//0 means overflow
//else no overflow
int	token_overflow(char *token)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*token == '+' || *token == '-')
	{
		if (*token == '-')
			sign = -1;
		token++;
	}
	while (*token)
	{
		result = result * 10 + (*token - '0');
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && -result < INT_MIN)
			return (0);
		token++;
	}
	return (1);
}

int	validate_tokens(char **tokens)
{
	int	i;

	i = 0;
	int count = 0;
	while (tokens[count])
		count++;
	while (i < count)
	{
		if (!valid_representation(tokens[i]))
			return(0);
		if (!token_overflow(tokens[i]))
			return(0);
		i++;
	}
	return(1);
}
