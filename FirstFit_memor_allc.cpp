//vinay
//First Fit memorey Allocation
#include<bits/stdc++.h>
using namespace std;

int inter_frag=0;
int ex_frag=0;

void firstfit(vector<int>&mem,vector<int>&pro,int n,int m)
{

		vector<int>v(m,-1);//to store which procces occupied which block
		vector<int>a(n,-1);//to check memorey occupied or not
		for(int i=0;i<m;i++)//proccess traversal
		{
			for(int j=0;j<n;j++)//memorey traversal
			{
				if(pro[i]<=mem[j] && a[j]==-1)
				{
					   a[j]=0;//means that memorey filled
					   v[i]=j+1;//storing the block number for a proccess
					   inter_frag+=mem[j]-pro[i];//for internal fragmentation
					   break;
					}

				}
			}

          //for external fragmentation
			int extrMem=inter_frag, extrPro=0;
			bool f=0;
			for(int i=0;i<m;i++)
				{
					if(v[i]==-1)
						{
							extrPro+=pro[i];
							f=1;
						}
				}
			for(int j=0;j<n;j++)
			    {
			      if(a[j]==-1){
			      extrMem+=mem[j];
			      f=1;
			  	}
			    }

				if(extrPro <=extrMem && f)
					ex_frag=extrMem;


			 cout<<"Process_Id \t"<<"Proccess_size\t "<<"Memorey_Block"<<endl;
			 for(int i=0;i<m;i++){
			 	cout<<"P"<<i+1<<"\t \t \t "<<pro[i]<<" \t \t \t";
			 			if(v[i]!=-1)cout<<"Block-"<<v[i]<<"("<<mem[v[i]-1]<<")"<<endl;
			 			else cout<<"Not allotted"<<endl;
			 		}

			 		cout<<"Internal Fragmentation"<<endl;
			 		cout<<inter_frag<<endl;
			 		cout<<"External Fragmentation"<<endl;
			 		cout<<ex_frag<<endl;
		  
    }


int main()
{
	int n;
	cin>>n;//no of memorey blocks
	
	vector<int>mem(n);
	for(int i=0;i<n;i++)
	  cin>>mem[i];
	int m;
	cin>>m;// no of process
	vector<int>pro(m);

	
	for(int i=0;i<n;i++)
		cin>>pro[i];

	firstfit(mem,pro,n,m);
}