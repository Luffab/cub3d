/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isdigit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 09:54:12 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 09:58:43 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	i;

	i = 0;
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}
