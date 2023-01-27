#include <iostream>
#include <vector>
#include "order.h"

Order::Order(Client client, std::vector<Product> products, Status status) : _client(client), _products(products), _status(status){
}

Client Order::client()const{
	return _client;
}
std::vector<Product> Order::products()const{
	return _products;
}
Status Order::status()const{
	return _status;
}

void Order::modify_status(Status status){
	switch(status){
		case Status::Deliver :
			_status = Status::Deliver;
			break;
		case Status::Undeliver :
			_status = Status::Undeliver;
			break;
		case Status::Ongoing :
			_status = Status::Ongoing;
			break;
	}
}

//-------Helper Functions--------//
std::string display_Order(Order order){
	std::string s;
	s = "id client : " + order.client().id();
	s += "\nEtat de la commande : ";
    switch(order.status()){
    	case Status::Deliver :
    		s += "livré";
    		break;
    	case Status::Undeliver :
    		s += "non livré";
    		break;
    	case Status::Ongoing :
    		s += "en cours de livraison";
    		break;
    	default :
    		break;
    }
	s += "\nproduit(s) selectionné(s) : ";
	for(int i = 0; i < order.products().size(); i++){
        s += display_Product(order.products().at(i));
    } 
    s += "\n";
    
    return s;
}

//-------Overloading Ops--------//

bool operator == (const Order& o1, const Order& o2)  { // check for equality
    if ((o1.client().id() == o2.client().id())&&(o1.products().size() == o2.products().size())) {
        for(int i =0; i < o1.products().size() ; i++){
        	if(o1.products().at(i) != o2.products().at(i)){
        		return false;
        	}
        }
    }
    return true;
}


std::ostream& operator<<(std::ostream& os, Order order){
std::string to_display = display_Order(order);
	os << to_display << std::endl;
	return os;
}