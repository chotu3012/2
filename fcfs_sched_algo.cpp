//vinay
#include<bits/stdc++.h>
using namespace std;



void FCFS(vector<vector<int>>a,int n)
{
 	
 	cout<<"The Ganttchart is "<<endl;
 	int turn;
 	int total_wt=0;
 	int total_turn=0;
 	int wt=0;
 	int ct=0;

 	
 	for(int i=0;i<n;i++)
 	{
 		cout<<"P"<<a[i][2]<<"  ";

 	    if(a[i][0] > ct)
 	       ct=a[i][0]+a[i][1];
        else 
           ct=ct+a[i][1];
           

 	    turn=ct-a[i][0];
 		wt=turn-a[i][1];
 		total_turn+=turn;
 		total_wt+=wt;

 	}
 	cout<<endl;
    
    float avgturn=(float)total_turn/n;
    float avgwt=(float)total_wt/n;
 	cout<<"The Average Turn Around Time is "<<avgturn<<endl;
 	cout<<"The Average Wating Time is "<<avgwt<<endl;

}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>a(n);

	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[i].push_back(x);//arrival time
		a[i].push_back(y);//burst time
		a[i].push_back(i+1);//p1,p2....
	}

	sort(a.begin(),a.end());

	FCFS(a,n);
}