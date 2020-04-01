using namespace std;//Kahn���������ڽӱ� O(N+M)
#include<iostream>  //�����Ե����ݽṹ(queue,stack,vector�ȶ�����)��¼���=0�ĵ㣬Ȼ��ʼѭ���� 
#include<cstdio>    //�������ݽṹ�е��׵㣬����ѷ��ʣ�cnt++��������֮�����ĵ㣬����iδ����, 
#include<cstring>   //�������-1����i���-1��=0������������ݽṹ�� 
#include<queue>     //ѭ��ֱ�����ݽṹ�գ���cnt��=n˵���ж����޷����ˣ���ͼ�д������� 
#define maxn 1000+10
#define maxm maxn*maxn

int n,m,cnt;
int /*e[maxn][maxn],*/u[maxm],v[maxm],first[maxn],next[maxm],InDegree[maxn],book[maxn];
queue<int>q; 

int main()
{
	void init();init();
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		u[i]=x,v[i]=y;//<-��ͬ�� 
		next[i]=first[u[i]],first[u[i]]=i;//<-��ͬ�� 
		InDegree[y]++;
	}
	
	for(int i=1;i<=n;i++)
	  if(InDegree[i]==0)
	  	q.push(i);
	
	cnt=0;
	while(!q.empty())
	{
		int t=q.front();q.pop();cout<<t<<" ";
		cnt++;
		book[t]=1;
		
		/*for(int i=1;i<=n;i++)
		  if(e[t][i]==1&&book[i]==0)
		  {
		  	InDegree[i]--;
		  	if(InDegree[i]==0)
		  	  q.push(i);
		  }*/
		int k=first[t];//<-��ͬ�� 
		while(k!=-1)
		{
			if(book[v[k]]==0)
			{
				InDegree[v[k]]--;
				if(InDegree[v[k]]==0)
				  q.push(v[k]);
			}
			k=next[k];
		}//<-��ͬ�� 
	}
	cout<<endl;
	
	if(cnt==n)
	  cout<<"No Circles"<<endl;
	else
	  cout<<"Has Circle(s)"<<endl;
	
	return 0;
}

void init()
{
	//memset(e,0,sizeof(e));
	memset(InDegree,0,sizeof(InDegree));
	memset(book,0,sizeof(book));
	memset(first,-1,sizeof(first));//<-��ͬ��  
	return;
}
