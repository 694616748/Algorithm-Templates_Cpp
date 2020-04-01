using namespace std;//Astart�㷨 O(��BFS��DoubleBFSһ�㶼С�ܶ࣬��Ҫȡ����H����) 
#include<iostream>//Astart�㷨��BFS�Ļ�����ͨ����������ʵ���Ż�����������f(i)=g(i)+h(i) 
#include<cstdio>  //����g(i)������ǰ״̬����������ɢ�ȣ�h(i)������ǰ״̬�����յ����ɢ�ȣ�h(i)�ֳ��������� 
#include<cstring> //������Dijkstra(f(i)>=0)��ѡ��open����f(i)��С�ļ���closed����״̬�Ľ�ӹ��Ʊ�Ϊȷ�� 
#include<cstdlib> //Ȼ���ٴӸ�״̬������չ����չ�ڵ�1.�����չ����״̬��closed����������Ϊ��״̬�Ľ��Ѿ�ȷ���ˣ�
#include<queue>   //2.�������closed��&&����open������ӽ�open��3.�����open�����ܷ��ɳ�f(��ʱ����g/h��δ��f) 
#include<set>     //�ܾ��ɳڷ�������
#define inf 999999999//�����ȷ�Ի���������1.�������h*(i)���м�ڵ�i��Ŀ��ڵ��ʵ�ʷ��ã�h(i)�ǹ��Ʒ��ã����
                    //                      ���� �κ� �ڵ�i����h(i)<=h*(i)&&g(start)=h(end)=0�����ù��ۺ���f(i)=g(i)+h(i)һ�����Եõ����Ž⡣ 
                    //                     2.f(i)>=0���ɳ������ι�ϵ���� 
int n,m,sx,sy,ex,ey,e[10][10];
int num[10][10],f[10*10],pre[10*10];
//num����ͼ�еĵ���(�Ա��������꣬������Ǳ��)��f�Ǹõ��ӦF����(�Ա����Ǹõ���)��pre��¼ǰ���ڵ�(�Ա����ǵ�ǰ����) 
//���ں����漰�����ȶ����еĵ��f���£���������ӳ��ͷ�ӳ��(num��fnum���Ǳ��裬������ɣ�������������ʽʵ����ͬ����) 
int next[5][5]={{0,1},{1,0},{0,-1},{-1,0}};

struct fnum//num�ķ�ӳ��(�Ա����Ǳ�ţ�������Ǳ��) 
{ int x,y; }fnum[10*10];
struct node
{ 
  int x,y;
  int step;
  int g,h;//G������H�����������Թ����⣬Gһ����step������(��㵽״̬�ľ���)��H������������پ��루���ã���ŷʽ���롢�ж�ѩ������ 
  bool operator < (const node &a) const
  { return (a.g+a.h)<(g+h); }
};

priority_queue<node>open;//open�� 
int closed[10][10];//closed���Ӳ�ͬ���Ҳ������set��map�� 
int inq[10][10];//����Ƿ����/�˶� 

int mht(int x1,int y1,int x2,int y2)//��������·�� 
{ return abs(x1-x2)+abs(y1-y2); }

int main()
{
	freopen("Astart.in","r",stdin);
	
	void init();init();
	cin>>n>>m;
    int cnt=0;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	char t;cin>>t;
	  	if(t=='1')
	  		e[i][j]=1;
		else
		{
			cnt++;
			num[i][j]=cnt;fnum[cnt].x=i,fnum[cnt].y=j;
			pre[cnt]=-1,f[cnt]=inf;
		    if(t=='c')
	  		  sx=i,sy=j;
	  	    else if(t=='b')
	  		  ex=i,ey=j;
		}  
	  }
	
	struct node t;
	t.x=sx,t.y=sy;
	t.step=0;
	t.g=0,t.h=mht(sx,sy,ex,ey);f[num[sx][sy]]=t.g+t.h;
	open.push(t);
	inq[sx][sy]=1;
	
	while(!open.empty())
	{
		struct node t=open.top();
		
		while(!open.empty()&&f[num[t.x][t.y]]!=t.g+t.h)
		{ open.pop();t=open.top(); }
		open.pop();closed[t.x][t.y]=1;//����closed��ֵ��ȷ�� 
		//�����ȵ�������չ�ڵ㣬��Ϊ�ڵ�������ȶ��к�ͻ��������pop�Ķ���front�Ϳ��ܲ���������ˣ�����pop��� 
		
		for(int i=0;i<=3;i++)
		{
			int dx=t.x+next[i][0];
			int dy=t.y+next[i][1];
			if(e[dx][dy]==1||dx<1||n<dx||dy<1||m<dy)
			  continue;
			if(closed[dx][dy]==1)//����closed���У���ȷ��ֵ�������޸�(���㲻continueҲû�취���ɳڡ���) 
			  continue;
			
			int dg=t.g+1;
			int dh=mht(dx,dy,ex,ey);
			if(inq[dx][dy]==1)//����ڶ��� 
			{
				if(dg+dh<f[num[dx][dy]])//�����ɳ� 
				  ;
				else
				  continue;
			}
			
			f[num[dx][dy]]=dg+dh;
			
			struct node v;
			v.x=dx,v.y=dy;
			v.step=t.step+1;
			v.g=dg,v.h=dh;
			open.push(v);inq[dx][dy]=1;
			//cout<<v.g<<" "<<v.h<<" "<<dx<<","<<dy<<endl;
			pre[num[dx][dy]]=num[t.x][t.y];
			
			if(dx==ex&&dy==ey)//�������·�� 
			{
				cout<<v.step<<endl;
				int k=num[dx][dy];
				while(k!=-1)
				{
					cout<<"("<<fnum[k].x<<","<<fnum[k].y<<") <- ";
					k=pre[k];
				}
				cout<<"start"<<endl;
				return 0;
			}/**/
		}
	}
    
	return 0;
}

void init()
{
	memset(e,0,sizeof(e));
	memset(num,0,sizeof(num));
	memset(fnum,-1,sizeof(fnum));
	while(!open.empty())
	  open.pop();
	memset(closed,0,sizeof(closed));
}

