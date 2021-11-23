#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int a;//开始时间
    int b;//结束时间
}node[50000];
int main(void)
{
	struct Node t;
    int n=5,max=0,j=0,k;
    int s[10000]={0};
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d%d",&node[i].a,&node[i].b);
    }
	node[0].a=2,node[0].b=4;
	node[1].a=1,node[1].b=12;
	node[2].a=4,node[2].b=5;
	node[3].a=7,node[3].b=10;
	node[4].a=7,node[4].b=8;
    for(i=0;i<n-1;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		if(node[i].a>node[j].a)
    		{
    			t=node[i];
    			node[i]=node[j];
    			node[j]=t;
			}
		}
	}
    int cnt=0;  //最终过题数
    int time=0;  //时间初始化为0
	i=0;
	j=0;
	for(k=0;k<n;k++)
	{
		for(;i<n;i++)
		{
			if(time<=node[i].a)
			{
				time=node[i].b;
				s[j]++;
			}
			else
			{
				j++;
				break;
			}
		}
		time=0;
	}
	for(i=0;i<n;i++)
	{
		max=max>s[i]?max:s[i];
	}
    printf("%d",max);
    return 0;
}

