class Solution {
public:
    
    bool f(vector<int>& nums , long long m , long long x){
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>x){
                if(nums[i]>x)return false;
                m--;
                if(m<1)return false;
                sum = nums[i];
            }
            else{
                sum = sum+nums[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long hi = 1e18 , low = 0 , ans = 1e18 , t = 200;
        while(t--){
            long long mid = (hi+low)/2;
            if(f(nums,  m, mid)==true){
                ans = mid;
                hi = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};