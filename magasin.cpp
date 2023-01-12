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

void Magasin::add_product(const Product& new_product){
    _products.push_back(new_product);
}

void Magasin::add_client(const Client& new_client){
    _clients.push_back(new_client);
}


//-------Helper Functions--------//
std::string display_Products(const Magasin& mag){
    std::string s = "nos produits : \n";
    Product produit1 = mag.products().at(0);
    for(auto i = 0; i < mag.products().size(); i++){
        s += display_Product(mag.products().at(i));
    }
    s += "\n";
    return s;
}


std::string display_Clients(const Magasin& mag){
    std::string s = "Clients du magasin : ";
    for(auto i = 0 ; i< mag.clients().size(); i++){
        s += "\n";
        s += "id : " + mag.clients().at(i).id() + " " ;
        s += mag.clients().at(i).firstname() + " " ;
        s += mag.clients().at(i).lastname() + " ";

        //s += display_Client(mag.clients().at(i));
    }
    s += "\n";
    return s;
}


std::string found_Product(const Magasin& mag){
    std::string title;
    std::string ref;
    bool found = false;
    std::cout<<"quel produit voulez vous selectionner ? : ";
    std::cin>>title;
    
    for(auto i = 0; i < mag.products().size(); i++){
        if(title == mag.products().at(i).gettitle()){
            std::cout<< display_Product(mag.products().at(i));
             ref = mag.products().at(i).getref_product();
                found = true;
            }
            if(found == true){
                return ref;
            }
    }
    while(found == false){
        std::cout<< "L'objet n'existe pas" << std::endl;
        std::cout<<"quel produit voulez vous selectionner ? : ";
        std::cin>>title;
        
        for(auto i = 0; i < mag.products().size(); i++){
            if(title == mag.products().at(i).gettitle()){
                std::cout<< display_Product(mag.products().at(i));
                ref = mag.products().at(i).getref_product();
                found = true;
            }
            if(found == true){
                return ref;
            }
        }
    }
}

std::string found_Client(const Magasin& mag){
    std::string name;
    std::string id;
    bool found = false;
    std::cout<<"Entrer le nom du client : ";
    std::cin>>name;
    
    for(auto i = 0; i < mag.clients().size(); i++){
        if(name == mag.clients().at(i).lastname()){
            std::cout<< display_Client(mag.clients().at(i));
            id = mag.clients().at(i).id();
                found = true;
            }
            if(found == true){
                return ref;
            }
    }
    while(found == false){
        std::cout<< "le client n'existe pas" << std::endl;
        std::cout<<"Entrer le nom du client : ";
        std::cin>>name;
        
        for(auto i = 0; i < mag.clients().size(); i++){
            if(name == mag.clients().at(i).lastname()){
                std::cout<< display_Client(mag.clients().at(i));
                id = mag.clients().at(i).id();
                found = true;
            }
            if(found == true){
                return ref;
            }
        }
    }

}

void add_Prod_to_Client(const Magasin& mag){
    std::string ref_product;
    std::string id_client;
    ref_product = found_Product(mag);
    id_client = found_Client(mag);
    for(auto i = 0; i<mag.clients().size(); i++){
        if(id)
    }
}

//-------Overloading Ops--------//
std::ostream& operator<<(std::ostream& os, const Magasin& mag){
    std::string to_display = display_Products(mag) + display_Clients(mag); 
	os << to_display << std::endl;
	return os;
}