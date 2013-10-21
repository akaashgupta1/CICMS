#ifndef DYNAMICARRAY_DATABASE_H
#define DYNAMICARRAY_DATABASE_H
#include "Base.h"

class dynamicArray:public Base{
private:
	int size;
	Product** arr;

	int getIndex(Product*); //get index of a particular product
public:
	dynamicArray(): size(0)
	{
		arr=new Product*[0];
	}
	~dynamicArray()
	{
		for (int i=0;i<size;i++)
			delete arr[i];
		delete [size] arr;
	}

	Product* retrieve(int);
	int getsize(){return size;}
	void add(Product*);
	void scrap(Product*);
	void reset_no_sold(Product*);
	void sale(Product*, int);
	void restock(Product*, int );
	bool check_expired(Product*);
	vector<Product*> search_name(string);
	vector<Product*> search_category(string);
	vector<Product*> search_manufacturer(string);
	Product* search_barcode(double);
};

#endif