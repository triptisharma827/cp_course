#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int num;
        cin>>num;

        string red,blue;
        cin>>red>>blue;


        int n=red.size();
        int redn=0;
        int bluen=0;
        
        
        for(int i=0;i<n;i++){
            if(red[i]>blue[i]){
                redn++;
            }
            else if(blue[i]>red[i]){
                bluen++;
            }
        }


        if(redn>bluen){
            cout<<"RED"<<endl;
        }
        else if(bluen>redn){
            cout<<"BLUE"<<endl;
        }
        else{
            cout<<"EQUAL"<<endl;
        }
        
        t--;
    }
    return 0;
}