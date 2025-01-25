import java.util.*;

class Node1 {
    public int data;
    Node1 left;
    Node1 right;

    Node1(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Tree {

    public static Node1 creattree() {
        System.out.println("Enter the root data");
        Scanner scn = new Scanner(System.in);
        int data = scn.nextInt();
        Node1 root = new Node1(data);
        Queue<Node1> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node1 temp = q.peek();
            q.remove();
            System.out.println("Enter the left Node1 data of " + temp.data);
            int leftval = scn.nextInt();
            if (leftval != -1) {
                Node1 leftNode1 = new Node1(leftval);
                temp.left = leftNode1;
                q.add(leftNode1);
            }
            System.out.println("Enter the right Node1 data of " + temp.data);
            int rightval = scn.nextInt();
            if (rightval != -1) {
                Node1 rightNode1 = new Node1(rightval);
                temp.right = rightNode1;
                q.add(rightNode1);
            }

        }
        scn.close();
        return root;

    }

    public static void print(Node1 root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        print(root.left);
        print(root.right);

    }

    public static void main(String[] args) {
        Node1 root = creattree();
        System.out.println("printing preorder traversal");
        // Node1 root = new Node1(1);
        // root.left = new Node1(2);
        // root.right = new Node1(3);
        print(root);
    }

}
