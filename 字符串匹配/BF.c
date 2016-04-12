int Search_Reverse(const char *Source,const char *SubString)     //常规BF算法
{
	int SourceArry = strlen(Source);                             //主字符串的长度
	int SubArry = strlen(SubString);                             //子字符串的长度

	int pSub;						      						 //pSub 为字串匹配数量(0为完全匹配)
	int pSour =  SubArry;                                        //pSour 开始匹配的位置(从字串末尾开始匹配)

	if(SubArry==0)
		return -1;

	while(pSour <= SourceArry)                                   //主字符串是否到了尽头             
	{   
		pSub = SubArry;                                          //初始化
		while(SubString[--pSub]==Source[--pSour])                //进行匹配比较
		{
			if(pSour < 0)  
				return -1;                   				     //如果pSour,以子串长度为一组的主串扫描结束

			if(pSub == 0) 
				return  pSour;                				     //为0,匹配成功

		}
		pSour += (SubArry - pSub) +1 ;                           //进行偏移,pSour值进行恢复与回溯,SubArry - pSub为以前减去的值补回

	}

	return -1;
}

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		printf("Please input two string\nThe first is SourceString\nand the second is SubString\n");
		return -1;
	}

	printf(">>>>>>>>>>>>>>>>>>>>%d\n", Search_Reverse(argv[1], argv[2]));

	return 0;
}
