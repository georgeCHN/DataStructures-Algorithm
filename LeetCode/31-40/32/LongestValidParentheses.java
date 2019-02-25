/***
 * 题目重点是要比较两个匹配的括号的下标，
 * 一开始解题思路是，如果匹配，就res+2，这样是行不通的，
 * 看其他的解法，有一种解法是用栈存储每个(的下标，可以用Index-栈种的下标得到元素的个数
 */


import java.util.Stack;

public class LongestValidParentheses {
    public int longestValidParentheses(String s) {
        if(s.length()<1||s==null)
            return 0;
        Stack<Integer>mystack=new Stack<>();
        int res=0;
        int start=0;
        for(int i=0,len=s.length();i<len;i++){
            if(s.charAt(i)=='(')
                mystack.push(i);
            else{
                if(mystack.isEmpty())
                    start=i+1;
                else{
                    mystack.pop();
                    if(mystack.isEmpty())
                        res=Math.max(res,i-start+1);
                    else
                        res=Math.max(res,i-mystack.peek());
                }
            }
        }
        return res;
    }
    public static void main(String[]args){
        LongestValidParentheses test=new LongestValidParentheses();
        System.out.println(test.longestValidParentheses(")()())"));
    }
}
