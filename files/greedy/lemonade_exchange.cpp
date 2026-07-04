class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 =0, count10=0;

        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5) count5++;
            else if(bills[i] == 10 && count5){
                count5--;
                count10++;
            }
            else if(bills[i] == 20){
                if(count10 && count5){
                    count10--;
                    count5--;
                }
                else if(count5>=3){
                    count5-=3;
                }
                else return false;
            }
            else return false;
        }   

        return true;  
    }
};