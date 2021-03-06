/*
File        : nbtree_d.cpp
Edited      : Andi Fauzy - 181511007
              Fahmi Widianto - 181511012
Deskripsi   : Implementasi dari NBTREE_D.H.
Kelas       : 1A / D3-T.Informatika (JTK'18)
*/
#include <malloc.h>
#include "nbtree_d.h"
#include "boolean.h"

/* Tampilan Menu */
int menu(){
    int pil;
    lagi:
        printf("\n\tImplementasi ADT Non-Binary Tree.\n");
        printf("\tProgram Silsilah Keluarga. (Kerajaan Spanyol)\n");
        printf("\t> Andi Fauzy D.   (181511007)\n");
        printf("\t> Fahmi Widianto. (181511012)\n");
        printf("\n\tMenu Program :\n");
        printf("\t1. Input Data Baru.\n");
        printf("\t2. Update Data.\n");
        printf("\t3. Delete Node.\n");
        printf("\t4. Tampilkan Silsilah Raja.\n");
        printf("\t5. Tampilkan Silsilah Keluarga.\n");
        printf("\t6. Keluar.\n");
        printf("\n\tPilihan Anda (1-6) : ");
        scanf(" %d",&pil);
        if(pil==1 || pil==2 || pil==3 || pil==4 || pil==5 || pil==6){
            return pil;
        } else {
            printf("\tInput Salah, Ulangi.\n\n\t");
            system("pause");
            system("cls");
            goto lagi;
        }
}

/* Konstruktor Tree */
void nbCreate(nbTree *x){
	(*x).root=NULL;
}

nbAddr nbCNode(nbType X,char Y,int Z,boolean O, boolean P){
	nbAddr newNode;
	newNode=(nbAddr) malloc(sizeof(ElmtTree));
	if (newNode != NULL){
		strcpy(newNode->nama,X);
		newNode->jeniskelamin=Y;
		newNode->usia=Z;
		newNode->status=O;
		newNode->king=P;
		newNode->fs=NULL;
		newNode->nb=NULL;
		newNode->parent=NULL;
	}
	return newNode;
}

/* Modul Alokasi untuk sebuah Node. Terdapat Input-an spt (Nama, Usia, JK, Status) */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X, char Y, int Z, boolean O, boolean P)
{
    nbAddr newNode, temp;

    newNode=nbCNode(X,Y,Z,O,P);
    if (newNode !=NULL)
        {
        if (parent==NULL)
        {
            tRoot->root=newNode;
        }
        else{
            temp=parent;
            if(temp->fs !=NULL)
                {
                temp=temp->fs;
                while(temp->nb!=NULL)
                    {
                    temp=temp->nb;
                    }
                    temp->nb=newNode;
                    newNode->parent=parent;
                }
                else{
                    temp->fs=newNode;
                    newNode->parent=parent;
                    }
            }
        }
}

nbTree create_tree2(nbTree *Troot, nbAddr temp){
    // Record untuk Header dari Tree baru.
    nbTree pCur;
    nbCreate(&pCur);
	boolean arah=false,test=false;
    nbType namaroot;

	Insertnode(&pCur, nbSearch(pCur.root,0),temp->nama,temp->jeniskelamin,temp->usia,temp->status,temp->king);
    if(temp->fs==NULL){
        return pCur;
    }
	do{
		if(temp->fs!=NULL && arah==0){
            temp=temp->fs;
			Insertnode(&pCur, nbSearch(pCur.root,temp->parent->nama),temp->nama,temp->jeniskelamin,temp->usia,temp->status,temp->king);
			}
		else{
			arah=0;

			if (temp->nb!= NULL){
                temp=temp->nb;
                Insertnode(&pCur, nbSearch(pCur.root,temp->parent->nama),temp->nama,temp->jeniskelamin,temp->usia,temp->status,temp->king);
			} else if(strcmp(temp->parent->nama,pCur.root->nama)!=0){
				temp=temp->parent;
				arah=1;
			} else if(strcmp(temp->parent->nama,pCur.root->nama)==0){
                test=true;
			}
		}
	}while(test!=true);
	return pCur;
}

