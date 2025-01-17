/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:
https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10^9.
*/

class Solution {
public:
    
    int dp[101][101];
    
    int uniquePathsrec(int r, int c){
        
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        if(r==0 || c==0){
            return 1;
        }
        if(r<0 || c<0){
            return 0;
        }
        int up = uniquePathsrec(r-1,c);
        int left = uniquePathsrec(r,c-1);
        dp[r][c] = up+left;
        return dp[r][c];
    }
    
    
    int uniquePaths(int r, int c) {
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            dp[i][j] = -1;
        }
    }
        return uniquePathsrec(r-1,c-1);
    }
};
