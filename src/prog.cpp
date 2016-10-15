//test input
#include <stdio.h>							
int main()								
{
	int a = 0;
	printf("Enter a number:");
	scanf("%d",&a);
	if(a == 0){
		printf("a = 0\n");
	}
	printf("The number you entered is:%d",a);
}