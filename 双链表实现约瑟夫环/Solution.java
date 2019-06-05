
public class Solution {
    public  Node josephCircle(Node head,int discard){
        if(discard<1)
            return null;
        int i=1;
        while (head.next!=head)
        {
            //System.out.print("every loop: ");
            //Node.print(head);
            Node temp=head.next;
            if(i%discard==0){
                Node prvTemp=head.prev;
                head.prev.next=head.next;
                //开始出现bug在于没有添加前向指针
                temp.prev=prvTemp;
            }
            head=temp;
            i++;
        }
        //System.out.println("the last link item is:");
        //Node.print(head);
        return head;
    }
    //考虑用循环链表解决
    public static void main(String[]args){
        Solution solution=new Solution();
        int nums[]={1,2,3,4,5};
        Node head = Node.linkListCreator(nums);
        head=solution.josephCircle(head,41);
        //System.out.println("after process link list is:");
        //Node.print(head);
    }
}
