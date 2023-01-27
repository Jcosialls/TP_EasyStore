#include <iostream>
#include <vector>
#include "magasin.h"


int main() {

	Client client0("JC_c00", "JuL", "COS");
	Client client1("JP_c01", "Jean", "PERRE");
	Client client2("JD_c02", "Jean", "DAVID");
	std::vector<Client> mesClients{client0, client1, client2, Client("JF_c03", "Jean", "FRANCOIS")};

	Product pain(0.95,200,"Un truc a manger","Pain","01-Pa");
	Product oeuf6(6.66,200,"Un autre truc a manger","oeufs*6","02-Oe");
	Product oeuf12(13.32,200,"Encore un autre truc a manger","oeufs*12","03-Oe");
	Product pates(2.99,200,"1kg de pattes pour les etudiants","pates","04-Da");
	std::vector<Product> mesBonsProduitsBio{pain,oeuf6, oeuf12, pates};

	//remplissage du panier de client
	client0.add_to_shopping_cart(pain);
	client0.add_to_shopping_cart(oeuf6);
	client0.add_to_shopping_cart(pain);
	client0.add_to_shopping_cart(pates);

	client2.add_to_shopping_cart(pain);
	client2.add_to_shopping_cart(pates);
	
	//création de commandes
	Order order0(client0, client0.shopping_cart(), Status::Undeliver);
	Order order2(client2, client2.shopping_cart(), Status::Undeliver);
	Order order3(client2, mesBonsProduitsBio, Status::Undeliver);

	std::vector<Order> mesCommandes{order0,order2, order3};
	//création du magasin
	Magasin carrouf(mesClients, mesBonsProduitsBio, mesCommandes);
	std::cout<<carrouf << std::endl;

	//initialisations des variables 
	std::string id_client, lastname, firstname;
	std::string title, description, ref;
	double price;
	int quantity;
	int num_order;
	int val;
	Product product;
	Client client;


	while(val!=-1){
	//menu principale
	std::cout<<"Entrer '1' pour gerer le magasin " << std::endl;
	std::cout<<"Entrer '2' pour gerer les clients " << std::endl;
	std::cout<<"Entrer '3' pour gerer les commandes " << std::endl;
	std::cin>>val;
	switch(val){
		case 1:
			std::cout<<"Entrer '1' pour afficher les produits du magasin " << std::endl;
			std::cout<<"Entrer '2' pour ajouter un produit " << std::endl;
			std::cout<<"Entrer '3' pour modifier la quantite d'un produit " << std::endl;
			std::cin>>val;
			switch(val){
				case 1:
					//afficher les produits :
					std::cout<< display_Products(carrouf) << std::endl;
					break;
				case 2:
					//ajouter un produit :
					std::cout<<"Entrer le nom du produit" << std::endl;
					std::cin>>title;
					std::cout<<"Entrer la description du produit" << std::endl;
					std::getline(std::cin >> std::ws, description); 	//pour ecrire plus qu'un paramètre
					std::cout<<"Entrer le prix du produit" << std::endl;
					std::cin>>price;
					std::cout<<"Entrer la quantite du produit" << std::endl;
					std::cin>>quantity;
					std::cout<<"Entrer la reference du produit" << std::endl;
					std::cin>>ref;
					carrouf.add_product(Product(price,quantity, description, title, ref));
					break;					
				case 3:
					//mise a joure du stock d'un produit :
					std::cout<<"Entrer le nom du produit" << std::endl;
					std::cin>>title;
					std::cout<<"Entrer la nouvelle quantite" << std::endl;
					std::cin>>quantity;
					product = carrouf.found_Product(title);
					carrouf.set_stock(product, quantity);
					break;
			}
			break;
		case 2:
			std::cout<<"Entrer '1' pour afficher les clients du magasin " << std::endl;
			std::cout<<"Entrer '2' pour ajouter un client " << std::endl;
			std::cout<<"Entrer '3' pour ajouter un produit au panier d' un client " << std::endl;
			std::cout<<"Entrer '4' pour supprimer un produit au panier d'un client " << std::endl;
			std::cout<<"Entrer '5' pour modifier la quantité d'un produit au panier d'un client " << std::endl;
			std::cin>>val;
			switch(val){
				case 1:
					//afficher les clients :
					std::cout<< display_Clients(carrouf) << std::endl;
					break;
				case 2:
					//ajouter un client :
					std::cout<<"Entrer le nom du client" << std::endl;
					std::cin>>lastname;
					std::cout<<"Entrer le prenom du client" << std::endl;
					std::cin>>firstname;
					std::cout<<"Entrer l'identifiant' du client" << std::endl;
					std::cin>>id_client;
					carrouf.add_client(Client(id_client, firstname, lastname));
					break;					
				case 3:
					//ajouter un produit au panier d'un client :
					std::cout<<"quel produit voulez vous selectionner ? : ";
					std::cin>>title;
					std::cout<<"Entrer l'identifient du client : ";
					std::cin>>id_client;
					add_Prod_to_Client(carrouf, title, id_client);
					break;
				case 4 :
					//supprimer un produit au panier d'un client :
					std::cout<<"quel produit voulez vous selectionner ? : ";
					std::cin>>title;
					std::cout<<"Entrer l'identifiant du client : ";
					std::cin>>id_client;
					del_Prod_to_Client(carrouf, title, id_client);
					break;
				case 5:
					//modifier la quantité d'un produit au panier d'un client :
					std::cout<<"quel produit voulez vous selectionner ? : ";
					std::cin>>title;
					std::cout<<"Entrer l'identifient du client : ";
					std::cin>>id_client;
					std::cout<<"Entrer la nouvelle quantite voulue : ";
					std::cin>>quantity;
					modify_QuantityProd_to_Client(carrouf, quantity, title, id_client);
					break;										
			}
			break;
		case 3:
			std::cout<<"Entrer '1' pour afficher les commandes du magasin" << std::endl;
			std::cout<<"Entrer '2' pour ajouter une commande " << std::endl;
			std::cout<<"Entrer '3' pour valider une commande " << std::endl;
			std::cout<<"Entrer '4' pour mettre a jour le statut d'une commande" << std::endl;
			std::cout<<"Entrer '5' pour afficher les commandes d'un client " << std::endl;
			std::cin>>val;
			switch(val){
				case 1:
					//afficher les commandes :
					std::cout<< display_Clients(carrouf) << std::endl;
					break;
				case 2:
					//ajouter une commande :
					std::cout<<"Entrer l'identifiant du client" << std::endl;
					std::cin>>id_client;
					client = carrouf.found_Client(id_client);
					carrouf.add_order(Order(client.id(), client.shopping_cart(), Status::Undeliver));
					break;					
				case 3:
					//valider une commande :
					std::cout<<"Entrer le numero de la commande a valider : ";
    				std::cin>>num_order;
    				check_order(carrouf, num_order);
					break;
				case 4 :
					//mise a jour du statut d'une commande :
					std::cout<<"Entrer le numero de la commande a modifier : ";
					std::cin>>num_order;
					std::cout<<"Entrer '1' pour 'commande livree' " << std::endl;
					std::cout<<"Entrer '2' pour 'commande en cours de livraison' "<< std::endl;
					std::cout<<"Entrer '3' pour 'commande non livree' "<< std::endl;
					std::cin>>val;
					change_status_order(carrouf, num_order, val);
					break;
				case 5:
					//afficher les commandes d'un client :
					std::cout<<"Entrer l'identifient du client : ";
 					std::cin>>id_client;
					std::cout<< orders_of_client(carrouf, id_client)<<std::endl;
					break;										
			}
			break;
		default:
			break;
	}
	
	std::cout<<carrouf;
	std::cout<<carrouf.clients().at(2);
	std::cout<<client2;
	}


	//pour trouver un produit dans le magasin :

  
   //pour trouver un client dans magasin : 									// problème d'affichage de son paniet
 
 
   //pour ajouter un produit dans le panier d'un client : 				// problème d'affichage de son paniet
    
   
   //pour supprimer un produit dans le panier d'un client : 
    

   //pour modifier la quantité d'un produit dans le panier d'un client : 
    
	
   //pour valider une commande : 												//problème d'indexe
    

   //modifier le statut d'une commande : 										//marche pas
	
	
	//afficher les commandes d'un client :
	

	
	return 0;
}