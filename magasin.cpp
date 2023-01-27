#include <iostream>
#include <vector>
#include "magasin.h"

Magasin::Magasin(std::vector<Client> clients, std::vector<Product> products,
                 std::vector<Order> orders) : _clients(clients),
                                              _products(products),
                                              _orders(orders) {
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

void Magasin::add_order(const Order& new_order){
    _orders.push_back(new_order);
}

void Magasin::set_stock(const Product& product, int quantity){
    for(int i = 0 ; i < _products.size(); i++){
        if( _products.at(i) == product){
            _products.at(i).setquantity(quantity);
        }
    }
}


Product Magasin::found_Product(std::string title){
    Product product;
    for(int i = 0; i < _products.size(); i++){
        if(title == _products.at(i).gettitle()){
            return _products.at(i);
        }
    }
    return product;
}

Client Magasin::found_Client(std::string id_client ){
    Client client;  
    for(int i = 0; i < _clients.size(); i++){
        if(id_client == _clients.at(i).id()){
            Client client = _clients.at(i);
            return client;
        }
    }
    return client;
}

//-------Helper Functions--------//



void add_Prod_to_Client(Magasin& mag, std::string title, std::string id_client){
    Product product;
    Client client;
    product = mag.found_Product(title);
    client = mag.found_Client(id_client);
    for(int i = 0; i < mag.clients().size(); i++){
        if(client == mag.clients().at(i)){
            mag.clients().at(i).add_to_shopping_cart(product);    
        }
    }
}

void del_Prod_to_Client(Magasin& mag, std::string title, std::string id_client){
    Product product;
    Client client;
    for(int i = 0; i < mag.clients().size(); i++){
        if(client == mag.clients().at(i)){
            mag.clients().at(i).del_to_shopping_cart(product);    
        }
    }
}
void modify_QuantityProd_to_Client(Magasin& mag, int quantity,
                                   std::string title, std::string id_client ){
    Product product;
    Client client;
    product = mag.found_Product(title);
    client = mag.found_Client(id_client);
    for(int i = 0; i < mag.clients().size(); i++){
        if(client == mag.clients().at(i)){
            mag.clients().at(i).modify_quantity(product,quantity);    
        }
    }
}

void check_order(Magasin& mag, int num_order){
    if(num_order < mag.orders().size()){
        auto it = mag.orders().begin() + num_order;
        //mag.orders().erase(mag.orders().begin() + num_order);
        mag.orders().erase(it);
    }
}

void change_status_order(Magasin& mag,  int num_order, int val){
    Status status;
    switch(val){
        case 1: 
            status = Status::Deliver;
            break;
        case 2: 
            status = Status::Undeliver;
            break;
        case 3: 
            status = Status::Ongoing;
            break;
    }   
    for(int i = 0 ; i < mag.orders().size(); i++){
        if(num_order == i){
            mag.orders().at(i).modify_status(status);
        }
    }
}

std::string orders_of_client(Magasin& mag, std::string id_client){
    Client client;
    std::vector<Order> orders_of_client;
    std::string s;
    client = mag.found_Client(id_client);
    for(int i = 0; i < mag.orders().size(); i++){
        if(mag.orders().at(i).client() == client){
            orders_of_client.push_back(mag.orders().at(i));
        }
    }

    s = "\n commandes trouvees : \n";
    for(auto it = orders_of_client.begin(); it != orders_of_client.end(); it++){
        s += display_Order(*it);
    }
    return s;
}

std::string display_Products(const Magasin& mag){
    std::string s = "[.]Nos produits : \n";
    Product produit1 = mag.products().at(0);
    for(int i = 0; i < mag.products().size(); i++){
        s += display_Product(mag.products().at(i));
    }
    s += "\n";
    return s;
}


std::string display_Clients(const Magasin& mag){
    std::string s = "[.]Clients du magasin : \n";
    for(int i = 0 ; i< mag.clients().size(); i++){
        // s += "\n";
        // s += "id : " + mag.clients().at(i).id() + " " ;
        // s += "Prenom : " + mag.clients().at(i).firstname() + " " ;
        // s += "Nom : " + mag.clients().at(i).lastname() + " ";
        s += display_Client(mag.clients().at(i));
        s+= "\n";
    }
    s += "\n\n";
    return s;
}

std::string display_Orders(const Magasin& mag){
    std::string s;
    s = "[.]Les commandes en cours : \n";
    for(int i = 0; i < mag.orders().size(); i++){
        s +=std::to_string(i) + " : " +  display_Order(mag.orders().at(i));
    }
    return s;
}

//-------Overloading Ops--------//
std::ostream& operator<<(std::ostream& os, const Magasin& mag){
    std::string to_display = display_Products(mag) + display_Clients(mag) + display_Orders(mag); 
	os << to_display << std::endl;
	return os;
}