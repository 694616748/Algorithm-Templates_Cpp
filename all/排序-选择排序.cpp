#include<iostream>//ѡ������ O(N^2) 
using namespace std;//ÿһ�˴Ӵ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ�
#include<cstdio>//˳��������ź�������е����ֱ��ȫ�������������Ԫ�����ꡣ 
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};

void select(int n)
{
  int i,j,min,minpos;
  for(i=1;i<=n-1;i++)
  {
    min=a[i];
    minpos=i;
    for(j=i+1;j<=n;j++)
      if(a[j]<min)
      {
	    min=a[j];
	    minpos=j;
	  }
	a[minpos]=a[i];
	a[i]=min;
  }
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  select(10);
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
}
