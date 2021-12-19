#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int Weight;
    int Lchild, Rchild, Parent;
}HFNode;
typedef char * HFCode[7];//动态分配数组存储哈夫曼编码表
void select(HFNode* hftree, int i, int * min1, int * min2)
{
    int j, t, flag;
    *min1 = *min2 = 0;
    for(j = 1; j <= i; j++)
    {
        if(hftree[j].Parent == 0)
        {
            if(*min1 == 0)
                *min1 = j;
            else if(*min2 == 0)
            {
                *min2 = j;
                flag = j;
                break;
            }
        }
    }
    if(hftree[*min1].Weight > hftree[*min2].Weight)
    {
        t = *min1;
        *min1 = *min2;
        *min2 = t;
    } 
    for(j = flag; j <= i; j++)
    {   
        if(hftree[j].Parent == 0 && hftree[j].Weight < hftree[*min1].Weight )
        {
            *min2 = *min1;
            *min1 = j;
        }
        else if(hftree[j].Parent == 0 && hftree[j].Weight < hftree[*min2].Weight )
        {
            *min2 = j; 
        }
    }
}
void CreateHuffman_Tree(HFNode* hftree)
{
    int min1, min2;
    for(int i = 1; i < 7; i++)
    {
    	scanf("%d",&hftree[i].Weight);
	}
    for(int i = 7; i < 12; i++)
    {   
        select(hftree, i-1,&min1, &min2);
        hftree[i].Weight = hftree[min1].Weight + hftree[min2].Weight;
        hftree[i].Lchild = min1;
        hftree[i].Rchild = min2;
        hftree[min1].Parent = hftree[min2].Parent = i;
    }
}
void HuffCode(HFNode* hftree, HFCode hfcode)
{
    int i, start, c, p;
    char * temp = (char *)malloc(6 * sizeof(char));
    temp[5]='\0';
    for(i = 1; i <= 6; i++)
    {
        start = 5;
        c = i;
        p = hftree[c].Parent;
        while(p != 0)
        {
            if(hftree[p].Lchild == c)
                temp[--start] = '0';
            else
                temp[--start] = '1';
            c = p;
            p = hftree[c].Parent;
        }
        hfcode[i] = (char *)malloc((6-start) * sizeof(char));
        strcpy(hfcode[i], &temp[start]);
    }
    free(temp);
}
void PrintCode(HFNode* hftree, HFCode hfcode)
{
    int i;
    char x = 'A';
    for(i = 1; i <= 6; i++)
        printf("%c:%s\n",x+i-1, hfcode[i]);
}
void TransCode(HFCode hfcode, char * inputChar)
{
    int i, index;
    for(i = 0; i < strlen(inputChar); i++) 
    {
        index = inputChar[i] - 'A' + 1;
        printf("%s",hfcode[index]);
    }
    printf("\n");
}
void TransChar(HFNode* hftree, HFCode hfcode, char * inputCode)
{
    int i = 0, j, p = 11, start;
    char * temp = (char *)malloc(6 * sizeof(char));
    while(inputCode[i] != '\0')
    {
        p = 11;
        start = 0; 
        while(1)
        {
            if(hftree[p].Lchild != 0)
            {
                if(inputCode[i] == '0')
                {
                    p = hftree[p].Lchild;
                    temp[start++] = '0';
                }
                else
                {
                    p = hftree[p].Rchild;
                    temp[start++] = '1';    
                }
            }
            else
            {
                break;
            }
            i++;
        }
        temp[start] = '\0'; 
        for(j = 1; j <= 6; j++)
        {
            if(strcmp(hfcode[j], temp) == 0)
            {
                printf("%c",'A'+j-1);
                break;
            }
        }
    }
    free(temp);
}
int main()
{
    char inputChar[100]; 
    char inputCode[100];
    HFNode hftree[12]={0};
    HFCode hfcode;
    CreateHuffman_Tree(hftree);
    HuffCode(hftree, hfcode);
    scanf("%s",inputChar);
    scanf("%s",inputCode);
    PrintCode(hftree, hfcode);
    TransCode(hfcode, inputChar);
    TransChar(hftree, hfcode, inputCode);
    return 0;
}
