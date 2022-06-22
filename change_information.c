#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student_input.h"

int change_line(int num,int n,struct student xiao)
{
	FILE * fp=NULL;
	FILE * fp1=NULL;
	char buf[40];
	char bufcopy[40];
	int i;
	int getID;
	fp = fopen("data.txt", "r+");
	fp1 = fopen("data_backup.txt", "w+");
	for(i=0;i<n;i++)
	{
		fgets(buf,sizeof(buf),fp);
		strcpy(bufcopy,buf);
		getID=atoi(strtok(buf,","));
		if(getID==num)
		{
			fprintf(fp1,"%d,%s,%c,%d,%d,%d,%d,%d\n",num,xiao.name,xiao.gender,
			xiao.age,xiao.math,xiao.chinese,xiao.english,xiao.math+xiao.chinese+xiao.english);
		}
		else
		{
			fprintf(fp1,"%s",bufcopy);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove("data.txt");
	rename("data_backup.txt","data.txt");
	
}

int change_student()
{
	int ID;
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
	ID=input_student_ID();
	back_list(n,xiao,ID_list,age_list,math_list,chinese_list,english_list,total_list);
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(ID==ID_list[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("错误：该学生信息不存在，修改失败！按任意键返回...");
		getchar();
	}
	else
	{
		xiao1=input_student(xiao1);
		change_line(ID,n,xiao1);
		printf("提示：修改成功，按任意键返回...");
		getchar();
	}	
}
