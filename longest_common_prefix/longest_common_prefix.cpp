class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        
        // Edge case: empty input
        if (strs.empty()) return prefix;
        
        // Loop through each character of the first string
        for (int k = 0; k < strs[0].size(); k++) {
            // Check each string for the current character at position k
            for (int i = 1; i < strs.size(); i++) {
                // If the k-th character is not the same across all strings, return the current prefix
                if (k >= strs[i].size() || strs[i][k] != strs[0][k]) {
                    return prefix;
                }
            }
            // If all strings have the same k-th character, append it to the prefix
            prefix += strs[0][k];
        }
        
        return prefix;
    }
};
