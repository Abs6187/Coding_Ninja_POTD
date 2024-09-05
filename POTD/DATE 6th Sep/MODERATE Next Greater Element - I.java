import java.util.* ;
import java.io.*; 
public class Solution {
    public static int[] nextGreaterElement(int n, int a[], int m2, int b[]) {
        int[] ans=new int[a.length];
        int[] nextGreater=new int[b.length];
        Stack<Integer> s=new Stack<>();
        HashMap<Integer,Integer> m=new HashMap<>();
        for(int i=b.length-1;i>=0;i--){
            while(!s.isEmpty() && s.peek()<=b[i]){
                s.pop();
            }

            nextGreater[i]=s.isEmpty()?-1:s.peek();
            s.push(b[i]);
            m.put(b[i],i);
        }

        for(int i=0;i<a.length;i++){
            if(m.containsKey(a[i])){
                ans[i]=nextGreater[m.get(a[i])];
            }else{
                ans[i]=-1;
            }
        }
        return ans;
    }
}
