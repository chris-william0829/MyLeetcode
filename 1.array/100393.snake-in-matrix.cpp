/*

https://leetcode.cn/problems/snake-in-matrix/description/

*/


class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for(int i=0;i<commands.size();i++){
            if(commands[i] == "UP"){
                x--;
            }else if(commands[i] == "DOWN"){
                x++;
            }else if(commands[i] == "RIGHT"){
                y++;
            }else if(commands[i] == "LEFT"){
                y--;
            }else{

            }
        }
        return x*n+y;
    }
};