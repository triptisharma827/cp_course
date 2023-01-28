#include<bits/stdc++.h>
using namespace std;
// #define vector<vector<int>> mat;
void val(int i,int j,vector<vector<int>> a ){
    a[i][j]=1;
    a[j][i]=1;
}
int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n*m);
    val(0,1,a);
    val(1,2,a);
    val(2,1,a);
    val(2,0,a);

    for(auto i: a){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;

}