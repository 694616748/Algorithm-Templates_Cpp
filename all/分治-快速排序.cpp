#include<iostream>//�������� O(NlogN)
using namespace std;//����˼�룺����������������ʵ������һ����Ҳ�ɣ���Ϊ�ο�����j����i���࣬����j���ҽ��������ҵ��Ȳο���
#include<cstdio>    //С��i������������ҵ��Ȳο�����ģ�����i��j����Ԫ�أ�����ѭ��ֱ��ij��������ʱ���������<=�ο������Ҵ���>=�ο��� 
                    //��Ȼ�˴����ǲο��������������λ�ã������λ��Ȼ����βο������󡢲ο������ң�ͬ����֮ 

int a[11]={0,10,8,3,9,2,5,6,4,7,1};

void quicksort(int left,int right)
{
  if(left>right)//û���ˣ������� 
    return;
	
  int i,j,tmp;
  i=left;//�ڱ�i����翪ʼ 
  j=right;//�ڱ�j���ҽ翪ʼ 
  tmp=a[left];//�ο��� 
  while(i!=j)
  {
		while(i<j&&a[j]>=tmp)//�ڱ�jҪ���ߣ�ֻ��j���ߣ����ܱ�֤i��j�����ĵط�����<�ο�������i����j���������ط���jͣ�µĵط�����<�ο������� 
		  j--;               //j����i�����ʱi���ϴν������i�����ϴν���ǰ��j����<�ο�����
		while(i<j&&a[i]<=tmp)
		  i++;
		
		swap(a[i],a[j]);
  }
  swap(a[left],a[i]);//���ο�����λ 
  quicksort(left,i-1);//���� 
  quicksort(i+1,right);	
}

int main()
{
	int i;
	for(i=1;i<=10;i++)
	  cout<<a[i]<<" ";
	cout<<endl;
	
	quicksort(1,10);//���Ų����������ҽ� 
	
	for(i=1;i<=10;i++)
	  cout<<a[i]<<" ";
	  
	getchar();getchar();
	return 0;
}
