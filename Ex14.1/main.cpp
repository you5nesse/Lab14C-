
#include <iostream>
#include <stdexcept>
using namespace std;

int diviser(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("Erreur : division par zero impossible !");
    }

    return a / b;
}

int main()
{
    try
    {
        cout << "10 / 2 = " << diviser(10, 2) << endl;
        cout << "20 / 4 = " << diviser(20, 4) << endl;
        cout << "15 / 0 = " << diviser(15, 0) << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
