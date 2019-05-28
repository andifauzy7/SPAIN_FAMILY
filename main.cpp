#include "nbtree_d.h"

int main(){
    nbType nama;
    nbTree MyList,MyList2;

    nbCreate(&MyList);
    nbCreate(&MyList2);
    //MyList=open_filetree();         // Membuka File FILE_TREE.DAT dengan kembalian berupa pointer head TREE(1).
    //MyList2=second_tree(&MyList);   // Mengolah TREE(1), Melakukan Cek siapa raja & membuat TREE(2) Baru untuk Warisan.

    ///*
    Insertnode(&MyList, nbSearch(MyList.root,0), "Alfonso 12", 'L', 162, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 12"),"Maria de las Mercedes", 'W', 139, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Maria de las Mercedes"),"Infante Alfonso", 'L', 118, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Alfonso"),"Infante Carlos Calabria", 'L', 71, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 12"),"Alfonso 13", 'L', 133, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 13"),"Infante Juan", 'L', 106, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Infanta Pilar", 'W', 82, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Dona Simoneta", 'W', 50, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"La Torre", 'L', 49, 1,0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Don Bruno", 'L', 48, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Don Luis", 'L', 46, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Don Fernando", 'L', 45, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Juan Carlos 1", 'L', 81, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Infanta Elena", 'W', 55, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Elena"),"Felipe de Marichalar", 'L', 20, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Elena"),"Victoria de Marichalar", 'W', 18, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Infanta Cristina", 'W', 53, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Juan Urdangarin", 'L', 19, 1,0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Don Pablo", 'L', 18, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Don Miguel", 'L', 17, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Dona Irene", 'W', 14, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Felipe 6", 'L', 51, 1, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Felipe 6"),"Leonor Princess Asturias", 'W', 14, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Felipe 6"),"Infanta Sofia", 'W', 12, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Infanta Margarita", 'W', 80, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Margarita"),"Alfonso Zurita", 'L', 46, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Margarita"),"Maria Zurita", 'W', 43, 1, 0);
    //*/
    MyList2=second_tree(&MyList);

    for(;;){
        switch(menu()){
        case 1 :
            // Input Data Baru.
            inputmember(&MyList);
            save_tree(MyList.root);
            printf("\n\tInput Berhasil!\n\t");
            break;
        case 2 :
            // Update Data.
            if(MyList.root==0){
                printf("\n\tTREE Kosong.");
            } else {
                updateTree(&MyList, &MyList2);
                if(SearchKing(MyList.root)->status==0){
                    SearchKing(MyList.root)->king=0;
                    change_king(MyList.root,MyList2.root);
                    save_tree(MyList.root);
                }
            }
            break;
        case 3 :
            // Delete Node (Delete pada Silsilah Tahta, Status diubah menjadi Meninggal)
            printf("\n\tNode yang ingin didelete : "); scanf(" %[^\n]",nama);
            if(nbSearch(MyList.root,nama)!=NULL){
                delete_node(&MyList,&MyList2,nama);
                printf("\n\tDelete Sukses!\n\t");
            } else {
                printf("\n\tInputan Salah!\n\t");
            }
            save_tree(MyList.root);
            break;
        case 4 :
            // Silsilah Raja
            printf("\n");
            MyList2=second_tree(&MyList);
            nbPrint(MyList2.root,"");
            printf("\n\t");
            break;
        case 5 :
            // Silsilah Keluarga
            printf("\n");
            nbPrint(MyList.root,"");
            printf("\n\t");
            break;
        case 6 :
            save_tree(MyList.root);
            // Keluar
            exit(1);
            break;
        }
        system("pause");
        system("cls");
    }

	return 0;
}
