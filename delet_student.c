#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student_input.h"
int return_line(int num,int a[],int n)
{
	int i,flag;
	for(i=0;i<n;i++)
	{
		if(a[i]==num)
		{
			flag=i;
			break;
		}
		else 
		{
			flag=-1;
		}
			
	}
	return flag;
}

int delet_line(int num,int n)
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
		//printf("%s ",buf);
		getID=atoi(strtok(buf,","));
		//printf("%d\n",getID);
		//printf("%s ",buf);
		if(getID==num)
		{
			//continue;
			fprintf(fp1,"%s",NULL);
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



int delet_by_ID()
{
	printf("输入学号:");
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
	int dnum,line;
	dnum=num_input(dnum,100,0);
	line=return_line(dnum,ID_list,n);

	if(line==-1)
	{
		printf("错误：该学生信息不存在，删除失败，按任意键返回...");
		getchar();
	}
	else
	{
		delet_line(dnum,n);
		printf("提示：删除成功，按任意键返回...");
		getchar();
	}	
}