nbTree second_tree(nbTree *Troot){
    nbTree Head, Head_two;
    nbCreate(&Head);
    boolean kiri=false, kanan=false;
    nbAddr alamat, cekhorizontal, ujunghead;

    alamat=cekhorizontal=ujunghead=NULL;
    cekhorizontal=alamat=SearchKing((*Troot).root);
    if(alamat->nb!=NULL){
        kanan=true;
    }
    if(alamat->parent->fs!=alamat){
        kiri=true;
    }

    // Menjadikan Raja sebagai Root.
    Head=create_tree2(&(*Troot),alamat);

    if(Head.root->fs!=NULL){
        ujunghead=Head.root->fs;
    while(ujunghead->nb!=NULL){
        ujunghead=ujunghead->nb;
        }
    }

    // Jika KING Memiliki adik.
    if(kiri==true){
        cekhorizontal=alamat->parent->fs;
        while(cekhorizontal->nb!=NULL && strcmp(cekhorizontal->nama,alamat->nama)!=0){
            nbCreate(&Head_two);
            Head_two=create_tree2(&(*Troot),cekhorizontal);
            Head_two.root->parent=Head.root;
            if(Head.root->fs==NULL){
                //Jika Head tidak memiliki FS.
                Head.root->fs=Head_two.root;
                Head_two.root->parent=Head.root;
                ujunghead=Head.root->fs;
            } else {
                //Jika Head memiliki Son.
                ujunghead->nb=Head_two.root;
                Head_two.root->parent=ujunghead;
                ujunghead=ujunghead->nb;
            }
        cekhorizontal=cekhorizontal->nb;
        }
    }
    // Jika KING Memiliki adik.
    if(kanan==true){
        cekhorizontal=alamat;
        while(cekhorizontal->nb!=NULL){
            cekhorizontal=cekhorizontal->nb;
            nbCreate(&Head_two);
            Head_two=create_tree2(&(*Troot),cekhorizontal);
            Head_two.root->parent=Head.root;
            if(Head.root->fs==NULL){
                //Jika Head tidak memiliki FS.
                Head.root->fs=Head_two.root;
                Head_two.root->parent=Head.root;
                ujunghead=Head.root->fs;
            } else {
                //Jika Head memiliki Son.
                ujunghead->nb=Head_two.root;
                Head_two.root->parent=ujunghead;
                if(ujunghead->nb!=NULL){
                    ujunghead=ujunghead->nb;
                }
            }
        }
    }
    return Head;

}

void inputmember(nbTree *root){
    nbTree memberlist;
    nbType nama, parent, live;
    char j_kel;
    int usia;
    boolean status, king;
    memberlist=(*root);
    printf("\n\tNama Lengkap          : "); scanf(" %[^\n]",nama);
    printf("  \tKelamin (L/W)         : "); scanf(" %c",&j_kel);
    printf("  \tUsia                  : "); scanf(" %d",&usia);
    printf("  \tStatus (Hidup / Mati) : "); scanf(" %s",live);
    if(strcmp("hidup",live)==0 || strcmp("Hidup",live)==0){
        status=1;
    } else {
        status=0;
    }
    king=0;
    printf("\n"); nbPrint(memberlist.root,"");
    inputparent:
    printf("\n\tOrang Tua             : "); scanf(" %[^\n]",parent); fflush(stdin);
    if(nbSearch(memberlist.root, parent)!=NULL){
        Insertnode(&(*root),nbSearch(memberlist.root, parent), nama, j_kel, usia, status, king);
    } else {
        printf("\tParent Tidak Ditemukan!");
        goto inputparent;
    }
}

/* Tampil Tree Preorder, Inorder, Postorder */
void Postorder(nbAddr root){
	if (root!=NULL){
		Postorder(root->fs);
		printf(" %s.", root->nama);
		Postorder(root->nb);
	}
}

