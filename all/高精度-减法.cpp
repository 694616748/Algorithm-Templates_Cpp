#include<iostream>//��-�� O(max(lenA,lenB)) 
using namespace std;//ûʲô����ģ�����ģ����������������Ż�Ϊ��10000�� 
#include<cstdio>    //ע�⣺1.�������� 
#include<cstring>   //      2.����������while����λ�� 
#define maxl 500+5  //      3.����Ǹ�����0�Ĵ��� 
                    //      4.����Ҫ��λ���ʲ���unsigned 
string a1,b1;
short a[maxl],b[maxl];//ֱ����a/b�ϼ�������unsigned������ 
int la,lb,l,fuhao;

void init()
{
	la=a1.length();lb=b1.length();
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));//���� 
	for(int i=0;i<la;i++)
	  a[i+1]=a1[la-1-i]-'0';
	for(int i=0;i<lb;i++)
	  b[i+1]=b1[lb-1-i]-'0';
}

void CalcMinus1()
{
	l=la;
    for(int i=1;i<=l;i++)
    {
    	if(a[i]<b[i])
		{
			a[i+1]--;
			a[i]+=10; 
		} 
		a[i]-=b[i];
	}
	while(a[l]==0)
	  l--;
}

void CalcMinus2()
{
	l=lb;
    for(int i=1;i<=l;i++)
    {
    	if(b[i]<a[i])
		{
			b[i+1]--;
			b[i]+=10; 
		} 
		b[i]-=a[i];
	}
	while(b[l]==0)//while!!
	  l--;
}

int main()
{
	cin>>a1>>b1;
	
	init();//�����ַ���a b��������� 
	fuhao=1;//�������� 
	if(la<lb||(la==lb&&a1<b1))
      fuhao=-1;
	if(fuhao==-1)
	  CalcMinus2();
	else
      CalcMinus1(); 
	void PrintOut();PrintOut(); 
	
	return 0;
}

void PrintOut()
{
	if(l==0)//�㴦�� 
	{
		cout<<"0"<<endl;
		return;
	}
	if(fuhao==-1)//�������� 
	{
	  cout<<"-";
	  for(int i=l;i>=1;i--)
	    cout<<b[i];
	}
	else
	{
	  for(int i=l;i>=1;i--)
	    cout<<a[i];
	}
	cout<<endl; 
}
