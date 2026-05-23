class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        
        while(!q.empty()){
            int level = q.size();
            for(int i = 0 ; i < level ; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr){
                    q.push(curr->left);
                    q.push(curr->right);
                    // Fixed: Safely handles any integer using to_string
                    s += to_string(curr->val) + ","; 
                }
                else{
                    // Fixed: Using string literal for the null marker
                    s += "#,"; 
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string item;
        
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // 1. Process Left Child
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    TreeNode* leftNode = new TreeNode(stoi(item));
                    curr->left = leftNode;
                    q.push(leftNode);
                }
            }
            
            // 2. Process Right Child
            if (getline(ss, item, ',')) {
                if (item != "#") {
                    TreeNode* rightNode = new TreeNode(std::stoi(item));
                    curr->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        
        return root;
    }
};