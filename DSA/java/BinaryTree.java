public class BinaryTree {
    public static void main(String[] args) {
        // Create the root node
        Node root = new Node(10);

        // Create left and right children
        root.left = new Node(5);
        root.right = new Node(15);

        // Print the data of the root and its children
        System.out.println("Root data: " + root.data);         // Output: 10
        System.out.println("Left child data: " + root.left.data);  // Output: 5
        System.out.println("Right child data: " + root.right.data); // Output: 15
    }
}
