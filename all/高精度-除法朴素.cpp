#include<iostream>//��/�� O(�̵Ĵ�С) 
using namespace std;//�����Գ�����ÿ�ο��������ܲ���CalcMinus������ֱ������(ʵ���Ͼ��ǳ���ת�����˼����㣬����) 
#include<cstdio>    
#include<cstring>   
#define maxl 500+5

string a1,b1;
short a[maxl],b[maxl],c[maxl]; 
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

int CalcMinus()
{
	if(la<lb)
	  return 0;
	if(la==lb)
	{
		for(int i=la;i>=1;i--)
		  if(a[i]<b[i])
		    return 0;
	}
	for(int i=1;i<=la;i++)
	{
		if(a[i]<b[i])
		{
			a[i+1]--;
			a[i]+=10;
		}
		a[i]-=b[i];
	}
	
	while(a[la]==0)
	  la--;
	return 1;
}

void CalcDivision()
{
	memset(c,0,sizeof(c));
	while(CalcMinus()==1)
	{
	  c[1]++;
	  for(int i=1;i<=l;i++)
	  {
		c[i+1]+=c[i]/10;c[i]%=10;
	  }  
	  if(c[l+1]>0)
	  l++;
	}
}

int main()
{	
	cin>>a1>>b1;
	
	init();//�����ַ���a b��������� 
    CalcDivision(); 
	void PrintOut();PrintOut(); 
	
	return 0;
}

void PrintOut()
{
	for(int i=l;i>=1;i--)
	  cout<<c[i];
	cout<<endl; 
}
