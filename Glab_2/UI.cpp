#include "UI.h"
#include <Windows.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 7
#define BLINK 128
	int UI::in_int()
	{
		int a;
		cin>>a;
		return a;
	}
	double UI::in_double()
	{
		double a;
		cin>>a;
		return a;
	}
	string UI::in_string()
	{
		getchar();
		string a;
		getline(cin,a);
		return a;
	}
	char UI::in_char()
	{
		char a;
		cin>>a;
		return a;
	}
	long UI::in_long()
	{
		long a;
		cin>>a;
		return a;
	}
	void UI::print_menu_footer()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		cout<<"What would you like to do?[Please enter number]"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void UI::get_name_string()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<"Enter Product Name OR Category OR Manufacturer"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout<<"[Press Enter if You want to Sarch by Barcode]"<<endl;
	}
	void UI::get_product_details()
	{
		cout<<endl<<"Enter Product Details :"<<endl;
		cout<<"Enter Product Name, Category, Barcode, Manufacturer, Price, Number Sold, Number in Stock -"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<"[ Press enter after each input ]"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void UI::print_error()
	{
		cout<<"Incorrect input, Please try again"<<endl;
	}
	void UI::printoutput(string a)
    {
	cout<<a<<endl;
    }
	void UI::print_stats_menu()
	{   
		
		cout<<endl<<"Display top selling by:"<<endl;
		cout<<"1."<<"Number(To be entered by you)"<<endl;
		cout<<"2."<<"Category"<<endl;
		cout<<"3."<<"Manufacturer"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout<<"Enter your Choice : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void UI::header_text()
	{   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);                                                                                   
   cout<<" .                                     ....  .       .....    ......"<<endl;         
   cout<<". .                     ..   ......    ..........  . ......   ,,,...."<<endl;         
   cout<<" .OOOOOOOOOOOOOOOOO$Z8OOOO...OOOO.... .,O,..OOO..  ..:OO:..DOOO$78OO,.."<<endl;       
   cout<<" .OOO.8O,.O8$7OO8I7OO:88OO...OO8OO... .,8,..8OO.     :OO:.IOO........."<<endl  ;      
    cout<<".OOO,,:.,.:.7OO$:?,+?~8OO...OO,OOO. ..,8,..8OO.     :OO,.?OO8...  . "<<endl   ;      
    cout<<".OOO,=,=,I,?7OO:O7I,OO~OO...OO.:OOO+,.,O,..8OO.     :OO,..8OOOOO~,...."<<endl;      
    cout<<".OO8777I777I$OO+$8,I8:ZOO...OO..,OOO?,,O,..8OO.     :OO,....OOOOO88..."<<endl;      
    cout<<".8OO888OOOOOO88OO88O88OO8...OO....OOO$,O,. 8OO.   ..:OO,..   ...8OOO.."<<endl;      
    cout<<" O.....:I.I:,...........8...OO.....OOO8O,..$OO..  ..OO8...    ...OOO..."<<endl;     
     cout<<"O.I$.D777I7O.I~,,8O+.,.8...OO..  .,8OOO,...OOO=...ZOOO..OO.....OO8O.."<<endl;      
    cout<<" O.~7.Z8777OO..I7IIO..=.8...OO..   ,.$OO,....,8O8OOO8.....8OOO8OOZ.,."<<endl;       
    cout<<" $..,7ZO8$8O8$777777IO,.8.. .     ... ...   ........ ..  .........."<<endl;         
    cout<<" ....877OOOZ7777$777....$.......................,.,.................."<<endl;       
    cout<<"..8...~..OI7$OIZ7O77...:....8~O~I,$..ZO.?$I?...D.8I?,8O..+=8==..Z=.?."<<endl;       
    cout<<" ..:.....O7?I...7?,77..O.  .8.OO$.O,.$O.,88?,..:??7.ZD.O.?=D.+..O.Z..."<<endl;      
     cout<<"..=.....7$...,7O..7I.O.   .........................................."<<endl;       
     cout<<" ..8.~I7I...OI$II77.8..   ....8..,.,..................           .."<<endl;        
      cout<<" ..8............,.8,..   .I.:8...Z$8..,..?88.:....O+=.."<<endl;                   
       cout<<" ...Z..... ....=7..     ...,....,....~O...O.,.,...,.."<<endl;                    
        cout<<"....,O.....,$?...      ............................"<<endl;                     
        cout<<" .. ...,8OZ,..                       .   ..         "<<endl;                    
         cout<<"  . ........                                       "<<endl;                    
                                                                  
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		for(int i=0;i<80;i++)
			cout<<"*";
			cout<<endl;
		for(int i=0;i<10;i++)
			cout<<" ";
			cout<<" CEG Hypermarket Inventory Control and Monitoring System"<<endl; 
		for(int i=0;i<80;i++)
			cout<<"*";
			cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	 }
	 void UI::print_menu()
	 {
		 cout<<endl<<endl<<"1."<<"Add new Product"<<endl;
		 cout<<"2."<<"Delete Product"<<endl;
		 cout<<"3."<<"Reset Product Sales"<<endl;
		 cout<<"4."<<"Sell Product"<<endl;
		 cout<<"5."<<"Restock Product"<<endl;
		 cout<<"6."<<"Generate Statistics"<<endl;
		 cout<<"7."<<"List all Products"<<endl;
		 cout<<"8."<<"Load Data"<<endl;
		 cout<<"9."<<"Check if a Product has Expired"<<endl;
		 cout<<"10."<<"Quit"<<endl;
		 cout<<"11."<<"Create a word document"<<endl;
		 cout<<"12."<<"Launch default browser"<<endl<<endl<<endl;
		 
	 }
	 void UI::confirm_perishable()
	 {
		 cout<<"Is the Product Perishable ? " <<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		 cout<<"[ Enter Y for yes and N for no ]"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	 }
	 void UI::get_perishable_details()
	 {
		 cout<<"Also enter discount percentage and date of expiry ( in the format ddmmyyyy )"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		 cout<<"[ Press enter after each input ]"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	 }
	 void UI::getcontinue()
	 {
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		 cout<<"Press Any Key to Return to Main Screen"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	 }