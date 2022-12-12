#include<stdio.h>
#include<string.h>

void isPalindromic(char str[],int len)
{
	int judge = 1;
	while (len>1)
	{
		if(str[0] != str[len - 1])
		{
			judge = 0;
			break;
		}
		
		isPalindromic(str+1, len - 2);
		
	}
	if (judge == 1)
	{
		printf("是回文字符串");
	}
	else
	{
		printf("不是回文字符串");
	}
}

int main()
{
	char str[] = "abcdcba";
	int len = strlen(str);
	isPalindromic(str, len);
	return 0;
}