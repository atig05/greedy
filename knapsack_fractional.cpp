#include<bits/stdc++.h>
using namespace std;
void swap(pair<int,int> *a,pair<int,int> *b){
	pair<int,int> t=*a;
	*a=*b;
	*b=t;
}
int partition(pair<int,int> a[],int i,int n){
	
	int pi=i;
	int l=i;
	int r=n;

	while(l<r){
			while(a[l].second/a[l].first<=a[pi].second/a[pi].first ){
			l++;
		}		
		while(a[r].second/a[r].first>a[pi].second/a[pi].first &&r>0){
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

float max_profit(int w[],int v[],int n,int tw){
	pair<int,int> arr[n];
	for(int i=0;i<n;i++){
		pair<int ,int> t;
		t.first=w[i];
		t.second=v[i];
		arr[i]=t;
	}
	quick(arr,0,n-1);
	float p=0;
	int i=n-1;
	while(tw){
		//cout<<p<<endl;
		if(tw>=arr[i].first){
			tw-=arr[i].first;
			p+=arr[i].second;
		}
		else{
			p+=tw*(arr[i].second/arr[i].first);
			tw=0;
		}
		i--;
	}
	return p;
}
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
//weight--40 10 20 24
//value--280 100 120 120
int main(void){
	cout<<"Number of elements--";
	int n;
	cin>>n;
	int w[n],v[n];
	int tw;
	cout<<"Total capacity--";
	cin>>tw;
	cout<<"enter  weights--";
	in(w,n);
	cout<<"enter Values--";
	in(v,n);
	cout<<max_profit(w,v,n,tw);
	return 122;
}
