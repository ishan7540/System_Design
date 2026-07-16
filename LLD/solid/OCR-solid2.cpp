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
class Persistance
{
    ShoppingCart *cart;

public:
    virtual void saveToDB() = 0;
};

class SaveToSql : public Persistance
{
    ShoppingCart *cart;

public:
    SaveToSql(ShoppingCart *c) : cart(c) {}
    void saveToDB() override
    {
        cout << "saved to SQL" << endl;
    };
};

class SaveToMongo : public Persistance
{
    ShoppingCart *cart;

public:
    SaveToMongo(ShoppingCart *c) : cart(c) {}
    void saveToDB() override
    {
        cout << "saved to mongoDB" << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product(100, "Mouse"));
    cart->addProduct(new Product(1200, "Laptop"));

    ShoppingCartInvoice *invoice = new ShoppingCartInvoice(cart);
    invoice->printInvoice();
    Persistance *sql = new SaveToSql(cart);
    Persistance *mongo = new SaveToMongo(cart);

    sql->saveToDB();
    mongo->saveToDB();
    return 0;
}