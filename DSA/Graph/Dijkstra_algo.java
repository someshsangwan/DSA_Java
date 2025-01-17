package Graph;

import java.util.*;
class Solution {
    static int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S) {
        // Define Pair class
        class Pair {
            int distance, node;
            Pair(int distance, int node) {
                this.distance = distance;
                this.node = node;
            }
        }

        // Min-Heap PriorityQueue
        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> Integer.compare(x.distance, y.distance));

        // Initialize distances
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[S] = 0;

        // Add source node to PriorityQueue
        pq.add(new Pair(0, S));

        // Process nodes
        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            int dis = current.distance;
            int node = current.node;

            for (int i = 0; i < adj.get(node).size(); i++) {
                int adjNode = adj.get(node).get(i).get(0);
                int edgeWeight = adj.get(node).get(i).get(1);

                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.add(new Pair(dist[adjNode], adjNode));
                }
            }
        }

        return dist;
    }
}
