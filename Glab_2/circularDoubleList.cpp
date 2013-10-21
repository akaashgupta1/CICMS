#include "circularDoubleList.h"
#include <vector>
#include <ctime>
#include <sstream>

circular_double_list::~circular_double_list()
{
	if (head==NULL)
		return;
	while (head->next!=head)
	{
		object* cur=head;
		head=head->next;
		head->prev=cur->prev;
		cur->prev->next=head;
		delete cur->item;
		delete cur;
	}
	delete head->item;
	delete head;
}

circular_double_list::object* circular_double_list::traverse(Product* pro)
{
	object* cur=head;
	do{
		if (cur->item->getbarcode()==pro->getbarcode())
			return cur;
		cur=cur->next;
	} while(cur!=head);
	return NULL;
}

Product* circular_double_list::retrieve(int index)
{
	object* cur=head;
	for (int i=0;i<index;i++)
		cur=cur->next;
	return cur->item;
}

void circular_double_list::add(Product* pro)
{
	//create a new object
	object* cur=new object;
	cur->item=pro;
	cur->next=NULL;
	cur->prev=NULL;

	//case empty list
	if (head==NULL)
	{
		cur->next=cur;
		cur->prev=cur;
	}

	//otherwise: insert to the begining of the list
	else
	{
		cur->next=head;
		cur->prev=head->prev;
		head->prev->next=cur;
		head->prev=cur;
	}

	//update head and size
	head=cur;
	size++;
}

void circular_double_list::scrap(Product* pro)
{
	object* cur=traverse(pro);
	if (cur==head)
		head=cur->next;
	cur->prev->next=cur->next;
	cur->next->prev=cur->prev;
	delete cur->item;
	delete cur;
	size--;
	if (size==0)
		head=NULL;
}
void circular_double_list::reset_no_sold(Product* pro)
{
	traverse(pro)->item->reset();
}

void circular_double_list::sale(Product* pro, int num)
{
	traverse(pro)->item->sell(num);
}

void circular_double_list::restock(Product* pro, int num)
{
	traverse(pro)->item->restock(num);
}

bool circular_double_list::check_expired(Product* pro)
{
	time_t t=time(0);
	tm* now=localtime(&t);
	istringstream instr(traverse(pro)->item->returnexpiry());
	int day, now_day=now->tm_mday;int date;
	int month, now_month=now->tm_mon+1;
	int year, now_year=now->tm_year+1900;
	instr>>date;
	day=date/1000000;
	month=(date/10000)%100;
	year=date%10000;
	if (now_year<year||(now_year==year&&now_month<month)||(now_year==year&&now_month==month&&now_day<day))
		return false;
	return true;
}

vector<Product*> circular_double_list::search_name(string name)
{
	vector<Product*> ans;
	object* cur=head;
	do{
		if (cur->item->getname()==name)
			ans.push_back(cur->item);
		cur=cur->next;
	}while (cur!=head);
	return ans;
}
vector<Product*> circular_double_list::search_category(string cate)
{
	vector<Product*> ans;
	object* cur=head;
	do{
		if (cur->item->get_category()==cate)
			ans.push_back(cur->item);
		cur=cur->next;
	}while (cur!=head);
	return ans;
}
vector<Product*> circular_double_list::search_manufacturer(string manu)
{
	vector<Product*> ans;
	object* cur=head;
	do{
		if (cur->item->getmanufacturer()==manu)
			ans.push_back(cur->item);
		cur=cur->next;
	}while (cur!=head);
	return ans;
}
Product* circular_double_list::search_barcode(double barcode)
{
	object* cur=head;
	do{
		if (cur->item->getbarcode()==barcode)
			return cur->item;
		cur=cur->next;
	}while (cur!=head);
	return NULL;
}
