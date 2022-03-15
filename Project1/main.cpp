#include "LinkList.h"
#include <iostream>

using namespace std;

void DownLine() {
	cout << "=================================" << endl;
}

int main() {
	int x, y, n, m;
	LinkList list, list1, list2;
	CreateList(list);
	CreateList(list1);
	CreateList(list2);
	Node* node;

	//Cau 01:
	cout << "Nhap danh sach lien ket don: ";
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		node = CreateNode(x);
		AddTail(list, node);
	}
	DownLine();

	//Cau 02:
	cout << "Danh sach lien ket don da nhap: ";
	PrintList(list);
	DownLine();

	//Cau 03:
	cout << "Do dai cua danh sach lien ket don la: ";
	cout << Length(list) << endl;
	DownLine();

	//Cau 04:
	cout << "Nhap vi tri can tim trong danh sach (in ra gia tri tai vi tri can tim): ";
	cin >> x;
	Node* NodeInX = GetNode(list, x);
	if (NodeInX == NULL) {
		cout << "Khong ton tai vi tri da nhap !" << endl;
	}
	else {
		cout << "Gia tri phan tu thu " << x << " la: " << NodeInX->data << endl;
	}
	DownLine();

	//Cau 05:
	cout << "Nhap gia tri can tim trong danh sach (kiem tra gia tri co ton tai hay khong): ";
	cin >> x;
	NodeInX = Search(list, x);
	if (NodeInX == NULL) {
		cout << "0 (khong ton tai gia tri can tim !)" << endl;
	}
	else {
		cout << "1 (ton tai gia tri can tim !)" << endl;
	}
	DownLine();

	//Cau 06:
	cout << "Nhap gia tri can tim trong danh sach (them phan tu sau gia tri can tim): ";
	cin >> y;
	Node* NodeInY = Search(list, y);
	if (NodeInY == NULL) {
		cout << "Khong ton tai gia tri da nhap !" << endl;
	}
	else {
		cout << "Nhap gia tri can them sau gia tri " << NodeInY->data << " la: ";
		cin >> x;
		Node* NodeX = CreateNode(x);
		InsertAfterNodeSearch(list, NodeX, NodeInY);
		cout << "Danh sach lien ket don sau khi them gia tri " << NodeX->data << " sau gia tri " << NodeInY->data << " la: ";
		PrintList(list);
	}
	DownLine();

	//Cau 07:
	cout << "Nhap x (vi tri can chen trong danh sach): ";
	cin >> x;
	cout << "Nhap vi tri can chen phan tu x: ";
	cin >> y;
	if (y > Length(list)) {
		cout << "Khong ton tai vi tri da nhap !" << endl;
	}
	else {
		Node* NodeX = CreateNode(x);
		NodeInY = GetNode(list, y);
		InsertAfterNodeSearch(list, NodeX, NodeInY);
		cout << "Danh sach lien ket don sau khi them gia tri " << NodeX->data << " tai gia tri " << y << " la: ";
		PrintList(list);
	}
	DownLine();

	//Cau 08:
	cout << "Danh sach sau khi dao nguoc la: ";
	list = ReverseList(list);
	PrintList(list);
	DownLine();

	//Cau 09:
	cout << "Nhap phan tu x (xoa phan tu co gia tri x trong danh sach): ";
	cin >> x;
	if (Search(list, x) != NULL) {
		int Check = RemoveInNodeSearch(list, Search(list, x));
		if (Check == 1)
			cout << "1 (xoa phan tu co gia tri " << x << " thanh cong !)" << endl;
		else
			cout << "0 (xoa phan tu co gia tri " << x << " khong thanh cong !)" << endl;
	}
	else
		cout << "phan tu x khong ton tai trong danh sach !" << endl;
	DownLine();


	//Cau 10:
	int Check = RemoveHead(list);
	if (Check == 0) {
		cout << "Khong co phan tu nao duoc xoa !" << endl;
	}
	else {
		cout << "Mang sau khi duoc xoa phan tu dau tien la: ";
		PrintList(list);
	}
	DownLine();

	//Cau 11:
	Check = RemoveTail(list);
	if (Check == 0) {
		cout << "Khong co phan tu nao duoc xoa !" << endl;
	}
	else {
		cout << "Mang sau khi duoc xoa phan tu cuoi cung la: ";
		PrintList(list);
	}
	DownLine();

	//Cau 12:
	DeleteList(list);
	cout << "Mang da duoc xoa !" << endl;
	PrintList(list);
	DownLine();

	//Cau 13:
	cout << "Nhap danh sach lien ket don da duoc sap xep tang dan (nhap 0 de ket thuc): ";
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		node = CreateNode(x);
		AddTail(list, node);
	}
	cout << "Nhap X (them vao phan tu x trong danh sach): ";
	cin >> x;
	AddTail(list, CreateNode(x));
	ArrangeList(list);
	cout << "Danh sach sau khi them phan tu x va duoc sap xep lai la: ";
	PrintList(list);
	DeleteList(list);
	DownLine();

	//Cau 14:
	cout << "Nhap danh sach lien ket don 1 (nhap 0 de ket thuc): ";
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		node = CreateNode(x);
		AddTail(list1, node);
	}
	cout << "Nhap danh sach lien ket don 2 (nhap 0 de ket thuc): ";
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		node = CreateNode(x);
		AddTail(list2, node);
	}
	list = ConnectList(list1, list2);
	cout << "Danh sach lien ket don sau khi duoc ghep lai la: ";
	PrintList(list);
	DeleteList(list);
	DeleteList(list1);
	DeleteList(list2);
	DownLine();

	//Cau 15:
	cout << "Nhap danh sach lien ket don (nhap 0 de ket thuc): ";
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		node = CreateNode(x);
		AddTail(list, node);
	}
	DetachList(list, list1, list2);
	cout << "Danh sach lien ket don sau khi duoc tach ra thanh 2 danh sach la: " << endl;
	cout << "Danh sach lien ket don 1: ";
	PrintList(list1);
	cout << "Danh sach lien ket don 2: ";
	PrintList(list2);
	DeleteList(list1);
	DeleteList(list2);
	DownLine();

	//Cau 16:
	DetachListOddAndEven(list, list1, list2);
	cout << "Danh sach lien ket don sau khi duoc tach ra thanh 2 danh sach chan le la: " << endl;
	cout << "Danh sach lien ket don 1: ";
	PrintList(list1);
	cout << "Danh sach lien ket don 2: ";
	PrintList(list2);
	DeleteList(list);
	DeleteList(list1);
	DeleteList(list2);
	DownLine();

	//Cau 17: 
	cout << "Nhap danh sach lien ket don 1 (nhap 0 de ket thuc): ";
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		node = CreateNode(x);
		AddTail(list1, node);
	}
	cout << "Nhap danh sach lien ket don 2 (nhap 0 de ket thuc): ";
	while (true)
	{
		cin >> x;
		if (x == 0)
			break;
		node = CreateNode(x);
		AddTail(list2, node);
	}
	list = ConnectListSmallToBig(list1, list2);
	cout << "Danh sach lien ket don sau khi duoc ghep va duoc sap xep lai la: ";
	PrintList(list);
	DownLine();
	return 0;
}
