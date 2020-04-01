#include<iostream>//��С��  ƽ��ʱ�临�Ӷ�O(NlogN) 
using namespace std;//����˼�룺 2�ֽ��ѷ�ʽ��1.�߽��ѱ�(����)ά��  O(NlogN)  2.�Ƚ���������٣���һ���£�ά��  
#include<cstdio>//��˵��  O(N) ��ɾ��Ԫ��ʱ�Ѷ�Ԫ�س��ѣ���βԪ�ز�λ�����µ������ɴ�ʵ������ 
//���ϵ������Ƚϸ��ڵ��Ƿ���Լ��������򽻻����������
//���µ������Ƚ��ӽڵ��Ƿ���Լ�С��������ȥ�ӽڵ�����С�Ľ������������
//��һ���µ����������һ���ڲ��ڵ㿪ʼ�����ڶ�����ȫ���������ʸýڵ���n/2����ö�ٱ������Ѷ�����һʵ�����µ��� 

int h[101];
int n;
int in[11]={0,5,2,3,4,1};

void swap(int x,int y)
{
	int a;
	a=h[x];
	h[x]=h[y];
	h[y]=a;
}

void siftup(int i)
{
	int t,flag=0;
	while(i!=1&&flag==0)
	{
		if(h[i]<h[i/2])
		{
			swap(i,i/2);
			
			i=i/2;
		}
		else
		  flag=1;
	}
}

void siftdown(int i)
{
	int t,flag=0;
	t=i;
	while(i*2<=n&&flag==0)
	{
		if(h[i*2]<h[i])
		  t=i*2;
		if(i*2+1<=n)
		  if(h[i*2+1]<h[t])
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

int main()
{
	int i;
	
	n=0;
	for(i=1;i<=5;i++)//�߲����ά��������С�ѣ����ϵ���   O(NlogN)
	{
		n++;
		h[n]=in[i];
		siftup(n);
	}
	
	/*for(i=1;i<=n;i++)
	  cout<<h[i];*/
	
	int num=n;
	for(i=1;i<=num;i++)//����ѣ����µ��� 
	{
		cout<<h[1]<<" ";
		h[1]=h[n];
		n--;
		siftdown(1);
	}
	cout<<endl;
	
	for(i=1;i<=5;i++)//�Ƚ����������ά����������µ���  O(N) 
	{
		n++;
		h[n]=in[i];
	}
	for(i=n/2;i>=1;i--)
	  siftdown(i);
	
	num=n;
	for(i=1;i<=num;i++)//����ѣ����µ��� 
	{
		cout<<h[1]<<" ";
		h[1]=h[n];
		n--;
		siftdown(1);
	}
	
	getchar();getchar();
	return 0;
}
