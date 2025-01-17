package Graph;

import java.util.*;

class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    public static void dfs(int node, boolean[] vis, ArrayList<Integer> res, ArrayList<ArrayList<Integer>> adj) {
        res.add(node);
        vis[node] = true;
        for (Integer it : adj.get(node)) {
            if (vis[it] == false) {
                dfs(it, vis, res, adj);
            }
        }

    }

    public ArrayList<Integer> dfsOfGraph(ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> res = new ArrayList<>();
        int V = adj.size();
        boolean[] vis = new boolean[V];
        dfs(0, vis, res, adj);
        return res;
    }
}