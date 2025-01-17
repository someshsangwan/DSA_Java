package Graph;
// Given an undirected graph with V vertices. We say two vertices u and v belong to a single province
//  if there is a path from u to v or v to u. Your task is to find the number of provinces.

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.*;

// Note: A province is a group of directly or indirectly connected cities and no other cities 
// outside of the group.
class Solution {
    public static void dfs(int node, boolean[] vis,List<List<Integer>> adj) {
        vis[node] = true;
        for (Integer it : adj.get(node)) {
            if (vis[it] == false) {
                dfs(it, vis, adj);
            }
        }

    }
    public int findCircleNum(int[][] isConnected) {
        int res=0;
        List<List<Integer>>adj=new ArrayList<>();
        int n=isConnected.length;
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                    adj.get(i).add(j);
            }
            }
        }
        boolean[] vis=new boolean[n];
        for(int i=0;i<n;i++){
             if(vis[i]==false){
                res++;
                dfs(i,vis,adj);
                System.out.println(i);
                
             }
        }
        return res;
    }
}
