// mergesort.cpp
#include <iostream>
using namespace std;

void merge( int *a, int *b, int *c, int n, int m)
{
	int i=0;
	int j=0,k=0;

	while(j<n and k<m)
	{
		if(b[j]<=c[k])
		{
			a[i]=b[j];
			j++;
			i++;
		}
		else
		{
			a[i]=c[k];
			k++;
			i++;
		}
	}
		while(j<n)
		{
			a[i]=b[j];
			j++;
			i++;
		}
		while(k<m)
		{
			a[i]=c[k];
			k++;
			i++;
		}
}

int main()
{
	int a[100];
	int b[]={5,6,7};
	int n= sizeof(b) / sizeof(int);
	int c[]={1,2,4,8,9};
	int m= sizeof(c) / sizeof(int);
	merge(a,b,c,n,m);

	for(int i=0; i<n+m; i++)
	{
		cout<<a[i]<<" ";
	}

	return 0;
}