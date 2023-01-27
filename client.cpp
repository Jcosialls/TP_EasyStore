#include <iostream>
#include <algorithm>
#include <vector>
#include "client.h"

Client::Client(std::string id, std::string firstname, std::string lastname)
	: _id(id), _firstname(firstname), _lastname(lastname) {
}

std::string Client::id()const {
	return _id;
}

std::string Client::firstname()const {
	return _firstname;
}

std::string Client::lastname()const {
	return _lastname;
}

std::vector<Product> Client::shopping_cart()const{
	return _shopping_cart;
}

void Client::add_to_shopping_cart(Product& product){
	_shopping_cart.push_back(product);
}

void Client::del_to_shopping_cart(Product& product){
	bool done = false;
	int i = 0;
	while((i<_shopping_cart.size()) && (done == false)){
		if(product.getref_product() == _shopping_cart.at(i).getref_product()){
			_shopping_cart.erase(_shopping_cart.begin()+ i);
			done = true;
		}
		i++;
	}
}

void Client::erase_shopping_cart(){
	_shopping_cart.clear();
}

void Client::modify_quantity(Product& product, int new_quantity){
	int current_quantity;
	current_quantity = std::count(_shopping_cart.begin(), _shopping_cart.end(), product);
	while(new_quantity != current_quantity){
		if(new_quantity < current_quantity){
			del_to_shopping_cart(product);
			current_quantity--;
		}
		else if(new_quantity > current_quantity){
			add_to_shopping_cart(product);
			current_quantity++;
		}
	}
}

//-------Helper Functions--------//
std::string display_ShoppingCart(Client client){
	std::string s;

	std::vector<Product> copy_cart = client.shopping_cart();
	auto it = copy_cart.begin();
	while( it!= copy_cart.end()){
		Product product = *it;

		s+= product.gettitle() + " x";
		//s+= std::to_string(std::count(copy_cart.begin(), copy_cart.end(), *it));
		auto erased = std::erase_if(copy_cart, [product](Product p) {return p==product;}); //need g++ v20
		s+= std::to_string(erased);
		s+= "\n";
	}
	return s;
}

std::string display_Client(Client client) {
	std::string c = client.firstname() + " " + client.lastname() + " , id : " + client.id();
	c+= "\nDans le panier : \n";
	c += display_ShoppingCart(client);
	return c;
}


//----------Overloading Ops----------//
bool operator == (const Client& c1, const Client& c2){
	if(c1.id() == c2.id()){
		return true;
	}
    return false;
}

std::ostream& operator<<(std::ostream& os, Client client) {
	std::string to_display = display_Client(client);
	os << to_display << std::endl;
	return os;
}

