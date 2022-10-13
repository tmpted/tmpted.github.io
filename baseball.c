#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int number[3] = {0, 0, 0};
	int digit[3] = {0, 0, 0};
		
		for(;;)
		{
			srand(time(NULL));     // 랜덤기능을 초기화한다
			digit[0] = rand()%10;  // 랜덤 숫자를 받는다.
			digit[1] = rand()%10;  // 랜덤 숫자를 받는다.
			digit[2] = rand()%10;  // 랜덤 숫자를 받는다.
			
			if((digit[0] == digit[1]) || (digit[0] == digit[2]) || (digit[1] == digit[2])) continue;
			if((digit[0] != digit[1]) || (digit[0] != digit[2]) || (digit[1] != digit[2])) break;
		}
		
		printf("%d %d %d\n", digit[0], digit[1], digit[2]);
	
		printf("type 3 number \n");
		for(;;)
		{
			scanf("%d %d %d", &number[0], &number[1], &number[2]);
			
			if((number[0] > 9) || (number[1] > 9) || (number[2] > 9))
			{
				printf("fail\n");
				continue;
			}
			
			if((number[0] < 0) || (number[1] < 0) || (number[2] < 0))
			{
				printf("fail\n");
				continue;
			}
			
			if((number[0] == number[1]) || (number[0] == number[2]) || (number[1] == number[2]))
			{
				printf("fail\n");
				continue;
			}
			printf("%d %d %d\n", number[0], number[1], number[2]);
			
			if((number[0] == digit[0]) && (number[1] == digit[1]) && (number[2] == digit[2]))
			{
				printf("3strike\n");
				break;
			}
			else if((number[0] == digit[0]) && (number[1] == digit[1]))
			{
				printf("2strike\n");
			}
			else if((number[0] == digit[0]) && (number[2] == digit[2]))
			{ 
				printf("2strike\n");
			}
			else if((number[1] == digit[1]) && (number[2] == digit[2]))
			{ 
				printf("2strike\n");
			}
			else if(number[0] == digit[0])
			{
				printf("1strike\n");
			}
			else if(number[1] == digit[1])
			{
				printf("1strike\n");
			}
			else if(number[2] == digit[2])
			{
				printf("1strike\n");
			}
			
			if((number[0] == digit[1] || number[0] == digit[2]) && (number[1] == digit[0] || number[1] == digit[2]) && (number[2] == digit[0] || number[2] == digit[1]))
			{
				printf("3ball\n");
			}
			else if((number[0] == digit[1] || number[0] == digit[2]) && (number[1] == digit[0] || number[1] == digit[2]))
			{	
				printf("2ball\n");
			}
			else if((number[0] == digit[1] || number[0] == digit[2]) && (number[2] == digit[0] || number[2] == digit[1]))
			{	
				printf("2ball\n");
			}
			else if((number[1] == digit[0] || number[1] == digit[2]) && (number[2] == digit[0] || number[2] == digit[1]))
			{	
				printf("2ball\n");
			}
			else if(number[0] == digit[1] || number[0] == digit[2])
			{
				printf("1ball\n");
			}
			else if(number[1] == digit[0] || number[1] == digit[2])
			{
				printf("1ball\n");
			}
			else if(number[2] == digit[0] || number[2] == digit[1])
			{
				printf("1ball\n");
			}
			
			if(((number[0] != digit[0]) && (number[1] != digit[1]) && (number[2] != digit[2])) && ((number[0] != digit[1] && number[0] != digit[2]) && (number[1] != digit[0] && number[1] != digit[2]) && (number[2] != digit[0] && number[2] != digit[1])))
			{
				printf("out\n");
			}
		}
}