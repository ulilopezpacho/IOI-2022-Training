#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
 
using namespace std;
 
int dp (int from, int to, int beforeLevel, int level, vector<int> &nums) {
    
    if (to-from == 1 && nums[to] > level) return 1;
    int sumaParcial = level - beforeLevel;
    int first = -1, minLevel = 1;
 
    for (int i = from; i < to; i++) {
        if (first == -1 && nums[i] > level) {
            first = i;
            minLevel = nums[i];
        }
        if (first != -1 && (nums[i] <= level || i == to-1)) {
            sumaParcial += dp(first, (i == to-1 && nums[i] > level? i+1:i), level, minLevel, nums);
            first = -1;
        }
        if (first != -1 && nums[i] > level) {
            minLevel = min(minLevel, nums[i]);
        }
    }
    return min(to-from, sumaParcial);
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
    vector<int> nums (n);
    forn (i,n) cin >> nums[i];
       
    if (n == 1 && nums[0] == 0) cout << 0 << "\n";
    else cout << dp(0, n, 0, 0, nums) << "\n";
}