import java.util.*;

class Node {
    public int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Llformat {
    public static Node creatLL() {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the root value");
        int d = scn.nextInt();
        Node root = new Node(d);
        Node curr = root;
        while (true) {

            System.out.println("Enter the next value");
            d = scn.nextInt();
            if (d == -1) {
                break;
            }
            Node temp = new Node(d);
            curr.next = temp;
            curr = curr.next;
        }
        scn.close();
        // curr.next = root;
        return root;

    }

    public static void printLL(Node root) {
        Node curr = root;
        while (curr != null) {
            System.out.println(curr.data);
            curr = curr.next;
        }
    }

    public static void main(String[] args) {
        Node first = creatLL();
        printLL(first);
    }
}
