#pragma once
#include <iostream>

class Product {
private:
	int _quantity;
	double _price_unit;
	std::string _description;
	std::string _title;
	std::string _ref_product;

	public:
	Product(double price_unit, int quantity,
	std::string description, std::string title, std::string ref_product);
	int getquantity();
	double getprice_unit();
	std::string getdescription();
	std::string gettitle();
	std::string getref_product();
	void setquantity(int quantity);
	void setprice_unit(double price_unit);
};

//-------Helper Functions--------//
std::string display_Product(Product product);

//-------Overloading Ops--------//
bool operator == (Product& product1, Product& product2);
std::ostream& operator<<(std::ostream& os, Product product);