class Solution {
public:
    int kthGrammar(int n, int k) {
        // base case
        if(n == 1 and k ==1) return 0;

        int col_len = pow(2, n-1);
        int mid = col_len/2;

        if(k <= mid) {
            int ans = kthGrammar(n-1, k);
            return ans;
        }
        else {
            int ans2 = kthGrammar(n-1, k-mid);
            return (ans2 == 0) ? 1 : 0;
        }
    }
};