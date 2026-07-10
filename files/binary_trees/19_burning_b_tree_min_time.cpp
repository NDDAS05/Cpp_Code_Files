// Intuition:
// just like nodes at k dist: we need to get "parent" of every node.
// Then we start at the target node and start a BFS using queue.
// each push means fire has propagated to the next level. but for first push time is 0; so when next lvl is pushed count++.
// That also means if next level is not pushed(last itr of q when all children are visited or null) fire did not spread/ tree is burning already
// In that case count+1 should not happen.

// Be mmindful of tracking visited nodes.



class Solution {
  public:
    int minTime(Node* root, int target) {

        queue<Node*> q;
        q.push(root);
        unordered_map<int, Node*> ump;
        unordered_set<int> visited;
        Node* targetNode = nullptr;
        
        ump[root->data] = nullptr;
        while(!q.empty()){
            int currSize = q.size();
            for(int i=0; i<currSize; i++){
                Node* t = q.front();
                // Capturing target node
                if(t->data == target) targetNode = t;
                q.pop();
                
                if(t->left){
                    ump[t->left->data] = t;
                    q.push(t->left);
                }
                
                if(t->right){
                    ump[t->right->data] = t;
                    q.push(t->right);
                }
            }
        }
        
        // now bfs traversal from node again.. 
        int count=0;
        q.push(targetNode);
        visited.insert(targetNode->data);
        
        // how are we counting time:
        // when 1st node is pushed: count = 0 <0 sec>
        // when it is popped and adjacents are pushed, count++ <1ec: fire propagates>
        // say no more nodes, i  next itr q will become empty as all childs are either visited or null.
        // we can NOT increment count there.. current nodes already burnt at time 1.
        // so we need to exclude the count we are doing for the last iteration where we are just emptuying the queue.
        //
        while(!q.empty()){
            count++;
            
            int currSize = q.size();
            for(int i=0; i<currSize; i++){
                
                Node* t = q.front();
                q.pop();
                
                if(ump[t->data]!=nullptr && visited.count(ump[t->data]->data) == 0){
                    q.push(ump[t->data]);
                    visited.insert(ump[t->data]->data);
                }
                
                if(t->left && visited.count(t->left->data) == 0) {
                    q.push(t->left);
                    visited.insert(t->left->data);
                    
                }
                if(t->right && visited.count(t->right->data) == 0){ 
                    q.push(t->right);
                    visited.insert(t->right->data);
                }
            }
        }
        
        return count-1;
    }
};