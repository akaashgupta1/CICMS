#include "dynamicArray.h"
#include <sstream>
#include <ctime>

Product* dynamicArray::retrieve(int index)
{
	return arr[index];
}

int dynamicArray::getIndex(Product* pro)
{
	int i;
	for (i=0;i<size;i++)
		if (arr[i]->getbarcode()==pro->getbarcode())
			return i;
	return -1;
}

void dynamicArray::add(Product* pro)
{
	//create a new array and copy the products
	Product** temp=new Product*[size+1];
	for (int i=0;i<size;i++)
		temp[i]=arr[i];
	temp[size]=NULL;

	//delete old array, create new one, copy and add products
	delete [size]arr;
	arr=new Product*[++size];
	for (int i=0;i<size-1;i++)
		arr[i]=temp[i];
	arr[size-1]=pro;
	//delete temporary array
	delete[size]temp;
}

void dynamicArray::scrap(Product* pro)
{
	//create new array and copy the products
	Product** temp=new Product*[size];
	for (int i=0;i<size;i++)
		temp[i]=arr[i];

	//find the product needs to be deleted
	int index=getIndex(pro);
	temp[index]=NULL;
	delete arr[index];
	arr[index]=NULL;

	//delete old array, create new one, copy products except the scraped one
	delete [size]arr;
	arr=new Product* [--size];
	for (int i=0;i<index;i++)
		arr[i]=temp[i];
	for (int i=index;i<size;i++)
		arr[i]=temp[i+1];

	//delete temporary array
	delete[size+1]temp;
}
void dynamicArray::reset_no_sold(Product* pro)
{
	arr[getIndex(pro)]->reset();
}

void dynamicArray::sale(Product* pro, int num)
{
	arr[getIndex(pro)]->sell(num);
}

void dynamicArray::restock(Product* pro, int num)
{
	arr[getIndex(pro)]->restock(num);
}

bool dynamicArray::check_expired(Product* pro)
{
	time_t t=time(0);
	tm* now=localtime(&t);
	istringstream instr(arr[getIndex(pro)]->returnexpiry());
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

vector<Product*> dynamicArray::search_name(string name)
{
	vector<Product*> ans;
	for (int i=0;i<size;i++)
		if (arr[i]->getname()==name)
			ans.push_back(arr[i]);
	return ans;
}
vector<Product*> dynamicArray::search_category(string category)
{
	vector<Product*> ans;
	for (int i=0;i<size;i++)
		if (arr[i]->get_category()==category)
			ans.push_back(arr[i]);
	return ans;
}
vector<Product*> dynamicArray::search_manufacturer(string manu)
{
	vector<Product*> ans;
	for (int i=0;i<size;i++)
		if (arr[i]->getmanufacturer()==manu)
			ans.push_back(arr[i]);
	return ans;
}
Product* dynamicArray::search_barcode(double barcode)
{
	vector<Product*> ans;
	for (int i=0;i<size;i++)
		if (arr[i]->getbarcode()==barcode)
			return arr[i];
	return NULL;
}


