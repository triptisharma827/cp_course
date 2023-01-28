#include<bits/stdc++.h>
using namespace std;
// #define vector<vector<int>> mat;
void val(int i,int j,vector<vector<int>> &a ){
    a[i][j]=1;
    a[j][i]=1;
    // cout<<"here";
}
int main(){

    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> a(n,vector<int> (m,0));
    val(0,1,a);
    val(1,2,a);
    // val(2,1,a);
    val(2,0,a);

    // for(auto i: a){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}