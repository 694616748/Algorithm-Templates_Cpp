#include<iostream>//��ϣ��-������ 
using namespace std;//����˼�룺�ֱ�����ϣ����ϣ���ͷ����ϣ���������ù�ϣ�����ڱ�ͷ���ҵ���Ӧ����ÿ�������һ������Ԫ�أ������ϣ�����󷵻�ֵ��ͬ�� 
#include<cstdio>//����Ԫ���ڹ�ϣ���������������ͨ��ɨ������������������Ԫ�� 
 
#include<cstring>//memset()��ͷ�ļ� 

#define N 100001
#define M 200003//��˵��ͷ����M�����N��2������ 

struct hxb//��ϣ�� 
{
	int data;
	int next;
}hxb[N];

int bt[M]={-1};//��ϣ���ͷ��ò�������Ӹ�ֵ-1��ʱҲ���У� 

int hash(int x)//��ϣ���� 
{
	return x%M;
}

int main()
{
	int n,m,i;
	
	memset(bt,-1,sizeof(bt));//��ʼ����ͷ 
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>hxb[i].data;//����Ԫ�� 
		hxb[i].next=-1;//��ʼ����Ԫ�صĺ��ָ�� 
		if(bt[hash(hxb[i].data)]!=-1)//�������Ƿ�����Ԫ�أ����������ͷ���룩 
		  hxb[i].next=bt[hash(hxb[i].data)];//����Ԫ�صĺ��ָ��ɵ���ͷ 
   	    bt[hash(hxb[i].data)]=i;//���ɱ�ͷָ�����Ԫ�� 
	}
	
	int x;
	int p;
	int flag;
	for(i=1;i<=m;i++)//����(����������һ���ɨ����Ȼ��Ч�ܶ࣬��Ч�ʵĴ�С���ɱ�ͷ�͹�ϣ����Ե�������������Ȼ�ڹ�ϣ�������㹻��ǰ����
	                // ��ͷ�������ϣ�������ı�Խ��Ч��Խ�ߣ�) 
	{
		cin>>x;
		flag=0;
	    p=bt[hash(x)];
	    //cout<<p<<endl;
	    while(p!=-1)
	    {
			if(hxb[p].data==x)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			}
			p=hxb[p].next;
		}
		if(flag==0)
		  cout<<"NO"<<endl;
	}
	
	getchar();getchar();
	return 0;
}