void Preorder(nbAddr root){
	if (root!=NULL){
		printf(" %s.", root->nama);
		Preorder(root->fs);
		Preorder(root->nb);
	}
}

void Inorder(nbAddr root){
	if (root!=NULL){
		Inorder(root->fs);
		if (root->fs==NULL) printf(" %s.", root->nama);
		if (root->parent !=NULL)
			if (root->parent->fs==root)
				printf(" %s.", root->parent->nama);
		Inorder(root->nb);
	}
}

void view_traversal(nbAddr root){
    printf("\n\tPostorder :\n");
    Postorder(root);
    printf("\n\tPreorder  :\n");
    Preorder(root);
    printf("\n\tInorder   :\n");
    Inorder(root);
    printf("\n");
}

/* Delete Node, diasumsikan pada silsilah keluarga statusnya menjadi meninggal */
nbAddr delete_node(nbAddr root, nbAddr root_kedua, nbType value){
    nbAddr temp;
    if(root==NULL){
        printf("\n\tTree belum dibuat!");
    } else {
        temp = nbSearch(root, value);
        if(temp == NULL){
            printf("\n\tNama Tidak Ditemukan!");
        } else {
            if(temp->king == 1){
                change_king(root, root_kedua);
            }
            if(temp==root){
                // Jika Root.
                root = delete_root(root, temp);
            }
            else if(isLeaf(temp)){
                // Jika Leaf atau Daun.
                root = delete_leaf(root, temp);
            } else {
                // Jika batang.
                root = delete_stem(root, temp);
            }
        printf("\n\tDelete Berhasil!\n\t");
        }
        return root;
    }

}

bool isLeaf(nbAddr root){
    if(root->fs == NULL){
        return true;
    } else {
        return false;
    }
}

nbAddr delete_root(nbAddr root, nbAddr value){
    if(isLeaf(value)){
        // Jika berupa Daun. (1 Node saja)
        root=NULL;
    } else {
        // Jika bukan Daun.
        nbAddr anaknya = value->fs;
        anaknya->parent = NULL;
        anaknya = upgrade_position(root,anaknya);
        root = anaknya;
    }
    value = NULL;
    free(value);
    return root;
}

nbAddr delete_leaf(nbAddr root, nbAddr value){
    if(nbSearchbefore(root, value)==0){
        // Seorang Kakak.
        if(value->nb!=NULL){
            // Memiliki Adik.
            nbAddr adiknya = value->nb;
            value->parent->fs = adiknya;
        } else {
            // Anak Tunggal.
            nbAddr ayahnya = value->parent;
            ayahnya->fs = NULL;
        }
    } else {
        // Memiliki Kakak.
        if(value->nb!=NULL){
            // Memiliki kakak dan Adik.
            nbSearchbefore(root, value)->nb = value->nb;
        } else {
            // Anak terkecil.
            nbSearchbefore(root, value)->nb = NULL;
        }
    }
    value=NULL;
    free(value);
    return root;
}

nbAddr delete_stem(nbAddr root, nbAddr value){
    nbAddr anaknya = value->fs;
    anaknya->parent = value->parent;
    // Jika seorang kakak.
    if(nbSearchbefore(root, value)==0){
        value->parent->fs = anaknya;
        //anaknya->fs = anaknya->nb;
        if(value->nb==NULL){
            // Tidak memiliki adik.
            anaknya = upgrade_position(root, anaknya);
        } else {
            // Memiliki seorang adik.
            nbAddr adiknya = value->nb;
            anaknya = upgrade_position(root, anaknya);
            anaknya->nb = adiknya;
        }
    } else {
        // Jika memiliki kakak.
        nbAddr kakaknya = nbSearchbefore(root, value);
        if(value->nb == NULL){
            // Jika tidak memiliki adik.
            anaknya = upgrade_position(root, anaknya);
        } else {
            // Jika Memiliki adik.
            nbAddr adiknya = value->nb;
            anaknya = upgrade_position(root, anaknya);
            anaknya->nb = adiknya;
        }
        kakaknya->nb = anaknya;
    }
    value=NULL;
    free(value);
    return root;
}

