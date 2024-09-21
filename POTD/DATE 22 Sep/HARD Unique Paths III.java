import java.util.* ;

import java.io.*; 

public class Solution {

    public static int robotPaths(int n, int m, int grid[][]) {

         int zero=0;

        int sx=0;

        int sy=0;

        for(int i=0;i<grid.length;i++){

            for(int j=0;j<grid[0].length;j++){

                if(grid[i][j]==0) zero++;

                else if(grid[i][j]==1){

                    sx=i;

                    sy=j;

                }

            }

        }

        return dfs(grid,sx,sy,zero);

    }

     public static int dfs(int[][] arr,int x,int y,int zero){

        if(x<0||y<0||x>=arr.length||y>=arr[0].length||arr[x][y]==-1) return 0;

        if(arr[x][y]==2) return zero==-1?1:0;

        arr[x][y]=-1;

        zero--;

        int res=dfs(arr,x+1,y,zero)+dfs(arr,x-1,y,zero)+dfs(arr,x,y-1,zero)+dfs(arr,x,y+1,zero);

        arr[x][y]=0;

        zero++;

        return res;

    }

 

}
