class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        int f = -1 , l = -1;
        for(auto element: nums){
            mp[element]++;
        }
        for(auto element: nums){
            mp[element]--;
            int req = target - element;
            if(mp[req]!=0){
                f = element;
                l = req;
                break;
            }
        }
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int element = nums[i];
            if(element==f||element==l){
                v.push_back(i);
            }
        }
        return v;
    }
};