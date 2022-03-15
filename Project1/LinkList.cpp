#include "LinkList.h"
#include <iostream>

using namespace std;

Node* CreateNode (int input)
{
	Node* node = new Node;
	node->data = input;
	node->next = NULL;
	return node;
}

void CreateList (LinkList& l)
{
	l.Head = l.Tail = NULL;
}

void AddHead (LinkList& l, Node* node)
{
	if (l.Head == NULL) {
		l.Head = l.Tail = node;
	}
	else {
		node->next = l.Head;
		l.Head = node;
	}
}

void AddTail (LinkList& l, Node* node)
{
	if (l.Head == NULL) {
		l.Head = node;
		l.Tail = node;
	}
	else {
		l.Tail->next = node;
		l.Tail = node;
	}
}

void InsertAfterNodeSearch(LinkList& l, Node* head, Node* nodesearch)
{
	if (nodesearch != NULL) {
		head->next = nodesearch->next;
		nodesearch->next = head;
		if (l.Tail == nodesearch)
			l.Tail = head;
	}
	else
		AddHead(l, head);
}

int RemoveHead (LinkList& l)
{
	if (l.Head != NULL) {
		Node* node = l.Head;
		l.Head = node->next;
		node = NULL;
		if (l.Head == NULL)
			l.Tail = NULL;
		return 1;
	}
	return 0;
}

int RemoveTail(LinkList& l)
{
	if (l.Head != NULL) {
		Node* node = l.Head->next;
		Node* NodeNext = node;
		while (node->next != NULL)
		{
			NodeNext = node;
			node = node->next;
		}
		l.Tail = NodeNext;
		l.Tail->next = NULL;
		return 1;
	}
	return 0;
}

int RemoveInNodeSearch (LinkList& l, Node* head)
{
	Node* node = l.Head;
	Node* NodeNext = NULL;
	while (node != NULL) {
		if (node->data == head->data)
			break;
		NodeNext = node;
		node = node->next;
	}
	if (node == NULL)
		return 0;
	if (NodeNext != NULL) {
		if (node == l.Tail)
			l.Tail = NodeNext;
		NodeNext->next = node->next;
		delete node;
	}
	else {
		l.Head = node->next;
		if (l.Head == NULL)
			l.Tail = NULL;
	}
	return 1;
}

LinkList ReverseList(LinkList& l)
{
	LinkList list;
	CreateList(list);
	Node* node = l.Head;
	while(node != NULL) {
		AddHead(list, CreateNode(node->data));
		node = node->next;
	}
	return list;
}

Node* GetNode (LinkList l, int index)
{
	Node* node = l.Head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}


void SwapNode(Node* node1, Node* node2)
{
	int Mid;
	Mid = node1->data;
	node1->data = node2->data;
	node2->data = Mid;
}

void ArrangeList(LinkList& l)
{
	for (Node* node1 = l.Head; node1 != NULL; node1 = node1->next)
		for (Node* node2 = node1->next; node2 != NULL; node2 = node2->next)
			if (node1->data > node2->data)
				SwapNode(node1, node2);
}

LinkList ConnectList(LinkList& l1, LinkList& l2)
{
	LinkList list;
	CreateList(list);
	Node* node = l1.Head;
	while (node != NULL) {
		AddTail(list, node);
		node = node->next;
	}
	node = l2.Head;
	while (node != NULL) {
		AddTail(list, node);
		node = node->next;
	}
	return list;
}

LinkList ConnectListSmallToBig(LinkList& l1, LinkList& l2)
{
	LinkList list;
	CreateList(list);
	ArrangeList(l1);
	ArrangeList(l2);
	Node* node1 = l1.Head;
	Node* node2 = l2.Head;
	if (node1->data < node2->data) {
		list.Head = list.Tail = CreateNode(node1->data);
		node1 = node1->next;
	}
	else {
		list.Head = list.Tail = CreateNode(node2->data);
		node2 = node2->next;
	}
	while(node1 != NULL || node2 != NULL) {
		if (node1 == NULL) {
			AddTail(list, CreateNode(node2->data));
			node2 = node2->next;
			continue;
		}
		if (node2 == NULL) {
			AddTail(list, CreateNode(node1->data));
			node1 = node1->next;
			continue;
		}
		if (node1->data < node2->data) {
			AddTail(list, CreateNode(node1->data));
			node1 = node1->next;
		}
		else {
			AddTail(list, CreateNode(node2->data));
			node2 = node2->next;
		}
	}
	return list;
}

void DetachList(LinkList& l1, LinkList& l2, LinkList& l3)
{
	Node* node = l1.Head;
	l2.Head = l2.Tail = CreateNode(node->data);
	node = node->next;

	if (node != NULL) {
		int j = 1;
		for (int i = 1; i < Length(l1) && i < (double)Length(l1) / 2; i++, node = node->next, j++) {
			AddTail(l2, CreateNode(node->data));
		}
		l3.Head = l3.Tail = CreateNode(node->data);
		node = node->next;
		for (;node != NULL; node = node->next) {
			AddTail(l3, CreateNode(node->data));
		}
	}
}

void DetachListOddAndEven(LinkList& l1, LinkList& l2, LinkList& l3)
{
	Node* node = l1.Head;
	if (node->data % 2 == 0)
		l2.Head = l2.Tail = CreateNode(node->data);
	else
		l3.Head = l3.Tail = CreateNode(node->data);
	node = node->next;
	if (node != NULL) {
		for (; node != NULL; node = node->next) {
			if (node->data % 2 == 0)
				AddTail(l2, CreateNode(node->data));
			else
				AddTail(l3, CreateNode(node->data));
		}
	}
}

void PrintList (LinkList l)
{
	if (l.Head != NULL) {
		Node* node = l.Head;
		while (node != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
}

Node* Search (LinkList l, int index)
{
	Node* node = l.Head;
	while (node != NULL && node->data != index)
		node = node->next;
	if (node != NULL)
		return node;
	return NULL;
}

int Length (LinkList l)
{
	int length = 0;
	Node* node = l.Head;
	while (node != NULL)
	{
		length++;
		node = node->next;
	}
	return length;
}

void DeleteList (LinkList& l)
{
	Node* node = l.Head;
	while (node != NULL) 
	{
		RemoveHead(l);
		node = l.Head;
	}
	l.Tail = NULL;
}
