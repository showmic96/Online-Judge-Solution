// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    typedef long long ll;
    int firstBadVersion(int n) {
        ll hi = n , low = 1 , t = 70 , ans = -1;
        while(t--){
            ll mid = (hi+low)/2;
            if(isBadVersion(mid)==true){
                ans = mid;
                hi = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
