//TIME COMPLEXITY:O(N^2) O(N):insert_at_bottom,O(N):reverseStack
void insert_at_bottom(stack<int> &stack,int ele)
{
    if(stack.empty())
    {
        stack.push(ele);
        return;
    }
    int num = stack.top();
    stack.pop();
    insert_at_bottom(stack,ele);
    stack.push(num);
}
//b(3) 1 2
//num = 2 stack:1 b(3) push(2)
//num = 1 stack:  b(3) push(1)
//push(3) return
void reverseStack(stack<int> &stack) 
{
    // Write your code here
    if(stack.empty())
       return;
    if(stack.size() == 1)
        return;
    int ele = stack.top();
    stack.pop();
    reverseStack(stack);
    insert_at_bottom(stack,ele);
}
//1 2 3 4 5
//f(5) b(5) 1 2 3 4
//f(4) b(4) 1 2 3
//f(3) b(3) 1 2
//f(2) b(2) 1
//f(1) b(1)

