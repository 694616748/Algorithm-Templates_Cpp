#include<iostream>//�����������  O(Xn)  
using namespace std;//����˼�룺������ȣ�������������ֱ���߽磬Ȼ����ݣ��ٷ��ʻ��ݺ�ڵ����һ�ڵ� 
#include<cstdio>
#include<cmath>
//���ӣ�N�ʺ����� 

int ans=0;
int n;	
int sel[14]={0};
		
int check(int deep)
{
	int i;
	for(i=1;i<=deep-1;i++)//�����ѷ��õĻʺ� 
	  if(sel[i]==sel[deep]||abs(i-deep)==abs(sel[i]-sel[deep]))//����Ƿ�ͬ�� �Ƿ�ͬб�ߣ���Ȼ������ͬ�У� 
	    return 0;
	return 1;
}

void dfs(int deep)
{
	if(deep>n)
	  ans++;
	else
	{
		int i;
		for(i=1;i<=n;i++)//Ϊ��ǰdeep����ûʺ� 
		{
			sel[deep]=i;
			if(check(deep))//����Ƿ��г�ͻ 
			  dfs(deep+1);
		}
	}
}
			
int main()
{
	cin>>n;
	
	ans=0;
	dfs(1);
	
	cout<<ans<<endl;
	
	getchar();getchar();
	return 0;
}
