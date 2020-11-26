#include <stdio.h>
void kuaipai(int a[],int left,int right)
{
	int i=left,j=right;
	int temp;
	int pivot;
	pivot = a[(left+right)/2];
	while(i<=j) 
	{
		//�������ҵ����ڵ��ڻ�׼���Ԫ��
		while(a[i]<pivot) 
		{
			i++;
		}
		//���ҵ����ҵ�С�ڵ��ڻ�׼���Ԫ�� 
		while(a[j]>pivot)
		{
			j--;
		}
		//���i<=j,�򻥻�
		if(i<=j)
		{
			temp = a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	if(left<j)
	{
		kuaipai(a,left,j);
	}
	if(i<right)
	{
		kuaipai(a,i,right);
	}
}
int main()
{
	int a[]={54,212,65,17,3,64,91,348,12,657,23,58,197};
	int i,length;
	length=sizeof(a)/sizeof(a[0]);
	kuaipai(a,0,length-1);
	for(i=0;i<length;i++)
	{
		printf("%6d",a[i]);
	}
}
