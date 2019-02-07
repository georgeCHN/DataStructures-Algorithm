/*
* 竟然写的这么费力。。。。
* 如果奇数次，返回第二个节点
* 如果偶数次，返回第一个节点
* 比较快...
* */
public class SwapNodesInPairs {

    public ListNode swapPairs(ListNode head) {
        ListNode res=new ListNode(0);
        ListNode temp=res;
        int i=1;
        while(head!=null){

            if(i%2==0){
                temp.next=head;
                head=head.next;
            }
            else{

            if(head.next!=null){
                temp.next=head.next;
                head.next=head.next.next;
            }else{
                temp.next=head;
                break;
            }
            }
            temp=temp.next;
            i++;
        }
        return res.next;
    }
    public static void main(String[]args){
        int nums[]={1,2,3,4,5,6};
        ListNode head=ListNode.createList(nums);
        ListNode.printList(head);
        SwapNodesInPairs test=new SwapNodesInPairs();
        ListNode.printList(test.swapPairs(head));
    }
}