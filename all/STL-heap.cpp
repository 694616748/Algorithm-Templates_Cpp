#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>//���㷨��ͷ�ļ�

int h[11]={0,10,5,7,2,4,3,9,8,1,6};

int cmp(int a,int b)
{
	return a>b;
} 

int cmp2(int a,int b)
{
	return a<b;
} 

int main()
{
	make_heap(&h[1],&h[10+1]);//������make_heap(ͷָ��,βָ��,�Ƚϲ���)��Ĭ������ 
	
	for(int i=1;i<=10;i++)//���ѱ������������� 
	  cout<<h[i]<<" ";
	cout<<endl;
	
	make_heap(&h[1],&h[10+1],cmp);//������С�ѣ�ע��cmp������������ 
	
	for(int i=1;i<=10;i++)//��С�ѱ������������� 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	h[11]=11;
	push_heap(&h[1],&h[10+1+1],cmp);//����cmp�ıȽϷ��������Ԫ�� 
	  
	for(int i=1;i<=11;i++)//��С�ѱ������������� 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	pop_heap(&h[1],&h[10+1+1],cmp);//�Ѷ�����(ʵ�����ǽ������ڶ�β��ʹ�ö�Ԫ��-1) 
    
    for(int i=1;i<=10;i++)//��С�ѱ������������� 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	cout<<h[11]<<endl;
	
    int k[11]={0,10,5,7,2,4,3,9,8,1,6};
    
    sort_heap(&k[1],&k[10+1],cmp2);//������ 
    
    for(int i=1;i<=10;i++)//��С�ѱ������������� 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	getchar();getchar();
	return 0;
} 
