//Leetcode Question: https://leetcode.com/problems/stone-game/
// 877. Stone Game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        //it is a special case of game problem
        //no. of piles are even.
        //so a player will pick either odd placed piles or all even placed piles.
        
        //since sum of piles is odd, ither sum of even placed will be greater or sum of odd placed will be greater.
        
        //So alice will always pick the greater one
        //therefore, she will always win
        //ans will always be true
        
        return true; 
    }
};
