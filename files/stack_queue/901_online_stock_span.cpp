// Basically Previous greater.
// No loop needed for spanning the array because elements are given one by one.

class StockSpanner {
    vector<int> stock;
    stack<int> stk;
    // Here cuz above should be maintained between multiple calls to the same object next function
public:
    StockSpanner(){
        // IDK :)
    }
    
    int next(int price) {
        int days;
        stock.push_back(price);
        while(!stk.empty() && stock[stk.top()] <= price){
            stk.pop();
        }
        days =(stk.empty()) ? stock.size() : (stock.size()-1 - stk.top());  
        stk.push(stock.size()-1);

        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */