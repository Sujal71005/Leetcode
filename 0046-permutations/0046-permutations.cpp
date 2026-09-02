class Solution {
public:
    void find_permutation(vector<int>& nums, vector<vector<int>>& ans, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            find_permutation(nums, ans, idx+1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> combination;
        int idx = 0;
        find_permutation(nums, ans, idx);
        return ans;
    }
};