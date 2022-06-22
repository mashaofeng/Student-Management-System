#include<stdio.h>
#include<string.h>
#include"student_input.h"

int num_input(int num,int high,int low)
{
	int ret;
	ret=scanf("%d",&num);
	while((ret!=1)||((num<low)||(num>high)))
	{
		printf("����������Ϊ%d-%d������,���ٴ����룺",low,high);
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

char * deletblank(char a[])//ȥ���ַ�������Ļ��з���ǰ��ո�
{
	char * p1;
	char * p2;
	p1=a;
	p2=a+strlen(a)-1;
	while(p1 <= p2 && *p1 == ' ')
	{
		p1++;
	}
	while (p2 >= p1 && (*p2 == ' '||*p2 == '\n'))
	{
		p2--;
	}
	*(++p2) = '\0';
	return p1;	
	
}

char * get_name(char a[])//������ĺ���һ���ȡ����
{
	fgets(a,30,stdin);
	while(strlen(deletblank(a))==0)
	{
		fgets(a,30,stdin);
	}
	return a;
}


int input_student_ID()
{
	int ID;
	printf("����ѧ�ţ�");
	ID=num_input(ID,100,1);
	return ID;
}

struct student input_student(struct student ma)
{
	printf("����������");
	strcpy(ma.name,deletblank(get_name(ma.name)));		
	printf("�����Ա�M��ʾ�еģ�W��ʾŮ�ģ�");
	scanf("%c",&ma.gender);
	while(ma.gender!='M'&&ma.gender!='W')
	{
		printf("�����Ա�ֻ������W��M,���������룺");
		while(getchar()!='\n')
		{
			continue;
		}
		scanf("%c",&ma.gender);
	}
	while(getchar()!='\n')
	{
		continue;
	}
	
	printf("�������䣺");
	ma.age=num_input(ma.age,100,1);	
	printf("������ѧ�ɼ���");
	ma.math=num_input(ma.math,100,0);
	printf("�������ĳɼ���");
	ma.chinese=num_input(ma.chinese,100,0);	
	printf("����Ӣ��ɼ���");
	ma.english=num_input(ma.english,100,0);
	return ma;
	
}

int flag_set(int n,int a[],int N)
{
	int flag=0;
	int i=0;
	while(i<N)
	{
		if(a[i]==n)
		{
			flag=1;
			i++;
		}
		else
		{
			i++;
			continue;
		}
	}
	return flag;
}

int input_all()
{
	FILE * fp=NULL;
	
	int n;
	n=read_line_num();
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=0;
	}
	int *p;
	p=get_ID_list(n,a);
	for(int i=0;i<n;i++)
	{
		a[i]=p[i];
	}
	struct student xiao;
	xiao.ID=input_student_ID();
	int flag;
	flag=flag_set(xiao.ID,a,n);
	while(flag)
	{
		printf("�������ID�Ѵ��ڣ�����������\n");
		xiao.ID=input_student_ID();
		flag=flag_set(xiao.ID,a,n);
	}
	xiao=input_student(xiao);
	fp=fopen("data.txt","at+");
	fprintf(fp,"%d,%s,%c,%d,%d,%d,%d,%d\n",xiao.ID,xiao.name,xiao.gender,
		xiao.age,xiao.math,xiao.chinese,xiao.english,xiao.math+xiao.chinese+xiao.english);
	
	fclose(fp);	
}
