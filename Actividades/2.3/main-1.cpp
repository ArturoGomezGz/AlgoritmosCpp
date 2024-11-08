//             ¶¶¶1   1¶¶1   1¶¶1                   
//            1¶¶1   1¶¶1   1¶¶1                    Act 2.3 - Actividad Integral estructura de datos lineales
//            1¶¶1   1¶¶1   1¶¶¶                    Equipo 2
//             ¶¶¶    ¶¶¶1   ¶¶¶1                       Arturo Gomez            A07109992    
//              ¶¶¶¶   1¶¶¶   1¶¶¶                      David Martinez          A01645721
//               1¶¶¶1   ¶¶¶1   ¶¶¶¶                    Oscar de la Paz         A01644484
//                 1¶¶1    ¶¶¶    ¶¶¶               
//                   ¶¶1    ¶¶1    ¶¶1              
//                   ¶¶¶    ¶¶¶    ¶¶¶              
//                  1¶¶1   1¶¶1    ¶¶1              
//                 ¶¶¶    ¶¶¶1   1¶¶1               
//                11     111     11                 
//           ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//1¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//1¶¶¶¶¶¶¶¶¶¶¶  1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//1¶¶       ¶¶  1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//1¶¶       ¶¶  1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//1¶¶       ¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//1¶¶       ¶¶  1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
// ¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
// ¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//           ¶¶   1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1       
//           1¶¶   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
//            ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11           
//11                                             111
//1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1
//  ¶¶111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111111111¶  



#include "LinkedList.h"
    
using namespace std;

int main()
{
    //Creacion de la lista1 vacia
    LinkedList list1 = LinkedList(); 

    // Carga del documento bitacora-1 a la lista1 este metodo crea la lista a pasrir del contenido del txt
    list1.addFile("bitacora-1");

    // Ordena la lista1 usando el metodo de odenamiento merge sort
    list1.sortByIp();

    // Exporta la lista1 (despues de ser ordenada) a un archivo bitacoraOrdenadaIP-Eq2.txt
    list1.exportToTxt("bitacoraOrdenadaIP-Eq2");

    // Realiza n cantidad de busquedas y las exporta a un salidaN-Eq2.txt 
    // Funcionamienot completo en "Linkedlist.h"
    list1.realizarBusqueda();

    return 0;
}
