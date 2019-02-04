/*
* 第一次超过99.9%的用户。。。
* 归并做法，且不占用其他空间
* */
public class MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        ListNode head=new ListNode(Integer.MAX_VALUE);
        ListNode temp=head;
        while(l1!=null&&l2!=null){
            if(l1.val<l2.val){
                temp.next=l1;
                l1=l1.next;
            }
            else{
                temp.next=l2;
                l2=l2.next;
            }
            temp=temp.next;
        }
        if(l1!=null&&l2==null)
            temp.next=l1;
        else if(l1==null&&l2!=null)
            temp.next=l2;

        return head.next;
    }

    public static void main(String[]args){
        ListNode h1=new ListNode(1);
        int nums1[]={1,1,1,1};
        h1=ListNode.createList(h1,nums1);
        //ListNode.printList(h1);

        ListNode h2=new ListNode(1);
        int nums2[]={1,1,2};
        h2=ListNode.createList(h2,nums2);
        //ListNode.printList(h2);
        //开始合并
        MergeTwoSortedLists test=new MergeTwoSortedLists();
        ListNode.printList(test.mergeTwoLists(h1,h2));
        ListNode for1=new ListNode(0);
        ListNode for2=null;
        ListNode.printList(test.mergeTwoLists(for1,for2));
    }
}
