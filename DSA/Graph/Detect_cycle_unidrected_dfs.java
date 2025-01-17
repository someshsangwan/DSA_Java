package Graph;
import java.util.*;
class Solution {
    public static boolean dfs(int node,int parent ,boolean [] vis,ArrayList<ArrayList<Integer>> adj ){
        vis[node]=true;
            for(Integer i:adj.get(node)){
                if(vis[i]==false){
                     dfs(i,node,vis,adj);
                }
                else if(parent !=i){
                    return true;
                }
            }
        
        return false;
    } 
    public boolean isCycle(ArrayList<ArrayList<Integer>> adj) {
        int n =adj.size();
        boolean [] vis=new boolean[n];
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                if(dfs(i,-1,vis,adj)){
                    return true;
                }
            }
        }
        return false;
        
    }
}