#include "nbtree_d.h"

int main(){
	nbTree MyList;
	nbAddr awal;
	nbCreate(&MyList);

	awal=(nbAddr)malloc(sizeof(ElmtTree));
	MyList.root=awal;
	awal->nama="Andi Fauzy";
	awal->jeniskelamin='L';
	awal->usia=20;
	awal->status=true;
	awal->parent=NULL;
	awal->nb=NULL;
	awal->fs=NULL;

    awal=NULL;
    free(awal);

    awal=(nbAddr)malloc(sizeof(ElmtTree));
	MyList.root->nb=awal;
	awal->nama="Fahmi Widianto";
	awal->jeniskelamin='L';
	awal->usia=25;
	awal->status=true;
	awal->parent=MyList.root;
	awal->nb=NULL;
	awal->fs=NULL;
	MyList.root->fs=awal;
	awal=NULL;
	free(awal);

	awal=(nbAddr)malloc(sizeof(ElmtTree));
	MyList.root->nb=awal;
	awal->nama="Febriyoga Bagus";
	awal->jeniskelamin='L';
	awal->usia=28;
	awal->status=false;
	awal->parent=MyList.root;
	awal->nb=NULL;
	awal->fs=NULL;
	MyList.root->fs->nb=awal;
	awal=NULL;
	free(awal);

    awal=(nbAddr)malloc(sizeof(ElmtTree));
	MyList.root->nb=awal;
	awal->nama="Luthfi Alri";
	awal->jeniskelamin='L';
	awal->usia=18;
	awal->status=true;
	awal->parent=MyList.root;
	awal->nb=NULL;
	awal->fs=NULL;
	MyList.root->fs->nb->nb=awal;
	awal=NULL;
	free(awal);

    awal=(nbAddr)malloc(sizeof(ElmtTree));
    awal=MyList.root->fs;
    while(awal->nb!=NULL){
        printf("Nama      : %s\n",awal->nama);
        printf("Kelamin   : %c\n",awal->jeniskelamin);
        printf("Usia      : %d\n",awal->usia);
        printf("Status    : ");
        if(awal->status==1){
            printf("Hidup\n");
        } else {
            printf("Meninggal\n");
        }
        printf("Orang Tua : %s\n",awal->parent->nama);
        printf("\n");
        awal=awal->nb;
    }
        printf("Nama      : %s\n",awal->nama);
        printf("Kelamin   : %c\n",awal->jeniskelamin);
        printf("Usia      : ");
        if(awal->status==1){
            printf("Hidup\n");
        } else {
            printf("Meninggal\n");
        }
        printf("Status    : %d\n",awal->status);
        printf("Orang Tua : %s\n\n",awal->parent->nama);


	return 0;
}
