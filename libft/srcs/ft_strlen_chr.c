/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:08:19 by psprawka          #+#    #+#             */
/*   Updated: 2017/10/02 15:08:22 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strlen_chr(char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}