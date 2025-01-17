package Graph;
import java.util.*;
class Solution {
    public static boolean dfs(int node,int parent ,boolean [] vis,boolean [] pathvis,ArrayList<ArrayList<Integer>> adj ){
        vis[node]=true;
        pathvis[node]=true;
            for(Integer i:adj.get(node)){
                if(vis[i]==false){
                     if(dfs(i,node,vis,pathvis,adj)) return true;
                }
                else if(pathvis[i]){
                    return true;
                }
            }
        pathvis[node]=false;
        return false;
    } 
    public boolean isCycle(ArrayList<ArrayList<Integer>> adj) {
        int n =adj.size();
        boolean [] vis=new boolean[n];
        boolean [] pathvis=new boolean[n];
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                if(dfs(i,-1,vis,pathvis,adj)){
                    return true;
                }
            }
        }
        return false;
        
    }
}