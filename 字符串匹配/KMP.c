#include <stdio.h>
#include <string.h>

void get_nextval(const char *T, int next[])
{
	// 求模式串T的next函数值并存入数组 next。
	int j = 0, k = -1;
	next[0] = -1;
	while ( T[j] != 0 )
	{
		if (k == -1 || T[j] == T[k])
		{
			++j; 
			++k;
			if (T[j]!=T[k])
				next[j] = k;
			else
				next[j] = next[k];
		}// if
		else
			k = next[k];
	}

	int i;
	for(i=0;i<j;i++)
	{
		printf("%c\t", T[i]);
	}
	putchar(10);
	for(i=0;i<j;i++)
	{
		printf("%d\t", next[i]);
	}
	putchar(10);
}


void get_nextval1(const char *T, int next[])
{
	int j = 1, k = 0;
	//int len = 0;
	next[0] = -1;
	while ( T[j] != 0 )
	{
		if (T[k] == T[j]) {
			if (0 == /*len*/k) {
				next[j] = -1;	
			}
			//++len;	
			++k;
			++j;	
		}
		else {
			next[j] = /*len*/k;
			//len = 0;
			k = 0;
			++j;
		}
	}

	int i;
	for(i=0;i<j;i++)
	{
		printf("%d\t", next[i]);
	}
	putchar(10);
}

int KMP(const char *Text,const char* Pattern)
{
	if (strlen(Text) < strlen(Pattern) || NULL == Text || NULL == Pattern) {
		return -1;
	}

	const char *c = Pattern;
	int len = strlen(Pattern);
	int * next = (int)malloc(len);

	get_nextval(Pattern, next);

	int index = 0, i = 0, j = 0;
	while (Text[i] != 0 && Pattern[j] != 0) {
		if (Text[i] == Pattern[j]) {
			++i;
			++j;
		}
		else {
			index += j - next[j];
			if(next[j] != -1)
				j = next[j];
			else {
				j = 0;
				++i;
			}
		}
	}
	
	free(next);

	if (Pattern[j] == 0)
		return index;
	else
		return -1;

}

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		printf("please input two string\n");
		return -1;
	}

	printf("---->>>>>>>>%d\n", KMP(argv[1], argv[2]));
}
