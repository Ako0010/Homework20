#pragma once

#pragma warning(disable : 4996)

class Product {
private:
    static int _staticid;
    int _id;
    char* _name = nullptr;
    char* _description = nullptr;
    double _price = 0.0;
    short _discount = 0;

public:
    Product()
    {
        _id = _staticid++;
    }

    Product(const char* name, const char* description, double price, short discount)
    {
        _id = _staticid++;
        _price = price;
        _discount = discount;
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        _description = new char[strlen(description) + 1];
        strcpy(_description, description);
    }

    Product(const char* name, const char* description, double price)
    {
        Product p(name, description, price, 0);
    }

    int getId()
    {
        return _id;
    }

    char* getName()
    {
        return _name;
    }

    char* getDescription()
    {
        return _description;
    }

    double getPrice()
    {
        return _price;
    }

    short getDiscount()
    {
        return _discount;
    }

    void setName(const char* name)
    {
        delete[] _name;
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }

    void setDescription(const char* description)
    {
        delete[] _description;
        _description = new char[strlen(description) + 1];
        strcpy(_description, description);
    }

    void setPrice(double price)
    {
        _price = price;
    }

    void setDiscount(short discount)
    {
        _discount = discount;
    }

    double getDiscountPrice()
    {
        return _price * (1 - _discount / 100.0);
    }

    void Print()
    {
        cout << "**************************************" << endl;
        cout << "Product ID: " << _id << endl
            << "Name: " << _name << endl
            << "Description: " << _description << endl
            << "Price: " << "$" << _price << endl
            << "Discount: " << _discount << endl
            << "Discounted Price: " << "$" << getDiscountPrice() << endl;
        cout << "**************************************" << endl;
    }

    ~Product()
    {
        delete[] _name;
        delete[] _description;
    }
};

int Product::_staticid = 1;

class Stock {
private:
    char* _name = nullptr;
    Product** _products = nullptr;
    size_t _count = 0;

public:
    Stock(const char* name) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }

    ~Stock() {
        delete[] _name;
        if (_products) {
            for (size_t i = 0; i < _count; i++) {
                delete _products[i];
            }
            delete[] _products;
        }
    }

    void addProduct(Product* product) {
        Product** newProducts = new Product * [_count + 1];
        for (size_t i = 0; i < _count; i++) {
            newProducts[i] = _products[i];
        }
        newProducts[_count] = product;
        delete[] _products;
        _products = newProducts;
        _count++;
    }

    void print() {
        cout << "Stock Name: " << _name << endl;
        cout << "Products in stock: " << _count << endl;
        for (size_t i = 0; i < _count; i++) {
            _products[i]->Print();
        }
    }

    Product* getProductById(int id) {
        for (size_t i = 0; i < _count; i++) {
            if (_products[i]->getId() == id) {
                return _products[i];
            }
        }
        return nullptr;
    }

};
