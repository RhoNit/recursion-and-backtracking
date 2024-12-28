// https://www.geeksforgeeks.org/problems/sort-a-stack/1

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &s, int elem) {
    // base condition
    if(s.size() == 0 or s.top() <= elem) {
        s.push(elem);
        return;
    }
    
    int tmp = s.top();
    s.pop();
    
    // recursive call
    insert(s, elem);
    
    // insert the tmp elem into the stack again
    s.push(tmp);
}

void SortedStack :: sort() {
   // base case
   if(s.size() == 1) {
       return;
   }
   
   int top_elem = s.top();
   s.pop();
   
   // recursive call
   sort();
   
   // insert the tmp element into the stack again
   insert(s, top_elem);
}
