package Stack;

class Stack {
    private int[] arr; // Array to store stack elements
    private int top; // Index of the top element in the stack
    private int capacity; // Maximum capacity of the stack

    // Constructor to initialize the stack
    public Stack(int size) {
        arr = new int[size]; // Create an array of the given size
        capacity = size; // Set the capacity
        top = -1; // Initialize the stack as empty
    }

    // Push operation: Add an element to the top of the stack
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot push " + value);
            return;
        }
        arr[++top] = value; // Increment top and add the value
    }

    // Pop operation: Remove and return the top element of the stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop");
            return -1; // Return -1 to indicate the stack is empty
        }
        return arr[top--]; // Return the top element and decrement top
    }

    // Peek operation: Return the top element without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty! Cannot peek");
            return -1; // Return -1 to indicate the stack is empty
        }
        return arr[top]; // Return the top element
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == -1; // Stack is empty if top is -1
    }

    // Check if the stack is full
    public boolean isFull() {
        return top == capacity - 1; // Stack is full if top is at the last index
    }

    // Get the size of the stack
    public int size() {
        return top + 1; // Number of elements in the stack
    }
}

public class Main {
    public static void main(String[] args) {
        // Create a stack of size 5
        Stack stack = new Stack(5);

        // Perform stack operations
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        System.out.println("Top element is: " + stack.peek()); // Output: 50
        System.out.println("Stack size is: " + stack.size()); // Output: 5

        // Pop elements from the stack
        System.out.println("Popped element: " + stack.pop()); // Output: 50
        System.out.println("Popped element: " + stack.pop()); // Output: 40

        System.out.println("Stack size after popping: " + stack.size()); // Output: 3

        // Push another element
        stack.push(60);

        System.out.println("Top element after pushing 60: " + stack.peek()); // Output: 60

        // Try to push when the stack is full
        stack.push(70); // Output: Stack Overflow! Cannot push 70
    }
}
