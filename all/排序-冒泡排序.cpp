#include<iostream>//ð������ O(N^2) 
using namespace std;//����˼�룺�����Ƚϴ���������Ԫ�صĴ�С��������������Ԫ�صĴ����෴ʱ�����н�����
#include<cstdio>//ֱ��û�з��������Ԫ��Ϊֹ��
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};

void bubble(int n)
{
	int i,j,flag;
	for(i=1;i<=n-1;i++)//ö�����������һ�������ù�λ����n-1�˼��� 
    {
	  flag=1;
	  for(j=1;j<=n-i;j++)//�����Ƚ�
	  {
	    if(a[j]>a[j+1])
		{
			a[0]=a[j];
			a[j]=a[j+1];
			a[j+1]=a[0];
			flag=0;
		}	 
	  }
	  if(flag)//�Ż������źÿ��Խ��� 
	    break;
	}
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  bubble(10);
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
}
