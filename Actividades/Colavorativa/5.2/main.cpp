#include "HashMap.h"

int main(){

/*     LinkedList list = LinkedList();
    list.insert("Jun 20 13:39:21 10.15.174.240:4486 Failed password for illegal user guest");
    list.insert("Sep 24 17:22:12 10.15.188.234:4145 Failed password for illegal user guest");

    list.print(); */

    HashMap map = HashMap();
    
    map.loadTxt("bitacora3");
    map.print();

    return 0;
}