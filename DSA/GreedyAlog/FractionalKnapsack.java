package GreedyAlog;

import java.util.*;

public class FractionalKnapsack {
    // Function to get the maximum total value in the knapsack.
    public static double fractionalKnapsack(List<Integer> val, List<Integer> wt, int capacity) {
        // Create a list of items with value, weight, and value-to-weight ratio
        List<Item> items = new ArrayList<>();
        for (int i = 0; i < val.size(); i++) {
            items.add(new Item(val.get(i), wt.get(i)));
        }

        // Sort items by value-to-weight ratio in descending order
        items.sort((a, b) -> Double.compare(b.ratio, a.ratio));

        double maxValue = 0.0; // To store the maximum value
        int remainingCapacity = capacity;

        // Iterate through the sorted items
        for (Item item : items) {
            if (remainingCapacity == 0) break; // If the knapsack is full, stop

            if (item.weight <= remainingCapacity) {
                // If the item can fit entirely, take it
                maxValue += item.value;
                remainingCapacity -= item.weight;
            } else {
                // If the item can't fit entirely, take the fraction of it
                maxValue += item.ratio * remainingCapacity;
                remainingCapacity = 0; // Knapsack is now full
            }
        }

        // Return the maximum value rounded to 6 decimal places
        return Math.round(maxValue * 1e6) / 1e6;
    }

    // Helper class to represent an item with value, weight, and value-to-weight ratio
    static class Item {
        int value;
        int weight;
        double ratio;

        Item(int value, int weight) {
            this.value = value;
            this.weight = weight;
            this.ratio = (double) value / weight;
        }
    }

    // Main method to test the function
    public static void main(String[] args) {
        List<Integer> val = Arrays.asList(60, 100, 120);
        List<Integer> wt = Arrays.asList(10, 20, 30);
        int capacity = 50;

        double maxValue = fractionalKnapsack(val, wt, capacity);
        System.out.println("Maximum value in the knapsack: " + maxValue);
    }
}
