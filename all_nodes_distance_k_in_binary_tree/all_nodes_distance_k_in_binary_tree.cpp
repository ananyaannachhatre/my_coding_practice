class Solution {
public:
    // Helper function to build the graph (parent pointers)
    void buildGraph(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (root == NULL) return;
        
        parentMap[root] = parent;  // Store the parent pointer
        
        // Recursively set parent for left and right children
        buildGraph(root->left, root, parentMap);
        buildGraph(root->right, root, parentMap);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        
        // Step 1: Build the graph with parent pointers
        buildGraph(root, NULL, parentMap);
        
        // Step 2: Perform BFS from the target node
        queue<pair<TreeNode*, int>> q;  // pair(node, current distance)
        unordered_set<TreeNode*> visited;
        vector<int> result;
        
        q.push({target, 0});
        visited.insert(target);
        
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            
            if (dist == k) {
                result.push_back(node->val);
            }
            
            // Check neighbors: left child, right child, parent
            if (node->left && visited.find(node->left) == visited.end()) {
                visited.insert(node->left);
                q.push({node->left, dist + 1});
            }
            if (node->right && visited.find(node->right) == visited.end()) {
                visited.insert(node->right);
                q.push({node->right, dist + 1});
            }
            if (parentMap[node] && visited.find(parentMap[node]) == visited.end()) {
                visited.insert(parentMap[node]);
                q.push({parentMap[node], dist + 1});
            }
        }
        
        return result;
    }
};

// Helper function to build a binary tree from an array
TreeNode* buildTree(const vector<int>& values) {
    if (values.empty()) return NULL;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (i < values.size() && values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}