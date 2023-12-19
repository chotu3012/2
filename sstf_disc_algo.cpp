//vinay
#include<bits/stdc++.h>
using namespace std;


int sstf_disk(vector<int>&a,int n,int *head)
{
	int mini=INT_MAX;
	int ind;
	for(int i=0;i<n;i++)
	{
		int x=abs(a[i] - *head);
		if(x<mini && a[i]!=-1)
		{
			mini=x;
			ind=i;
		}
	}
	*head=a[ind];
	a[ind]=-1;
	return mini;
}

int main()

{
	int n;
	cin>>n;
	vector<int>a;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	int head;
	cin>>head;
	int sum=0;
	
	sort(a.begin(),a.end());
	
	for(int i=0;i<n;i++)
	{
		sum+=sstf_disk(a,n,&head);
	}
	
	cout<<"Total process time is "<<sum;
}