#ifndef BASE_H
#define BASE_H
#include "Product.h"
#include "Perishable.h"
#include <vector>

class Base  //store the products
{
public:
	virtual Product* retrieve(int)=0;
	virtual int getsize()=0;
	virtual void add(Product*)=0;
	virtual void scrap(Product*)=0;
	virtual void reset_no_sold(Product*)=0;
	virtual void sale(Product*, int)=0;
	virtual void restock(Product*, int )=0;
	virtual bool check_expired(Product*)=0;
	virtual vector<Product*> search_name(string)=0;
	virtual vector<Product*> search_category(string)=0;
	virtual vector<Product*> search_manufacturer(string)=0;
	virtual Product* search_barcode(double)=0;
};

#endif;