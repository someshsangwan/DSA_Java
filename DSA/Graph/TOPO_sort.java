package Graph;
import java.util.*;
//Only for directed acyclic graph (DAG)
//topo->linear ordering of vertices such that if threre is an edge between u & v, u appears before v.
class Solution {
    // Function to return list containing vertices in Topological order.
    public static void dfs(int node, boolean[] vis, Stack<Integer>st, ArrayList<ArrayList<Integer>> adj) {
        vis[node] = true;
        for (Integer it : adj.get(node)) {
            if (vis[it] == false) {
                dfs(it, vis, st, adj);
            }
        }
        st.add(node);

    }
    static ArrayList<Integer> topologicalSort(ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer>res=new ArrayList<>();
        Stack<Integer>st=new Stack<>();
        int n=adj.size();
        boolean[] vis=new boolean[n];
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i,vis,st,adj);
            }
        }
        while(!st.isEmpty()){
            res.add(st.peek());
            st.pop();
        }
        return res;
    }
}


//detect cycle using topo sort:-