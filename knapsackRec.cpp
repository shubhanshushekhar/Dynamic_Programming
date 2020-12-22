#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector< pair<int,int> > val,int wt, int cur)
{
   if(cur >= val.size()) return 0;
   int ans = max(knapsack(val, wt, cur+1), knapsack(val, wt- val[cur].second , cur+1) + val[cur].first);
   return ans;
}

int main()
{
   int i, j, max_wt,n;
   cin >> n >> max_wt;
   vector< pair<int,int>  > val(n);
   for(i=0;i<n;i++) cin >> val[i].first >> val[i].second;
   cout << knapsack(val,max_wt, 0);
}
