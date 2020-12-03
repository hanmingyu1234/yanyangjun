#include <stdio.h>
#include <string.h>
int main()
{
	char a[210];
	char b[210];
	int c[210]={0},j;
	int i,k=0,la,lb,lmax;
	scanf("%s",a);
	scanf("%s",b);
	la=strlen(a);
	lb=strlen(b);
	if(la>lb)
	{
		lmax=la;
		for(i=la-1,j=lb-1;j>=0;i--,j--)
		{
			b[i]=b[j];
		}
		for(i=0;i<la-lb;i++)
		{
			b[i]='0';	
		}
	}
	else
	{
		lmax=lb;
		for(i=lb-1,j=la-1;j>=0;i--,j--)
		{                                                    //第一组大的 if else 进行右对齐 
			a[i]=a[j]; 
		}
		for(i=0;i<lb-la;i++)
		{
			a[i]='0';	
		}
	}
	for(i=lmax-1;i>=0;i--)                                       //主要的for循环对c数组进行赋值 
	{
		c[i]=a[i]+b[i]+c[i]-96;
		if(c[i]>=10)
		{
			c[i]=c[i]-10;
			c[i-1]=c[i-1]+1;	
		}
	}
	if(a[0]+b[0]-96>=10)
	{
		for(i=lmax-1;i>=0;i--)
		{
			c[i+1]=c[i];
		}
		c[0]=1;
		for(i=0;i<=lmax;i++)
		{
			printf("%d",c[i]);
		}
	}
	else
	{
		for(i=0;i<lmax;i++)
		{
			if(c[i]!=0)
			{
				k=i;
				break;	
			}
		}
		for(i=k;i<lmax;i++)
		{
			printf("%d",c[i]);	
		}
	}
}
