#include <conio2.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char a[12];
	fflush(stdin);
	gets(a);
	strupr(a);
	printf("%s",a);
	return 0;
}
