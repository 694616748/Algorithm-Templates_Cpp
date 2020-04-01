#include<iostream>//���鼯  O(logN) 
using namespace std;//��Ϊһ�����ݽṹ�����鼯����ֻ�����ֲ������ϲ����Ϻͼ���Ԫ���������� 
#include<cstdio> 

int f[101];

int getf(int v)//�� 
{
	if(f[v]==v)//���Լ��ĸ��ڵ�����Լ�����Ȼ�ýڵ��Ǹ����ĸ� 
	  return v;
	else
	{
		f[v]=getf(f[v]);//˳����������ȥ�����ﻹ��·��ѹ�����Լ��ٺ���Ĳ���
		return f[v];
	}
} 

void merge(int u,int v)
{
	int t1=getf(u);//�� 
	int t2=getf(v);//�� 
	if(t1!=t2)//�������ڵ����ͬ�����ٺϲ�
	{
		f[t2]=t1;//������ 
	} 
} 

int main()
{
	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	int n,m,i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)//��ʼ�� 
	  f[i]=i;
	  
	int x,y;
	for(i=1;i<=m;i++)//�� 
	{
		cin>>x>>y;
		merge(x,y);
	} 
	
	int sum=0;
	for(i=1;i<=n;i++) 
	  if(f[i]==i)
	    sum++;
    cout<<sum<<endl;
	
	getchar();getchar();
	return 0;
}