nbAddr upgrade_position(nbAddr root, nbAddr value){
    nbAddr anaknya = value;
    if(anaknya->fs!=NULL && anaknya->nb!=NULL){
        // Jika punya anak dan saudara.
        nbAddr cucu = anaknya->fs;
        while(cucu->nb!=NULL){
            cucu = cucu->nb;
        }
        nbAddr saudara = anaknya->nb;
        cucu->nb = saudara;
        anaknya->nb=NULL;
        while(saudara!=NULL){
            saudara->parent = anaknya;
            saudara = saudara->nb;
        }
    } else {
        if(anaknya->fs==NULL){
            // Jika punya saudara aja.
            nbAddr saudara = anaknya->nb;
            anaknya->nb = NULL;
            anaknya->fs = saudara;
                while(saudara!=NULL){
                    saudara->parent = anaknya;
                    saudara = saudara->nb;
                }
        }
    }
    return anaknya;
}

void change_king(nbAddr treesatu, nbAddr treedua){
    nbAddr gerak,tertua,tertua_free;
    tertua=gerak=tertua_free=NULL;
    gerak=treedua->fs;
    while(gerak->nama!=NULL){
        if(gerak->usia>=20 && gerak->jeniskelamin=='L' && gerak->status==1){
            tertua=gerak;
        }
        if(gerak->usia>=20 && gerak->status==1){
            if(tertua_free==NULL){
                tertua_free=gerak;
            }
        }
        gerak=gerak->nb;
    }
    // Search nama KING baru via Tree 1, Ubah Bagian KING Menjadi 1.
    if(tertua==NULL){
        nbSearch(treesatu,tertua_free->nama)->king=1;
    } else {
        tertua_free=tertua;
        nbSearch(treesatu,tertua_free->nama)->king=1;
    }
}

void updateTree(nbTree *root, nbTree *root2){
        nbTree memberlist;
        nbAddr change;
        nbType srcnama, changenama, changelive, namaking;
        char changej_kel;
        int changeusia,pil;
        boolean changestatus, changeking;

        lagi:
        memberlist=(*root);
        nbPrint(memberlist.root, "");
        printf("\n\tNama Lengkap          : "); scanf(" %[^\n]",srcnama);
        change=nbSearch(memberlist.root, srcnama);
        if (strcmp(change->nama, srcnama)==0)
            {
        printf("\tApa yang akan diubah ? \n");
        printf("\n\t1. Nama");
        printf("\n\t2. Jenis Kelamin");
        printf("\n\t3. Usia");
        printf("\n\t4. Status");
        printf("\n\t5. King");
        printf("\n\tPilihan Anda (1-5) : ");
        scanf("%d", &pil);

        switch(pil){

        /* Mengubah nama node */

        case 1 :
            printf("\n\tMasukan Nama Baru : ");
            scanf(" %[^\n]", changenama);
            strcpy(change->nama,changenama);
            break;

        /* Mengubah jenis kelamin Node */

        case 2 :
            printf("\n\tMasukan Jenis Kelamin (L/W) : ");
            scanf(" %c",&changej_kel);
            change->jeniskelamin=changej_kel;
            break;

        /* Mengubah Usia Node */

        case 3 :
             printf("\n\tMasukan Usia : ");
            scanf(" %d",&changeusia);
            change->usia=changeusia;
            break;

        /* Mengubah status Hidup/Mati Node*/

        case 4 :
         printf("\n\tStatus (Hidup / Mati) : ");
         scanf(" %s",changelive);
           if(strcmp("hidup",changelive)==0 || strcmp("Hidup",changelive)==0){
        changestatus=1;
        } else {
        changestatus=0;
        }
        change->status=changestatus;
        break;

        /* Mengubah status Raja */

        case 5 :
            printf("\n\t Status Raja (Raja) : ");
            scanf(" %s",namaking);
        if(strcmp("Raja",namaking)==0 || strcmp("raja",namaking)==0){
        changeking=1;
        } else {
        changeking=0;
        }
        if (changeking==1 && SearchKing((*root).root)->king!=NULL){
            SearchKing((*root).root)->king=0;
        }else if (changeking==0 && strcmp(SearchKing((*root).root)->nama,change->nama)==0){
            change_king((*root).root, (*root2).root);
        }
        change->king=changeking;
        break;

        default :
            printf("\n\tInput Salah, Ulangi.\n\n\t");
            system("pause");
            system("cls");
            goto lagi;

        }

    }else
        {
            printf("\n\tNama Tidak Ada, Ulangi.\n\n\t");
            system("pause");
            system("cls");
            goto lagi;
        }
}

