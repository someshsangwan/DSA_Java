package Graph;

import java.util.ArrayList;
import java.util.List;

public class GraphList {
    public static void main(String[] args) {
        int vertices = 4;
        List<List<Integer>> adjacencyList = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i <= vertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        // Add edges
        addEdge(adjacencyList, 0, 1);
        addEdge(adjacencyList, 0, 2);
        addEdge(adjacencyList, 1, 2);
        addEdge(adjacencyList, 2, 3);

        // Print adjacency list
        for (int i = 0; i < adjacencyList.size(); i++) {
            System.out.println("Node " + i + ": " + adjacencyList.get(i));
        }
    }

    public static void addEdge(List<List<Integer>> list, int source, int destination) {
        list.get(source).add(destination); // For directed graph
        list.get(destination).add(source); // For undirected graph
    }

}
