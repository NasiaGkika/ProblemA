#include <stdio.h> 
#include <math.h> 
#include <string.h>

int main()
{
    int     i, length, atg_position, atg_present, stop_position ;
    char    seq[5000];

		scanf( "%s", seq );

		atg_position = 0;
		atg_present = 0;
		stop_position = 0;
     		length = strlen( seq );

    		for ( i = 0 ; i < length - 2 ; i++ )
		{
			if ( (seq[i]) == 'A' && (seq[i + 1]) == 'T' && (seq[i + 2]) == 'G') 
				{
                			atg_present = 1;
					atg_position = i ;
				}
		}

     		if (atg_present == 1) 
		{
			for (i = atg_position + 3; i < length - 2; i += 3) 
			{
                		if ( (seq[i]) == 'T' && (seq[i + 1]) == 'A' && (seq[i + 2]) == 'A' ||
                    	     	(seq[i]) == 'T' && (seq[i + 1]) == 'A' && (seq[i + 2]) == 'G' ||
                             	(seq[i]) == 'T' && (seq[i + 1]) == 'G' && (seq[i + 2]) == 'A') 
					{
                    				stop_position = i + 2;
						break;
					}
			}

		}

		if (atg_present == 1 && stop_position != 0)
		{
            		printf("The sequence %s is a typical procaryotic coding sequennce. The starting position is %d and the ending position is %d.\n", seq , atg_position+1, stop_position+1 );
		}
		else
		{
        		printf("The sequence %s is not a typical procaryotic coding sequence.\n", seq);
		}
    return 0;

}
