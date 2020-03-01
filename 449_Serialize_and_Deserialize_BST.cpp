//===========================================================================================
// 449. Serialize and Deserialize BST

// Serialization is the process of converting a data structure or object into a sequence of bits 
// so that it can be stored in a file or memory buffer, 
// or transmitted across a network connection link to be reconstructed later in the same or 
// another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. 
// There is no restriction on how your serialization/deserialization algorithm should work. 
// You just need to ensure that a binary search tree can be serialized to a string and 
// this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Note: Do not use class member/global/static variables to store states. 
// Your serialize and deserialize algorithms should be stateless.
//===========================================================================================

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	if(root == NULL){
    		return "";
    	}
        string res = "";
        res = res + to_string(root->val);      
        string left = "";
        if(root->left){
        	left = serialize(root->left);
        }
        string right = "";
        if(root->right){
        	right = serialize(root->right);
        }
        return res+left+right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	TreeNode* root = new TreeNode(data[0]-'0');   
    	int mid = -1; 	
        for(int i = 1; i < data.size(); i++){
        	if(data[i]-'0' > root->val){
        		mid = i-1;
        		break;
        	}        	
        }
        if(mid >= 1){
        	string left = data.substr(1, mid);
        	root->left = deserialize(left);
        }
        if(mid > 0){
        	string right = data.substr(mid+1);
        	root->right = deserialize(right);
        }        
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));