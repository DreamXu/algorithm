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

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		printf("please input a string\n");
		return -1;
	}

	int a[100];
	get_nextval(argv[1], a);
	get_nextval1(argv[1], a);
	return 0;
}
