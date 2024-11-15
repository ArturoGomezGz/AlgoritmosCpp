#include "HashMap.h"

int main(){

    HashMap map = HashMap();
    
    map.instert("Oct 9 10:32:24 10.15.175.231:6166 Failed password for illegal user guest");
    map.instert("Aug 28 23:07:49 10.15.178.241:6710 Failed password for root");
    map.instert("Aug 4 3:18:56 10.15.176.220:5268 Failed password for admin");
    map.instert("Jun 20 13:39:21 10.15.174.240:4486 Failed password for illegal user guest");
    map.instert("Jun 2 18:37:41 10.15.173.244:5491 Failed password for illegal user guest");
    map.instert("Oct 1 7:22:46 10.15.180.236:5978 Illegal user");
    map.instert("Sep 14 10:01:55 10.15.189.242:5537 Failed password for illegal user guest");
    map.instert("Jun 16 22:09:01 10.15.170.237:6452 Failed password for illegal user test");
    map.instert("Sep 24 17:22:12 10.15.188.234:4145 Failed password for illegal user guest");

    map.print();

    return 0;
}