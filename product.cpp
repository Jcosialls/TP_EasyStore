#include <iostream>
#include "produit.h"


Product::Product(double priceunit, int quantity,
				 std::string description, std::string title, std::string referenceproduct) :
		         _priceunit(priceunit), _quantity(quantity), _description(description),
		         _title(title), _referenceproduct(referenceproduct){

}

int Product::getquantity() {
	return _quantity;
}

double Product::getpriceunit() {
	return _priceunit;
}

std::string Product::getdescription() {
	return _description;
}

std::string Product::gettitle() {
	return _title;
}

std::string Product::getreferenceproduct() {
	return _referenceproduct;
}

void Product::setquantity(int quantity) {
	if (quantity <= 0) {
	std::cout << "Nombre de produits invalide" << std::endl;
	}
	else {
	_quantity = quantity;
	}
}



//-------Fontions Helpers--------//

//petit soucis : le compilateur me dit qu'il faut mettre par exemple
//_getpriceunit alors que c'est getpriceunit  ;(

std::string display_Product(Product product) {
	std::string p = product.title() + " " + product.description() + product.priceunit() + product.getquantity() + product.getreferenceproduct() ;
	return p;
}

std::ostream& operator<<(std::ostream& os, Product product) {
	std::string to_display = display_Product(product);
	os << to_display << std::endl;
	return os;
}
