#include<iostream>//�����������ѣ�������  O(NlogN) 
using namespace std;//����˼�룺�����������ʣ��Դ˶Ե��Ѷ�����������Ͷ�β���Ե���Ѷ����µ��������ٶ�Ԫ������ 
#include<cstdio>//����Ϊ�����ĶѶ��ѳ��ѣ�ʵ���ϴ��ڶ�β���ɴ˶�������β��Ѷ�������εݼ���Ԫ�ش�СҲ���εݼ���
///��Ϊÿ�η���(��ʱ) ��β�Ķ��ǣ���ʱ����������Ԫ��
 
int h[101];
int n=0;
int a[11]={0,7,6,9,1,4,3,2,8,5,10};

void swap(int x,int y)
{
	int z=h[x];
	h[x]=h[y];
	h[y]=z;
}

void siftdown(int i)
{
	int t,flag=0;
	
	t=i;
	while(i*2<=n&&flag==0)
	{
		if(h[i*2]>h[i])
		  t=i*2;
		if(i*2+1<=n)
		  if(h[i*2+1]>h[t])
		    t=i*2+1;
		
		if(t!=i)
		{
			swap(i,t);
			i=t;
		}
		else
		  flag=1;
	}
}

void create()
{
	int i;
	for(i=n/2;i>=1;i--)
	  siftdown(i);
}

void heapsort()
{
	while(n>1)
	{
		swap(1,n);
		n--;
		siftdown(1);
	}
} 

int main()
{
	int i;
	
	n=0;
	for(i=1;i<=10;i++)
	{
		n++;
		h[n]=a[i];
	}
	
	create();
	
	for(i=1;i<=n;i++)//����������(���Ǳ���������������򲻴������������) 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	int num=n;
	heapsort();//�����������ѣ����������ʹ�ö��������������������� 
	
	for(i=1;i<=num;i++)//����������(�������������Ѷ���������������)
	  cout<<h[i]<<" ";
	  
	getchar();getchar();
	return 0;
}
