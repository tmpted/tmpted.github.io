//#include <stdio.h>
//#include <math.h>
//#include <string.h>

//int main()
//{
//	int a,b;
//	char c;
//	char input[256];
//
//	printf("please enter\n");
//	
//	for(;;)
//	{
//		for (int i=0; i<256; i++) input[i] = 0;
//		gets (input);
//		if(strcmp ("quit", input) == 0) break;
//		
//		sscanf(input, "%d %c %d", &a, &c, &b);
//		printf("%d %c %d", a, c, b);
//		
//		if(c == '+')printf(" = %d\n\n", a + b);
//		else if(c == '-')printf(" = %d\n\n", a - b);
//		else if(c == '*')printf(" = %d\n\n", a * b);
//		else if(c == '/')printf(" = %d\n\n", a / b);
//		else printf("\nerror\n\n");
//	}
//}