class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0 , r = 0 , ans = 1;
        multiset<int>st;
        while(r!=nums.size()){
            if(st.size()==0){
                st.insert(nums[r]);
                r++;
            }
            else{
                int mi = *st.begin();
                int mx = *--st.end();
                if(mx-mi>limit){
                    auto it = st.upper_bound(nums[l]-1);
                    st.erase(it);
                    l++;
                }
                else{
                    st.insert(nums[r]);
                    mi = min(nums[r], mi);
                    mx = max(nums[r], mx);
                    r++;
                    if(mx-mi>limit)continue;
                }
            }
            
            ans = max(ans , (int)st.size());
        }
        return ans;
    }
};
