typedef long long int ll;

class Solution {
    ll LCM (ll x, ll y) {
        return (x * y) / __gcd (x, y);
    }
    
    bool IsPossible (ll max_value, const int divisor1, const int divisor2, const int uniqueCnt1, const int uniqueCnt2) {
        ll valid = max_value;
        
        ll both_invalid = max_value / LCM (divisor1, divisor2);
        ll arr1_invalid = max_value / divisor1 - both_invalid;
        ll arr2_invalid = max_value / divisor2 - both_invalid;
        
        ll can_be_in_any = max_value - arr2_invalid - arr1_invalid - both_invalid;
        
        if (arr2_invalid < uniqueCnt1) can_be_in_any -= (uniqueCnt1 - arr2_invalid);
        if (arr1_invalid < uniqueCnt2) can_be_in_any -= (uniqueCnt2 - arr1_invalid);
        
        return (can_be_in_any >= 0);
    }
    
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll l = 1, r = 2e9;
        while (l < r) {
            ll m = (l+r) >> 1;
            
            if (IsPossible(m, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) r = m;
            else l = m+1;
        }
        return l;
    }
};
