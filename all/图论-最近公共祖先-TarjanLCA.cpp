using namespace std;//�����������Tarjan�����㷨(�ڽӱ�)->O(N*N+M=M+N2) ��ʵ�ڽӾ�����ڽӱ�ò�Ʋ�˶��١����ֻ��ϵ�������� 
#include<iostream>  //Ҫ�ú���Ტ�鼯�������ǿ������ 
#include<cstdio>
#include<cstring>
#define maxn 10+5
#define maxm maxn-1//��������=����-1 

int n,NumOfQuestion,rt;
int /*e[maxn][maxn],*/first[maxn],next[maxm],u[maxm],v[maxm],ans[maxn],SonOrNot[maxn];
int ancestor[maxn],book[maxn]; 

struct question
{
	int num,qt;
}question[maxn][maxn];
struct f
{
	int rank,father;
}f[maxn];

void TarjanLCA(int root)
{
    void merge(int u,int v);int getf(int v);
    
	ancestor[root]=root;
	book[root]=1;
	
	/*for(int i=1;i<=n;i++)
	  if(e[root][i]==1&&book[i]==0)
	  {
	  	TarjanLCA(i);//�������� 
	  	merge(root,i);//����������ϣ����Ӻϼ� (���鼯)<-----------------------��������ܲ��ɷ�,������ܵ��»ش���ȷ 
	  	ancestor[getf(i)]=root;//��Ǹü�(���鼯)��������ȣ���ǰ�ڵ�<---------
	  }*/
	int k=first[root];//<-��ͬ�� 
	while(k!=-1)
	{
		if(book[v[k]]==0)
		{
			TarjanLCA(v[k]);
			merge(root,v[k]);
			ancestor[getf(v[k])]=root;
		}
		k=next[k];
	}//<-��ͬ�� 
	
	for(int i=1;i<=n;i++)
	  if(question[root][i].qt==1&&book[i]==1)//�ش��йص�ǰ�ڵ��ѯ�� 
	  	ans[question[root][i].num]=ancestor[getf(i)];//�Լ����� �ο��������ͣ� http://blog.csdn.net/hnust_xiehonghao/article/details/9109295
	                                                 //                          (->���������codeò�Ʋ���)http://www.cnblogs.com/ylfdrib/archive/2010/11/03/1867901.html 
	                                                 //                          http://alanyume.com/130.html
	return;
}

int main()
{
	freopen("TarjanLCA.in","r",stdin);
	void init();init();
	
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;cin>>x>>y;//����ı�һ����"����ʽ"��x��->y�ӣ��������޷�ȷ������� 
		//e[x][y]=e[y][x]=1;
		u[i]=x,v[i]=y;//<-��ͬ�� 
		next[i]=first[u[i]],first[u[i]]=i;//<-��ͬ�������ڱ���"����ʽ",�ʲ����ٽ���"������"�� 
		SonOrNot[y]=1;//Ѱ�Ҹ��ڵ� 
	}
	cin>>NumOfQuestion;
	for(int i=1;i<=NumOfQuestion;i++)//TarjanLCA�������㷨���ȼ�¼������ѯ�� 
	{
		int x,y;cin>>x>>y;
		question[x][y].qt=question[y][x].qt=1;
		question[x][y].num=question[y][x].num=i;//ѯ��˳�� 
	}

	for(int i=1;i<=n;i++)
	{
	  f[i].father=i,f[i].rank=1;
	  if(SonOrNot[i]==0)
	    rt=i;
    }
    	
	TarjanLCA(rt);
	 
	for(int i=1;i<=NumOfQuestion;i++)
	  cout<<ans[i]<<endl;/**/
	
	return 0;
}

void init()
{
	/*memset(e,0,sizeof(e));*/
	memset(question,0,sizeof(question));
	memset(ans,-1,sizeof(ans));
	memset(SonOrNot,0,sizeof(SonOrNot));
	memset(book,0,sizeof(book));
	memset(first,-1,sizeof(first));//<-��ͬ�� 
	return;
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
	int t1=getf(u),t2=getf(v);
	if(t1!=t2)
	{
		if(f[t1].rank>=f[t2].rank)
		  f[t2].father=t1,f[t1].rank+=f[t2].rank;
		else
		  f[t1].father=t2,f[t2].rank+=f[t1].rank;
	}
}
