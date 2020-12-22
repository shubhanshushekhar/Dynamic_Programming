#include<iostream>
#include<vector>

using namespace std;
vector< vector<int> > dp(2000, vector<int>(2000,-1));

int knapsack(vector< pair<int,int> > ar, int n, int wt)
{
    if(n<0) return 0;
    if(dp[n][wt]!=-1) return dp[n][wt];
    else 
      {
        dp[n][wt] = max(knapsack(ar, n-1, wt),
        knapsack(ar,n-1,wt-ar[n].second)+ar[n].first);
        return dp[n][wt];
      }
}

int main()
{
    int n, wt; cin >> n >> wt;
    vector< pair<int, int>  > value(n);
    for(int i=0;i<n;i++) cin >> value[i].first >> value[i].second;
    cout << knapsack(value, n-1, wt);
}
