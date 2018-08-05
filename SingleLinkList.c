#include<SingleLinkList.h>
/*函数名：
 *功能：链表初始化
 *输入：
 *输出：
 */
node* init_single_link_list()
{
    node* sl_node;
    sl_node=(node*)malloc(sizeof(node));//申请内存空间
    if(NULL==sl_node)
    {
        printf("申请内存空间失败\n");
        exit(0);
    }
    sl_node->p_next = NULL;

    return sl_node;
}

/*函数名：
 *功能：头插法创建单向链表
 *输入：
 *输出：
 */
node* single_link_list_create_h( )
{
    //初始化一个空链表
    node* sl_node=init_single_link_list();

    printf("输入数据，以'-1'结束\n");

    //定义链表数据域中的数据
    NODE_DATA_TYPE data;
    while(1)
    {
        if((scanf("%d",&data)<1)||(data==-1))
        {
            break;
        }
        node* p_node;
        p_node          = init_single_link_list();
        p_node->data    = data;
        p_node->p_next  = sl_node->p_next;
        sl_node->p_next = p_node;
    }
    return sl_node;
}

/*函数名：
 *功能：尾插法创建单向链表
 *输入：
 *输出：
 */
node* single_link_list_create_r( )
{
    //初始化一个空链表并返回头结点
    node* sl_node=init_single_link_list( );

    printf("请输入数据，并以‘-1’结束\n");

    //定义链表数据域中的数据
    NODE_DATA_TYPE data;

    while(1)
    {
        //创建一个新节点
        node* sl_node=init_single_link_list( );
        //创建一个指向尾节点的指针
        node* rear_node;
        rear_node = sl_node;//开始时指向头结点的下一节点

        //定义节点的数据域
        NODE_DATA_TYPE data;
        scanf("%d",&data );
        while(data  != -1)
        {
            //创建一个新节点存放数据
            node* p_node        = init_single_link_list();
            //节点数据域赋值
            p_node->data        = data;
            //将新节点插入表尾
            rear_node->p_next   = p_node;
            //尾节点指向表尾
            rear_node           = p_node;

            scanf("%d",&data );
        }
        return sl_node;//返回链表头指针
    }
}

/*函数名：
 *功能：遍历链表
 *输入：
 *输出：
 */
 void printSingleLinklist(node* sl_node)
 {
     if(NULL == sl_node->p_next)
     {
         printf("printSingleList()执行,链表为空");
     }
     else
     {
         sl_node=sl_node->p_next;
         while(NULL != sl_node)
         {
            printf("%d\n",sl_node->data);
            sl_node=sl_node->p_next;
         }
         printf("链表输出结束\n");
     }
}

 int singleLinkListLength(node* sl_node)
 {
     int length = 0;
     while(sl_node->p_next != NULL)
     {
         length++;
         sl_node=sl_node->p_next;
     }
     return length;
 }

  /*清除链表中的所有元素*/
 void clearSingleLinkList(node* sl_node)
 {
     if(sl_node->p_next == NULL)
     {
         printf("The list is empty!\n");
     }
     else
    {
     node* sl_cur;
     node* sl_temp;
     sl_cur          = sl_node;
     sl_cur          = sl_cur->p_next;
     while(sl_cur != NULL)
     {
         sl_temp = sl_cur->p_next;
         free(sl_cur);
         sl_cur = sl_temp;
     }
     sl_node->p_next = NULL;
     printf("The single link list has been clear \n");
    }
 }

/*删除某个节点*/
int deleteSigleLinkListNode(node* sl_node,NODE_DATA_TYPE data)
{
    if(sl_node->p_next == NULL)
    {
        printf("空表");
        return 0;
    }
    node* p_cur = sl_node;
    node* p_temp  = p_cur;
    p_cur = p_cur->p_next;
    while(p_cur!= NULL)
    {
        if(p_cur->data == data)
        {
            p_temp->p_next = p_cur->p_next;
            free(p_cur);
            printf("节点%d已删除\n",data);
            return 1;
        }
        p_temp = p_cur;
        p_cur  = p_cur->p_next;
    }
    printf("未找到该节点\n");
    return 0;
}
/*增加节点*/
int addSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data)
{
    node* p_cur = sl_node;
    while(p_cur->p_next != NULL)
    {
        p_cur = p_cur->p_next;
    }
    node* newNode =(node*)malloc(sizeof(node));//申请内存空间
    if(NULL == newNode)
    {
        printf("申请内存空间失败\n");
        exit(0);
        return 0;
    }
    newNode->data   = data;
    p_cur->p_next   = newNode;
    newNode->p_next = NULL;
    printf("添加节点%d成功\n",data);
    return 1;
}

/*链表反转*/
node* reverseSingleLinkListNode(node* sl_node)
{
    if(sl_node->p_next==NULL || sl_node == NULL)
    {
        printf("空表\n");
        return sl_node;
    }
    node* p_pre  = NULL;
    node* p_node = sl_node->p_next;
    node* p_next = NULL;

    while(p_node != NULL)
    {
        p_next = p_node->p_next;
        p_node->p_next = p_pre;
        p_pre = p_node;
        p_node =p_next;
    }
    sl_node->p_next=p_pre;

    return sl_node;
}

/*查找某个节点*/
int searceSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data)
{
    if(sl_node->p_next == NULL)
    {
        printf("空表\n");
        return 0;
    }
    node* p_cur=sl_node->p_next;
    while(p_cur != NULL)
    {
        if(p_cur->data == data)
        {
            printf("节点%d找到\n",data);
            return 1;
        }
        p_cur = p_cur->p_next;
    }
    printf("未找到节点%d\n",data);
    return 0;
}
/*修改某个节点*/
int modifySingleLinkListNode(node* sl_node,NODE_DATA_TYPE dataToChange,NODE_DATA_TYPE dataNew)
{
    if(sl_node->p_next == NULL)
    {
        printf("空表\n");
        return 0;
    }
    node* p_cur=sl_node->p_next;
    while(p_cur != NULL)
    {
        if(p_cur->data == dataToChange)
        {
            p_cur->data = dataNew;
            return 1;
        }
        p_cur = p_cur->p_next;
    }
    printf("未找到节点%d\n",dataToChange);
    return 0;
}

