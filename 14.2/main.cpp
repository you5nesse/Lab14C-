
#include <iostream>
#include <stdexcept>
using namespace std;

class StockInsuffisantException : public runtime_error
{
public:
    StockInsuffisantException()
        : runtime_error("Erreur : Stock insuffisant !")
    {
    }
};

class Produit
{
private:
    int stock;

public:
    Produit(int s)
    {
        stock = s;
    }


    void vendre(int quantite)
    {
        if (quantite > stock)
        {
            throw StockInsuffisantException();
        }

        stock -= quantite;

        cout << "Vente effectuee avec succes !" << endl;
        cout << "Stock restant : " << stock << endl;
    }
};

// 3. Programme principal
int main()
{
    Produit p(10);

    try
    {
        p.vendre(3);
        p.vendre(4);
        p.vendre(5);
    }
    catch (const StockInsuffisantException& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
