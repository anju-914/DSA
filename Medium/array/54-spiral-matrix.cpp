// 54. Spiral Matrix
// Difficulty: Medium
// Topics: Array, Matrix, Simulation
// Link: https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return{};
        }
        int m =matrix.size();
        int n = matrix[0].size();
    
        vector<int> result;
        int top =0,down=m-1,left=0,right=n-1;
        while(top<=down&&left<=right){
                for(int i =left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            
                for(int i = top;i<=down;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
                if(top <= down){
                    for(int i =right;i>=left;i--){
                    result.push_back(matrix[down][i]);
                    }
                    down--;}
                if(left <= right){    
                for(int i =down;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;}
        }
        return result;
        
    }
};