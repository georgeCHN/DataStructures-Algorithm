//
// Created by george on 19/8/18.
//
#include "binaryTree.h"
#include "stack/my_stack.h"
#include "queue/my_queue.h"
#include<string.h>
#include<math.h>

//树的层序遍历的变体,借助一个栈来实现
void bt_level_traversal_inverse(BiTree root)
{
    my_queue *queue = queue_init(100);
    my_stack_t *stack = stack_init(100);
    queue_enqueue(queue,*root);
    BiNode node;
    while(!queue_empty(queue)){
        queue_dequeue(queue,&node);
        stack_push(stack,node);
        if(node.left)
            queue_enqueue(queue,*(node.left));
        if(node.right)
            queue_enqueue(queue,*(node.right));
    }
    while(!stack_is_empty(stack)){
        stack_pop(stack,&node);
        printf("%c",node.data);
    }
}
//求树的高度，不使用递归
int bt_height(BiTree root)
{
    if(!root) return 0;
    int height=0;
    my_queue *queue = queue_init(100);
    queue_enqueue(queue,*root);
    BiNode node;
    int level_total=1;
    int curr_cnt=0;
    while(!queue_empty(queue)){
        queue_dequeue(queue,&node);
        curr_cnt++;
        if(node.left)
            queue_enqueue(queue,*(node.left));
        if(node.right)
            queue_enqueue(queue,*(node.right));
        if(curr_cnt==level_total){
            curr_cnt=0;
            level_total=queue_count(queue);//此时队列中的元素的个数就是下一层的节点个数
            height++;
        }
    }
    return height;
}
BiTree  bt_create_by_traverse_core(const char* pre, const char* in,int left1,int right1,int left2,int right2)
{
    BiNode* root=(BiNode*)malloc(sizeof(BiNode));
    root->data=pre[left1];
    int mid=left2;
    while(in[mid]!=root->data)
        mid++;
    if(mid-left2==0)
        root->left=NULL;
    //收缩左边的区间
    else
        root->left=bt_create_by_traverse_core(pre,in,left1+1,left1+mid-left2,left2,mid-1);
    if(right2-mid==0)
        root->right=NULL;
    //收缩右边的区间
    else
        root->right=bt_create_by_traverse_core(pre,in,left1+mid-left2+1,right1,mid+1,right2);
    return root;
}
//由先序和中序建立一棵树
BiTree bt_create_by_traverse(const char* pre, const char* in)
{
    int len1 = (int)strlen(pre);
    int len2=(int) strlen(in);
    if(len1!=len2 || len1==0) return NULL;
    return bt_create_by_traverse_core(pre,in,0,len1-1,0,len2-1);
}
//解题思路类似用层次遍历
bool bt_is_complete_bt(BiTree root)
{
    if(!root)   return true;
    int cnt=bt_count_depth(root);
    cnt=(int)pow(2,cnt)-1;
    //array作为队列用
    BiNode** array=(BiNode**)malloc(cnt*sizeof(BiNode*));
    int front=0;
    int rear=0;
    array[rear++]=root;
    while (rear!=front){
        root=array[front++];
        if(root){
            array[rear++]=root->left;
            array[rear++]=root->right;
        }
        //当节点为空时，检测其后的节点，如果有不为空的说明不是完全二叉树
        else{
            while(rear!=front){
                root=array[front++];
                if(root!=NULL)
                    return false;
            }
        }
    }
    //释放内存
    for(int i=0;i<cnt;i++)
        free(array[i]);
    free(array);
    return true;
}
int bt_count_dualNode(BiTree root)
{
    if(!root)return 0;
    if(root->left && root->right)
        return 1+bt_count_dualNode(root->left)+bt_count_dualNode(root->right);
    else
        return bt_count_dualNode(root->left)+bt_count_dualNode(root->right);
}
void bt_swap_leftRight_node(BiTree root)
{
    if(!root) return;
    bt_swap_leftRight_node(root->left);
    bt_swap_leftRight_node(root->right);
    BiNode* tmp=root->left;
    root->left=root->right;
    root->right=tmp;
}
char bt_preOrder_kth(BiTree root,int k)
{
    static int cnt=0;
    if(!root||k==0) return '#';
    else{
        cnt++;
        if(cnt==k)
            return root->data;
    }
    char tmp=bt_preOrder_kth(root->left,k);
    char ch=bt_preOrder_kth(root->right,k);
    if(tmp=='#')
        return ch;
    else
        return tmp;
}
//删除以root的根节点的整棵树
void bt_clear(BiTree root){
    if(!root) return;
    bt_clear(root->left);
    bt_clear(root->right);
    free(root);
}
BiNode* bt_removeX(BiTree root,char x)
{
    if(root==NULL) return NULL;
    if(root->data==x) {
        bt_clear(root->left);
        bt_clear(root->right);
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    root->left=bt_removeX(root->left,x);
    root->right=bt_removeX(root->right,x);
    return root;
}
void bt_ancestor_path_aux(BiTree root,char ch,my_stack_t* stack)
{
    if(!root) return;
    bt_ancestor_path_aux(root->left,ch,stack);
    bt_ancestor_path_aux(root->right,ch,stack);
    if(root->data==ch){
        stack_push(stack,*root);
    }else if(!stack_is_empty(stack)){
        BiNode *pNode = stack_top(stack);
        //简言之,就是栈顶节点是否是该节点的子节点
        bool flag=(root->left&&root->left->data==pNode->data)||(root->right&&root->right->data==pNode->data);
        if(flag)
            stack_push(stack,*root);
    }
}
void bt_ancestor_path(BiTree root,char ch)
{
    if(!root) return;
    int cnt =bt_count_depth(root);
    //stack_init开始出现了错误, 存放BiNode时，malloc(BiNode),分配malloc(BiTree)时会有错误
    my_stack_t *stack = stack_init(cnt);
    bt_ancestor_path_aux(root,ch,stack);
    BiNode node;
    while(!stack_is_empty(stack)){
        stack_pop(stack,&node);
        printf("%c-->",node.data);
    }
    printf("\n");
}
//找出p,q的最近公共节点
void bt_ancestor(BiTree root,char p,char q)
{
    //初始化两个栈，用bt_ancestor_path_core()求出路径放在栈中
    int height = bt_count_depth(root);
    my_stack_t *pStack = stack_init(height);
    my_stack_t *qStack = stack_init(height);
    bt_ancestor_path_aux(root,p,pStack);
    bt_ancestor_path_aux(root,q,qStack);
    if(stack_is_empty(pStack)||stack_is_empty(qStack))
        return;
    BiNode pNode,qNode;
    //last来记录最近相同的节点
    BiNode *last = stack_top(pStack);
    while((!stack_is_empty(pStack))&&(!stack_is_empty(qStack))){
        stack_pop(pStack,&pNode);
        stack_pop(qStack,&qNode);
        if(pNode.data!=qNode.data)
            break;
        last->data=pNode.data;
    }
    printf("%c and %c common node is:%c\n",p,q,last->data);
}
int bt_width(BiTree root)
{
    if(!root) return 0;
    my_queue *queue = queue_init(bt_count_node(root));
    queue_enqueue(queue,*root);
    int width=1;
    int next_cnt=1;
    int curr_cnt=0;
    while(!queue_empty(queue)){
        queue_dequeue(queue,root);
        if(root->left)
            queue_enqueue(queue,*(root->left));
        if(root->right)
            queue_enqueue(queue,*(root->right));
        curr_cnt++;
        if(curr_cnt==next_cnt){
            next_cnt=queue_count(queue);//更新下一层有多少个节点
            width=width>next_cnt?width:next_cnt;//更新目前最大的宽度
            curr_cnt=0;//更新新的一层遍历过的个数
        }
    }
    return width;
}
BiTree bt_create_fullBT_AUX(const char*str,int* i,int height,int curr)
{
    //递归来的并没有使用该字符串,再退回去一个位置
    if(curr>=height) {
        (*i)--;
        return NULL;
    }
    BiNode* node=(BiNode*)malloc(sizeof(BiNode));
    node->data=str[*i];
    (*i)++;
    node->left=bt_create_fullBT_AUX(str,i,height,curr+1);
    (*i)++;
    node->right=bt_create_fullBT_AUX(str,i,height,curr+1);
    return node;
}
BiTree bt_create_fullBT(const char * str)
{
    int len=(int)strlen(str);
    int height=(int)log2(len+1);
    int i=0;
    return bt_create_fullBT_AUX(str,&i,height,0);
}
//建立一个小型的链表用
typedef struct list{
    BiNode* data;
    struct list* next;
}LinkList;
void print(BiTree root)
{
    while(root){
        printf("%c-->",root->data);
        root=root->right;
    }
}
BiTree head,pre=NULL;
BiTree bt_connect_leafNode_AUX(BiTree root)
{
    if(root==NULL) return NULL;
    bt_connect_leafNode_AUX(root->left);
    //链接
    if(!root->left&&!root->right){
        if(pre==NULL){
            head=root;
            pre=root;
        }else{
            pre->right=root;
            pre=root;
        }
    }
    bt_connect_leafNode_AUX(root->right);
    return head;
}
BiNode* bt_connect_leafNode(BiTree root)
{
    if(!root)   return NULL;
    return bt_connect_leafNode_AUX(root);
}
bool bt_similar(BiTree root1,BiTree root2)
{
    if(root1==NULL&&root2==NULL) return true;//两树都空
    else if(root1==NULL||root2==NULL) return false;//只有一树为空
    return bt_similar(root1->left,root2->left)
                &&  bt_similar(root1->right,root2->right);
}
//18

//求叶节点的带权路径长度
int bt_WPL(BiTree root,int depth)
{
    if(root==NULL) return 0;
    if((root->left==NULL)&&(root->right==NULL))//叶节点,因为存储的是char类型,所以-48
        return (root->data-48)*depth;
    else
        return bt_WPL(root->left,depth+1)+bt_WPL(root->right,depth+1);
}
void bt2infixExpression(BiTree root,int tag)
{
    if(!root) return;
    //内部节点加上'('和')',tag=1标识不是根节点，初始化时tag=0为根节点
    if(root->left||root->right){
        if(tag==1)
            printf("(");
        bt2infixExpression(root->left,1);
    }
    //leaf node,直接输出值
    printf("%c",root->data);
    //内部节点加上'('和')'
    if(root->right||root->left){
        bt2infixExpression(root->right,1);
        if(tag==1)
            printf(")");
    }
}