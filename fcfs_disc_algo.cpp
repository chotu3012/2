//vinay
#include<bits/stdc++.h>
using namespace std;


int fcfs_disk(vector<int>&a,int n,int head)
{

	int sum=0;
    sum=abs(a[0]-head);
	for(int i=1;i<n;i++){
		sum+=abs(a[i]-a[i-1]);
	}
	return sum;
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
	cout<<"Total process time is "<<fcfs_disk(a,n,head);

}
