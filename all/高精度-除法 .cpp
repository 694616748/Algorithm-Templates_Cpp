#include<iostream>//��/�� O(�̵ĸ�λ��֮��)<=(LenOf������*10) ���ɳ��� 
using namespace std;//һ��ʼ�Ȱѳ���b���쵽���(*10*10*...*10)������������a>=b 
#include<cstdio>    //Ȼ��Ϳ�ʼѭ���Գ������a>=b,��CalceMinus,����ѹ��b(/10) 
#include<cstring>   //���ѹ��b�Ľ����lb<��ʼlb,˵��a�Ѿ������ٳ���(������ԭʼb) 
#include<cmath>     //��ʱ�������� 
#define maxl 500+5  //ע�⣺1.���ڵ�����ԽѹԽ���ģ���c��λ����Խ��Խ�ߵ� 
                    //        c�Ĵ洢ʵ������1λ��ߣ�Ȼ��ÿ�ζ���lc+1��չ��Ϊ���λ 
string a1,b1;       //      2.Ϊ�˷��㵯�������ѹ����b�Ĵ洢Ҳ��1λ���lb��� 
short a[maxl],b[maxl],c[maxl];
int la,lb,originlb,lc;

void reverseb()
{
	for(int i=1;i<=lb/2;i++)
	  swap(b[i],b[lb-i+1]); 
}

void init()
{
	la=a1.length();lb=b1.length();originlb=lb;
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));//���� 
	for(int i=0;i<la;i++)
	  a[i+1]=a1[la-1-i]-'0';
	for(int i=0;i<lb;i++)
	  b[i+1]=b1[lb-1-i]-'0';
	reverseb();
}

void CalcMinus()
{
	reverseb();
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
	reverseb();
}

int cmp()//cmp a b
{
	if(la>lb)
	  return 1;
	else if(la==lb)
	{
		reverseb();
		int l=la;
		for(int i=l;i>=1;i--)
	    {
	    	if(a[i]>b[i])
	    	{
	    		reverseb();
	    		return 1;
			} 
	    	else if(a[i]<b[i])
	    	{
	    		reverseb();
	    		return 0;
			}  
		}
		reverseb();
		return 1;
	}
	else 
	  return 0;
}

void CalcDivision()
{
	while(cmp()==1)//a>=b
	{
		lb++;
		b[lb]=0;
	}
	lb--;
	/*for(int i=la;i>=1;i--)
		cout<<a[i];
	cout<<endl;
	for(int i=1;i<=lb;i++)
		cout<<b[i];
	cout<<endl;*/
	
	memset(c,0,sizeof(c));lc=1;
	while(1)
	{
		while(cmp()==1)//a>=b
		{ 
		  /*for(int i=la;i>=1;i--)
		    cout<<a[i];
		  cout<<"-";
		  for(int i=1;i<=lb;i++)
		    cout<<b[i];
		  cout<<endl;*/
		  
		  CalcMinus();
		  c[lc]++;
		}  
		
		lb--;
		if(lb<originlb)
		  break;
		lc++;
		c[lc]=0;
		
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
	for(int i=1;i<=lc;i++)
	  cout<<c[i];
	cout<<endl; 
}
