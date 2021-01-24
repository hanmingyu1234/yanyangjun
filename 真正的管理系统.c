#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	char name[10];
	char team[10];
	int age;
	char place[10];
	int score;
	int number;
	struct node*next;
}NODE;
void input(NODE*);
void save(NODE*);
void display(NODE*);
void revise(NODE*);
void inquire(NODE*);
void add(NODE*);
void delet(NODE*);
int find(NODE*,int);
void menu(NODE*);
void kang(NODE*,int);
void sort(NODE*);
int main()
{
	system("color 0E");
	int n;
	NODE*head=(NODE*)malloc(sizeof(NODE));
	head->next=NULL;
	printf("\n\t                                 欢迎进入球员管理系统"); 
	printf("\n\t请先选择1号选项进行球员信息的录入(请一次性录入，若还需添加，之后可以选择五号选项逐一添加)");
	menu(head);
}
void input(NODE*head)//录入球员信息//尾插 
{
	int i,n,k=1;
	NODE*p=head;
	printf("\n\t请输入你要录入球员的个数；");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	NODE*pnew=(NODE*)malloc(sizeof(NODE));
		if(!pnew)
		{
			printf("\n\t录入失败，请退出管理系统重新录入");
			return;
		}
		printf("\n\t请输入第%d球员信息",k);
		printf("\n\t请输入球员姓名；");
		scanf("%s",pnew->name);
		printf("\n\t请输入球员所在球队:"); 
		scanf("%s",pnew->team);
		printf("\n\t请输入球员年龄:");
		scanf("%d",&pnew->age);
		printf("\n\t请输入球员出战位置:");
		scanf("%s",pnew->place);
		printf("\n\t请输入球员本赛季场均得分:");
		scanf("%d",&pnew->score);
		printf("\n\t请输入球员编号"); 
		scanf("%d",&pnew->number);
		pnew->next=NULL;
		p->next=pnew;
		p=pnew;
		k++;
	}
	
	printf("\n\t球员信息录入已完成"); 
}
int find(NODE*head,int n)//检查某个球员信息是否已经存在 
{
	NODE*p=head;
	p=p->next;
	while(p!=NULL)
	{
		if(p->number==n)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;
}
void display(NODE*head)//显示球员信息
{
	NODE*p=head;
	p=p->next;
	while(p!=NULL)
	{
		printf("\n\n\t%s    %s    %d    %s    %d    %d",p->name,p->team,p->age,p->place,p->score,p->number);
		p=p->next;
	}
}
void inquire(NODE*head)//查询球员信息 
{
	int i,k;
	NODE*p=head;
	p=p->next;
	printf("\n\t请输入你要查询的球员编号:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t该球员不存在，请重新输入");
		printf("\n\t请重新输入你要查询的球员编号:");
		scanf("%d",&i);
		k=find(head,i);
	}
	p=head->next;
	while(p!=NULL)
	{
		if(p->number==i)
		{
			printf("\n\t以下为你所选中的球员信息"); 
			printf("\n\n\t%s    %s    %d    %s    %d    %d",p->name,p->team,p->age,p->place,p->score,p->number);
			break;
		}
		p=p->next;
	}
}
void revise(NODE*head)// 修改球员信息
{
	int i,k;
	NODE*p;
	printf("\n\t请输入你要修改的球员的编号:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t该球员不存在，请重新输入");
		printf("\n\t请重新输入你要修改的球员的编号:");
		scanf("%d",&i);
		k=find(head,i);
	}
	p=head->next;
	while(p!=NULL)
	{
		if(p->number==i)
		{
			printf("\n\t查找成功，请进行修改");
			printf("\n\t请重新输入球员姓名；");
			scanf("%s",p->name);
			printf("\n\t请重新输入球员所在球队:"); 
			scanf("%s",p->team);
			printf("\n\t请重新输入球员年龄:");
			scanf("%d",&p->age);
			printf("\n\t请重新输入球员出战位置:");
			scanf("%s",p->place);
			printf("\n\t请重新输入球员本赛季场均得分:");
			scanf("%d",&p->score);
			printf("\n\t请重新输入球员编号:");
			scanf("%d",&p->number);
			printf("\n\t修改完成");
			break;
		}
		p=p->next;
	}
}
void add(NODE*head)//添加球员信息 
{
	int i,n,k;
	printf("\n\t请输入你要添加的球员的编号:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==1)
	{
		printf("\n\t你所输入的球员已存在，请重新输入");
		scanf("%d",&i);
		k=find(head,i); 
	}
	printf("\n\t请添加新的球员信息");
	NODE*pnew=(NODE*)malloc(sizeof(NODE));
	pnew->next=head->next;
	head->next=pnew;
	printf("\n\t请输入球员姓名；");
	scanf("%s",pnew->name);
	printf("\n\t请输入球员所在球队:"); 
	scanf("%s",pnew->team);
	printf("\n\t请输入球员年龄:");
	scanf("%d",&pnew->age);
	printf("\n\t请输入球员出战位置:");
	scanf("%s",pnew->place);
	printf("\n\t请输入球员本赛季场均得分:");
	scanf("%d",&pnew->score);
	pnew->number=i;
}
void delet(NODE*head)//删除球员信息 
{
	int i,n,k;
	printf("\n\t请输入你所要删除的球员的编号:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t你所要删除的球员不存在，请重新输入你要删除的球员编号:");
		scanf("%d",&i);
		k=find(head,i);
	}
	NODE*p=head;
	NODE*q=head;
	p=p->next;
	while(p!=NULL)
	{
		if(p->number==i)
		{
			q->next=p->next;
		}
		p=p->next;
		q=q->next;
	}
	free(p);
}
void sort(NODE*head)
{
	int numberx;
	char namex[10];
	char teamx[10];
	int agex;
	char placex[10];
	int scorex;
	NODE*p=head;
	p=p->next;
	if(p=NULL)
	{
		printf("\n\t管理系统中没有信息，请录入信息之后再排序"); 
	}
	else
	{
		while(p!=NULL)
		{
			while(p->next!=NULL)
			{
			if(p->number > p->next->number)
			{
				numberx=p->number;
				strcpy(namex,p->name);
				strcpy(teamx,p->team);
				agex=p->age;
				strcpy(placex,p->place);
				scorex=p->score;
					
				p->number=p->next->number;
				strcpy(p->name,p->next->name);
				strcpy(p->team,p->next->team);
				p->age=p->next->age;
				strcpy(p->place,p->next->place);
				p->score=p->next->score;
					
				p->next->number=numberx;
				strcpy(p->next->name,namex);
				strcpy(p->next->team,teamx);
				p->next->age=agex;
				strcpy(p->next->place,placex);
				p->next->score=scorex;
			}
			p=p->next;
			}		
		} 
	}
}
void save(NODE*head)//把信息保存到文件中
{
	NODE*p=head;
	p=p->next;
	FILE *fp;
	if((fp=fopen("d:\\playerlist","wb"))==NULL)
	{
		printf("\n\t不能正确打开文件");
		exit(1); 
	}
	printf("\n\t数据已经成功保存");
	while(p!=NULL)
	{
		fprintf(fp,"\n\t%s    %s    %d    %s    %d    %d",p->name,p->team,p->age,p->place,p->score,p->number);
		p=p->next;
	}
	fclose(fp);	
}
void menu(NODE*head)
{
	int i,n;
	printf("\n\n\t ***************球员管理系统***************\n\n");
	printf("\t|*                1.录入球员信息                *|\n");
	printf("\t|*                2.显示球员信息                *|\n");
	printf("\t|*                3.查询球员信息                *|\n");
	printf("\t|*                4.修改球员信息                *|\n");
	printf("\t|*                5.添加球员信息                *|\n");
	printf("\t|*                6.删除球员信息                *|\n");
	printf("\t|*                7.排序球员信息                *|\n");
	printf("\t|*                8.退出管理系统                *|\n");
	printf("\n\t ***************球员管理系统***************");
	printf("\n\t请选择菜单项:");
	scanf("%d",&i);
	while(i<1||i>8)
	{
		printf("\n\t选择无效，请重新选择:"); 
		scanf("%d",&i);
	}
	kang(head,i);
}
void kang(NODE*head,int i)
{
	int n;
	switch(i)
	{
		case 1:
			system("cls");
			input(head);
			system("cls");
			printf("\n\t1.返回主菜单,继续进行操作"); 
			printf("\n\t2.退出管理系统");
			printf("\n\t请输入1或2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t输入无效，请重新输入");
				scanf("%d",&n); 
			}
			if(n==1)
			{
				menu(head);
			}
			else
			{
				exit(0);
			}
			break; 
		case 2:
			system("cls");
			display(head);
			//system("cls");
			printf("\n\t1.返回主菜单,继续进行操作"); 
			printf("\n\t2.退出管理系统");
			printf("\n\t请输入1或2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t输入无效，请重新输入");
				scanf("%d",&n); 
			}
			if(n==1)
			{
				menu(head);
			}
			else
			{
				exit(0);
			}
			break;
		case 3:
			system("cls");
			inquire(head);
			printf("\n\t1.返回主菜单,继续进行操作"); 
			printf("\n\t2.退出管理系统");
			printf("\n\t请输入1或2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t输入无效，请重新输入");
				scanf("%d",&n); 
			}
			if(n==1)
			{
				menu(head);
			}
			else
			{
				exit(0);
			}
			break;
		case 4:
			system("cls");
			revise(head);
			printf("\n\t1.返回主菜单,继续进行操作"); 
			printf("\n\t2.退出管理系统");
			printf("\n\t请输入1或2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t输入无效，请重新输入");
				scanf("%d",&n); 
			}
			if(n==1)
			{
				menu(head);
			}
			else
			{
				exit(0);
			}
			break;
		case 5:
			system("cls");
			add(head);
			printf("\n\t1.返回主菜单,继续进行操作"); 
			printf("\n\t2.退出管理系统");
			printf("\n\t请输入1或2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t输入无效，请重新输入");
				scanf("%d",&n); 
			}
			if(n==1)
			{
				menu(head);
			}
			else
			{
				exit(0);
			}
			break;
		case 6:
			system("cls");
			delet(head);
			printf("\n\t1.返回主菜单,继续进行操作"); 
			printf("\n\t2.退出管理系统");
			printf("\n\t请输入1或2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t输入无效，请重新输入");
				scanf("%d",&n); 
			}
			if(n==1)
			{
				menu(head);
			}
			else
			{
				exit(0);
			}
			break;
		case 7:
			system("cls");
			sort(head);
			printf("\n\t1.返回主菜单,继续进行操作"); 
			printf("\n\t2.退出管理系统");
			printf("\n\t请输入1或2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t输入无效，请重新输入");
				scanf("%d",&n); 
			}
			if(n==1)
			{
				menu(head);
			}
			else
			{
				exit(0);
			}
			break;
		case 8:
			system("cls");
			exit(0);
			break;
	}
}
