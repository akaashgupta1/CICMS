#include "product_manager.h"
#include "Product.h"
#include "Perishable.h"
#include "circularDoubleList.h"
#include "dynamicArray.h"
#include "vector_version.h"
#include<fstream>
#include<fstream>
#include<iostream>
#include "UI.h"
#include <ctime>
using namespace std;

product_manager::product_manager()
{
	database=new dynamicArray;
}

void product_manager::add_item(Product* x)
{
	if (database->search_barcode(x->getbarcode())==NULL)
		database->add(x);
	else
		database->restock(x,x->getno_in_stock());
}
bool product_manager::delete_item(string ncm)
{
	vector <Product*> search_results;
	search_results=database->search_name(ncm);
	if(search_results.empty()==true)
		search_results=database->search_category(ncm);
	if(search_results.empty()==true)
		search_results=database->search_manufacturer(ncm);
	if(search_results.size()==1)
	{
		database->scrap(search_results[0]);
		return true;
	}
	else if(search_results.size()>1)
	{
		for(int i=0;i<search_results.size();i++)
		{
			database->scrap(search_results[i]);
		}
		return true;
	}
	else 
	{   
		UI ui;
		ui.printoutput("Enter barcode");
		double x=ui.in_double();
		bool result=delete_item(x);
		return result;
}
}
bool product_manager::delete_item(double barcode)
{
	Product* ans=database->search_barcode(barcode);
	if(ans!=NULL)
	{
		database->scrap(ans);
		return true;
	}
	else
		return false;
}
/*
	void sale(string ncm);
	void sale(double barcode);
	void restock(string ncm);
	void restock(double barcode);
	void reset_sales(string ncm);
	void reset_sales(double barcode);

	*/
