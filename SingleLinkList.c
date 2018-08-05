#include<SingleLinkList.h>
/*��������
 *���ܣ������ʼ��
 *���룺
 *�����
 */
node* init_single_link_list()
{
    node* sl_node;
    sl_node=(node*)malloc(sizeof(node));//�����ڴ�ռ�
    if(NULL==sl_node)
    {
        printf("�����ڴ�ռ�ʧ��\n");
        exit(0);
    }
    sl_node->p_next = NULL;

    return sl_node;
}

/*��������
 *���ܣ�ͷ�巨������������
 *���룺
 *�����
 */
node* single_link_list_create_h( )
{
    //��ʼ��һ��������
    node* sl_node=init_single_link_list();

    printf("�������ݣ���'-1'����\n");

    //���������������е�����
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

/*��������
 *���ܣ�β�巨������������
 *���룺
 *�����
 */
node* single_link_list_create_r( )
{
    //��ʼ��һ������������ͷ���
    node* sl_node=init_single_link_list( );

    printf("���������ݣ����ԡ�-1������\n");

    //���������������е�����
    NODE_DATA_TYPE data;

    while(1)
    {
        //����һ���½ڵ�
        node* sl_node=init_single_link_list( );
        //����һ��ָ��β�ڵ��ָ��
        node* rear_node;
        rear_node = sl_node;//��ʼʱָ��ͷ������һ�ڵ�

        //����ڵ��������
        NODE_DATA_TYPE data;
        scanf("%d",&data );
        while(data  != -1)
        {
            //����һ���½ڵ�������
            node* p_node        = init_single_link_list();
            //�ڵ�������ֵ
            p_node->data        = data;
            //���½ڵ�����β
            rear_node->p_next   = p_node;
            //β�ڵ�ָ���β
            rear_node           = p_node;

            scanf("%d",&data );
        }
        return sl_node;//��������ͷָ��
    }
}

/*��������
 *���ܣ���������
 *���룺
 *�����
 */
 void printSingleLinklist(node* sl_node)
 {
     if(NULL == sl_node->p_next)
     {
         printf("printSingleList()ִ��,����Ϊ��");
     }
     else
     {
         sl_node=sl_node->p_next;
         while(NULL != sl_node)
         {
            printf("%d\n",sl_node->data);
            sl_node=sl_node->p_next;
         }
         printf("�����������\n");
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

  /*��������е�����Ԫ��*/
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

/*ɾ��ĳ���ڵ�*/
int deleteSigleLinkListNode(node* sl_node,NODE_DATA_TYPE data)
{
    if(sl_node->p_next == NULL)
    {
        printf("�ձ�");
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
            printf("�ڵ�%d��ɾ��\n",data);
            return 1;
        }
        p_temp = p_cur;
        p_cur  = p_cur->p_next;
    }
    printf("δ�ҵ��ýڵ�\n");
    return 0;
}
/*���ӽڵ�*/
int addSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data)
{
    node* p_cur = sl_node;
    while(p_cur->p_next != NULL)
    {
        p_cur = p_cur->p_next;
    }
    node* newNode =(node*)malloc(sizeof(node));//�����ڴ�ռ�
    if(NULL == newNode)
    {
        printf("�����ڴ�ռ�ʧ��\n");
        exit(0);
        return 0;
    }
    newNode->data   = data;
    p_cur->p_next   = newNode;
    newNode->p_next = NULL;
    printf("��ӽڵ�%d�ɹ�\n",data);
    return 1;
}

/*����ת*/
node* reverseSingleLinkListNode(node* sl_node)
{
    if(sl_node->p_next==NULL || sl_node == NULL)
    {
        printf("�ձ�\n");
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

/*����ĳ���ڵ�*/
int searceSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data)
{
    if(sl_node->p_next == NULL)
    {
        printf("�ձ�\n");
        return 0;
    }
    node* p_cur=sl_node->p_next;
    while(p_cur != NULL)
    {
        if(p_cur->data == data)
        {
            printf("�ڵ�%d�ҵ�\n",data);
            return 1;
        }
        p_cur = p_cur->p_next;
    }
    printf("δ�ҵ��ڵ�%d\n",data);
    return 0;
}
/*�޸�ĳ���ڵ�*/
int modifySingleLinkListNode(node* sl_node,NODE_DATA_TYPE dataToChange,NODE_DATA_TYPE dataNew)
{
    if(sl_node->p_next == NULL)
    {
        printf("�ձ�\n");
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
    printf("δ�ҵ��ڵ�%d\n",dataToChange);
    return 0;
}

