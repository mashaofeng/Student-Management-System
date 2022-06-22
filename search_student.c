#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student_input.h"

int searchPage()
{
	int n;
	n=read_line_num();
	printf("**************************查询学生信息（当前共有%d名学生）***************************\n",n);
	printf("*                                                                                   *\n");
	printf("*                         1）根据学号查询                                           *\n");
	printf("*                         2）根据姓名查询                                           *\n");
	printf("*                         3）根据数学成绩查询                                       *\n");
	printf("*                         4）根据语文成绩查询                                       *\n");
	printf("*                         5）根据英语成绩查询                                       *\n");
	printf("*                         6）根据总成绩查询                                         *\n");
	printf("*                         0）返回主菜单                                             *\n");
	printf("*************************************************************************************\n");
	printf("请输入选项：");
}

int search_by_ID(int a[],int n)
{
	int num,i;
	int flag=0;
	struct student xiao1;
	FILE *fp=NULL;
	fp=fopen("data.txt","at+");
	char buf[40];

	int set;
	num=input_student_ID();
	for(i=0;i<n;i++)
	{
		if(num==a[i])
		{
			flag=1;
			set=i;
			break;
		}
	}
	if(flag==0)
	{
		printf("错误：该学生信息不存在，查询失败！按任意键返回...");
		getchar();
	}
	else
	{
		printf("----------------------------------------------------------------------------------------\n");
		printf("   学号   |   姓名   |   性别   |   年龄   |   数学   |   语文   |   英语   |   总成绩  \n");
		printf("----------+----------+----------+----------+----------+----------+----------+-----------\n");
		for(i=0;i<set;i++)
		{
			fgets(buf,sizeof(buf),fp);
		}
		fgets(buf,sizeof(buf),fp);
		xiao1=get_list(xiao1,buf);
		printf("   %-7d|%-10s|   %-7c|   %-7d|   %-7d|   %-7d|   %-7d|   %-7d\n",xiao1.ID,xiao1.name,xiao1.gender,xiao1.age,
		xiao1.math,xiao1.chinese,xiao1.english,xiao1.math+xiao1.chinese+xiao1.english);
		printf("----------------------------------------------------------------------------------------\n");
		printf("按任意键返回...");
		getchar();
	}
	fclose(fp);

}


int search_by_name(int n)
{
	int i;
	char name[30];
	int flag=0;
	struct student xiao1;
	FILE *fp=NULL;
	fp=fopen("data.txt","at+");
	char buf[40];
	int set;
	
	printf("输入姓名：");
	strcpy(name,deletblank(get_name(name)));
	for(i=0;i<n;i++)
	{
		fgets(buf,sizeof(buf),fp);
		xiao1=get_list(xiao1,buf);
		if(strcmp(xiao1.name, name)==0)
		{
			flag=1;
			set=i;
			break;
		}
	}
	fclose(fp);
	FILE *fp1=NULL;
	fp1=fopen("data.txt","at+");
	if(flag==0)
	{
		printf("错误：该学生信息不存在，查询失败！按任意键返回...");
		getchar();
	}
	else
	{
		printf("----------------------------------------------------------------------------------------\n");
		printf("   学号   |   姓名   |   性别   |   年龄   |   数学   |   语文   |   英语   |   总成绩  \n");
		printf("----------+----------+----------+----------+----------+----------+----------+-----------\n");
		for(i=0;i<set;i++)
		{
			fgets(buf,sizeof(buf),fp1);
		}
		fgets(buf,sizeof(buf),fp1);
		xiao1=get_list(xiao1,buf);
		printf("   %-7d|%-10s|   %-7c|   %-7d|   %-7d|   %-7d|   %-7d|   %-7d\n",xiao1.ID,xiao1.name,xiao1.gender,xiao1.age,
		xiao1.math,xiao1.chinese,xiao1.english,xiao1.math+xiao1.chinese+xiao1.english);
		printf("----------------------------------------------------------------------------------------\n");
		printf("按任意键返回...");
		getchar();
	}
	fclose(fp1);

}

int num_input_single()
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

