public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
    public static void printList(ListNode head){
        System.out.print("HEAD:\t");
        ListNode temp=head;
        if(head==null)
            System.out.println("\n");
        while(temp!=null){
            if(temp.next!=null)
                System.out.print(temp.val+"->");
            else
                System.out.println(temp.val);
            temp=temp.next;
        }
    }
    //create做法是新建一个链表，其中头节点已经存在
    public static ListNode createList(int nums[]){
        ListNode head=new ListNode(Integer.MAX_VALUE);
        ListNode temp=head;
        for(int tmp:nums){
            temp.next=new ListNode(tmp);
            temp=temp.next;
        }
        return head.next;
    }
}