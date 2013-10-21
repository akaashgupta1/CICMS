#ifndef VECTOR_VERSION_H
#define VECTOR_VERSION_H
#include "Base.h"

class vector_version:public Base{
private:
	vector<Product*> vtr;

	int getIndex(Product* pro);
public:
	~vector_version();

	Product* retrieve(int index) {return vtr[index];}
	int getsize() {return vtr.size();}
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

#endif;