#include <stdio.h>
int main()
{
	int y,m,d;
	int k=274,n=0,i; 
	int result=0;
	scanf("%d-%d-%d",&y,&m,&d);
	int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((y%4==0&&y%100!=0)||y%400==0)
	{
		for(i=m-2;i>=0;i--)
		{
			n+=a[i];
		}
		n+=d;
	}
	else
	{
		for(i=m-2;i>=0;i--)
		{
			n+=b[i];	
		}
		n+=d;	
	}
	for(i=y-1;i>0;i--)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
			n+=366;
		else
			n+=365;
	}
  	for(i=1948;i>0;i--)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
			k+=366;
		else
			k+=365;
	}
	if(n>k)
		result=n-k;
	else
	    result=k-n;
	printf("%d",result);
}


