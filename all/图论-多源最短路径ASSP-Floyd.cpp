#include<iostream>//Floyd-Warshall�㷨 O(N3) 
using namespace std;//����˼�룺��ÿһ���ڵ���Ϊ�м̵�ö�٣��ɳڸ���֮��ľ��� 
#include<cstdio>
#define inf 999999999

int tu[101][101];

int main()
{
	
	freopen("Floyd.in","r",stdin);
	freopen("Floyd.out","w",stdout);
	
    int i,j;//��ʼ���ڽӾ��� 
	for(i=1;i<=100;i++)
	  for(j=1;j<=100;j++)
	    if(i==j)
	      tu[i][j]=0;
	    else
	      tu[i][j]=inf;	
	
    int n,m,x,y,z;
    cin>>n>>m;//���붥����n����m 
    for(i=1;i<=m;i++)//������� 
    {
		cin>>x>>y>>z;
		tu[x][y]=z;
	}
	
	int k;//Floyd-Warshall�ɳ� 
	for(k=1;k<=n;k++)
	  for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	      if(tu[i][j]>tu[i][k]+tu[k][j])//��tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]); 
	        tu[i][j]=tu[i][k]+tu[k][j];
	
	cin>>x>>y;
	cout<<tu[x][y]<<endl;
	
	getchar();getchar();
	return 0;
}
