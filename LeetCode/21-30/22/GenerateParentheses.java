import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class GenerateParentheses {
    public static boolean isValid(String str){
        Stack<Character> stack=new Stack<>();
        for(int i=0,len=str.length();i<len;i++){
            if(str.charAt(i)=='1')
                stack.push('1');
            else{
                if(stack.empty())
                    return false;
                else
                    stack.pop();
            }
        }
        if(!stack.empty())
            return false;
        else
            return true;
    }
    public List<String> generateParenthesis(int n) {
        ArrayList<String>result=new ArrayList<>();
        if(n==0)
            return result;
        String low="";
        String high="";
        for(int i=0;i<n;i++){
            low+="10";
            high+="1";
        }
        for(int i=0;i<n;i++)
            high+="0";
        int lowIndex=Integer.parseInt(low,2);
        int hightIndex=Integer.parseInt(high,2);
        while(lowIndex<=hightIndex){
            String temp=Integer.toBinaryString(lowIndex);
            if(isValid(temp)){
                String parenth="";
                for(int i=0,len=temp.length();i<len;i++){
                    if(temp.charAt(i)=='1')
                        parenth+="(";
                    else
                        parenth+=')';
                }
                result.add(parenth);
            }
            lowIndex+=2;
        }
        return result;
    }
    public List<String> generateParenthesis_copy(int n) {
        List<String> ans = new ArrayList();
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
    //这个回溯法，递归写的太好了，导致我根本想不出来。。。。
    public void backtrack(List<String> ans, String cur, int open, int close, int max){
        if (cur.length() == max * 2) {
            ans.add(cur);
            return;
        }

        if (open < max)
            backtrack(ans, cur+"(", open+1, close, max);
        if (close < open)
            backtrack(ans, cur+")", open, close+1, max);
    }
    public static void main(String[]args){
        GenerateParentheses test=new GenerateParentheses();
        //System.out.println(test.generateParenthesis(6));
        System.out.println(test.generateParenthesis_copy(3));
    }
}
