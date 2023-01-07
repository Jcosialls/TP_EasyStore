#include <iostream>
#include <vector>
#include "magasin.h"

Magasin::Magasin(std::vector<Client> clients, std::vector<Product> products, std::vector<Order> orders) :
                 _clients(clients), _products(products), _orders(orders) {

}

std::vector<Client> Magasin::clients()const{
    return _clients;
}

std::vector<Product> Magasin::products()const{
    return _products;
}
	
std::vector<Order> Magasin::orders()const{
    return _orders;
}

void Magasin::add_product(Product new_product){
    _products.push_back(new_product);
}


//-------Fonctions helpers-----------//
std::string display_Products(const Magasin& mag){
    std::string s = "nos produits : \n";
    Product produit1 = mag.products().at(0);
    for(auto i = 0; i < mag.products().size(); i++){
        s += display_Product(mag.products().at(i));
    }
    return s;
}

void found_Product(const Magasin& mag){
    std::string title;
    bool found = false;
	std::cout<<"quel produit voulez vous selectionner ? : ";
	std::cin>>title;
    
    for(auto i = 0; i < mag.products().size(); i++){
        if(title == mag.products().at(i).gettitle()){
            std::cout<< display_Product(mag.products().at(i));
            found = true;
        }
    }
    while(found == false){
    	std::cout<< "L'objet n'existe pas" << std::endl;
    	std::cout<<"quel produit voulez vous selectionner ? : ";
		std::cin>>title;
	    
	    for(auto i = 0; i < mag.products().size(); i++){
	        if(title == mag.products().at(i).gettitle()){
	            std::cout<< display_Product(mag.products().at(i));
	            found = true;
	        }
	    }
    }

}


//--------Surcharge d'opérateur------//
std::ostream& operator<<(std::ostream& os, const Magasin& mag){
    std::string to_display = display_Products(mag);
	os << to_display << std::endl;
	return os;
}