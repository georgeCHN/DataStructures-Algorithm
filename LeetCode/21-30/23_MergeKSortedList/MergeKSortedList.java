/**
 * 该题目也可以暴力解法，直接遍历ListNode[]，把所有的链表全部合并一次，第一次暴力解法，结果超越了25%的用户。。
 * 比较好一点的解法是，用类似外排序中的归并，每次把两个小的字串归并为一个大的字串。
 * 由于合并两个链表时，如果一个长的链表和短的链表合并时候，长的直接拼接到短的上去，相比于暴力法，单次归并不会造成更多时间的浪费。
 * 合并的次数也要少一些，因为N>(N/2+N/4+N/8+16/N+....+2);但是这两个数字相差并不多啊，为什么运行结果相差这么多
 * 难道是由于第二次的方法总是访问前N/2个元素，驻在内存中，不用经常取数据导致的速度快吗?
 * 当只剩下1个链表时，就不会再继续归并了。
 */
public class MergeKSortedList {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists==null||lists.length<1)
            return null;

        int listSize=lists.length;
        while(listSize>1){
            for(int i=0;i<listSize/2;i++){
                lists[i]=mergeTwoList(lists[i],lists[listSize-1-i]);
            }
            if(listSize%2==1)
                listSize=listSize/2+1;
            else
                listSize/=2;
        }

        return lists[0];
    }
    public ListNode mergeTwoList(ListNode one,ListNode two){
        ListNode head=new ListNode(Integer.MAX_VALUE);
        ListNode temp=head;
        while(one!=null&&two!=null){
            if(one.val<two.val){
                temp.next=one;
                one=one.next;
            }
            else{
                temp.next=two;
                two=two.next;
            }
            temp=temp.next;
        }
        if(one!=null&&two==null){
            temp.next=one;
        }
        if(two!=null&&one==null)
            temp.next=two;
        return head.next;
    }
    public static void main(String[]args){
        int arr1[]={1,4,5};
        int arr2[]={1,3,4};
        int arr3[]={2,6};
        ListNode[] listArray={ListNode.createList(arr1)};
        for(ListNode tmp:listArray)
        ListNode.printList(tmp);
        ListNode[]listArray1=null;
        MergeKSortedList test=new MergeKSortedList();
        ListNode.printList(test.mergeKLists(listArray));
        ListNode[]bug={};
        System.out.println("bug:"+bug);
        ListNode.printList(test.mergeKLists(bug));
    }
}
