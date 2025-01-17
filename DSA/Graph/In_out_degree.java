package Graph;

import java.util.List;

public class In_out_degree {
    static void findInOutDegree(List<List<Integer> > adjList, int n)
    {
        int in[] = new int[n];
        int out[] = new int[n];
 
        for (int i = 0; i < adjList.size(); i++) {
 
            List<Integer> list = adjList.get(i);
 
            // Out degree for ith vertex will be the count
            // of direct paths from i to other vertices
            out[i] = list.size();
            for (int j = 0; j < list.size(); j++)
 
                // Every vertex that has an incoming 
                // edge from i
                in[list.get(j)]++;
        }
 
        System.out.println("Vertex\tIn\tOut");
        for (int k = 0; k < n; k++) {
            System.out.println(k + "\t" + in[k] + "\t" + out[k]);
        }
    }
    
    
}
