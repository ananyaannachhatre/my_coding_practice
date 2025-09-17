class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; 
        permuteHelper(nums, 0, result);
        return result;
    }

private:
    void permuteHelper(vector<int>& nums, int idx, vector<vector<int>>& result) {
        // Base case: when idx reaches the size of nums, add the current permutation to the result
        if (idx == nums.size()) {
            result.push_back(nums); 
            return;
        }

        // Recursive case: generate permutations by swapping each element
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]); // Swap the current element with idx
            permuteHelper(nums, idx + 1, result); // Recurse for the next position
            swap(nums[idx], nums[i]); // Backtrack by swapping back
        }
    }
};