#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[100001],b[100001],c[100002];
int la,lb;
void high_add(){
	int m=max(la,lb);
	for(int i=1;i<=m;i++){
		c[i]+=a[i]+b[i];
		if(c[i]>9){
			c[i+1]++;
			c[i]-=10;
		}
	}
}
void high_dec(){
	int m=max(la,lb);
	for(int i=1;i<=m;i++){
		c[i]+=a[i]-b[i];
		if(c[i]<0){
			c[i+1]--;
			c[i]+=10;
		}
	}	
}
void high_to(){
	int m=max(la,lb);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			c[i+j-1]+=a[i]*b[j];
			if(c[i+j-1]>9){
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
			}
		}
	}
}
int main(){
	char x[100001],y[100001];
	//cin>>la>>lb;
	cin>>x>>y;
	la=strlen(x);lb=strlen(y);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=la;i>=1;i--){
		char m; m=x[la-i+1]; a[i]=m-'0';
	}
	for(int i=lb;i>=1;i--){
		char m; m=y[lb-i+1]; b[i]=m-'0';
	}
	high_to();
	int n=la+lb;
	for(int i=n;i>=1;i--){
		if(i==n && c[i]==0)continue;
		cout<<c[i];
	}
	return 0;
}
