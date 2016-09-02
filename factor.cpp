#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[3001]={0,1};
void decer(int n){
	for(int i=1;i<=3000;i++){
		a[i]*=n;
	}
	for(int i=1;i<=3000;i++){
		if(a[i]>9){
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
}
int main(){
	freopen("6666.in","r",stdin);
	freopen("6666.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;return 0;
	}
	if(n==2){
		cout<<1;return 0;
	}
	for(int m=2;m<n;m++){
		decer(m);
	}
	int total=3000;
	for(;;total--){
		if(a[total]!=0){break;}}
	for(int i=total;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
