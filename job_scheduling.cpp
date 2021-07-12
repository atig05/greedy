#include<bits/stdc++.h>
using namespace std;
void swap(pair<int,int> *a,pair<int,int> *b){
	pair<int,int> t=*a;
	*a=*b;
	*b=t;
}
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
int partition(pair<int,int> a[],int i,int n){
	
	int pi=i;
	int l=i;
	int r=n;

	while(l<r){
	
		
		while(a[l].second<=a[pi].second){
			l++;
		}
		
		while(a[r].second>a[pi].second &&r>0){
			r--;
		}
		
		if(l>=r)
			break;
			
		else
			swap(&a[l],&a[r]);	
	
	}
	//if(l=r)
//	if(l)	
		swap(&a[r],&a[pi]);	
	return r;
}
void quick(pair<int,int> a[],int i,int r){
	
	if(i>=r)
		return;
	int m=partition(a,i,r);
//	cout<<"m-- "<<m<<" i- "<<i<<endl;
	quick(a,i,m-1);
	quick(a,m+1,r);
}

int max_profit(int t[],int p[],int n){
	pair<int,int> arr[n];
	for(int i=0;i<n;i++){
		pair<int ,int> a;
		a.first=t[i];
		a.second=p[i];
		arr[i]=a;
	}
	quick(arr,0,n-1);	
	bool slot[n];
	int P=0;
	for(int i=0;i<n;i++){                      //=(n-1<t[i])?n-1:
		slot[i]=false;
	}
	for(int i=n-1;i>=0;i--){
		
		int j=arr[i].first;
		for(j;j>0;j--){
			if(!slot[j-1]){
				slot[j-1]=true;
				P+=arr[i].second;
				break;
			}
		}
	
	}
	return P;
}
//deadline-- 5 3 3 2 4 2
//profit-- 200 180 190 300 120 100
int main(void){
	cout<<"Number of jobs--";
	int n;
	cin>>n;
	int t[n],p[n];
	int tw;
	cout<<"enter  dead lines--";
	in(t,n);
	cout<<"enter profit--";
	in(p,n);
	cout<<max_profit(t,p,n);
	return 122;
}
