#include<bits/stdc++.h>
using namespace std;
 
#define LL long long

void solve(int n, LL m)
{
	vector<int> temp(n+1,0);
	vector<int>a, b; 
	for (int i = 0; i < n; ++i){
         cin>>temp[i];
    }


	int flag=0;
	for (int i = 0; i < n; ++i) {
        cin>>flag;
		if (flag == 1) {
			a.push_back(temp[i]);
		}
		else b.push_back(temp[i]);
	}
	sort(a.rbegin(), a.rend()); 
	sort(b.rbegin(), b.rend());
	int lenb = b.size();
	LL SumA = 0;
	LL SumB = accumulate(b.begin(), b.end(), 0);
	int ans = INT_MAX; 
	int lena = a.size();
	for (int i = 0; i <= lena; ++i) {
		while (lenb > 0 && SumA + SumB - b[lenb - 1] >= m) {
			--lenb;
			SumB -= b[lenb];
		}
		if (SumA + SumB >= m) {
			ans = min(ans, 2 * lenb + i);
		}
		if (i != lena) {
			SumA += a[i];
		}
	}


	if (ans == INT_MAX){
         puts("-1");
    }
	else{
        cout<<ans<<endl;
    }
}
 
 
int main(void)
{
	int t, n;
	LL m;
    cin>>t;
	while (t--)
	{
        cin>>n>>m;
		solve(n, m);
	}
	return 0;
}