#include<stdio.h>
int num_input()
{
	int num;
	int ret;
	ret=scanf("%d",&num);
	while(ret!=1)
	{
		printf("����������Ϊ����,���ٴ����룺");
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
	printf("����������ֵ��");
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
		printf("�����ֵ���ԣ����ٴ����룺");
		low_input=num_input();
		high_input=num_input();
	}
	while(low_input)
	{
	
		
		
		printf("���󣺳ɼ���ȡֵ��ΧΪ%d~%d,���������������...\n",low,high);
		printf("Ҫ��ѯ�ĳɼ���Χ��");
		low_input=num_input();
		high_input=num_input();
		
	}
	
	while(low_input>high_input)
	{
		printf("������߷�Ҫ������ͷ֣����������������...\n");
		printf("Ҫ��ѯ�ĳɼ���Χ��");
		low_input=num_input();
		high_input=num_input();
	}*/
	if(low_input>high_input)
	{
		
	}
	
	
	
	
	
	
}