//vinay
#include<bits/stdc++.h>
using namespace std;


 vector<int>a;
 int hit=0;
 int k=0;//to keep count in number of frames
 int c=0;//no of page faults


void print(vector<int>&v,int i,int x,int n)
{

  	if(a.size()<x){

	  		 cout<<"Previous: ";
		 	for(auto val:a)cout<<val<<" ";
		 		cout<<endl;

		 	 cout<<"Updated : ";
		auto it=find(a.begin(),a.end(),v[i]);
		  	 if(it!=a.end()){
		  	 		cout<<"Hit("<<v[i]<<")"<<endl<<endl;
		  	 		hit++;
		  	 	}
		 else{ 	 	
	          
		    a.push_back(v[i]);
		   
		    for(auto va:a)
		    	 cout<<va<<" ";
		    	cout<<endl<<endl;
		    	c++;
	    }
  	}


    else{
		  	cout<<"Previous: ";
		  	for(auto va:a) cout<<va<<" ";
		  		cout<<endl;

		     cout<<"Updated : ";
			  	auto it=find(a.begin(),a.end(),v[i]);
			  	 if(it!=a.end()){
			  	 		cout<<"Hit("<<v[i]<<")"<<endl<<endl;
			  	 		hit++;
			  	 	}
			  	 else{
			  	 	if(k==x)k=0;
			  	 	a[k]=v[i];
			  	 	k++;
			  	 	c++;//no of page faults
			  	 	for(auto va:a)
			  	 		cout<<va<<" ";

			  	 		cout<<endl<<endl;
			  	 }
       }
}
void fifo(vector<int>&v, int x, int n)
{

	for(int i=0;i<n;i++)
		print(v,i,x,n);
	
}

int main()
{
    int n,x;
    cin>>n>>x;
	vector<int>v;	

	for(int i=0;i<n;i++)
		{
			int z;
			 cin>>z;
			 v.push_back(z);
		}

	fifo(v,x,n);
	cout<<"Number of page falls : "<<c<<endl;
	cout<<"No of Hits : "<<hit<<endl;
}