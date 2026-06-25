class Solution {
public:
    // We will use a Queue.
    // An astorid only can collide if A right going ast is on the left of an left going ast.
    // (+) ------> <------ (-) <this will always collide>
    // <-----(-) (+)----->   <This will never collide>
    // So we shall take one element by one from array.
    // We shall take a stack. Scan elements one by one
    // Positives on positives, Negatives on Negatives will never collide.
    // Also positives ON negatives will never collide too. They goes oppo direction.
    // Only negative on positive collides. Because, negative wants to move down, positive wants to go up.

    // We need to reverse the final answer.
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> ans;

        // Scan all elements
        for(int i=0; i<asteroids.size(); i++){
            if(stk.empty() || asteroids[i] > 0) stk.push(asteroids[i]);
            else if(asteroids[i]<0){
                // empty handled earlier.
                int top = stk.top();
                int abs_ast = -1*asteroids[i];
                bool place_ast=true;
                while(!stk.empty() && top>0){
                    if(abs_ast == top) 
                    {
                        stk.pop();
                        place_ast=false;
                        break;
                    } // Both destroyed
                    else if(abs_ast < top){
                        place_ast = false;
                        break; // nothing to push
                    }
                    else{
                        stk.pop();
                        if(!stk.empty())top = stk.top();
                    }
                }
                //Exits when: 1. both destroyed
                //            2. top > to be placed.
                //            3. top<0
                //            4. Stack empty

                //place_ast check because stack can be empty due to crushing too [8 -8]: -8 crushed 8 in loop then exits.
                // In this case stack is empty but we can not push the current one.
                if(place_ast && (stk.empty() || stk.top() < 0)) stk.push(asteroids[i]);
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        std::reverse(ans.begin(), ans.end());
        return ans;

        // Now stack holds element
    }
};