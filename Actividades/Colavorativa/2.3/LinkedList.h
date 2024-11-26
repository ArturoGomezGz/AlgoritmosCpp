#include "node.h"

class LinkedList
{
private:
    int size;               // Tamaño de la linked list
    Node *head;             // Head de la lista (primer elemento)

    Node* mergeSort(Node* head);                        //   Descripcion de los metodos abajo
    Node* split(Node* head);                            //                   |
    Node* mergeLists(Node* first, Node* second);        //                   |                                
    Node* binarySearch(string ip);                      //                   |
    long long ipToComparableValue(string ipStr);        //           v       |       v
public:                                                 //             v     |     v
    LinkedList();                                       //               v   |   v
    ~LinkedList();                                      //                 v | v 
    Node* getHead();                                    //                   v   
    void addFileBySrc(string src);
    void addFile(string fileName);
    void insertFirst(string data);
    void print();
    void realizarBusqueda();
    void exportToTxt(string fileName);
    void sortByIp();
};

// Constructor del objeto LinkedList (crea la lista vacia)
LinkedList::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

// Destructor del objeto LinkedList
LinkedList::~LinkedList()
{
}

// Devuelve head de la lista
Node* LinkedList::getHead()
{
    return this->head;
}

// Carga la lista a partir de la ruta de un documento txt
void LinkedList::addFileBySrc(string src)
{
    ifstream file(src);  // Abre el archivo de texto
    
    cout << "documento abierto con exito" << endl;

    string line;

    // Procesa cada línea del archivo
    while (getline(file, line))
    {
        insertFirst(line);
    }
    cout << "documento cargado con exito" << endl;
    system("cls");

    file.close();
}

// Carga la lista a partir del nombre un documento txt
void LinkedList::addFile(string fileName)
{
    ifstream file("./"+fileName+".txt");  // Abre el archivo de texto
    
    cout << "documento abierto con exito" << endl;

    string line;

    // Procesa cada línea del archivo
    while (getline(file, line))
    {
        insertFirst(line);
    }
    cout << "documento cargado con exito" << endl;
    system("cls");

    file.close();
}

// Agrega un nuevo nodo al inicio de la lista a partir de un string 
void LinkedList::insertFirst(string data)
{
    Node* newNode = new Node(this->head, data);
    this->head = newNode;
    this->size++;
}

// Recorre la lista imprimiendo en consola los resultados
void LinkedList::print()
{
    Node* temp = this->head; // Comenzar desde la cabeza
    while (temp) {
        temp->print();
        temp = temp->next;
    }
}

//Metodo para buscar nodos por ip
// Pide al usuario 2 ips como rangos para buscar los nodos
// Crea un archivo txt con los resultados obtenidos
// Imprime los resultados en consola
// Usa binary seach para encontrar el nodo inical y a parir de ahi recorre la lista imprimiendo y escibiendo en txt los ressultados hasta encontrar o sobrepasar el ip final (secuencial)
void LinkedList::realizarBusqueda()
{
    bool continuar = true;
    int contador = 0;
    while (continuar) {
        contador++;

        string 
            ipIni = "",
            ipFin = ""
        ;

        cout << "ip inicial:" << endl;
        cin >> ipIni;
        cout << "ip final:" << endl;
        cin >> ipFin;

        if (ipToComparableValue(ipIni) < ipToComparableValue(ipFin))
        {
            ofstream file("./salida"+ to_string(contador) +"-Eq2.txt");
            Node* actual = binarySearch(ipIni);
            while (actual->ipComparableValue <= ipToComparableValue(ipFin))
            {
                file << actual->writeLine() << endl;
                actual->print();
                actual = actual->next;
            }
            file.close();
        } else {
            cout << "la ip inicial debe ser menos a la ip final" << endl;
            contador--;
        }

        cout << "Deseas hacer otra busqueda? y/n" << endl;
        char opt;
        cin >> opt;
        continuar = (opt == 'y');
    }
}

// Metodo que llama mergesort para ourdenar la lista y actualizar la head por la lista ordenada 
void LinkedList::sortByIp()
{
    this->head = this->mergeSort(this->head);
}

// Metodo para exportar la lista a un archivo txt, recibe el nombre del archivo a crear o sobreescribir
void LinkedList::exportToTxt(string fileName)
{
    ofstream file("./"+fileName+".txt");
    Node* temp = this->head;
    while (temp) {
        
        file << temp->writeLine() << endl;
        
        temp = temp->next;
    }
    file.close();
}

// Metodo que ordena la lista utilizando Merge Sort, recibe el head de la lsita desordenada y devuelve el head de la lista ordenada
Node* LinkedList::mergeSort(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return mergeLists(head, second);
}

// Metodo que divide la lista, recibe el head de la lista y devuelve el nodo a mitad de la lista
Node* LinkedList::split(Node* head)
{
    Node *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = nullptr;
    return temp;
}

// Metodo que une dos listas previamente ordenadas en una sola, devielve en head de una lista ordenada 
Node* LinkedList::mergeLists(Node* first, Node* second)
{
    if (!first) return second;
    if (!second) return first;

    if (first->ipComparableValue < second->ipComparableValue) {
        first->next = mergeLists(first->next, second);
        return first;
    } else {
        second->next = mergeLists(first, second->next);
        return second;
    }
}

// Metodo que genera un valor tipo long long a partir de ip (Sumamente util para comparar ips)
long long LinkedList::ipToComparableValue(string ipStr)
{
    int 
        octet1,
        octet2,
        octet3,
        octet4,
        port = 0
    ;

    char 
        dummy
    ;
    
    stringstream ss(ipStr);

    ss >> octet1 >> dummy >> octet2 >> dummy >> octet3 >> dummy >> octet4;

    long long ipValue = (static_cast<long long>(octet1) << 24) | (octet2 << 16) | (octet3 << 8) | octet4;

    return ((ipValue << 16) | port);
}

// Metodo que usa el metodo de busqueda binary search para encontrar un nodo con ip especifico (En caso de no encontrarlo, devuelve el nodo anterior a donde debeía estar)
Node* LinkedList::binarySearch(string ipStr)
{
    long long targetValue = ipToComparableValue(ipStr);

    Node *start = head;
    Node *end = nullptr;

    Node *closestNext = nullptr;

    while (start != end) {
        Node *mid = start;
        Node *fast = start;

        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            mid = mid->next;
        }

        if (mid->ipComparableValue == targetValue) {
            return mid;
        } else if (mid->ipComparableValue < targetValue) {
            start = mid->next;
        } else {
            closestNext = mid;
            end = mid;
        }
    }

    return closestNext;
}
