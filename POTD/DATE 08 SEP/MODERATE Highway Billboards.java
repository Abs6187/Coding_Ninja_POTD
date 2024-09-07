import java.util.* ;
import java.io.*; 
 
public class Solution {

	public static int highwayBillboard(int[] bill, int[] rev, int m, int x) {
		 
		int n = bill.length;
		int[][] dp = new int[n + 1][m + 1];

		for(int i = n - 1; i >= 0; i--) {

			for(int j = 0; j <= m; j++) {
				
				int d = j;
				int prof = 0;
				if(d == 0 || bill[i] - d > x)
					prof = rev[i] + dp[i + 1][bill[i]];
				
				dp[i][j] = Math.max(prof, dp[i + 1][d]);
			}
		}
		return dp[0][0];
	}

}
