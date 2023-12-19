//vinay
#include<bits/stdc++.h>
using namespace std;

int ct=0;//completion time
pair<int,int> mini(vector<vector<int>>&a,int n)
{
    int mini=INT_MAX;
    int ind;
    a[0][2]=-1;//for first one
    for(int i=0;i<n;i++)
    {
        if(a[i][2]<mini && a[i][2]!=-1 && a[i][0]<=ct){
            mini=a[i][2];
            ind=i;
        }
    }
    a[ind][2]=-1;//assigning -1  to find next highest prority
    int bt=a[ind][1];
    return {ind,bt};//returning minimum burst time index and burst time
}

void SJF(vector<vector<int>>&a,int n)
{
    cout<<"The Ganttchart is "<<endl;
    int turn;
    int total_wt=0;
    int total_turn=0;
    int wt=0;
    

    
    int at;//arrival time
    int bt;//busrt time
    for(int i=0;i<n;i++)
    {
        pair<int,int>pb;
        
        if(i==0){
            cout<<"P"<<a[i][3]<<" ";
            at=a[i][0];
            bt=a[i][1];
        }
        else
        {
         pb=mini(a,n);
         int j=pb.first;//index
        cout<<"P"<<a[j][3]<<"  ";
           at=a[j][0];
           bt=pb.second;//burst time (minimun)
        }

        if(at > ct)
           ct=at+bt;
        else 
           ct=ct+bt;
            

        turn=ct-at;//turn around time
        wt=turn-bt;//weighting time
        total_turn+=turn;  //totol turn around time
        total_wt+=wt;   //total weighting time 

      

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
        int x,y,z;
        cin>>x>>y>>z;
        a[i].push_back(x);//arrival time
        a[i].push_back(y);//burst time
        a[i].push_back(z);//priority
        a[i].push_back(i+1);//p1,p2....
    }

    //sort(a.begin(),a.end());

    SJF(a,n);
}