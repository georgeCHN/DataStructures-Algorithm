import java.util.Stack;
/**
 * 题目是判断括号是否有效，含有([{
 * 肯定是用栈来解决，但是，循环时候用for-each时比较快一些，用for-each时，把string转换为char的数组
 * 用到的String方法时toCharArray()
 * 然后就没什么了。
 * duplicated版本是参考其他提交者的改良版本
 */
public class ValidParentheses {
    public static  boolean isMathch(Stack<Character>mystack,char temp){
        if(mystack.empty())
            return false;
        char peek=mystack.peek();
        switch (temp) {
            case ')':
                if (peek == '(')
                    return true;
                else
                    return false;
            case ']':
                if (peek == '[')
                    return true;
                else
                    return false;
            case '}':
                if (peek == '{')
                    return true;
                else
                    return false;
            default:
                return false;
        }
    }
    public boolean isValid(String s) {
        Stack<Character> mystack=new Stack<>();
        for(int i=0,len=s.length();i<len;i++){
            char temp=s.charAt(i);
            if(temp=='('||temp=='{'||temp=='[')
                mystack.push(temp);
            else{
                if(isMathch(mystack,temp))
                    mystack.pop();
                else
                    return false;
            }
        }
        if(!mystack.empty())
            return false;
        else
            return true;
    }
    public  boolean isValid_duplicated(String s){
        Stack<Character>stack=new Stack<>();
        for(char tmp:s.toCharArray()){
            if(tmp=='('||tmp=='{'||tmp=='[')
                stack.push(tmp);
            else{
                if(stack.empty())
                    return false;
                else{
                    if(tmp==')'&&stack.peek()=='(')
                        stack.pop();
                    else if(tmp=='}'&&stack.peek()=='{')
                        stack.pop();
                    else if(tmp==']'&&stack.peek()=='[')
                        stack.pop();
                    else
                        return false;
                }
            }
        }
        if(stack.empty())
            return true;
        else
            return false;
    }
    public static void main(String[]args){
        ValidParentheses test=new ValidParentheses();
        //System.out.println(test.isValid("{{)}"));
        System.out.println(test.isValid_duplicated(""));
    }
}

