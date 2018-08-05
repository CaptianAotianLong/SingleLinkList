#include <SingleLinkList.h>

int main()
{
    int data,dataTemp;

    /*声明一个单向链表*/
    node* list;
    list = single_link_list_create_r();
    /*打印链表*/
    printSingleLinklist(list);

    lengthOfList = singleLinkListLength(list);

    printf("The length of list is %d\n",lengthOfList);

    list = reverseSingleLinkListNode(list);
    printf("Rverse:\n");
    printSingleLinklist(list);
    //clearSingleLinkList(list);

    //printSingleLinklist(list);
    printf("输入要删除的节点\n");
    scanf("%d",&data);
    deleteSigleLinkListNode(list,data);

    printf("输入要增加的节点\n");
    scanf("%d",&data);
    addSingleLinkListNode(list,data);
    printSingleLinklist(list);

    printf("输入要查找的节点\n");
    scanf("%d",&data);
    searceSingleLinkListNode(list,data);
    printSingleLinklist(list);

    printf("输入要修改的节点\n");
    scanf("%d",&data);
    printf("输入新的数据\n");
    scanf("%d",&dataTemp);
    modifySingleLinkListNode(list,data,dataTemp);
    printSingleLinklist(list);

    return 1;
}
