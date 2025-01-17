class Node {
    int data;       // Data stored in the node
    Node left;      // Reference to the left child
    Node right;     // Reference to the right child

    // Constructor to initialize the node
    public Node(int data) {
        this.data = data;   // Set the data
        this.left = null;   // Initialize left child as null
        this.right = null;  // Initialize right child as null
    }
}
 