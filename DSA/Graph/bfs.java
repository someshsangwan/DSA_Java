package Graph;

import java.util.*;

class Solution {
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> res = new ArrayList<>(); // To store the BFS traversal result
        Queue<Integer> q = new LinkedList<>(); // Queue for BFS
        boolean[] vis = new boolean[V]; // Visited array, initialized to false by default

        // Start BFS from vertex 0
        q.add(0);
        vis[0] = true; // Mark vertex 0 as visited

        while (!q.isEmpty()) {
            int x = q.poll(); // Get the front element of the queue
            res.add(x); // Add it to the result

            // Traverse all neighbors of the current vertex
            for (int i = 0; i < adj.get(x).size(); i++) {
                int y = adj.get(x).get(i); // Neighbor vertex
                if (!vis[y]) { // If the neighbor is not visited
                    q.add(y); // Add it to the queue
                    vis[y] = true; // Mark it as visited
                }
            }
        }

        return res; // Return the BFS traversal result
    }
}
