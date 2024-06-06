#include"header.h"
void main()
{
	int i;
	printf("Hello..\n");
	for(i=0;i<3;i++)
	{
		if(fork()==0)
		{
			printf("Child..\n");
	//		break;     //only 3 process created all from parent like  q(parent)
									//	 /    |   \
									//	q+1  q+2  q+3	
		}
		else
		{
			printf("Parent..\n");
//			break;	//only 3 process is created like q-->q+1-->q+2-->q+3
		}	
	}
	while(1);
}
/*


q	              q+1	         q+2		    q+3
i=0----------------->i=0/ 1------------>i=1/ 2------------->i=2/ 3(~~over)
i=1--------------    i=2------------    i=3(~~over)
i=2------       |	           |
i=3     |       | 	           |
(over)  |       V 	           V
        V      q+5                 q+4
       q+7     i=1/ 2-----         i=2/ 3(~~over)
       i=2/    i=3(over) |
      3(over)            |
                         V
                        q+6
                        i=2/ 3(~~over)

*/
