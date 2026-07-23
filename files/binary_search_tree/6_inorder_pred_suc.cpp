class Solution {
	// in inorder traversal first node that is greater than the given node.
	// Since bst inorder traversal is sorted, we can employ something
	Node* inOrderSuccessor(Node* root, int key) {
		if (root == nullptr)
			return nullptr;
		
		Node* ans = nullptr;
		if (root->data <= key) {
			ans = inOrderSuccessor(root->right, key);
		}
		else {
			ans = inOrderSuccessor(root->left, key);
			if(ans==nullptr) ans = root;
		}
		
		return ans;
	}
	
	Node* inOrderPred(Node* root, int key) {
		// The last node < given one.
		
		if (root == nullptr)
			return nullptr;
		
		Node* ans = nullptr;
		if (root->data >= key) {
			ans = inOrderPred(root->left, key);
		}
		else {
			ans = inOrderPred(root->right, key);
			if(ans==nullptr) ans=root;
		}
		
		return ans;
	}
	
	public:
	vector<Node*> findPreSuc(Node* root, int key) {
		// code here
		Node* inorderSuc = inOrderSuccessor(root, key);
		Node* inorderPred = inOrderPred(root, key);
		
		return {inorderPred, inorderSuc};
		
	}
};
