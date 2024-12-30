// https://www.geeksforgeeks.org/problems/josephus-problem/1

class Solution {
  public:
    int josephus(int n, int k) {
        vector<int> persons;
        for(int i = 1; i <= n; i++) persons.push_back(i);
        k = k-1; // position: including the current person
        int res = -1;
        
        solve(0, k, persons, res);
        
        return res;
    }
    
    void solve(int idx, int k, vector<int> &persons, int &res) {
        // base case
        if(persons.size() == 1) {
            res = persons[0];
            return;
        }
        
        idx = (idx+k)%persons.size(); // persons would be treated as a circular array
        persons.erase(persons.begin()+idx); // remove the person from that index
        
        // recursive call
        solve(idx, k, persons, res);
    }
};