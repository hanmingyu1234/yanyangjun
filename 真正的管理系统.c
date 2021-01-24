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
	printf("\n\t                                 ��ӭ������Ա����ϵͳ"); 
	printf("\n\t����ѡ��1��ѡ�������Ա��Ϣ��¼��(��һ����¼�룬��������ӣ�֮�����ѡ�����ѡ����һ���)");
	menu(head);
}
void input(NODE*head)//¼����Ա��Ϣ//β�� 
{
	int i,n,k=1;
	NODE*p=head;
	printf("\n\t��������Ҫ¼����Ա�ĸ�����");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	NODE*pnew=(NODE*)malloc(sizeof(NODE));
		if(!pnew)
		{
			printf("\n\t¼��ʧ�ܣ����˳�����ϵͳ����¼��");
			return;
		}
		printf("\n\t�������%d��Ա��Ϣ",k);
		printf("\n\t��������Ա������");
		scanf("%s",pnew->name);
		printf("\n\t��������Ա�������:"); 
		scanf("%s",pnew->team);
		printf("\n\t��������Ա����:");
		scanf("%d",&pnew->age);
		printf("\n\t��������Ա��սλ��:");
		scanf("%s",pnew->place);
		printf("\n\t��������Ա�����������÷�:");
		scanf("%d",&pnew->score);
		printf("\n\t��������Ա���"); 
		scanf("%d",&pnew->number);
		pnew->next=NULL;
		p->next=pnew;
		p=pnew;
		k++;
	}
	
	printf("\n\t��Ա��Ϣ¼�������"); 
}
int find(NODE*head,int n)//���ĳ����Ա��Ϣ�Ƿ��Ѿ����� 
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
void display(NODE*head)//��ʾ��Ա��Ϣ
{
	NODE*p=head;
	p=p->next;
	while(p!=NULL)
	{
		printf("\n\n\t%s    %s    %d    %s    %d    %d",p->name,p->team,p->age,p->place,p->score,p->number);
		p=p->next;
	}
}
void inquire(NODE*head)//��ѯ��Ա��Ϣ 
{
	int i,k;
	NODE*p=head;
	p=p->next;
	printf("\n\t��������Ҫ��ѯ����Ա���:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t����Ա�����ڣ�����������");
		printf("\n\t������������Ҫ��ѯ����Ա���:");
		scanf("%d",&i);
		k=find(head,i);
	}
	p=head->next;
	while(p!=NULL)
	{
		if(p->number==i)
		{
			printf("\n\t����Ϊ����ѡ�е���Ա��Ϣ"); 
			printf("\n\n\t%s    %s    %d    %s    %d    %d",p->name,p->team,p->age,p->place,p->score,p->number);
			break;
		}
		p=p->next;
	}
}
void revise(NODE*head)// �޸���Ա��Ϣ
{
	int i,k;
	NODE*p;
	printf("\n\t��������Ҫ�޸ĵ���Ա�ı��:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t����Ա�����ڣ�����������");
		printf("\n\t������������Ҫ�޸ĵ���Ա�ı��:");
		scanf("%d",&i);
		k=find(head,i);
	}
	p=head->next;
	while(p!=NULL)
	{
		if(p->number==i)
		{
			printf("\n\t���ҳɹ���������޸�");
			printf("\n\t������������Ա������");
			scanf("%s",p->name);
			printf("\n\t������������Ա�������:"); 
			scanf("%s",p->team);
			printf("\n\t������������Ա����:");
			scanf("%d",&p->age);
			printf("\n\t������������Ա��սλ��:");
			scanf("%s",p->place);
			printf("\n\t������������Ա�����������÷�:");
			scanf("%d",&p->score);
			printf("\n\t������������Ա���:");
			scanf("%d",&p->number);
			printf("\n\t�޸����");
			break;
		}
		p=p->next;
	}
}
void add(NODE*head)//�����Ա��Ϣ 
{
	int i,n,k;
	printf("\n\t��������Ҫ��ӵ���Ա�ı��:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==1)
	{
		printf("\n\t�����������Ա�Ѵ��ڣ�����������");
		scanf("%d",&i);
		k=find(head,i); 
	}
	printf("\n\t������µ���Ա��Ϣ");
	NODE*pnew=(NODE*)malloc(sizeof(NODE));
	pnew->next=head->next;
	head->next=pnew;
	printf("\n\t��������Ա������");
	scanf("%s",pnew->name);
	printf("\n\t��������Ա�������:"); 
	scanf("%s",pnew->team);
	printf("\n\t��������Ա����:");
	scanf("%d",&pnew->age);
	printf("\n\t��������Ա��սλ��:");
	scanf("%s",pnew->place);
	printf("\n\t��������Ա�����������÷�:");
	scanf("%d",&pnew->score);
	pnew->number=i;
}
void delet(NODE*head)//ɾ����Ա��Ϣ 
{
	int i,n,k;
	printf("\n\t����������Ҫɾ������Ա�ı��:");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t����Ҫɾ������Ա�����ڣ�������������Ҫɾ������Ա���:");
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
		printf("\n\t����ϵͳ��û����Ϣ����¼����Ϣ֮��������"); 
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
void save(NODE*head)//����Ϣ���浽�ļ���
{
	NODE*p=head;
	p=p->next;
	FILE *fp;
	if((fp=fopen("d:\\playerlist","wb"))==NULL)
	{
		printf("\n\t������ȷ���ļ�");
		exit(1); 
	}
	printf("\n\t�����Ѿ��ɹ�����");
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
	printf("\n\n\t ***************��Ա����ϵͳ***************\n\n");
	printf("\t|*                1.¼����Ա��Ϣ                *|\n");
	printf("\t|*                2.��ʾ��Ա��Ϣ                *|\n");
	printf("\t|*                3.��ѯ��Ա��Ϣ                *|\n");
	printf("\t|*                4.�޸���Ա��Ϣ                *|\n");
	printf("\t|*                5.�����Ա��Ϣ                *|\n");
	printf("\t|*                6.ɾ����Ա��Ϣ                *|\n");
	printf("\t|*                7.������Ա��Ϣ                *|\n");
	printf("\t|*                8.�˳�����ϵͳ                *|\n");
	printf("\n\t ***************��Ա����ϵͳ***************");
	printf("\n\t��ѡ��˵���:");
	scanf("%d",&i);
	while(i<1||i>8)
	{
		printf("\n\tѡ����Ч��������ѡ��:"); 
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
			printf("\n\t1.�������˵�,�������в���"); 
			printf("\n\t2.�˳�����ϵͳ");
			printf("\n\t������1��2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t������Ч������������");
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
			printf("\n\t1.�������˵�,�������в���"); 
			printf("\n\t2.�˳�����ϵͳ");
			printf("\n\t������1��2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t������Ч������������");
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
			printf("\n\t1.�������˵�,�������в���"); 
			printf("\n\t2.�˳�����ϵͳ");
			printf("\n\t������1��2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t������Ч������������");
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
			printf("\n\t1.�������˵�,�������в���"); 
			printf("\n\t2.�˳�����ϵͳ");
			printf("\n\t������1��2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t������Ч������������");
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
			printf("\n\t1.�������˵�,�������в���"); 
			printf("\n\t2.�˳�����ϵͳ");
			printf("\n\t������1��2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t������Ч������������");
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
			printf("\n\t1.�������˵�,�������в���"); 
			printf("\n\t2.�˳�����ϵͳ");
			printf("\n\t������1��2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t������Ч������������");
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
			printf("\n\t1.�������˵�,�������в���"); 
			printf("\n\t2.�˳�����ϵͳ");
			printf("\n\t������1��2:");
			scanf("%d",&n);
			while(n<1||n>2)
			{
				printf("\n\t������Ч������������");
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
