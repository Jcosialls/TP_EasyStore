#include <iostream>
#include <vector>
#include "magasin.h"


int main() {

	std::vector<Product> shopping_cart;
	std::vector<Client> mesClients{Client("JC_c00", "JuL", "COS", shopping_cart),
								   Client("JP_c01", "Jean", "PERRE", shopping_cart)};
	std::vector<Product> mesBonsProduitsBio{Product(0.95,200,"Un truc a manger","Pain","01-Pa"),
											Product(6.66,200,"Un truc a manger","Pack 6 oeufs","02-Oe"),
											Product(13.32,200,"Un truc a manger","Pack 12 oeufs","03-Oe"),
											Product(2.99,200,"1kg de pattes pour les etudiants","pates","04-Da")};
	std::vector<Order> mesCommandes;

	Magasin carrouf(mesClients, mesBonsProduitsBio, mesCommandes);

	std::cout<<mesClients.at(0)<< mesClients.at(1);

	mesClients.at(0).add_to_shopping_cart(mesBonsProduitsBio.at(0));
	mesClients.at(0).add_to_shopping_cart(mesBonsProduitsBio.at(2));
	mesClients.at(0).add_to_shopping_cart(mesBonsProduitsBio.at(0));
	mesClients.at(0).add_to_shopping_cart(mesBonsProduitsBio.at(3));

	std::cout<< mesClients.at(0);
	//found_Product(carrouf);
	Client client("JD_c02", "Jean", "DAVID", shopping_cart);
	carrouf.add_client(client);

	std::cout<<carrouf;
	//found_Client(carrouf);

	return 0;
}