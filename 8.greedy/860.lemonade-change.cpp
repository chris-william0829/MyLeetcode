/*

https://leetcode.cn/problems/lemonade-change/description/
2024-8-1

*/


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }
            if(bills[i] == 10){
                ten++;
                five--;
                if(five < 0){
                    return false;
                }
            }
            if(bills[i] == 20){
                twenty++;
                if(ten > 0){
                    ten--;
                    five--;
                    if(five < 0){
                        return false;
                    }
                }else if(ten == 0){
                    five -= 3;
                    if(five < 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};