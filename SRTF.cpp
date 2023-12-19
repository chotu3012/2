#include<bits/stdc++.h>
using namespace std;
struct process
{
	string pID;
	int at,bt,ct,tat,wt;	
};
void SRTF(process *p,int n)
{
	int burst[n];
	for(int i=0;i<n;i++)
	{
		burst[i]=p[i].bt;		
	}
	int count=0;
	int time=0;
	while(count<n)
	{
		int selected=-1;
		int lowBurstTime=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(p[i].at<=time and p[i].bt<lowBurstTime and  p[i].bt>0)
			{
				selected=i;
				lowBurstTime=p[i].bt;
			}
		}
		if(selected==-1)
		{
			time++;
		}
		else
		{
			time++;
			p[selected].bt--;
			if(p[selected].bt==0)
			{
				cout<<p[selected].pID<<"  "<<time<<"   "<<endl;
				p[selected].ct=time;
				p[selected].tat=p[selected].ct-p[selected].at;
				p[selected].wt=p[selected].tat-burst[selected];
				count++;	
			}
		
		
		}
	}
	
}
void Sort(process *p,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				swap(p[j],p[j+1]);
			}
		}
	}
}
void SSort(process *p,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].pID>p[j+1].pID)
			{
				swap(p[j],p[j+1]);
			}
		}
	}
}
void display(process *p,int n)
{
	cout<<"PID   at   bt   ct   tat   wt"<<endl;
	for(int  i=0;i<n;i++)
	{
		cout<<p[i].pID<<"  "<<p[i].at<<"  "<<p[i].bt<<"  "<<p[i].ct<<"   "<<p[i].tat<<"   "<<p[i].wt<<endl;
	}
}
int main()
{
	int n;
	cout<<"enter number of processes : ";
	cin>>n;
	process p[n];
	cout<<"enter the process Id(p1,p2..) , arrival time and burst time"<<endl;
	int tempBurst[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i].pID>>p[i].at>>p[i].bt;
		tempBurst[i]=p[i].bt;
	}
	
	Sort(p,n);
	
	SRTF(p,n);
	SSort(p,n);
	for(int i=0;i<n;i++)
	{
		p[i].bt=tempBurst[i];
	}
	display(p,n);
	int total_turn=0;
	int total_wait=0;
	float avg_turn;
	float avg_wait;
	for(int i=0;i<n;i++)
	{
		total_turn+=p[i].tat;
		total_wait+=p[i].wt;
	}
	avg_turn=(float)total_turn/n;
	avg_wait=(float)total_wait/n;
	cout<<"Average turn around time : "<<avg_turn<<endl;
	cout<<"Average waiting time : "<<avg_wait<<endl;
	
}

