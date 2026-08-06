class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int p = 1;
            int temp = n;
            if (temp == 0){
                p = 0;
            }
            while(temp > 0){
                p *= temp % 10;
                temp /= 10;
            };
            if (p % t == 0){
                return n; 
            }
            n++;  
        } 
    }
};
