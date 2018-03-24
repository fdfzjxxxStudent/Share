#include<iostream>
#include<algorithm>
#include<iomanip>
#define ERR 0.000001
#define N 100005 
using namespace std;
double v[N],p[N],z[N];
int n,k;
bool OK(double x){
	for(int i=0;i<n;i++) z[i]=v[i]-x*p[i];
	sort(z,z+n);
	double sum=0;
	for(int i=n-k;i<n;i++)sum+=z[i];
	return sum>=0;
}	
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++) cin>>v[i];
	double maxv=*max_element(v,v+n);
	double minp=*min_element(p,p+n);
	double r;
	if(minp==0) r=100;
	else r=maxv/minp;
	double l=0,ans=0;
	while(r-l>ERR){
		double mid=l+(r-l)/2;
		if(OK(mid)) ans=l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(2)<<ans*100<<"%"<<endl;
	return 0;
}
