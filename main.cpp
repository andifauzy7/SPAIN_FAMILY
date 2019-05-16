#include "nbtree_d.h"

int main(){
    nbAddr tempik, parent;
    nbType Nama;
    char JK;
    int Age;
    boolean St;


	nbTree MyList;
	nbCreate(&MyList);

    tempik=nbCNode("Fahmi",'L',72,false);
    printf("Nama : %s ,JK : %c , Usia : %d ,Status : %d \nKet: 1=Life 0=Death.", tempik->nama, tempik->jeniskelamin, tempik->usia, tempik->status);
    printf("\n");

    printf("NAMA : ");
    scanf("%s", &Nama);
    printf("\nJenis Kelamin : ");
    scanf(" %c", &JK);
    printf("\nUsia : ");
    scanf(" %d", &Age);
    printf("\nStatus : ");
    scanf(" %d", &St);

    Insertnode(&MyList, parent, Nama, JK, Age, St);

	return 0;
}
