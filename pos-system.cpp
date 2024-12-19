#include <iostream>
//for abort()
#include <cmath>
using namespace std;




float culc(float price, int quantity) {
    return price * quantity;
}

float menu() {
    int choice, quantity;
    float price = 0;


    cout << "----------------------------- \n" << "\t OUR MENU \n" << "----------------------------- \n" << "1. Coca Cola \t $1 \n" 
    << "2. Sprite \t $1.5 \n" << "3. Monster \t $2.5 \n" << "4. Orange Joe \t $3 \n" << "----------------------------- \n";

    cout << "Choose your drink: ";
    cin >> choice;

    //detects invalid choice
    while (choice <1 || choice > 4){
        cout << "\a This is not in our menu";
        cout << "\n Choose again (1-4): ";
        cin >> choice;
    }


    cout << "Choose quantity: ";
    cin >> quantity;

    switch(choice) {
        case 1:
            price = 1.0;
            break;
        case 2:
            price = 1.5;
            break;
        case 3:
            price = 2.5;
            break;
        case 4:
            price = 3.0;
            break;
    }
    return culc(price, quantity);
}


int main() {
    char cont;
    float total = 0, wallet, cost, dept;

    cout << "Enter the ammount of your wallet: ";
    cin >> wallet;
   
    do {
        
        if (wallet <= 0){
            cout << "\a" << "Bruh your wallet is negative\n";
            break;
        }
        cost = menu();
        total += cost; // Add the cost of the selected drinks to the total
        wallet -= cost;

        //to switch from the negative value to a positive
        dept =  fabs(wallet);

        cout << "Wallet amount: " << wallet; 
        cout << "You want to continue shopping? [Y/N]: ";
        cin >> cont;
     
    } while (cont == 'Y' || cont == 'y');

    if(wallet < 0){
        cout << "You are in dept \n";
        cout << "You owe us: " << dept;
    }
    else if(total >0){
        cout << "----------------------------\n";
        cout << "That would be:" << total << "\n";
        cout << "Money left in wallet:" << wallet;
        cout << "\n----------------------------";
    }else{
        cout << "Leave..";
    }

    return 0;
}