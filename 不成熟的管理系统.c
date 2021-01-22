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
	printf("��ӭ������Ա����ϵͳ"); 
	int i;
	printf("\n\n\t ***************��Ա����ϵͳ***************\n\n");
	printf("\t|*                1.¼����Ա��Ϣ                 *|\n");
	printf("\t|*                2.��ʾ��Ա��Ϣ                 *|\n");
	printf("\t|*                3.��ѯ��Ա��Ϣ                 *|\n");
	printf("\t|*                4.�޸���Ա��Ϣ                 *|\n");
	printf("\t|*                5.�����Ա��Ϣ                 *|\n");
	printf("\t|*                6.ɾ����Ա��Ϣ                 *|\n");
	printf("\t|*                7.������Ա��Ϣ                 *|\n");
	printf("\t|*                8.�˳�����ϵͳ                 *|\n");
	printf("\n\t ***************��Ա����ϵͳ***************");
	printf("\n\t��ѡ��˵���:");
	scanf("%d",&i);
	while(i<1||i>8)
	{
		printf("\n\tѡ����Ч��������ѡ��:"); 
		scanf("%d",&i);
	} 
	return i;
} 
void input(NODE*head)//¼����Ա��Ϣ
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
	}
	menu();
}
int find(NODE*head,int n)//���ܺ��� 
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
	printf("\n\t������������Ա����Ϣ"); 
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
void inquire(NODE*head)//��ѯ��Ա��Ϣ 
{
	int i,k;
	NODE*p=head;
	p=p->next;
	printf("\n\t��������Ҫ��ѯ����Ա���");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t����Ա�����ڣ�����������");
		printf("\n\t������������Ҫ��ѯ����Ա���");
		scanf("%d",&i);
		k=find(head,i);
	}
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
	printf("\n\t��������Ҫ�޸ĵ���Ա�ı��");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t����Ա�����ڣ�����������");
		printf("\n\t������������Ҫ�޸ĵ���Ա�ı��");
		scanf("%d",&i);
		k=find(head,i);
	}
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
			printf("\n\t������������Ա���");
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
	printf("\n\t��������Ҫ��ӵ���Ա�ı��");
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
	printf("\n\t��������Ա���"); 
	scanf("%d",&pnew->number);
}
void delet(NODE*head)//ɾ����Ա��Ϣ 
{
	int i,n,k;
	printf("\n\t����������Ҫɾ������Ա�ı��");
	scanf("%d",&i);
	k=find(head,i);
	while(k==0)
	{
		printf("\n\t����Ҫɾ������Ա�����ڣ�������������Ҫɾ������Ա���");
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
void sort()//������Ա��Ϣ 
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
