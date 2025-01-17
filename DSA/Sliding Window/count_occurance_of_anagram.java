import java.util.HashMap;
import java.util.Map;
class count_occurance_of_anagram {

    public static int search(String pat, String txt) {
        int m = txt.length();
        int n = pat.length();

        // If the pattern is longer than the text, return 0
        if (n > m) {
            return 0;
        }

        int res = 0; // Result to store the count of anagrams
        int i = 0, j = 0;

        // Create a map to store the frequency of characters in the pattern
        Map<Character, Integer> mp = new HashMap<>();
        for (char c : pat.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        int ct = mp.size(); // Count of distinct characters in the pattern

        // Sliding window logic
        while (j < m) {
            // If the current character exists in the map, decrement its count
            if (mp.containsKey(txt.charAt(j))) {
                mp.put(txt.charAt(j), mp.get(txt.charAt(j)) - 1);
                if (mp.get(txt.charAt(j)) == 0) {
                    ct--; // Decrease the count of distinct characters
                }
            }

            // If the window size is smaller than the pattern size, expand the window
            if (j - i + 1 < n) {
                j++;
            } else {
                // If the window size matches the pattern size
                if (ct == 0) {
                    res++; // Found an anagram
                }

                // Slide the window: Remove the effect of the character at index `i`
                if (mp.containsKey(txt.charAt(i))) {
                    mp.put(txt.charAt(i), mp.get(txt.charAt(i)) + 1);
                    if (mp.get(txt.charAt(i)) == 1) {
                        ct++; // Increase the count of distinct characters
                    }
                }

                // Move the window forward
                i++;
                j++;
            }
        }

        return res;
    }
    public static void main(String args[]){
        String text="forxxorfxdofr";
        String pat="for";
        int x=search(pat, text);
        System.out.print(x);

    }
}