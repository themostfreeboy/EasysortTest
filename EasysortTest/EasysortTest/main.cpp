#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using std::swap;

#define N 10

int comp(const void*a,const void*b)
{
	return *((int*)a)-*((int*)b);
}

void easysort1(int data[],int n)//冒泡排序
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(data[j]>data[j+1])	swap(data[j],data[j+1]);
		}
	}
}

void easysort2(int data[],int n)//选择排序
{
	int i,j,min_index;
	for(i=0;i<n-1;i++)
	{
		min_index=i;
		for(j=i+1;j<n;j++)
		{
			if(data[j]<data[min_index])	min_index=j;
		}
		swap(data[i],data[min_index]);
	}
}

void easysort3(int data[],int n)//插入排序
{
	int i,j,index,temp;
	for(i=0;i<n;i++)
	{
		index=i;
		temp=data[n-1];
		for(j=0;j<i;j++)
		{
			if(temp<data[j])
			{
				index=j;
				break;
			}
		}
		for(j=n-1;j>index;j--)
		{
			data[j]=data[j-1];
		}
		data[index]=temp;
	}
}

int main()
{
	int data[N],ans[N],i,temp,wrongIndex;
	bool hasWrong;
	srand((unsigned)time(NULL));
	while(1)
	{
		for(i=0;i<N;i++)
		{
			temp=rand()%10000;
			data[i]=temp;
			ans[i]=temp;
		}
		printf("原始数据:\n");
		for(i=0;i<N;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		easysort1(data,N);
		//easysort2(data,N);
		//easysort3(data,N);
		printf("我的排序后数据:\n");
		for(i=0;i<N;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		hasWrong=false;
		for(i=0;i<N-1;i++)
		{
			if(data[i]>data[i+1])
			{
				hasWrong=true;
				wrongIndex=i+1;
				break;
			}
		}
		if(hasWrong)
		{
			printf("我的排序数据有误，第一个错误处出现在下标为%d处，标准排序后数据:\n",wrongIndex);
			qsort(ans,N,sizeof(int),comp);
			for(i=0;i<N;i++)
			{
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
		else
		{
			printf("我的排序数据全部正确\n");
		}
		system("pause");
	}
	return 0;
}