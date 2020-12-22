#include <iostream>
#include <vector>

using namespace std;

bool rec(vector<int> v, int sum, int n)
{
   if(n<0) return false;
   if(sum==0) return true;
   return rec(v,sum,n-1) || rec(v,sum-v[n],n-1);
}

int main()
{
   int i, j, sum, n;
   cin >> n >> sum;
   vector<int> v(n);
   for(i=0;i<n;i++) cin >> v[i];

   if(rec(v,sum,n-1)) cout << "Possible\n";
   else cout << "Not Possible";
}
