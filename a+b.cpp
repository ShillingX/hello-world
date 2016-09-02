#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[401]={0,1};
void mi(){
	for(int i=1;i<=400;i++){
		a[i]*=2;
	}
	for(int i=1;i<=400;i++){
		if(a[i]>9){
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
}
int main(){
	//freopen("2333.in","r",stdin);
	//freopen("2333.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		mi();
	}
	int total=400;
	for(;;total--){
		if(a[total]!=0){break;}}
	for(int i=total;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
