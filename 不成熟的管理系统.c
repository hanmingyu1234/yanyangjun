#include <stdio.h>
#include <stdlib.h>
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
int menu()
{
	printf("欢迎进入球员管理系统"); 
	int i;
	printf("\n\n\t ***************球员管理系统***************\n\n");
	printf("\t|*                1.录入球员信息                 *|\n");
	printf("\t|*                2.显示球员信息                 *|\n");
	printf("\t|*                3.查询球员信息                 *|\n");
	printf("\t|*                4.修改球员信息                 *|\n");
	printf("\t|*                5.添加球员信息                 *|\n");
	printf("\t|*                6.删除球员信息                 *|\n");
	printf("\t|*                7.排序球员信息                 *|\n");
	printf("\t|*                8.退出管理系统                 *|\n");
	printf("\n\t ***************球员管理系统***************");
	printf("\n\t请选择菜单项:");
	scanf("%d",&i);
	while(i<1||i>8)
	{
		printf("\n\t选择无效，请重新选择:"); 
		scanf("%d",&i);
	} 
	return i;
} 
void input(NODE*head)//录入球员信息
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
	}
	menu();
}
int find(NODE*head,int n)//功能函数 
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
	printf("\n\t以下是所有球员的信息"); 
	int i=1;
	NODE*p=head;
	p=p->next;
	while(p!=NULL)
	{
		printf("\n\n\t%d.%s    %s    %d    %s    %d    %d",i,p->name,p->team,p->age,p->place,p->score,p->number);
		p=p->next;
		i++;
	} 
}
void inquire(NODE*head)//查询球员信息 
{
	int i,k;
	NODE*p=head;
	p=p->next;
	printf("\n\t请输入你要查询的球员编号");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t该球员不存在，请重新输入");
		printf("\n\t请重新输入你要查询的球员编号");
		scanf("%d",&i);
		k=find(head,i);
	}
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
	printf("\n\t请输入你要修改的球员的编号");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t该球员不存在，请重新输入");
		printf("\n\t请重新输入你要修改的球员的编号");
		scanf("%d",&i);
		k=find(head,i);
	}
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
			printf("\n\t请重新输入球员编号");
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
	printf("\n\t请输入你要添加的球员的编号");
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
	printf("\n\t请输入球员编号"); 
	scanf("%d",&pnew->number);
}
void delet(NODE*head)//删除球员信息 
{
	int i,n,k;
	printf("\n\t请输入你所要删除的球员的编号");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t你所要删除的球员不存在，请重新输入你要删除的球员编号");
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
}
void sort()//排序球员信息 
{
	
}
int main()
{
	int k;
	NODE*head=(NODE*)malloc(sizeof(NODE));
	head->next=NULL;
	k=menu();
	while(1)
	{
		system("cls");
		switch(k)
		{
			case 1:
				input(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				inquire(head);
				break;
			case 4:
				revise(head);
				break;
			case 5:
				add(head);
				break;
			case 6:
				delet(head);
				break;
			case 7:
				sort(head);
				break;
			case 8:
				exit(0);	
		}
	}
}
