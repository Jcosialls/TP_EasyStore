#pragma once
#include <iostream>

class Product {
private:
	int _quantity;
	double _priceunit;
	std::string _description;
	std::string _title;
	std::string _referenceproduct;

	public:
	Product(double priceunit, int quantity,
	std::string description, std::string title, std::string referenceproduct);
	int getquantity();
	double getpriceunit();
	std::string getdescription();
	std::string gettitle();
	std::string getreferenceproduct();
	void setquantity(int quantity);
};

std::string display_Product(Product product);

std::ostream& operator<<(std::ostream& os, Product product);