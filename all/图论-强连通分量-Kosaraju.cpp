using namespace std;//ǿ��ͨ����SCC(Strongly Connected Component)-Kosaraju�㷨 O(2*(N+M)) 
#include<iostream>  //��ԭͼG����һ��DFS����������ʱ��¼ÿ���ڵ��"����ʱ���"(Ҳ��ͨ��ѹջʵ��) 
#include<cstdio>    //Ȼ������"����ʱ���"�ѷ�ͼGr����DFS��������u�ܵ���v��˵��u vǿ��ͨ�����ò� 
#include<cstring>  //�鼯���кϲ���2��DFS���������Եĵ�ǿ��ͨ������ɵĲ��鼯�� 
#include<stack>    //��ȷ��֤������pΪ�ڵ��"����ʱ���"����Kosaraju�㷨�Ĳ��������ڶ���DFS�д��� 
#define maxn 100+10 //u->v��һ����������ô�ض���������2������: 
#define maxm 1000+10//1.����ԭͼG,����u<-v  2.pu>pv 
                    //��������2�����������ڵ���������2�����ҽ�������2���������(����ԭͼG��DFS) 
int n,m,first[5][maxn],next[5][maxm],u[5][maxm],v[5][maxm],vis[maxn];
stack<int>s;       //1.v����uΪ�����������ķǸ��ڵ�  2.u��v����ͨ����u���ڵ���ͼ��v���ڵ���ͼ������� 
struct node        //����Ϊ��ͼGrDFS����u<-v(����1)���������2��������ֻ�����1������ 
{ int rank,father; }f[maxn];//�ۺ� ����1�����1֪����ԭͼG�У�u->v u<-v ��u vǿ��ͨ 
void merge(int u,int v);    //����֤��u vǿ��ͨ��v tǿ��ͨ����u tǿ��ͨ����u v t�໥ǿ��ͨ(������) 
                            //�ʴ�Kosaraju�㷨����ȷ�Ե�֤ 
void dfs(int t,int flag)
{
	/*if(flag==2) 
	  cout<<t<<" ";*/
	int k=first[flag][t];
    while(k!=-1)
    {
    	if(vis[v[flag][k]]==0)
    	{
    		if(flag==2)
    	      merge(u[flag][k],v[flag][k]);//cout<<"merge:"<<u[flag][k]<<"&"<<v[flag][k]<<endl;
    		vis[v[flag][k]]=1;
		    dfs(v[flag][k],flag);
		}
		k=next[flag][k];
	}
	if(flag==1)
	  s.push(t);//cout<<t<<" ";
	
	return;
}

int main()
{
	freopen("graph.in","r",stdin);
	
	cin>>n>>m;
	memset(first[1],-1,sizeof(first[1]));
	for(int i=1;i<=m;i++)
	{
		cin>>u[1][i]>>v[1][i];
		next[1][i]=first[1][u[1][i]];first[1][u[1][i]]=i;
	}
	
	//cout<<"backtrce index of dfs1:";
	memset(vis,0,sizeof(vis));//������ͼG
	while(!s.empty()) s.pop(); 
	for(int i=1;i<=n;i++)
	{
		f[i].rank=1;f[i].father=i;//���鼯���ںϲ�ǿ��ͨ�ĵ� 
		if(vis[i]==0)
		{
			vis[i]=1;
		    dfs(i,1);
		}
	}//cout<<endl; 
	
	memset(first[2],-1,sizeof(first[2]));
	for(int i=1;i<=m;i++)//������ͼG�õ���ͼGr 
	{
		u[2][i]=v[1][i];v[2][i]=u[1][i];
		next[2][i]=first[2][u[2][i]];first[2][u[2][i]]=i;
	}
	
	//cout<<"dfs2:"<<endl;
	memset(vis,0,sizeof(vis));//������ͼGr 
	while(!s.empty())
	{
		int i=s.top();
		if(vis[i]==0)
		{
			vis[i]=1;
		    dfs(i,2);
		}
		s.pop();
	}//cout<<endl;
	
	//cout<<"SCCs:"<<endl;
	for(int i=1;i<=n;i++)
		if(f[i].father==i)
		{
			for(int j=1;j<=n;j++)
			  if(f[j].father==i)
			    cout<<j<<" ";
			cout<<endl;
		}
	
	return 0;
}

int getf(int v)
{
	if(f[v].father==v)
	  return v;
	else
	{
		f[v].father=getf(f[v].father);
		return f[v].father;
	}
}

void merge(int u,int v)
{
	int t1=getf(u);
	int t2=getf(v);
	if(u!=v)
	{
		if(f[t1].rank>=f[t2].rank)
		{
			f[t2].father=t1;f[t1].rank+=f[t2].rank;
		}
		else
		{
			f[t1].father=t2;f[t2].rank+=f[t1].rank;
		}
	}
}
