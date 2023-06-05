/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:51 by biaroun           #+#    #+#             */
/*   Updated: 2023/06/05 15:24:53 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_control_seq(int c)
{
	struct termios	conf;

	ioctl(ttyslot(), TIOCGETA, &conf);
	if (c == 1)
		conf.c_lflag |= ECHOCTL;
	else if (c == 0)
		conf.c_lflag &= ~(ECHOCTL);
	ioctl(ttyslot(), TIOCSETA, &conf);
}
