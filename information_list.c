#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student_input.h"
void swap_num(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

struct student get_list(struct student ma,char str[])
{
	char *token;
	char ID[20];
	token=strtok(str,",");
	strcpy(ID,token);
	ma.ID=atoi(ID);
	int i=1;
	char s[2]=",";
	while(i<7)
	{
		
		switch(i)
		{
			case 1:token = strtok(NULL, s);strcpy(ma.name,token);break;
			case 2:token = strtok(NULL, s);strcpy(ID,token);ma.gender=ID[0];break;
			case 3:token = strtok(NULL, s);ma.age=atoi(token);break;
			case 4:token = strtok(NULL, s);ma.math=atoi(token);break;
			case 5:token = strtok(NULL, s);ma.chinese=atoi(token);break;
			case 6:token = strtok(NULL, s);ma.english=atoi(token);break;
			default :break;
		}
		i++;		
	}
	return ma;
}

int * sort_back(int a[],int N,int sort[])
{
	int i,j;
	int p[N];
	for (i=0;i<N;i++)
	{
		p[i]=a[i];
	}
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(a[i]>a[j])
			{
				swap_num(&a[i],&a[j]);
			}
		}
	}
	
	for(i=0;i<N;i++)
	{
		j=0;
		while(a[i]!=p[j])
		{
			j++;
		}
		sort[i]=j;	
			
	}
	return sort;
}

float average(int a[],int n)
{
	float sum=0;
	float ave;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	ave=sum/n;
	return ave ;
}


int * back_list(int n,struct student xiao[],int ID_list[],int age_list[],int math_list[],int chinese_list[],int english_list[],int total_list[])
{
	FILE *fp=NULL;
	fp=fopen("data.txt","at+");
	char buf[40];
	int i;
	for(i=0;i<n;i++)
	{
		fgets(buf,sizeof(buf),fp);
		xiao[i]=get_list(xiao[i],buf);
		ID_list[i]=xiao[i].ID;
		age_list[i]=xiao[i].age;
		math_list[i]=xiao[i].math;
		chinese_list[i]=xiao[i].chinese;
		english_list[i]=xiao[i].english;
		total_list[i]=xiao[i].math+xiao[i].chinese+xiao[i].english;
	}
	fclose(fp);
}

char * back_gender(int n,struct student xiao[],char gender_list[])
{
	FILE *fp=NULL;
	fp=fopen("data.txt","at+");
	char buf[40];
	int i;
	for(i=0;i<n;i++)
	{
		fgets(buf,sizeof(buf),fp);
		xiao[i]=get_list(xiao[i],buf);
		gender_list[i]=xiao[i].gender;
	}
	fclose(fp);
}




int list_all()
{
	int n;
	n=read_line_num();
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
	back_gender(n,xiao,gender_list);
	printf("----------------------------------------------------------------------------------------\n");
	printf("   学号   |   姓名   |   性别   |   年龄   |   数学   |   语文   |   英语   |   总成绩  \n");
	printf("----------+----------+----------+----------+----------+----------+----------+-----------\n");
	int w=0;
	int m=0;
	for(i=0;i<n;i++)
	{
		if(gender_list[i]=='W')
		{
			w+=1;
		}
		else
		{
			m+=1;
		}
	}
	int s[n];
	int *p=sort_back(ID_list,n,s);
	for(i=0;i<n;i++)
	{
		printf("   %-7d|%-10s|   %-7c|   %-7d|   %-7d|   %-7d|   %-7d|   %-7d\n",xiao[p[i]].ID,xiao[p[i]].name,xiao[p[i]].gender,xiao[p[i]].age,
		xiao[p[i]].math,xiao[p[i]].chinese,xiao[p[i]].english,xiao[p[i]].math+xiao[p[i]].chinese+xiao[p[i]].english);
	}
	printf("----------+----------+----------+----------+----------+----------+----------+-----------\n");
	printf("   --     |   --     |   %d/%-2d   |  %.2f   |  %.2f   |  %.2f   |  %.2f   |  %.2f    \n",m,w,
	average(age_list,n),average(math_list,n),average(chinese_list,n),average(english_list,n),average(total_list,n));
	printf("----------------------------------------------------------------------------------------\n");
}
