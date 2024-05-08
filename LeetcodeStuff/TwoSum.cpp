class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        for(int i =0;i<nums.size() -1;i++){
            int t = nums[i] + nums[i+1];
            if (t == target){
                ans.push_back(i);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