bool product_manager::sale(string ncm)
{
	double x;
	vector<Product*> search_result=database->search_name(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=database->search_category(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=database->search_manufacturer(ncm);
	if(search_result.size()==1)
	{
		if (search_result[0]->getno_in_stock()<=0)
			return false;
		search_result[0]->saleof_stock(1);
		search_result[0]->sell(1);
		return true;
	}
	else if(search_result.size()>=1)
	{
		bool re=false;
		for(int i=0;i<search_result.size();i++)
		{
			if (search_result[i]->getno_in_stock()>0)
			{
				re=true;
				search_result[i]->saleof_stock(1);
				search_result[i]->sell(1);
			}
		}
		return re;
	}
	else
	{
		UI ui;
		ui.printoutput("Enter barcode");
		x=ui.in_double();
		if (sale(x))
			return true;
		return false;
	}
}
	


bool product_manager::sale(double barcode)
{
	Product* ans=database->search_barcode(barcode);
	if (ans->getno_in_stock()<=0)
		return false;
	if(ans!=NULL)
	{
		ans->saleof_stock(1);
		ans->sell(1);
		return true;
	}
	return false;
}

bool product_manager::restock(string ncm,int number)
{
	double x;
	vector<Product*> search_result=database->search_name(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=database->search_category(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=database->search_manufacturer(ncm);
	if(search_result.size()==1)
	{
		search_result[0]->restock(number);
		return true;
	}
	else if(search_result.size()>=1)
	{
		for(int i=0;i<search_result.size();i++)
		{
			search_result[i]->restock(number);
		}
		return true;
	}
	else
	{
		UI ui;
		ui.printoutput("Enter barcode");
		x=ui.in_double();
		if (restock(x,number))
			return true;
		return false;
	}
}

bool product_manager::restock(double barcode,int number)
{
	
	Product* ans=database->search_barcode(barcode);
	if(ans!=NULL)
	{
		ans->restock(number);
		return true;
	}
	return false;
}
bool product_manager::reset_sales(string ncm)
{
	double x;
	vector<Product*> search_result=database->search_name(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=database->search_category(ncm);
	if(search_result.size()==0)
		vector<Product*> search_result=database->search_manufacturer(ncm);
	if(search_result.size()==1)
	{
		search_result[0]->reset();
		return true;
	}
	else if(search_result.size()>=1)
	{
		for(int i=0;i<search_result.size();i++)
		{
			search_result[i]->reset();
		}
		return true;
	}
	else
	{
		UI ui;
		ui.printoutput("Enter barcode");
		x=ui.in_double();
		if (reset_sales(x))
			return true;
		return false;
	}
}
bool product_manager::reset_sales(double barcode)
{
	
	Product* ans=database->search_barcode(barcode);
	if(ans!=NULL)
	{
		ans->reset();
		return true;
	}
	return false;
}
/*//file operations
	void list_initialize();
	void file_update();*/

void product_manager::list_initialize()
{
	ifstream readFile("batchdata.txt");
	int x=0,i=0;//x contains the number of products to be inputted
	readFile>>x;
	char type;
	while(i<x)
	{
		readFile>>type;
		if(type=='y')
		{
			string name,manufacturer,category;
			int barcode;double price,disc_percent;
			int no_in_stock,no_sold,date;
			getline(readFile,name),getline(readFile,name);//>>name>>category>>barcode>>price>>manufacturer>>no_in_stock>>no_sold;
			getline(readFile,category);
			readFile>>barcode;
			readFile>>price;
			getline(readFile,manufacturer);getline(readFile,manufacturer);
			readFile>>no_in_stock;
			readFile>>no_sold;
			readFile>>date;
			readFile>>disc_percent;
			//string name1,double barcode1,double price1,string manufacturer1,int no_in_stock1,int no_sold1,string category1,int day1,int month1,int year1
			Product* newprod=new Perishable(name,barcode,price,manufacturer,no_in_stock,no_sold,category,date/1000000,(date/10000)%100,date%10000,disc_percent);
			add_item(newprod);

		}
		else
		{
			string name,manufacturer,category;
			int barcode;double price,disc_percent;
			int no_in_stock,no_sold,date;
			getline(readFile,name);getline(readFile,name);//>>name>>category>>barcode>>price>>manufacturer>>no_in_stock>>no_sold;
			getline(readFile,category);
			readFile>>barcode;
			readFile>>price;
			getline(readFile,manufacturer);getline(readFile,manufacturer);
			readFile>>no_in_stock;
			readFile>>no_sold;
			//string name1,double barcode1,double price1,string manufacturer1,int no_in_stock1,int no_sold1,string category1,int day1,int month1,int year1
			Product* newprod=new Product(name,barcode,price,manufacturer,no_in_stock,no_sold,category);
			add_item(newprod);
		}
	i++;
	}
readFile.close();
}

			
void product_manager::file_update()
{
	ofstream writeFile("data.txt");
	int a=0;
	Product* retrieveprod;
	writeFile<<database->getsize()<<endl;
	while(a<(database->getsize()))
	{
		retrieveprod=database->retrieve(a);
		char test=retrieveprod->ifperishable();
		if(test==('y'))
		{
			writeFile<<"y"<<endl<<retrieveprod->getname()<<endl<<retrieveprod->get_category()<<endl<<retrieveprod->getbarcode()<<endl<<retrieveprod->getprice()<<endl<<retrieveprod->getmanufacturer()<<endl<<retrieveprod->getno_in_stock()<<endl<<retrieveprod->getno_sold()<<endl<<retrieveprod->returnexpiry()<<endl<<retrieveprod->getdisc_percent()<<endl;

		}
		else
		{
			writeFile<<"n"<<endl<<retrieveprod->getname()<<endl<<retrieveprod->get_category()<<endl<<retrieveprod->getbarcode()<<endl<<retrieveprod->getprice()<<endl<<retrieveprod->getmanufacturer()<<endl<<retrieveprod->getno_in_stock()<<endl<<retrieveprod->getno_sold()<<endl;			
		}
		a++;
	}
}

			

	int	product_manager::findNextMax(Base* database, int max)
	{
		int nextmax=0;
		for (int i=0;i<database->getsize();i++)
		{
			Product* cur=database->retrieve(i);
			if (cur->getno_sold()>nextmax && cur->getno_sold()<max)
				nextmax=cur->getno_sold();
		}
		return nextmax;
	}
	void product_manager::topselling(int number)
	{
		int count=0, max=32767;
		UI ui;
		while (count<number)
		{
			max=findNextMax(database,max);
			for (int i=0;i<database->getsize();i++)
			{
				Product* cur=database->retrieve(i);
				if (cur->getno_sold()==max)
				{
					ui.printoutput(cur->getname());
					count++;
				}
			}
		}
	}
	double product_manager::highestselling()
	{
		double max=0;
		for (int i=0;i<database->getsize();i++)
		{
			double total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if (total>max)
				max=total;
		}
		return max;
	}
    void product_manager::bestselling()
	{
		UI ui;
		for (int i=0;i<database->getsize();i++)
		{
			double total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if (total==highestselling())
				ui.printoutput(database->retrieve(i)->getname());
		}
	}
	product_manager::~product_manager()
	{
		delete database;
	}
/*
  void bestmanufacturer(Base*); //print the manufacturer(s) whose products are highest-selling.
       int highest_incategory(Base*, string); //get the highest selling among products in a particular category
       void best_incategory(Base*, string); //print the product(s) with highest selling in a particular category
};
*/

	void product_manager::bestmanufacturer()
	{
		UI ui;
		double max=highestselling();
		for(int i=0;i<database->getsize();i++)
		{
			double total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if(max==total)
			ui.printoutput((database->retrieve(i))->getmanufacturer());
		}
	}
	double product_manager::highest_incategory(string x)
	{
		
		double max=0,total=0;
		
		for (int i=0;i<database->getsize();i++)
		{
			if(database->retrieve(i)->get_category()==x)
			total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if (total>max && database->retrieve(i)->get_category()==x)
				max=total;
		}
		return max;
	}
	void product_manager::best_incategory(string x)
	{
		UI ui;
		double highest=highest_incategory(x);
		double total=0;
		for(int i=0;i<database->getsize();i++)
		{
			if(database->retrieve(i)->get_category()==x)
			total=database->retrieve(i)->getno_sold()*database->retrieve(i)->getprice();
			if(database->retrieve(i)->get_category()==x && highest==total)
				ui.printoutput(database->retrieve(i)->getname());
		}
	}


	void product_manager::list_items()
	{
		int i;
		for(i=0;i<database->getsize();i++)
		{
			if(database->retrieve(i)->returnexpiry()==" ")
			{
				cout<<"Item name:"<<database->retrieve(i)->getname()<<endl;
				cout<<"Item price:"<<database->retrieve(i)->getprice()<<endl;
				cout<<"Item barcode:"<<database->retrieve(i)->getbarcode()<<endl;
				cout<<"Item category:"<<database->retrieve(i)->get_category()<<endl;
				cout<<"No. in stock:"<<database->retrieve(i)->getno_in_stock()<<endl;
				cout<<"No. sold this month:"<<database->retrieve(i)->getno_sold()<<endl;
				cout<<"*************************"<<endl;
			}
			else
			{
				cout<<"Item name:"<<database->retrieve(i)->getname()<<endl;
				cout<<"Item price:"<<database->retrieve(i)->getprice()<<endl;
				cout<<"Item barcode:"<<database->retrieve(i)->getbarcode()<<endl;
				cout<<"Item category:"<<database->retrieve(i)->get_category()<<endl;
				cout<<"No. in stock:"<<database->retrieve(i)->getno_in_stock()<<endl;
				cout<<"No. sold this month:"<<database->retrieve(i)->getno_sold()<<endl;
				cout<<"Expiry Date:"<<database->retrieve(i)->returnexpiry()<<endl;
				cout<<"discount percent:"<<database->retrieve(i)->getdisc_percent()<<endl;
				cout<<"*************************"<<endl;
			}
		}
	}
	void product_manager::checkexpired(string ncm)
	{
		double x;bool answer;
		vector<Product*> search_result=database->search_name(ncm);
		if(search_result.size()==0)
			vector<Product*> search_result=database->search_category(ncm);
		if(search_result.size()==0)
			vector<Product*> search_result=database->search_manufacturer(ncm);
		if(search_result.size()>=1)
		{
			if(search_result[0]->returnexpiry()!=" ")
			{
				answer=database->check_expired(search_result[0]);
				UI ui;
				if(answer)
				{
					ui.printoutput("Product has Expired");
				}
				else
					ui.printoutput("Product has not Expired");
			}
		}
		else
		{
			UI ui;
			ui.printoutput("Enter barcode");
			x=ui.in_double();
			checkexpired(x);
		}
	}

	void product_manager::checkexpired(double barcode)
	{
		Product* ans=database->search_barcode(barcode);
		UI ui;
		if (ans!=NULL)
		if(ans->returnexpiry()!=" ")
		{
			bool answer=database->check_expired(ans);
			if(answer)
			{
				ui.printoutput("Product has Expired");
			}
			else
				ui.printoutput("Product has not Expired");
		}
	}