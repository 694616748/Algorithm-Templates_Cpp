#include<iostream>//Dijkstra�㷨 �����Ż� 
using namespace std;//�Ż������ȶ��У����ӿ��˲�����С����ֵ���ٶȣ���N��ΪlogN(�Լ���������ͼ���֪�����˶���) 
#include<cstdio>
#define inf 999999999
#include<queue>//���ȶ���ͷ�ļ� 

int u[101],v[101],w[101];
int first[101],next[101];

int dis[101];
//���ȶ����Ż����ǲ���Ҫbook�ģ���Ϊbook����������P��Q�������ȶ����Ż������ȶ���q����Q 
//��˵�ˣ��Ż�ǰbook���������ڲ��ҹ���ֵ�е���Сֵ�����ڶ��������ˣ�book�͸��Ӳ���Ҫ�� 

struct number//���ȶ��еĽṹ��
{
	int num;//
	int w;//
	bool operator < (const number &a) const//��������� 
	{//
		return w>a.w;//ʹ�ð�Ȩֵ��С�����Ŷ� 
	}//
};//

priority_queue<number>q;//�������ȶ��� 

int main()
{
	
	freopen("di.in","r",stdin);
	
	int n,m,i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	  first[i]=-1;
	
	for(i=1;i<=n;i++)
	  dis[i]=inf;
	
	int point=1;//Ĭ��Դ��Ϊ����1 
	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		next[i]=first[u[i]];
	    first[u[i]]=i;
	    
	    if(u[i]==point)
	    {
	    	dis[v[i]]=w[i];
	    	
	    	struct number x;//�õ���Դ��ֱ����ͨ��������ͨ�߼������ȶ��� 
	    	x.num=v[i];//
	    	x.w=w[i];//
	    	q.push(x);//
	    }
	      
	}
	
	dis[point]=0;
	
    while(!q.empty())//�����й���ֵ��ʱ(Q���ϲ���ʱ)ִ��ѭ�� 
    {
	  struct number x=q.top();//��������ֵ��Դ������Ķ��� 
	  q.pop();//
	  
	  if(x.w!=dis[x.num])//����ÿ����չ���㶼�����ɳڣ����ɳڱ�Ȼ����ͬһ����������ӡ�����������ķ�����������dis�� 
	    continue;        //������(��dis�е�ֵ�ض������µ�) ���Դ˻رܵ������Ԫ�� 
	  
	  int k=first[x.num];
	  while(k!=-1)
	  {
	    if(dis[v[k]]>dis[u[k]]+w[k]) //д���ˣ���dis[v[k]]>w[k] 
	    {
	      dis[v[k]]=dis[u[k]]+w[k];//д���ˣ���dis[v[k]]=w[k] 
		  if(dis[v[k]]<inf)//ÿ���ɳں�����һЩ�����Դ��Ĺ���ֵ���£�Ҫ���(�����ظ�������������ѽ��)	
		  {                //��ס����inf��Щû��Ҫ��ӵ���ӡ�����book�Ͳ���Ҫ�����ˣ�ԭ����� 
			struct number y;//
			y.num=v[k];//
			y.w=dis[v[k]];//
			q.push(y);//
		  }//
	    } 
	    k=next[k];
	  }	
	} 
	
	for(i=1;i<=n;i++)
	  cout<<dis[i]<<" ";
	
	getchar();getchar();
	return 0;
}
