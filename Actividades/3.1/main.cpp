#include "MyBST.h"
    
using namespace std;

int main()
{
    MyBST arbol1 = MyBST();

    arbol1.insert(4);

    arbol1.insert(9);
    arbol1.insert(2);

    arbol1.insert(3);
    arbol1.insert(8);
    arbol1.insert(1);
    arbol1.insert(11);

    arbol1.visit(4);
    if (arbol1.search(11))
    {
        cout << "valor encontrado" << endl;
    }

    cout << arbol1.whatLevelAmI(4) << endl;

    arbol1.ancestors(11);
    
    string wait;
    cin >> wait;
    return 0;
}
