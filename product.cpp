#include <iostream>
#include <sstream>
#include <iomanip>
#include "product.h"


Product::Product(double price_unit, int quantity,
				 std::string description, std::string title, std::string ref_product) :
		         _price_unit(price_unit), _quantity(quantity), _description(description),
		         _title(title), _ref_product(ref_product){

}

int Product::getquantity() {
	return _quantity;
}

double Product::getprice_unit() {
	return _price_unit;
}

std::string Product::getdescription() {
	return _description;
}

std::string Product::gettitle() {
	return _title;
}

std::string Product::getref_product() {
	return _ref_product;
}

//Vérifie si la quantité est correcte
//et si il reste des produits en stock
//et modifie la quantité de produits disponibles
void Product::setquantity(int quantity) {
	if (quantity < 0) {
	std::cout << "Nombre de produits invalide" << std::endl;
	}
	else if (quantity == 0) {
	std::cout << "Produit en rupture de stock" << std::endl;	
	}
	else {
	_quantity = quantity;
	}
}


//Vérifie si le prix unitaire est correct
void Product::setprice_unit(double price_unit) {
	if (price_unit < 0) {
	std::cout << "Prix invalide" << std::endl;
	}
	else {
	_price_unit = price_unit;
	}

}


//-------Helper Functions--------//
std::string display_Product(Product product) {
	std::ostringstream out;
	out<<std::fixed;
	out<<std::setprecision(2);
	std::string p = "Titre : " + product.gettitle() + " ; Description : " + product.getdescription();
	out<<product.getprice_unit();
	p += " ; Prix : " + out.str();
	p += " ; Quantite : " + std::to_string(product.getquantity());
	p += " ; Ref produit : " + product.getref_product() + "\n";
	return p;
}

//-------Overloading Ops--------//
bool operator == (Product& product1, Product& product2)  { // check for equality
    if(product1.getref_product() == product2.getref_product()) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, Product product) {
	std::string to_display = display_Product(product);
	os << to_display << std::endl;
	return os;
}


