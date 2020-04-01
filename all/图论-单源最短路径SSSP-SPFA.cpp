#include<iostream>//SPFA(Shortest Path Faster Algorithm):Bellman-Ford�Ķ����Ż� 
using namespace std;//����˼·���е�����ѣ����ݽ��ɳڸ��ߣ�����һ��������������ӣ���Ϊ��Ȼ���ö������·�����޸������ĳ��߶��㼰������ 
#include<cstdio>    //�������·��Ҳ��仯(���)������Ҫ�ٴ�����޸ĺ����ڵ㡣 
                    // ���Bellman-Ford�ŵ�����ÿ�ο��������չ�ǲ����Ǳ������еı߶��ǳ�������ڽӱ������������չ����ĺ��� 
#define inf 999999999 

int dis[101];
int u[101],v[101],w[101];
int first[101],next[101];

int book[101];

int q[101];
int head=1,rear=1;

int main()
{
	freopen("be2.in","r",stdin);
	freopen("be2.out","w",stdout);
	
	int n,m,i;
	cin>>n>>m;
	
	int point=1;
	for(i=1;i<=n;i++)
	{  
		first[i]=-1;
		book[i]=0;
		dis[i]=inf;
    }
    dis[point]=0;

	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		
		next[i]=first[u[i]];
		first[u[i]]=i;
    }
	
	q[rear]=point;
	book[point]=1;
	rear++;
	
	while(head<rear)
	{
		int p=first[q[head]];
		
		while(p!=-1)
		{
			if(dis[v[p]]>dis[u[p]]+w[p])
			{
				dis[v[p]]=dis[u[p]]+w[p];
				if(book[v[p]]==0)
				{
					book[v[p]]=1;
					q[rear]=v[p];
				    rear++;
				}
			}
			p=next[p];
			
		}
		head++;
		book[q[head]]=0;//˳����ˣ� 
	}
	
	for(i=1;i<=n;i++)
	  cout<<dis[i]<<" ";
	
	getchar();getchar();
	return 0;
}
