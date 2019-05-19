#include "nbtree_d.h"

int main(){
    nbTree MyList,MyList2;
    nbCreate(&MyList);
    nbCreate(&MyList2);

    MyList=open_filetree();
    MyList2=MyList;

    for(;;){
        switch(menu()){
        case 1 :
            // Input Data Baru
            break;
        case 2 :
            // Update Data
            break;
        case 3 :
            // Delete Node
            break;
        case 4 :
            // Silsilah Raja
            break;
        case 5 :
            // Silsilah Keluarga
            printf("\n\tRaja saat ini : %s\n",SearchKing(MyList.root)->nama);
            printf("\n");
            nbPrint(MyList.root,"");
            printf("\n\t");
            system("pause");
            break;
        case 6 :
            // Keluar
            save_tree(MyList.root);
            exit(1);
            break;
        }
        system("cls");
    }

	return 0;
}
