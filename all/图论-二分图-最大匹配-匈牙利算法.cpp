#include<iostream>//�������㷨  O��NM�� 
using namespace std;//����˼��:ö������һ�ߵĶ��㣬��ÿһ�����в��Կ��ö����Ƿ���Գɹ�ƥ�����ɹ���ƥ��+1�����Զ����Ƿ���Գɹ�ƥ�䣺DFS(ע������)
#include<cstdio>    //�����붥�������ıߣ��鿴����DFS��δ���ʹ��Ķ����Ƿ�����ƥ�䣬����ƥ��������1.�ö���δƥ�� �� 2.�õ����������Ӧ��Ҳ��DFS�жϣ� 
#include<cstring>//memset()

int book[101];//����DFS������
int match[101];//���ڼ�¼ƥ���ϵ
int sum=0;//���ƥ�䣨�������ۼ���
int e[101][101];

int n,m;

int dfs(int u)
{
	int i;
	for(i=1;i<=n;i++)//ö�ٶ�����б��� 
	{
		if(e[u][i]==1&&book[i]==0)//���õ��뵱ǰ����ͨ��δ������
		{
			book[i]=1;
			if(match[i]==0||dfs(match[i])==1)//���õ㻹û��ƥ����߿��Բ���������Ӧ��ǰ�������֮ƥ��
			{
				match[i]=u;
				match[u]=i;
				return 1;//����ƥ��ɹ� 
			}
			
		}
	}
	return 0;//����ƥ��ʧ��
} 

int main()
{
    int i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=m;i++)	
	{
		int x,y;
		cin>>x>>y;
		e[x][y]=1;
		e[y][x]=1;
	}
	
	memset(match,0,sizeof(match));//��ʼ��ƥ������ 
	sum=0;
	for(i=1;i<=n;i++)//ö������һ�ߵĶ������ƥ��(���ݶ���ͼ�����ʿ�ֻ֪��ö��ƥ������һ�ߵĶ���)
	{
		memset(book,0,sizeof(book));//����һ������ƥ��ǰ��Ҫ������DFS���ص�book��0
		if(dfs(i)==1)//����õ�ƥ��ɹ������ƥ��+1 
		  sum++;
	} 
	
	cout<<sum<<endl;
	
	getchar();getchar();
	return 0;
}
