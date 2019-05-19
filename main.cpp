#include "nbtree_d.h"

int main(){
    nbTree MyList;
    nbCreate(&MyList);
    MyList=open_filetree();
    nbPrint(MyList.root,"");

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
            //view_traversal(MyList.root);
            //system("pause");
            // Silsilah Keluarga
            break;
        case 6 :
            // Keluar
            //save_tree(MyList.root);
            exit(1);
            break;
        }
        system("cls");
    }

	return 0;
}
