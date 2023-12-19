#include<bits/stdc++.h>
using namespace std;
struct process
{
	string pID;
	int at,bt,ct,priority,tat,wt;
};
void priemptive_priority(process *p,int n)
{
	int burst[n];
	for(int i=0;i<n;i++)
	{
		burst[i]=p[i].bt;
	}
	int time=0;
	int count=0;
	while(count<n)
	{
		int selected=-1;
		int highPriority=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(p[i].at<=time and p[i].priority<highPriority and p[i].bt>0)
			{
				selected=i;
				highPriority=p[i].priority;
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
				p[selected].ct=time;
				p[selected].tat=p[selected].ct-p[selected].at;
				p[selected].wt=p[selected].tat-burst[selected];
				count++;
			}
		}
	}
}
void display(process *p,int n)
{
	cout<<"PID at bt prio ct tat wt"<<endl;
	for(int  i=0;i<n;i++)
	{
		cout<<p[i].pID<<"  "<<p[i].at<<"  "<<p[i].bt<<"  "<<p[i].priority<<"    "<<p[i].ct<<"   "<<p[i].tat<<"   "<<p[i].wt<<endl;
	}
}
int main()
{
	int n;
	cout<<"enter number of processes: "<<endl;
	cin>>n;
	process p[n];
	cout<<"enter the process Id ,arrival time ,burst time and priority"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].pID>>p[i].at>>p[i].bt>>p[i].priority;
	}
	priemptive_priority(p,n);
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
