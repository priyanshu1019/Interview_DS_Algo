/*
    MY YOUTUBE VIDEO ON THIS Qn : Recur + Memo - https://www.youtube.com/watch?v=YU9IGG5PB2Y
                                  Bottom Up - Soon coming
    Company Tags                : Will Update soon
    Leetcode Link               : https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(m*n*k)
class Solution {
public:
    int N, M, K;
    int MOD = 1e9+7;
    int t[51][51][101];
    
    int solve(int idx, int searchCost, int maxSoFar) {
        if(idx == N) {
            if(searchCost == K)
                return 1;
            return 0;
        }
        
        if(t[idx][searchCost][maxSoFar] != -1) {
            return t[idx][searchCost][maxSoFar];
        }
        
        int result = 0;
        
        for(int i = 1; i <= M; i++) {
            
            if(i > maxSoFar) {
                result = (result + solve(idx+1, searchCost+1, i)) % MOD;
            } else {
                result = (result + solve(idx+1, searchCost, maxSoFar)) % MOD;
            }
            
        }
        
        return t[idx][searchCost][maxSoFar] = result % MOD;
        
    }
    
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0);
    }
};


//Approach-2 (Bottom Up)
//Soooon Coming

/************************************************************ JAVA ************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(m*n*k)
public class Solution {
    private int N, M, K;
    private final int MOD = 1000000007;
    private int[][][] t;

    public int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        t = new int[51][51][101];
        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                Arrays.fill(t[i][j], -1);
            }
        }
        return solve(0, 0, 0);
    }

    private int solve(int idx, int searchCost, int maxSoFar) {
        if (idx == N) {
            if (searchCost == K) {
                return 1;
            }
            return 0;
        }

        if (t[idx][searchCost][maxSoFar] != -1) {
            return t[idx][searchCost][maxSoFar];
        }

        int result = 0;

        for (int i = 1; i <= M; i++) {
            if (i > maxSoFar) {
                result = (result + solve(idx + 1, searchCost + 1, i)) % MOD;
            } else {
                result = (result + solve(idx + 1, searchCost, maxSoFar)) % MOD;
            }
        }

        return t[idx][searchCost][maxSoFar] = result % MOD;
    }
}
