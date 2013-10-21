#include <iostream>
#include <Windows.h>
#include "Product.h"
#include <conio.h>
#include <stdlib.h>
#include "UI.h"
#include "product_manager.h"
#include "Perishable.h"
#include "Splash.cpp"
#include <ShlObj.h>
#include<Shlwapi.h>
#include<ObjBase.h>
#include<ShellAPI.h>

using namespace std;
int main()
{
	int choice;
	product_manager PM;
	UI uin;
	splash x;
	int y=x.homescreen();
	if(y==0)
		return 0;
	



	PM.list_initialize();
	do
	{   
		uin.header_text();
		uin.print_menu();
		uin.print_menu_footer();
		cin>>choice;
		switch(choice)
		{
		
		case 11:
			{	
			}
		case 12:
			{
				
				system( "\"D:\\\\Rohit_Browser.exe\"");
			
		
			}
		
		
		
		case 10: 
			{
				PM.file_update();
				return 0;
			}
		case 1:
			{   uin.confirm_perishable();
				char c=uin.in_char();

				Product* newproduct=NULL;
				switch(c)
				{
				case 'y':
				case 'Y':
					{
					    string name2,manufacturer,category;
						double price,barcode;
						int no_in_stock,no_sold;
						uin.get_product_details();
						name2=uin.in_string();
						category=uin.in_string();
						barcode=uin.in_double();
						manufacturer=uin.in_string();
						price=uin.in_double();
						no_sold=uin.in_int();
						no_in_stock=uin.in_int();
						uin.get_perishable_details();
						int date;double discountpercent;
						discountpercent=uin.in_double();
						date=uin.in_int();
						newproduct=new Perishable(name2,barcode,price,manufacturer,no_in_stock,no_sold,category,(date/1000000),((date/10000)%100),date%10000,discountpercent);
						break;
					}
				case 'n':
				case 'N':
					{
						string name2,manufacturer,category;
						double price,barcode;
						int no_in_stock,no_sold;
						uin.get_product_details();
						name2=uin.in_string();
						category=uin.in_string();
						barcode=uin.in_double();
						manufacturer=uin.in_string();
						price=uin.in_double();
						no_sold=uin.in_int();
						no_in_stock=uin.in_int();
						newproduct=new Product(name2,barcode,price,manufacturer,no_in_stock,no_sold,category);
						break;
					}
				default:
					{
						uin.print_error();
						return 0;
					}
				}
				PM.add_item(newproduct);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				uin.printoutput("Product Added");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				break;
			}
		case 2:
			{
				int index;
				string product_name;
				uin.get_name_string();
				product_name=uin.in_string();
				bool result=PM.delete_item(product_name);
				if(result)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					uin.printoutput("Product Deleted");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else
				{
					uin.print_error();
				}
				break;
			}
		case 3:
			{
				string product_name;
				uin.get_name_string();
				product_name=uin.in_string();
				if (!PM.reset_sales(product_name))
					uin.print_error();
				break;
			}

		case 4:
			{
					string product_name;
					uin.get_name_string();
					product_name=uin.in_string();
					if (!PM.sale(product_name))
						uin.print_error();
					break;
			}		
		case 5:	
			{	string product_name;
					uin.get_name_string();
					product_name=uin.in_string();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					uin.printoutput("Enter the number by which to restock");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					int x=uin.in_int();
					if (x<0)
						uin.print_error();
					else
					if (!PM.restock(product_name,x))
						uin.print_error();
					break;
			}
		case 6:
			{
					int choice2;
					uin.print_stats_menu();
					choice2=uin.in_int();
					string choice3;
					int number;
					switch(choice2)
					{
					case(1):
						{
							uin.printoutput("Enter Number of Products to Display -");
							number=uin.in_int();
							PM.topselling(number);
							break;
						}
					case(2):
						{
							uin.printoutput("Enter Category -");
							choice3=uin.in_string();
							PM.best_incategory(choice3);
							break;
						}
					case(3):
						{
							uin.printoutput("Best Selling Manufacturer -");
							PM.bestmanufacturer();
							break;
						}
					default:
						uin.print_error();
					}
					break;
			}
		case 7:
			{
				PM.list_items();
				break;
			}
		case 8:
			{
				PM.list_initialize();
				break;
			}
		case 9:
			{
				string product_name;
				uin.get_name_string();
				product_name=uin.in_string();
				PM.checkexpired(product_name);
				break;
			}
		default:
			{ 
				uin.print_error();
			}
		}
	 uin.getcontinue();
	 getch();
     system("cls");
	}while(true);
	return 0;
}
