#include<iostream>//��+�� O(max(lenA,lenB)) 
using namespace std;//ûʲô����ģ�����ģ������ӷ��������Ż�Ϊ��10000�� 
#include<cstdio>    //ע�⣺1.�������� 
#include<cstring>
#define maxl 500+5

string a1,b1;
unsigned short a[maxl],b[maxl],c[maxl+1];//����c[maxl+1] 
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

void CalcPlus()
{
	memset(c,0,sizeof(c));//���� 
    l=max(la,lb);
    for(int i=1;i<=l;i++)
    {
    	c[i]+=a[i]+b[i];
    	c[i+1]+=c[i]/10;c[i]%=10;//��λ 
	}
	if(c[l+1]>0)
	  l++;
}

int main()
{
	cin>>a1>>b1;
	
	init();//�����ַ���a b��������� 
    CalcPlus(); 
	void PrintOut();PrintOut(); 
	
	return 0;
}

void PrintOut()
{
	for(int i=l;i>=1;i--)
	  cout<<c[i];
	cout<<endl; 
}
