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
	Product(double price_unit = 0, int quantity = 0,
			std::string description = "defaultdescription", std::string title = "defaultdescription",
			std::string ref_product = "defaultdescription");
	int getquantity()const;
	double getprice_unit()const;
	std::string getdescription()const;
	std::string gettitle()const;
	std::string getref_product()const;
	void setquantity(int quantity);
	void setprice_unit(double price_unit);
};

//-------Helper Functions--------//
std::string display_Product(Product product);

//-------Overloading Ops--------//
bool operator == (const Product& product1, const Product& product2);
std::ostream& operator<<(std::ostream& os, Product product);