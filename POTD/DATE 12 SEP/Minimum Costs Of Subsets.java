import java.util.* ;
import java.io.*; 
import java.util.ArrayList;


public class Solution 
{
	private static int res;
	public static int minimumCostsubsets(ArrayList<Integer> arr, int n, int k) 
	{
		res = Integer.MAX_VALUE;
		SortedSet<Integer> [] partion = new TreeSet[k];
		for(int i = 0 ; i < k ; i++ ) partion[i] = new TreeSet<>();
		getMin(arr, n, k,n/k, 0, partion);
		return res >= Integer.MAX_VALUE ? -1 :res;
	}
	public static void getMin(ArrayList<Integer> arr, int n, int k,int req,int idx,SortedSet<Integer> [] partion){
		if(idx == n){
			int sum = 0;
			for(SortedSet<Integer> temp : partion){
			   sum += (temp.last() - temp.first()); 
			}
			res = Math.min(sum , res);
		}
		for(int i = 0 ; i < k ; i++){
			if(partion[i].size() < req && !partion[i].contains(arr.get(idx))){
				partion[i].add(arr.get(idx));
				getMin(arr, n, k, req, idx+1, partion);
				partion[i].remove(arr.get(idx));
			}
		}
	}
}

