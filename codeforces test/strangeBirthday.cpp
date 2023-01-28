#include <bits/stdc++.h>
#include <math.h>
using namespace std;

long long mod(long long x){
    if(x<0){
        x = -x;
    }
    return x;
}

long long add(long long num1, long long num2){
    return mod(mod(num1)+mod(num2));
}

long long multiply(long long num1, long long num2){
    return mod(mod(num1)*mod(num2));
}

long long modPow(long long num1, long long num2){
    if(num2==0)
        return 1LL;
    if(num2==1)
        return num1;
    long long result=1;
    while(num2){
        if(num2%2==1)
            result=multiply(result,num1);
        num1=multiply(num1,num1);
        num2=num2/2;
    }
    return result;
}

void solve(){
    int a,b;
    cin>>a>>b;
    vector<long long>arr1(a);
    vector<long long>arr2(b);
    for(int i=0;i<a;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<b;i++){ 
        cin>>arr2[i];
    }

    sort(arr1.begin(),arr1.end(),greater<>());

    long long total=0;
    int j=0;
    for(int i=0;i<a;i++){
        if(j<b){
            if(arr2[j]<arr2[arr1[i]-1]){
                total+=arr2[j];
                j++;
            }
            else{
                total+=arr2[arr1[i]-1];
            }
        }
        else{
            total+=arr2[arr1[i]-1];
        }
    }
    cout<<total<<"\n";
 }

int main(){
    cout<<fixed;
    cout<<setprecision(10);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        solve();
    }
    return 0;
}