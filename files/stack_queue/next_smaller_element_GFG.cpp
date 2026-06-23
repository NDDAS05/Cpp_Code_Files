class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        // Reverse logic of NGE
        // If current element is smaller than the stack top, upcoming elements (<---)
        // Next smaller will be this one, not the large one in stack already.
        vector<int> ans(arr.size(), -1);
        stack<int> s;
        
        for(int i=arr.size()-1; i>=0; i--){
            while(!s.empty()){
                // If current element is smaller than stack top, then we keep popping untill we find a strictly smaller element.
                
                if(arr[i] <= s.top()) s.pop();
                else break;
            }
            
            // If stack is empty then -1 prev lesser element is -1 else the stack top.
            if(!s.empty()) ans[i] = s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};