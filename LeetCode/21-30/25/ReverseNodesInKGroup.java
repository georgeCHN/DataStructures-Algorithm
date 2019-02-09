/*
* 做的我好烦。。。。
*
* */
public class ReverseNodesInKGroup {
    //remove第N个节点，如果不存在返回null，否则返回被删除的节点
    public static ListNode removeNthNode(ListNode head,int n){
    //链表的head作为第一个节点,1
        ListNode res=null;
        if(n<1)
            return res;
        for(int i=1;i<n&&(head!=null);i++){
            head=head.next;
        }
        if(head!=null){
            res=head.next;
            if(head.next!=null)
                head.next=head.next.next;
        }
        return res;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        if(k<=1)
            return head;
        //构建一个头节点，方便操作
        ListNode dump=new ListNode(0);
        dump.next=head;
        ListNode temp=dump;
        //head形成一个多余的头节点
        head=new ListNode(-1);
        head.next=dump.next;

        outer:while(head.next!=null){
            for(int i=k;i>0;i--){
                ListNode newNode=removeNthNode(head,i);
                if(newNode!=null){
                    System.out.println("remove node is: "+newNode.val);
                    temp.next=newNode;
                    temp=temp.next;
                }else{
                    temp.next=head.next;
                    break outer;
                }
            }
        }
        return dump.next;
    }
    public static void main(String[]args){
        //测试用例，0作为一个dump节点
        int nums[]={1,2,3,4,5};
        ListNode head=ListNode.createList(nums);
        ListNode.printList(head);
        //测试
        ReverseNodesInKGroup test=new ReverseNodesInKGroup();
        ListNode.printList(test.reverseKGroup(head,2));
    }
}
