#include<iostream>//Ͱ���� O(N) 
using namespace std;//����˼�룺������b��a��ÿһ��Ԫ�ؽ��б�ǣ����м��b����Щ��������� 
#include<cstdio>
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};
short b[10001]={0};//ͰҪ�����㹻�󣡣� 

void bucket(int n)
{
	int i,j;
	for(i=1;i<=n;i++)//��Ͱ 
	  b[a[i]]++;
	  
	for(i=1;i<=10000;i++)//�����ʵ���ϲ�û�и�a��������ֻ�Ƕ�a�е�����b�б���ˣ� 
	  if(b[i])
	    for(j=1;j<=b[i];j++)
	      cout<<i<<" ";
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  bucket(10); 
  
  getchar();getchar();
  return 0;
}
