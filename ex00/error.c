/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:35:25 by mijang            #+#    #+#             */
/*   Updated: 2024/09/22 13:44:59 by mijang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


//Check the parameters
int	param(int argc, char **argv, int *views)
{
	char	p;
	int		i;

	//check 2 nombers(including name of file and first param)
	if	(argc != 2)
		return (1);
	
	//like strlen -> must be 31 caracters in the string
	//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	p = argv[1];
	while (p != '\0')
		 p++;
	if (p - argv[1] != 31)
		return (2);
	
	//checks the 16 number caracters one by one & their separators
	p = argv[1];
	i = 0;
	while (i < 16)
	{
		//check if separator = space
		if (*(p + 1) != ' ' && i < 15)
            		return (3);
        	
		//checks if caracter is number caracter 1,2,3 or 4
		if (*p != '1' && *p != '2' && *p != '3' && *p != '4')
            		return (4);
        	
		//everything is OK here
		
		//stores the expected view number in "views" array
		views[i++] = *p - '0';
        	
		//shifts 2 places ahead
		p += 2;
	}
	return (0);
}


//===Check incoming parameters===
//	Return error codes:
//		Err1) No arguments or too many
//      	Err2) Argument string too long or too short
//      	Err3) Wrong view numbers separator
//      	Err4) Error in view numbers
//      	Err5) No solution found(found by main() )
