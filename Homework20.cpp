#include <iostream>
using namespace std;

#include "functions.h"

int main()
{
    Stock stock("Electronics Store");
    stock.addProduct(new Product("HP Pavilion dv6000", "A low-performance laptop", 405.5, 10));
    stock.addProduct(new Product("Iphone 5s", "Old Smartphone", 305.5, 10));
    stock.addProduct(new Product("Samsung Galaxy S10", "Premium smartphone", 850.0, 5));

    stock.print();

    cout << endl;

    Product* searchedProduct = stock.getProductById(1);
    if (searchedProduct) {
        cout << "Found product: " << endl;
		searchedProduct->Print();
    }
    else {
        cout << "Product not found!" << endl;
    }

    return 0;
}