/* Seperangkat Modul File */
void save_tree(nbAddr root){
    FILE *f_tree;
    people orang;
    nbAddr pCur;
	boolean arah=0;
    if((f_tree=fopen("FILE_TREE.dat", "wb"))==NULL){
        printf("File Mengalami Error\n");
        exit(1);
    }

    pCur=(nbAddr)malloc(sizeof(ElmtTree));
	pCur=root;
    orang=move_structure(orang,pCur);
    fwrite(&orang, sizeof(orang), 1, f_tree);
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
			orang=move_structure(orang,pCur);
            fwrite(&orang, sizeof(people), 1, f_tree);
		}else{
			arah=0;
			if (pCur->nb!= NULL){
				pCur=pCur->nb;
				orang=move_structure(orang,pCur);
                fwrite(&orang, sizeof(people), 1, f_tree);
			}else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);

    fclose(f_tree);
}

nbTree open_filetree(){
    people orang;
    nbAddr pCur;
    FILE *f_tree;
    nbTree Mylist;

    nbCreate(&Mylist);
    pCur=(nbAddr)malloc(sizeof(ElmtTree));
    if((f_tree=fopen("FILE_TREE.dat","rb"))==NULL){
        printf("File Mengalami Error\n");
        exit(1);
    }

    while(fread(&orang,sizeof(orang),1,f_tree) == 1){
        fflush(stdin);
        Insertnode(&Mylist, nbSearch(Mylist.root,orang.pr), orang.nama, orang.jk, orang.usia, orang.status, orang.king);
        fflush(stdin);
    }
    fclose(f_tree);
    return Mylist;
}

people move_structure(people data, nbAddr pCur){
    data.jk=pCur->jeniskelamin;
    data.status=pCur->status;
    data.king=pCur->king;
    data.usia=pCur->usia;

    strcpy(data.nama,pCur->nama);
    if(pCur->parent!=NULL){
        strcpy(data.pr,pCur->parent->nama);
    } else {
        strcpy(data.pr,"0");
    }
    return data;
}

/* Modul Pembantu */

/* Search dengan mengembalikan address Node tertentu */
nbAddr nbSearch(nbAddr root, nbType src){
	nbAddr nSrc;
	if (root!=NULL){
		if (strcmp(root->nama,src)==0)
			return root;
		else{
			nSrc=nbSearch(root->fs,src);
			if (nSrc==NULL)
				return nbSearch(root->nb,src);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

nbAddr nbSearchbefore(nbAddr root, nbAddr alamat){
	nbAddr nSrc;
	if (root!=NULL){
		if (root->nb==alamat)
			return root;
		else{
			nSrc=nbSearchbefore(root->fs,alamat);
			if (nSrc==NULL)
				return nbSearchbefore(root->nb,alamat);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

nbAddr SearchKing(nbAddr root){
	nbAddr nSrc;
	if (root!=NULL){
		if (root->king==1)
			return root;
		else{
			nSrc=SearchKing(root->fs);
			if (nSrc==NULL)
				return SearchKing(root->nb);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

/* Cetak Tree */
void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
            if(node->king==1){
                printf("\t%s%s (RAJA)\n",tab,node->nama);
            } else {
                printf("\t%s%s\n",tab,node->nama);
            }
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}

