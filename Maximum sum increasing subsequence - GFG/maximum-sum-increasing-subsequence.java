//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
}    
// } Driver Code Ends




//User function Template for Java

class Solution
{
	 int[][] dp;

    public int maxSumIS(int arr[], int n) {
        dp = new int[n][n];
        for (int[] a : dp) {
            Arrays.fill(a, -1);
        }
        return maxSumISTopDown(arr, n, 0, -1);
    }

    public int maxSumISTopDown(int arr[], int n, int i, int prev) {
        if (i >= n) {
            return 0;
        }
        if ( dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }
        int notTake = maxSumISTopDown(arr, n, i + 1, prev);
        int take = 0;
        if (prev == -1 || arr[i] > arr[prev]) {
            take = arr[i]+maxSumISTopDown(arr, n, i + 1,i );
        }
        return dp[i][prev+1] = Math.max(take, notTake);
    }

}