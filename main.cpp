#include "nbtree_d.h"

int main(){
    nbAddr tempik;


	nbTree MyList;
	nbCreate(&MyList);
    tempik=nbCNode("Fahmi",'L',72,true);
    printf("%s %c %d %d", tempik->nama, tempik->jeniskelamin, tempik->usia, tempik->status);
	return 0;
}
