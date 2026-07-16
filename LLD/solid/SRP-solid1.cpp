#include <bits/stdc++.h>
using namespace std;
// we are practising single responsibility principle and how composition works
class Product
{
    double price;
    string name;

public:
    Product(int p, string n) : price(p), name(n) {}
    double getPrice()
    {
        return price;
    }
    string getName()
    {
        return name;
    }
};

class ShoppingCart
{
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }
    vector<Product *> &getProducts()
    {
        return products;
    }
    double calulateTotalPrice()
    {
        double sum = 0;
        for (auto p : products)
        {
            sum += p->getPrice();
        }
        return sum;
    }
};
// this class is only reposible to for printing receipts
class ShoppingCartInvoice
{
    ShoppingCart *cart;

public:
    ShoppingCartInvoice(ShoppingCart *c) : cart(c) {}
    void printInvoice()
    {
        for (auto p : cart->getProducts())
        {
            cout << "product name: " << p->getName() << ", produce price: " << p->getPrice() << endl;
        }
    }
};
// this class is only resposible for saving to DB
class saveCartToDB
{
    ShoppingCart *cart;

public:
    saveCartToDB(ShoppingCart *c) : cart(c) {};
    void save()
    {
        cout << "Cart saved to DB" << endl;
    }
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product(100, "Mouse"));
    cart->addProduct(new Product(1200, "Laptop"));

    ShoppingCartInvoice *invoice = new ShoppingCartInvoice(cart);
    invoice->printInvoice();
    saveCartToDB *DB = new saveCartToDB(cart);
    DB->save();

    return 0;
}