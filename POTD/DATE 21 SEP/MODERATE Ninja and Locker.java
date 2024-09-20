import java.util.* ;
import java.io.*; 
public class Solution {
    public static int savedCash(int n, ArrayList<Integer> cash, int m, ArrayList<Integer> locker) {
        // Step 1: Build the prefix minimum array for locker heights
        int[] prefixMinLockerHeight = new int[m];
        prefixMinLockerHeight[0] = locker.get(0);
        for (int i = 1; i < m; i++) {
            prefixMinLockerHeight[i] = Math.min(prefixMinLockerHeight[i - 1], locker.get(i));
        }

        // Step 2: Sort the cash stacks in decreasing order
        Collections.sort(cash, Collections.reverseOrder());

        // Step 3: Initialize Union-Find (Disjoint Set Union) data structure
        int[] parent = new int[m];
        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        int count = 0; // Number of cash stacks placed

        // Step 4: Process each cash stack
        for (int h : cash) {
            int idx = getRightmostIndex(prefixMinLockerHeight, h);
            if (idx == -1) continue; // No suitable locker section found

            int lockerIndex = find(parent, idx);
            if (lockerIndex >= 0) {
                count++;
                // Mark this locker section as used
                parent[lockerIndex] = find(parent, lockerIndex - 1);
            }
        }
        return count;
    }

    // Union-Find 'find' function with path compression
    static int find(int[] parent, int i) {
        if (i < 0) return -1; // No available locker sections left
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }

    // Binary search to find the rightmost index where prefixMinLockerHeight[i] >= h
    static int getRightmostIndex(int[] prefixMinLockerHeight, int h) {
        int low = 0, high = prefixMinLockerHeight.length - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (prefixMinLockerHeight[mid] >= h) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}
