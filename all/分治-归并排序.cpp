#include<iostream>
using namespace std;
#include<cstdio>

int a[11]={0,2,5,1,4,3,7,6,8,9,10};
int t[11];//������ʱ�洢����С�����a�ȴ� 

void mergesort(int left,int right)
{
	if(left<right)//��������������˵��ֻ�ֽ�ʣ��1��Ԫ���ˣ������ٷ��ˣ����� 
	{
		int i,j,mid,tp;
		mid=left+(right-left)/2;
		i=left;//������ָ��i 
		j=mid+1;//������ָ��j 
        tp=left;//�ݴ�����t��ָ�� 
				
		mergesort(left,mid);//��:���õݹ齫���зֽ� 
		mergesort(mid+1,right);
		
	    while(i<=mid||j<=right)//��������ǰ����ֽ�Ϊ������������䣬�ֱ���i jָ����������ͷԪ�أ�i j����ƣ������ڣ����αȽ�ȥ��С�ķ���t����ʱ�洢 
	    {                      //ע�⣺�����䵯��Ԫ�ص�t��������iָ��Ԫ�ر�j��С �� j�Ѿ��������䡣������ͬ�� 
			if(j>right||i<=mid&&a[i]<=a[j])
			  t[tp++]=a[i++];
			else
			  t[tp++]=a[j++];
		}
		int k;
		for(k=left;k<=right;k++)
		  a[k]=t[k]; 
	}
}	  

int main()
{
	int n=10;
	
	mergesort(1,n);
	
	int i;
	for(i=1;i<=n;i++)
	  cout<<a[i]<<" "; 
	
	getchar();getchar();
	return 0;
}
