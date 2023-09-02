#include <iostream>
#include <thread>
#include <chrono>

void debut();
void add();
void show();
void remove();
void choix();

int choose;
int history;
int SomeInAcount = 0;
int pocket = 100;
int SommeToAdd = 0;
int SommeToRemove = 0;
int ye = 0;

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

int main()
{
    debut();
    return 0;
}

void debut()
{
    std::cout << "                                   \n";
    std::cout << "***********Bazznque Walid************\n";
    std::cout << "Bienvenue dans la Banque Walid\n";
    std::cout << "1 - Ajouter de l'argent dans le compte \n";
    std::cout << "2 - Montrer le contenue du compte \n";
    std::cout << "3 - Enlever de l'argent du compte \n";
    std::cout << "4 - Sortir \n";
    std::cout << "Fait un choix avec (1-4): ";
    std::cin >> choose , choix();
}

void choix() {
    switch (choose)
    {
    case 1:
        add();
        break;
    case 2:
        show();
        break;
    case 3:
        remove();
        break;
    case 4:
        return;
        ;
        break;
    default:
        std::cout << GREEN << "Vous n'avez pas fait le bon choix entre (1-3): " << RESET << "\n";
        if (true) 
        {
            debut();
        }
        break;
    }
}

void add()
{
    std::cout << "                                   \n";
    std::cout << BLUE << "Vous avez " << SomeInAcount <<  " dans votre compte " << RESET << " \n";
    std::cout << BLUE << "Vous avez " << pocket << "  dans votre poche " << RESET << "\n";


    do{
        std::cout << "Voulez vous ajouter de l'argent dans votre compte (1 = oui / 2 = non): ";
        std::cin >> ye;
        std::cout << GREEN << "Mauvaise saisie veuillez sasir (1 = oui / 2 = non) " << RESET << "\n";
    } while (ye != 1 && ye != 2);

    if (ye == 1) {
        std::cout << "                                   \n";
        std::cout << "Veuillez dire combien d'argent voulez vous transferer sur votre compte: ";
        std::cin >> SommeToRemove;
        if (pocket <= 0) {
            std::cout << BLUE << "Vous n'avez pas assez de font dans votre compte banquaire " << RESET << "\n";
            std::cout << "                                   \n";
            std::cout << "Veuillez dire combien d'argent voulez vous transferer sur votre compte: ";
            std::cin >> SommeToRemove;
        }

        while (SommeToRemove > pocket){
            std::cout << BLUE << "Vous n'avez pas assez de font dans votre compte banquaire " << RESET << "\n";
            std::cout << "                                   \n";
            std::cout << "Veuillez dire combien d'argent voulez vous transferer sur votre compte: ";
            std::cin >> SommeToRemove;
        }
        while (SommeToRemove <= 0) {
            std::cout << BLUE << "Veuillez donner une somme positif" << RESET << "\n";
            std::cout << "                                   \n";
            std::cout << "Veuillez dire combien d'argent voulez vous transferer sur votre compte: ";
            std::cin >> SommeToRemove;
        }
            SomeInAcount = SomeInAcount + SommeToRemove;
            pocket = pocket - SommeToRemove;
        

        std::cout << "                                   \n";
        std::cout << BLUE << "Vous avez " << SomeInAcount << " dans votre compte " << RESET << " \n";
        std::cout << BLUE << "Vous avez " << pocket << "  dans votre poche " << RESET << "\n";        
        debut();
    
    }
    else if (ye == 2) {
        std::cout << "Anulation en cours... \n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        debut();
    }
}

void remove() {
    std::cout << "                                   \n";
    std::cout << BLUE << "Vous avez " << SomeInAcount << " dans votre compte " << RESET << " \n";
    std::cout << BLUE << "Vous avez " << pocket << "  dans votre poche " << RESET << "\n";
        
    std::cout << "Voulez vous ajouter de l'argent dans votre compte (1 = oui / 2 = non): ";
    std::cin >> ye;
    do {
        std::cout << "Voulez vous ajouter de l'argent dans votre compte (1 = oui / 2 = non): ";
        std::cin >> ye;
        std::cout << GREEN << "Mauvaise saisie veuillez sasir (1 = oui / 2 = non) " << RESET << "\n";
    } while (ye != 1 && ye != 2);

    if (ye == 1) {
        std::cout << "                                   \n";
        std::cout << "Veuillez dire combien d'argent voulez vous retirer: ";
        std::cin >> SommeToAdd;

        if (SomeInAcount <= 0) {
            std::cout << "                                   \n";
            std::cout << BLUE << "Vous n'avez pas assez de font dans votre compte banquaire " << RESET << "\n";
            std::cout << "                                   \n";
            std::cout << "Veuillez dire combien d'argent voulez vous retirer: ";
            std::cin >> SommeToAdd;
        }
        else {
            SomeInAcount = SommeToAdd - SomeInAcount;
            pocket = pocket + SommeToAdd;
        }

        std::cout << "                                   \n";
        std::cout << BLUE << "Vous avez " << SomeInAcount << " dans votre compte " << RESET << " \n";
        std::cout << BLUE << "Vous avez " << pocket << "  dans votre poche " << RESET << "\n";
        debut();

    }
    else if (ye == 2) {
        std::cout << "Anulation en cours... \n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        debut();
    }
}

void show(){
    std::cout << "                                   \n";
    std::cout << BLUE << "Vous avez " << SomeInAcount << " dans votre compte " << RESET << " \n";
    std::cout << BLUE << "Vous avez " << pocket << "  dans votre poche " << RESET << "\n";
    std::cout << "                                   \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    debut();
}