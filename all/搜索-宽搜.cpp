#include<iostream>//����������� ʱ�临�Ӷȣ����� 
using namespace std;//����˼��:����㿪ʼ��չ�ӽڵ㣬�Կ������һ��һ����չ��ֱ������Ŀ��ڵ��Ϊ�ӽڵ� 
#include<cstdio>
//���ӣ���ˮ���� 
#define maxn 5000000+10000

int x,y,z;
struct queue
{
	int x;
	int y;
	int step;
}q[maxn];//���Ѵ�������ݽṹ-���� 
int head=1,rear=1;
int book[101][101]={0};//���Ѽǵ�Ҫ����(���Ѷ��������Ҫ���أ���������ʱ�ɲ���) 

int movex(int i)
{
	if(i==1)
	  if(q[head].x==x)
	    return -1;
	  else
	    return x;
	if(i==2)
	  return q[head].x;
	if(i==3)
	  if(q[head].x==0)
	    return -1;
	  else
	    return 0;
	if(i==4)
	  return q[head].x;
    if(i==5)
      if(y-q[head].y>=q[head].x)
        return 0;
      else
        return q[head].x-(y-q[head].y);
	if(i==6)
	  if(x-q[head].x>=q[head].y)
	    return q[head].x+q[head].y;
	  else
	    return x;
}	
	
int movey(int i)
{
	if(i==1)
	  return q[head].y;
	if(i==2)
	  if(q[head].y==y)
	    return -1;
	  else
	    return y;
	if(i==3) 
	  return q[head].y;
	if(i==4)
	  if(q[head].y==0)
	    return -1;
      else
        return 0;
	if(i==5)
	  if(y-q[head].y>=q[head].x)
	    return q[head].y+q[head].x;
	  else
	    return y;
	if(i==6)
	  if(x-q[head].x>=q[head].y)
	    return 0;
	  else
	    return q[head].y-(x-q[head].x);
}

int main()
{
	//cin>>x>>y>>z;
	x=3,y=22,z=1;
	
	q[rear].x=0;//������� 
	q[rear].y=0;
	q[rear].step=0;
	rear++;
	book[0][0]=1;//��¼�ѷ��ʸýڵ㣬�������� 
	
	while(head<rear)
	{
		
		//cout<<head<<" "<<rear<<endl;
		
		int i;
		int tx,ty;
		for(i=1;i<=6;i++)//��չ�ӽڵ� 
		{
			tx=movex(i);
			if(tx==-1)
			  continue;
	        ty=movey(i);
	        if(ty==-1)
			  continue;
			  
			if(book[tx][ty]==1)//���� 
			  continue;  
	        
	        q[rear].x=tx;
	        q[rear].y=ty;
	        q[rear].step=q[head].step+1;
	        rear++;
	        
	        book[tx][ty]=1;
	        
	        if(q[rear-1].x==z||q[rear-1].y==z)//����Ƿ��ѵ���Ŀ��ڵ� 
	        {
				cout<<q[rear-1].step<<endl;
				getchar();getchar();
	            return 0;
			}
		}/**/
		head++;//���ڵ�����չ��ϣ����ӣ����ܼ�����չ��һ�����ڵ㣩 
	}
	
	cout<<"impossible"<<endl;
	
	getchar();getchar();
	return 0;
}
