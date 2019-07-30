public class Node {
    int value;
    Node next;
    Node prev;
    public Node(int value,Node next,Node prev){
        this.value=value;
        this.next=next;
        this.prev=prev;
    }
    public static Node linkListCreator(int[]nums){
        if(nums==null||nums.length<1) return null;
        if(nums.length==1){
            Node tmp=new Node(nums[0],null,null);
            tmp.prev=tmp;
            tmp.next=tmp;
            return tmp;
        }
        //Node head=new Node(nums[0],null,null);
        Node arr[]=new Node[nums.length];
        for(int i=0;i<nums.length;i++) arr[i]=new Node(nums[i],null,null);
        Node head=arr[0];
        Node temp=head;
        for(int i=1;i<arr.length;i++){
            arr[i].prev=arr[i-1];
            if(i+1<arr.length)
                arr[i].next=arr[i+1];
        }
        //设置头节点
        arr[0].prev=arr[arr.length-1];
        arr[0].next=arr[1];
        //设置尾节点
        arr[arr.length-1].next=head;
        return head;
    }

    public static void print(Node head){
        if(head==null) return;
        Node tmp=head.next;
        String info="";
        info+=head.value+"->";
        while (tmp!=head){
            info+=tmp.value+"->";
            tmp=tmp.next;
        }
        info=info.substring(0,info.length()-2);
        System.out.println(info);
    }

}
