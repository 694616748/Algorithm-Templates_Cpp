#include<iostream>//��+�� O(max(lenA,lenB)) 
using namespace std;//ûʲô����ģ�����ģ������ӷ�
#include<cstdio>    //ע�⣺1.�������� 
#include<cstring>   //      2.�˷���λ���� 
#define maxl 500+5

string a1,b1;
unsigned short a[maxl],b[maxl],c[2*maxl];//����c[2*maxl] 
int la,lb,l;

void init()
{
	la=a1.length();lb=b1.length();
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));//���� 
	for(int i=0;i<la;i++)
	  a[i+1]=a1[la-1-i]-'0';
	for(int i=0;i<lb;i++)
	  b[i+1]=b1[lb-1-i]-'0';
}

void CalcTimes()
{
	memset(c,0,sizeof(c));//����
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			int ca,cb;
			ca=i,cb=j-1;
			
			c[ca+cb]+=a[i]*b[j];
			c[ca+cb+1]+=c[ca+cb]/10;c[ca+cb]%=10; 
			//cout<<c[ca+cb]<<" ";
		} 
		//cout<<endl;
	} 
	
	l=la+lb;
	if(c[l]==0)
	  l--;
}

int main()
{	
	cin>>a1>>b1;
	
	init();//�����ַ���a b��������� 
    CalcTimes(); 
	void PrintOut();PrintOut(); 
	
	return 0;
}

void PrintOut()
{
	for(int i=l;i>=1;i--)
	  cout<<c[i];
	cout<<endl; 
}
