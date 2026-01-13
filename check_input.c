/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:33:18 by mgoguely          #+#    #+#             */
/*   Updated: 2026/01/13 15:35:48 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*check_input(char **argv)
{
	int	*num;

	check_syntaxe(argv);
	num = convert_numbers(argv);
	check_doublons(num, argv);
	return (num);
}

void	check_syntaxe(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
			j++;
		if (argv[i][j] != '\0')
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	return ;
}

int	*convert_numbers(char **argv)
{
	int		*num;
	long	n;
	int		i;

	i = size_tab(argv);
	num = malloc(sizeof(int) * i);
	if (!num)
		exit(1);
	i = 0;
	while (argv[i])
	{
		n = ft_atoi_long(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_printf("Error\n");
			free (num);
			exit(1);
		}
		num[i] = n;
		i++;
	}
	return (num);
}

int	size_tab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	check_doublons(int *num, char **argv)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = size_tab(argv);
	while (i < s)
	{
		j = i + 1;
		while (j < s)
		{
			if (num[j] == num[i])
			{
				ft_printf("Error\n");
				free(num);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return ;
}
