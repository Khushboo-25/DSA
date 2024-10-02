class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        if (n == 1) // Base case: first row always starts with '0'
            return 0;

        // Recursively calculate the parent element (from the previous row)
        int parent = kthGrammar(n - 1, (k + 1) / 2);
        
        // If k is odd, the value is the same as the parent; if k is even, it's flipped
        return (k % 2 == 1) ? parent : !parent;
    }
};
