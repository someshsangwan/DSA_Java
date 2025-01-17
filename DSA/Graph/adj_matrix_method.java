package Graph;

//two way to store graph
//N-Node, M-edge
// 1) using adjacent matrix
// make array of int[][] adj=new int[N+1][N+1];
// we use N+1 becuase node value start from 1 ,now make value one where is edge 
//o(N^2);
public class adj_matrix_method {
    public static void main(String[] args) {
        int n = 3;
        int m = 3;
        int adj[][] = new int[n + 1][n + 1];
        // edge 1-----2
        adj[1][2] = 1;
        adj[2][1] = 1;

        // edge 2---3
        adj[2][3] = 1;
        adj[3][2] = 1;

    }

    public static void weighted_graph() {
        int n = 3;
        int m = 3;
        int adj[][] = new int[n + 1][n + 1];
        // edge 1-----2
        adj[1][2] = 3; // here we will store weigt instead of 1
        adj[2][1] = 3;

        // edge 2---3
        adj[2][3] = 4;
        adj[3][2] = 4;

    }
}