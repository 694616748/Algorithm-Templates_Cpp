#include<iostream>//�������� O(N^2) 
using namespace std;//����˼�룺ÿ�ν�һ�������������Ԫ�أ����뵽ǰ���Ѿ��ź����
#include<cstdio>//�����е��ʵ�λ�ã�ʹ������Ȼ����ֱ������������Ԫ��ȫ��������Ϊֹ��
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};

void insert(int n)
{
  int i,j;
  
  for(i=2;i<=n;i++)//ö�ٲ������
  {
	a[0]=a[i];
    for(j=i-1;j>=1;j--)//�����ź���������в����ʵ���λ��
   {
	  if(a[j]>a[0])
	    a[j+1]=a[j];//���Ų
	  else
	    break;//��λ���ɴ���֤��j�Խ�������ͬһ�����Ϻ��������ڽ�ǰ����ĺ��棬��j��������֮�� 
   } 
   a[j+1]=a[0]; 
  } 
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  insert(10);
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
}
