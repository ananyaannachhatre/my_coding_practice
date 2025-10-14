class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        // Arrays to store the previous smaller and next smaller indices
        vector<int> prev(n, -1), nxt(n, n);
        
        // Stack to help find the previous smaller element indices
        stack<int> s;
        
        // Find previous smaller element indices
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (!s.empty()) {
                prev[i] = s.top();
            }
            s.push(i);
        }
        
        // Clear the stack to reuse it for finding next smaller elements
        while (!s.empty()) s.pop();
        
        // Find next smaller element indices
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nxt[i] = s.top();
            }
            s.push(i);
        }
        
        // Now calculate the maximum area
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = nxt[i] - prev[i] - 1;  // Width of the rectangle
            maxi = max(maxi, width * heights[i]);  // Calculate area and update maxi
        }
        
        return maxi;
    }
};