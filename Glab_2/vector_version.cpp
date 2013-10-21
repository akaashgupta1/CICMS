#include "vector_version.h"
#include <ctime>
#include <sstream>

vector_version::~vector_version()
{
	while (!vtr.empty())
	{
		delete vtr.back();
		vtr.pop_back();
	}
}

void vector_version::add(Product* pro)
{
		vtr.push_back(pro);
}

int vector_version::getIndex(Product* pro)
{
	for (int i=0;i<vtr.size();i++)
		if (vtr[i]->getbarcode()==pro->getbarcode())
			return i;
	return -1;
}

void vector_version::scrap(Product* pro)
{
	//create a new vector
	vector<Product*> temp;

	//copy items, delete the scrapped one
	while (vtr.size()!=0)
	{
		if (vtr.back()->getbarcode()!=pro->getbarcode())
			temp.push_back(vtr.back());
		else
			delete vtr.back();
		vtr.pop_back();
	}

	//copy items back
	vtr=temp;
}

void vector_version::reset_no_sold(Product* pro)
{
	vtr[getIndex(pro)]->reset();
}

void vector_version::sale(Product* pro, int num)
{
	vtr[getIndex(pro)]->sell(num);
}

void vector_version::restock(Product* pro, int num)
{
	vtr[getIndex(pro)]->restock(num);
}

bool vector_version::check_expired(Product* pro)
{
	time_t t=time(0);
	tm* now=localtime(&t);
	istringstream instr(vtr[getIndex(pro)]->returnexpiry());
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

vector<Product*> vector_version::search_name(string name)
{
	vector<Product*> ans;
	for (int i=0;i<vtr.size();i++)
		if (vtr[i]->getname()==name)
			ans.push_back(vtr[i]);
	return ans;
}
vector<Product*> vector_version::search_category(string category)
{
	vector<Product*> ans;
	for (int i=0;i<vtr.size();i++)
		if (vtr[i]->get_category()==category)
			ans.push_back(vtr[i]);
	return ans;
}
vector<Product*> vector_version::search_manufacturer(string manu)
{
	vector<Product*> ans;
	for (int i=0;i<vtr.size();i++)
		if (vtr[i]->getmanufacturer()==manu)
			ans.push_back(vtr[i]);
	return ans;
}
Product* vector_version::search_barcode(double barcode)
{
	vector<Product*> ans;
	for (int i=0;i<vtr.size();i++)
		if (vtr[i]->getbarcode()==barcode)
			return vtr[i];
	return 0;
}
