#include<iostream>//STL��sort()����  O(NlogN)
using namespace std;
#include<cstdio>
#include<algorithm>//����sort������ͷ�ļ�

short a[11]={0,1,2,4,3,5,6,9,7,10,8};

bool cmp(int a,int b)//���ر�����bool�ͣ��ú�����������ʽ 
{
	return a<b;//a<b����true a>b����false ,�������� 
}

int main()
{
  int i;
  for(i=1;i<=10;i++)
   cout<<a[i]<<" ";
  cout<<endl;
  
  sort(a+1,a+1+10,cmp);//����1����������׵�ַ(���ﲻ��a[0]��a+1������a) 
                       //����2���������ĩ��ַ����һ����ַ��˵���˾��� �׵�ַ+������Ԫ�س���
					   //����3������or���� ���� 
  for(i=1;i<=10;i++)
   cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
} 
