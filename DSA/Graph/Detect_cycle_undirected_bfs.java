package Graph;
import java.util.*;
class Solution {
    // Function to detect cycle in an undirected graph.
        static class Pair {
        int first;  // Current node
        int second; // Parent node

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    public static boolean bfs(int node,boolean [] vis,ArrayList<ArrayList<Integer>> adj ){
        Queue< Pair >q=new LinkedList<>();
        q.add(new Pair(node,-1));
        vis[node]=true;
        while(!q.isEmpty()){
            int nod=q.peek().first;
            int parent=q.peek().second;
            q.poll();
            for(Integer i:adj.get(nod)){
                if(vis[i]==false){
                    q.add(new Pair(i,nod));
                    vis[i]=true;
                }
                else if(parent !=i){
                    return true;
                }
            }
        }
        return false;
    } 
    public boolean isCycle(ArrayList<ArrayList<Integer>> adj) {
        int n =adj.size();
        boolean [] vis=new boolean[n];
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                if(bfs(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
        
    }
}