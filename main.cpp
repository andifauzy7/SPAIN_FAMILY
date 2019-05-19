#include "nbtree_d.h"

int main(){
    nbTree MyList;
	nbAddr awal, anak1,anak2,anak3;

    nbCreate(&MyList);
    Insertnode(&MyList, nbSearch(MyList.root,0), "Alfonso 12", 'L', 20, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 12"),"Maria Mercedes", 'L', 25, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Maria Mercedes"),"Infante Alfonso", 'L', 25, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Alfonso"),"Carlos Calabria", 'L', 25, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 12"),"Alfonso 13", 'L', 28, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 13"),"Infante Juan", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Duchess Badajoz", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Badajoz"),"Dona Simoneta", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Badajoz"),"La Torre", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Badajoz"),"Don Bruno", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Badajoz"),"Don Luis", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Badajoz"),"Don Fernando", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Juan Carlos 1", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Duchess Lugo", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Lugo"),"Don Felipe", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Lugo"),"Dona Victoria", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Infanta Cristina", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Juan Urdangarin", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Don Pablo", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Don Miguel", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Dona Irene", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Felipe 6", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Felipe 6"),"Princess Asturias", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Felipe 6"),"Infanta Sofia", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Duchess Soria", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Soria"),"Don Alfonso", 'L', 18, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Duchess Soria"),"Dona Maria", 'L', 18, 1);

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
            view_traversal(MyList.root);
            system("pause");
            // Silsilah Keluarga
            break;
        case 6 :
            // Keluar
            save_tree(MyList.root);
            open_filetree();
            system("pause");
            exit(1);
            break;
        }
        system("cls");
    }

	return 0;
}
