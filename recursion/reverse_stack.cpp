// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

class Solution{
public:
    void insert(stack<int> &St, int elem) {
        // base case
        if(St.size() == 0) {
            St.push(elem);
            return;
        }
        
        int tmp = St.top();
        St.pop();
        
        // recursive call
        insert(St, elem);
        
        St.push(tmp);
    }
    
    void Reverse(stack<int> &St){
        // base case
        if(St.size() == 1) {
            return;
        }
        
        int elem = St.top();
        St.pop();
        
        // recursive call
        Reverse(St);
        
        insert(St, elem);
    }
};