#include<stdio.h>
int num_input()
{
	int num;
	int ret;
	ret=scanf("%d",&num);
	while(ret!=1)
	{
		printf("错误：输入需为整数,请再次输入：");
		while(getchar()!='\n')
		{
			continue;
		}
		ret=scanf("%d",&num);
	}
	while(getchar()!='\n')
	{
		continue;
	}
	return num;
}

int main()
{
	printf("请输入两个值：");
	int low=0;
	int high=100;
	int low_input,high_input;
	low_input=num_input();
	high_input=num_input();
	int flag=((low<=low_input)&&(low_input<=high_input)&&(high_input<=high));
	while(1)
	{
		if(flag==0)
		{
			printf("");
			continue;
		}
	}
	/*while(!((low<=low_input)&&(low_input<=high_input)&&(high_input<=high)))
	{
		printf("输入的值不对，请再次输入：");
		low_input=num_input();
		high_input=num_input();
	}
	while(low_input)
	{
	
		
		
		printf("错误：成绩的取值范围为%d~%d,按任意键重新输入...\n",low,high);
		printf("要查询的成绩范围：");
		low_input=num_input();
		high_input=num_input();
		
	}
	
	while(low_input>high_input)
	{
		printf("错误：最高分要高于最低分！按任意键重新输入...\n");
		printf("要查询的成绩范围：");
		low_input=num_input();
		high_input=num_input();
	}*/
	if(low_input>high_input)
	{
		
	}
	
	
	
	
	
	
}