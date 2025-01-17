package Graph;

import java.util.ArrayList;
import java.util.List;

class Edge {
    int destination; // The neighbor vertex
    int weight; // The weight of the edge

    Edge(int destination, int weight) {
        this.destination = destination;
        this.weight = weight;
    }

    @Override
    public String toString() {
        return "(" + destination + ", " + weight + ")";
    }
}

public class WeightedGraph {
    public static void main(String[] args) {
        int vertices = 4; // Number of vertices
        List<List<Edge>> adjacencyList = new ArrayList<>();

        // Initialize the adjacency list
        for (int i = 0; i < vertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        // Add edges
        addEdge(adjacencyList, 0, 1, 4); // Edge from 0 to 1 with weight 4
        addEdge(adjacencyList, 0, 2, 3); // Edge from 0 to 2 with weight 3
        addEdge(adjacencyList, 1, 2, 2); // Edge from 1 to 2 with weight 2
        addEdge(adjacencyList, 2, 3, 5); // Edge from 2 to 3 with weight 5

        // Print the adjacency list
        printGraph(adjacencyList);
    }

    // Function to add an edge to the graph
    public static void addEdge(List<List<Edge>> adjacencyList, int source, int destination, int weight) {
        adjacencyList.get(source).add(new Edge(destination, weight)); // Add edge for source
        adjacencyList.get(destination).add(new Edge(source, weight)); // Add edge for destination (for undirected graph)
    }

    // Function to print the graph
    public static void printGraph(List<List<Edge>> adjacencyList) {
        for (int i = 0; i < adjacencyList.size(); i++) {
            System.out.print("Node " + i + ": ");
            for (Edge edge : adjacencyList.get(i)) {
                System.out.print(edge + " ");
            }
            System.out.println();
        }
    }
}
