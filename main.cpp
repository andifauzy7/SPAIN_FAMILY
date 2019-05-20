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
            printf("\n\tInput Berhasil!\n\t");
            system("pause");
            break;
        case 2 :
            // Update Data.
            break;
        case 3 :
            // Delete Node (Delete pada Silsilah Tahta, Status diubah menjadi Meninggal)
            printf("\n\tNode yang ingin didelete : "); scanf(" %[^\n]",nama);
            delete_node(&MyList2,nama);
            system("pause");
            break;
        case 4 :
            // Silsilah Raja
            printf("\n\tRaja Saat Ini : %s",SearchKing(MyList.root)->nama);
            printf("\n\tUsia Saat Ini : %d",SearchKing(MyList.root)->usia);
            printf("\n\tOrang Tua     : %s\n",SearchKing(MyList.root)->parent->nama);
            printf("\n");
            MyList2=second_tree(&MyList);
            nbPrint(MyList2.root,"");
            printf("\n\t");
            system("pause");
            break;
        case 5 :
            // Silsilah Keluarga
            printf("\n\tRaja Saat Ini : %s",SearchKing(MyList.root)->nama);
            printf("\n\tUsia Saat Ini : %d",SearchKing(MyList.root)->usia);
            printf("\n\tOrang Tua     : %s\n",SearchKing(MyList.root)->parent->nama);
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
