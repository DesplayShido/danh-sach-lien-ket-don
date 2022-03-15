#ifndef LinkedList_h
#define LinkedList_h
struct Node
{
	int data;
	Node* next;
};
struct LinkList
{
	Node* Head;
	Node* Tail;
};
Node* CreateNode (int input);
void CreateList	(LinkList& l);
void AddHead (LinkList& l, Node* node);
void AddTail(LinkList& l, Node* node);
void InsertAfterNodeSearch (LinkList& l, Node* head, Node* tail);
int RemoveHead (LinkList& l);
int RemoveTail (LinkList& l);
int RemoveInNodeSearch (LinkList& l, Node* head);
LinkList ReverseList (LinkList& l);
Node* GetNode (LinkList l, int index);
void SwapNode (Node* node1, Node* node2);
void ArrangeList (LinkList& l);
LinkList ConnectList (LinkList& l1, LinkList& l2);
LinkList ConnectListSmallToBig (LinkList& l1, LinkList& l2);
void DetachList(LinkList& l1, LinkList& l2, LinkList& l3);
void DetachListOddAndEven(LinkList& l1, LinkList& l2, LinkList& l3);
void PrintList (LinkList l);
Node* Search (LinkList l, int index);
int Length (LinkList l);
void DeleteList (LinkList& l);
#endif // LinkedList_h
