#include<bits/stdc++.h>
using namespace std;
#define DP unordered_map<int, unordered_map<int,int>>

int solve(string &word1, string &word2,int f_idx,int s_idx , DP &dp){
    if(f_idx==word1.size()){
        return word2.size()-s_idx;
    }
    if(s_idx==word2.size()){
        return word1.size()-f_idx;
    }
    // if its already present in dp 
    if((dp.find(f_idx)!=dp.end() && dp[f_idx].find(s_idx)!=dp[f_idx].end() )==true){
        return dp[f_idx][s_idx];
    }



    if(word1[f_idx]==word2[s_idx]){
        return dp[f_idx][s_idx]= solve(word1,word2,f_idx+1,s_idx+1,dp);
    }


    int remove=solve(word1,word2,f_idx+1,s_idx,dp);
    int replace=solve(word1,word2,f_idx+1,s_idx+1,dp);
    int insert=solve(word1,word2,f_idx,s_idx+1,dp);

    return dp[f_idx][s_idx]=1+min(remove,min(replace,insert));

} 


int main() {
    string word1="horse";
    string word2="ros";
    int f_idx=0;
    int s_idx=0;
    DP dp;
    cout<<solve(word1,word2,f_idx,s_idx,dp)<<endl;
    return 0;
}