#include<iostream>
using namespace std;

void heapsort(int a[],int l);
void maxheap(int i,int a[],int l);
void makemaxheap(int a[],int l);
int getleft(int i,int l);
int getright(int i,int l);
void swap(int i,int j,int a[]);



int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;++i)
        cin>>a[i];
    heapsort(a,n);
    for(i=0;i<n;++i)
        cout<<a[i]<<" ";
    return 0;
}


void makemaxheap(int a[],int l)
{
    int i;
    for(i=l/2-1;i>-1;--i)
        maxheap(i,a,l);   
}


void maxheap(int i,int a[],int l)
{
    int a1,a2,j=i;
    
    a1=getleft(i,l);
    a2=getright(i,l);
    
    if(a[a1]>a[i] && a1<l)
        j=a1;
    else
        j=i;
    
    if(a[a2]>a[j] && a2<l)
        j=a2;
    
    if(j!=i)
    {
        swap(i,j,a);
        maxheap(j,a,l);
    }
}


int getleft(int i,int l)
{
    return 2*i+1;
}


int getright(int i,int l)
{
    return 2*i+2;
}
    


void swap(int i,int j,int a[])
{
    int c;
    c=a[i];
    a[i]=a[j];
    a[j]=c;
}

void heapsort(int a[],int l)
{
    makemaxheap(a,l);
    int i; 
    int l1=l;
    for(int i=l1-1;i>0;--i)
    {
        swap(0,i,a);
        --l;
        maxheap(0,a,l);    

    }
}

