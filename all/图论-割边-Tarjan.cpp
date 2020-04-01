#include<iostream>   //Tarjan����㷨  O(N+M)
using namespace std;//����˼�룺���һ�����㷵����ҵ��Ķ�����СҲ�ȸ��ڵ�Ҫ����Ȼ�ö����޷��ڲ��������ڵ�������»ص����Ƚڵ㣬�ʸ�·��Ϊ��� 
#include<cstdio>    //ע�⣺������ǣ�low[i]>=num[cur] ��ֻҪ����ϸ�������㡱�͡��ߡ���������Ϊʲô 
#include<algorithm>//min()
#define N 51
#define M 101

int u[M],v[M];
int first[N];
int next[M];

int n,m;
int index;
int num[N];
int low[N];

void dfs(int cur,int father)
{
	index++;
	num[cur]=index;
	low[cur]=index;
	
	int k=first[cur];
	while(k!=-1)
	{
		if(num[v[k]]==0)
		{
			dfs(v[k],cur);
			low[cur]=min(low[cur],low[v[k]]);
			
			if(low[v[k]]>num[cur])//�����㷨ֻ�д˴���ͬ������������ͬ 
			  cout<<cur<<"-"<<v[k]<<endl;
		}
		else if(v[k]!=father)
		{
			low[cur]=min(low[cur],num[v[k]]);
		}
		
		k=next[k];
	}
}
	
int main()
{
	freopen("Tarjan2.in","r",stdin);
	freopen("Tarjan2-2.out","w",stdout);
	
	int i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
	  first[i]=-1;
	  num[i]=0;
	}
	
	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		
		next[i]=first[u[i]];
		first[u[i]]=i;
    }
    for(i=m+1;i<=2*m;i++)
    {
		u[i]=v[i-m];
		v[i]=u[i-m];
		
		next[i]=first[u[i]];
		first[u[i]]=i;
	}
    
    int root=1;
    index=0;
    dfs(1,root);
	
	getchar();getchar();
	return 0;
}
