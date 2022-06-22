#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student_input.h"

int searchPage()
{
	int n;
	n=read_line_num();
	printf("**************************��ѯѧ����Ϣ����ǰ����%d��ѧ����***************************\n",n);
	printf("*                                                                                   *\n");
	printf("*                         1������ѧ�Ų�ѯ                                           *\n");
	printf("*                         2������������ѯ                                           *\n");
	printf("*                         3��������ѧ�ɼ���ѯ                                       *\n");
	printf("*                         4���������ĳɼ���ѯ                                       *\n");
	printf("*                         5������Ӣ��ɼ���ѯ                                       *\n");
	printf("*                         6�������ܳɼ���ѯ                                         *\n");
	printf("*                         0���������˵�                                             *\n");
	printf("*************************************************************************************\n");
	printf("������ѡ�");
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
		printf("���󣺸�ѧ����Ϣ�����ڣ���ѯʧ�ܣ������������...");
		getchar();
	}
	else
	{
		printf("----------------------------------------------------------------------------------------\n");
		printf("   ѧ��   |   ����   |   �Ա�   |   ����   |   ��ѧ   |   ����   |   Ӣ��   |   �ܳɼ�  \n");
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
		printf("�����������...");
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
	
	printf("����������");
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
		printf("���󣺸�ѧ����Ϣ�����ڣ���ѯʧ�ܣ������������...");
		getchar();
	}
	else
	{
		printf("----------------------------------------------------------------------------------------\n");
		printf("   ѧ��   |   ����   |   �Ա�   |   ����   |   ��ѧ   |   ����   |   Ӣ��   |   �ܳɼ�  \n");
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
		printf("�����������...");
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

int two_num_input(int * a,int *b)
{
	printf("����������ֵ��");
	int low_input,high_input;
	low_input=num_input_single();
	high_input=num_input_single();
	int flag=((*a<=low_input)&&(low_input<=*b)&&(high_input<=*b)&&(*a<=high_input));
	while(1)
	{
		if(flag==0)
		{
			printf("������Ҫ��%d~%d��Χ�ڣ���������������룺\n",*a,*b);
			getchar();
			while(getchar()!='\n')
			{
				continue;
			}
			printf("����������ֵ��");
			low_input=num_input_single();
			high_input=num_input_single();
			flag=((*a<=low_input)&&(low_input<=*b)&&(high_input<=*b)&&(*a<=high_input));
			continue;
		}
		else
		{
			if(low_input>high_input)
			{
				printf("�������ֵ���ܳ����������ֵ���밴������������룺\n");
				getchar();
				while(getchar()!='\n')
				{
					continue;
				}
				printf("����������ֵ��");
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
		case 1:low=0;high=100;printf("Ҫ��ѯ�ĳɼ���Χ��");two_num_input(&low,&high);;break;
		case 2:low=0;high=100;printf("Ҫ��ѯ�ĳɼ���Χ��");two_num_input(&low,&high);break;
		case 3:low=0;high=100;printf("Ҫ��ѯ�ĳɼ���Χ��");two_num_input(&low,&high);break;
		case 4:low=0;high=300;printf("Ҫ��ѯ�ĳɼ���Χ��");two_num_input(&low,&high);break;
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
		printf("����û�в�ѯ����ؼ�¼�������������...");
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
		printf("   ѧ��   |   ����   |   �Ա�   |   ����   |   ��ѧ   |   ����   |   Ӣ��   |   �ܳɼ�  \n");
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
		printf("�����������...");
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