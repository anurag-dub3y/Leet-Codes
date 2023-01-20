class MinStack {
public:
    stack<int> s1, s2;
    void push(int x) {
	    s1.push(x);
	    if(s2.empty() or x <= getMin()){  s2.push(x); }	    
    }
    void pop() {
	    if(s1.top()==getMin()){  s2.pop(); }
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};