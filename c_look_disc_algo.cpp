//vinay
#include<bits/stdc++.h>
using namespace std;

int sum=0;
int c_look(vector<int>&v,int n,int head,string dir)
{
	int ind=0;
	
	for(int i=0;i<n;i++)
		{
			
			if(v[i]<=head)
				ind++;
			else 
			 break;
		}
		
      cout<<"Path:-"<<endl;
        cout<<head<<" ";
		if(dir=="right"){
			sum+=abs(v[ind]-head);
			for(int i=ind;i<n-1;i++)
				{
					cout<<v[i]<<" ";
					if(i!=n-1)
					sum+=abs(v[i]-v[i+1]);
				}

               
                sum=2*sum;
				sum+=abs(v[ind-1]-head);
				for(int i=ind-1;i>=0;i--)
				{
				   cout<<v[i]<<" ";
				   if(i!=0)
				   sum+=abs(v[i]-v[i-1]);
				}

				for(int i=0;i<ind;i++)
   				{   
   					if(i!=0)
					cout<<v[i]<<" ";
					if(i!=ind-1) 
					sum+=abs(v[i]-v[i+1]);
				}
			cout<<endl;
			return sum;
		}
		else 
		{
			ind--;
			sum+=abs(v[ind]-head);
			
				for(int i=ind;i>=0;i--)
				{
				   cout<<v[i]<<" ";
				   if(i!=0)  
				   sum+=abs(v[i]-v[i-1]);
				}

				sum=abs(head-v[ind+1])+2*sum;

			  for(int i=ind+1;i<n-1;i++){
			  		
			   		if(i!=n-1)
			     	sum+=abs(v[i]-v[i+1]);
			   }

			  for(int i=n-1;i>ind;i--)
			  {
			  	
			  		cout<<v[i]<<" ";
			  	if(i!=ind+1)
			  	sum+=abs(v[i]-v[i-1]);
			  }
				cout<<endl;
				return sum;
		}
}

int main()
{
	int n;
	cin>>n;

	vector<int>v(n);

	for(int i=0;i<n;i++)
		 cin>>v[i];    

		int head;
		cin>>head;   //head position
		
		string dir;
		cin>>dir;  //select direction (left/right)
		sort(v.begin(),v.end());

		cout<<"Total cost ="<<c_look(v,n,head,dir);
		
}