#include "nbtree_d.h"

int main(){
    nbType nama;
    nbTree MyList,MyList2;

    nbCreate(&MyList);
    nbCreate(&MyList2);
    MyList=open_filetree();         // Membuka File FILE_TREE.DAT dengan kembalian berupa pointer head TREE(1).
    MyList2=second_tree(&MyList);   // Mengolah TREE(1), Melakukan Cek siapa raja & membuat TREE(2) Baru untuk Warisan.



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
            nbPrint(MyList.root,"");
            printf("\n\tNode yang ingin didelete : "); scanf(" %[^\n]",nama);
            if(nbSearch(MyList.root,nama)!=NULL){
                MyList.root = delete_node(MyList.root, nama);
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
