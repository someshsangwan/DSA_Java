package Graph;

import java.util.*;

class Solution {
    static class Pair {
        int distance, node;
        Pair(int distance, int node) {
            this.distance = distance;
            this.node = node;
        }
    }

    static int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S, int target) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> Integer.compare(x.distance, y.distance));
        int[] dist = new int[V];
        int[] pred = new int[V]; // Predecessor array
        Arrays.fill(dist, Integer.MAX_VALUE);
        for(int i=0;i<V;i++){
            pred[i]=i;
        }
        
        dist[S] = 0;

        pq.add(new Pair(0, S));

        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            int dis = current.distance;
            int node = current.node;

            for (int i = 0; i < adj.get(node).size(); i++) {
                int adjNode = adj.get(node).get(i).get(0);
                int edgeWeight = adj.get(node).get(i).get(1);

                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pred[adjNode] = node; // Update predecessor
                    pq.add(new Pair(dist[adjNode], adjNode));
                }
            }
        }

        // Print the shortest path
        printPath(pred,target);

        return dist;
    }

    static void printPath(int[] pred,int n) {
        ArrayList<Integer>list=new ArrayList<>();
        int node=n;
        while(pred[node]!=node){
            list.add(node);
        }
        //now reverse the list and return;
    }
 
}
