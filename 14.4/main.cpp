
#include <iostream>
#include <stdexcept>
using namespace std;

// 1. Exception : Montant invalide
class MontantInvalideException : public runtime_error
{
public:
    MontantInvalideException()
        : runtime_error("Erreur : Montant invalide !")
    {
    }
};

// 2. Exception : Solde insuffisant
class SoldeInsuffisantException : public runtime_error
{
public:
    SoldeInsuffisantException()
        : runtime_error("Erreur : Solde insuffisant !")
    {
    }
};


class Compte
{
private:
    int solde;

public:

    Compte(int s)
    {
        solde = s;
    }

    void deposer(int montant)
    {
        if (montant < 0)
        {
            throw MontantInvalideException();
        }

        solde += montant;

        cout << "Depot effectue avec succes !" << endl;
        cout << "Solde actuel : " << solde << endl;
    }

    void retirer(int montant)
    {
        if (montant < 0)
        {
            throw MontantInvalideException();
        }

        if (montant > solde)
        {
            throw SoldeInsuffisantException();
        }

        solde -= montant;

        cout << "Retrait effectue avec succes !" << endl;
        cout << "Solde actuel : " << solde << endl;
    }
};

int main()
{
    Compte c(1000);

    try
    {
        c.deposer(500);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        c.retirer(300);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        c.retirer(2000);
    }
    catch (const SoldeInsuffisantException& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        c.deposer(-100);
    }
    catch (const MontantInvalideException& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