int two_num_input(int * a,int *b)
{
	printf("请输入两个值：");
	int low_input,high_input;
	low_input=num_input_single();
	high_input=num_input_single();
	int flag=((*a<=low_input)&&(low_input<=*b)&&(high_input<=*b)&&(*a<=high_input));
	while(1)
	{
		if(flag==0)
		{
			printf("输入需要在%d~%d范围内，按任意键重新输入：\n",*a,*b);
			getchar();
			while(getchar()!='\n')
			{
				continue;
			}
			printf("请输入两个值：");
			low_input=num_input_single();
			high_input=num_input_single();
			flag=((*a<=low_input)&&(low_input<=*b)&&(high_input<=*b)&&(*a<=high_input));
			continue;
		}
		else
		{
			if(low_input>high_input)
			{
				printf("先输入的值不能超过后输入的值，请按任意键重新输入：\n");
				getchar();
				while(getchar()!='\n')
				{
					continue;
				}
				printf("请输入两个值：");
				low_input=num_input_single();
				high_input=num_input_single();
				flag=((*a<=low_input)&&(low_input<=*b)&&(high_input<=*b)&&(*a<=high_input));
				continue;
			}
			else
			{
				break;
			}
		}
	}
	*a=low_input;
	*b=high_input;
}

int search_by_num(int a[],int n,int type)
{
	int low,high,i,j;
	int k=0;
	j=0;
	struct student xiao1;
	switch(type)
	{
		case 1:low=0;high=100;printf("要查询的成绩范围：");two_num_input(&low,&high);;break;
		case 2:low=0;high=100;printf("要查询的成绩范围：");two_num_input(&low,&high);break;
		case 3:low=0;high=100;printf("要查询的成绩范围：");two_num_input(&low,&high);break;
		case 4:low=0;high=300;printf("要查询的成绩范围：");two_num_input(&low,&high);break;
	}
	
	for(i=0;i<n;i++)
	{
		if((a[i]>=low)&&(a[i]<=high))
		{
			k++;
		
		}
	}
	if(k==0)
	{
		printf("错误：没有查询到相关记录！按任意键返回...");
		getchar();
	}
	else
	{
		int list[k];
		for(i=0;i<n;i++)
		{
			if((a[i]>=low)&&(a[i]<=high))
			{
				list[j]=i;
				j++;
			}
		}
		FILE *fp=NULL;
		fp=fopen("data.txt","at+");
		char buf[40];
		i=0;
		j=0;
		printf("----------------------------------------------------------------------------------------\n");
		printf("   学号   |   姓名   |   性别   |   年龄   |   数学   |   语文   |   英语   |   总成绩  \n");
		printf("----------+----------+----------+----------+----------+----------+----------+-----------\n");
		for(i=0;i<n;i++)
		{
			if(list[j]==i)
			{
				fgets(buf,sizeof(buf),fp);
				xiao1=get_list(xiao1,buf);
				printf("   %-7d|%-10s|   %-7c|   %-7d|   %-7d|   %-7d|   %-7d|   %-7d\n",xiao1.ID,xiao1.name,xiao1.gender,xiao1.age,
				xiao1.math,xiao1.chinese,xiao1.english,xiao1.math+xiao1.chinese+xiao1.english);
				j++;
			}
			else
			{
				fgets(buf,sizeof(buf),fp);
				continue;
			}		
		}
		printf("----------------------------------------------------------------------------------------\n");
		printf("按任意键返回...");
		getchar();
		fclose(fp);
	}

}

int search_by_student()
{
	int n;
	n=read_line_num();
	struct student xiao1;
	struct student xiao[n];
	int i;
	int ID_list[n];
	char gender_list[n];
	int age_list[n];
	int math_list[n];
	int chinese_list[n];
	int english_list[n];
	int total_list[n];
	back_list(n,xiao,ID_list,age_list,math_list,chinese_list,english_list,total_list);
	searchPage();
	int choose;
	choose=input_int(choose ,0,6);
	while(choose)
	{
		
		switch (choose)
		{
			case 1:search_by_ID(ID_list,n);break;
			case 2:search_by_name(n);break;
			case 3:search_by_num(math_list,n,1);break;
			case 4:search_by_num(chinese_list,n,2);break;
			case 5:search_by_num(english_list,n,3);break;
			case 6:search_by_num(total_list,n,4);break;
			
		}
		system("cls");
		searchPage();
		choose=input_int(choose ,0,6);
	}
	
}