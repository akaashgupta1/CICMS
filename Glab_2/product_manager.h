
#ifndef PRODUCT_MANAGER
#define PRODUCT_MANAGER
#include "Base.h"

class product_manager{
	
private: 
	Base* database;
	int findNextMax(Base* data, int max); //find highest no of selling that is lower than max
	struct task{
		Product* item;
		string task_name;
	};
	
public:
	
product_manager();
~product_manager();
	
	
	//basic list operations
	void add_item(Product* );
	
	bool delete_item(string ncm);//this delete_item deletes item by matching input string against Product name,Manufacturer or Category.
	
	bool delete_item(double barcode);//overloaded function deleting using barcode

	bool sale(string ncm);
	bool sale(double barcode);
	bool restock(string ncm,int number);
	bool restock(double barcode,int number);
	bool reset_sales(string ncm);
	bool reset_sales(double barcode);
	void list_items();
	void checkexpired(string);
	void checkexpired(double);
	
	//file operations
	void list_initialize();
	void file_update();
	
	//batch processing 
	void assignment_engine(task );
	

	//the below functions are taken from original generate_statistics.h
	void topselling(int number); //if many products have the same no of sold, print all
	double highestselling(); //get highest selling
    void bestselling(); //print product(s) with highest selling
	void bestmanufacturer(); //print the manufacturer(s) whose products are highest-selling.
	double highest_incategory( string); //get the highest selling among products in a particular category
	void best_incategory(string); //print the product(s) with highest selling in a particular category
};
#endif

