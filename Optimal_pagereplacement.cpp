
//vinay
#include<bits/stdc++.h>
using namespace std;

 vector<int>a;
 int hit=0;
 int k=0;//to keep count in number of frames
 int c=0;//no of page faults

void print(vector<int>&v,int i,int x,int n)
{

  	if(a.size()<x){    //frame size

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


    else{							//a.size equal to frame size(x)
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

			  	 	int ind=i+1;
			  	 	int ct=0;
			  	 	map<int,int>mp; 
			  	 	for(auto j=0;j<x;j++)mp[a[j]]=1;
			  	 	int k=5;//for max
			  	 	for(int j=ind;j<n;j++){

			  	 		if(mp[v[j]]==1){
			  	 		        mp[v[j]]=k++; //to get last element (upcoming element)
			  	 			 	ct++;
			  	 		}
			  	 		if(ct==x)break;
			  	 	}

			  	 	int y,ma=INT_MIN;
			  	 	
			  	 	for(auto va:mp){
			  	 		if(va.second>ma){
			  	 			ma=va.second;
			  	 			y=va.first;
			  	 		}
			  	 		else if(va.second == 1){//if there is no same element in future
			  	 			y=va.first;
			  	 			break;
			  	 		}
			  	 	}
			  	 	for(int j=0;j<x;j++){
			  	 		if(a[j]==y){ 
			  	 	      a[j]=v[i];break;}
			  	 	}
			  	 	c++;//no of page faults
			  	 	for(auto va:a)
			  	 		cout<<va<<" ";

			  	 		cout<<endl<<endl;
			  	 }
       }
}
void Optimal(vector<int>&v, int x, int n)
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

	Optimal(v,x,n);
	cout<<"Number of page faults : "<<c<<endl;
	cout<<"No of Hits : "<<hit<<endl;
}