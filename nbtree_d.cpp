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

void LevelOrder(nbAddr root,int curLevel, int desLevel){
	if(root!=NULL)
	{
		if(curLevel==desLevel)
			printf("%s. ",root->nama);
		LevelOrder(root->fs,curLevel+1,desLevel);
		LevelOrder(root->nb,curLevel,desLevel);
	}
}

void AllLevelOrder(nbAddr root, int maxlevel){
    int i=0;
    while(i<=maxlevel){
        printf("\tLevel %d   : ",i);
        LevelOrder(root,0,i);
        printf("\n");
        i++;
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
    //AllLevelOrder(root,nbDepth(root));
    printf("\n\tHierarki  :\n");
    nbPrint(root,"");
}

/* Delete Node, diasumsikan pada silsilah keluarga statusnya menjadi meninggal */
void delete_node(nbTree *pTree){
	nbAddr pdel, temp, sonbaru, ujungbrother;
	nbType value;
	char nama[30];
    printf("\nNode yg di delete : ");
	gets(nama);
	strcpy(value,nama);

	if(pTree->root != NULL){
	    pdel=nbSearch(pTree->root,value);
		if(pdel->fs != NULL){
		    // Jika yang dihapus memiliki son. Menandai First-an dari node tersebut.
            temp=pdel->fs;
            if(pdel->parent==NULL){
                pTree->root=temp;
                temp->parent=NULL;
            } else {
            temp->parent=pdel->parent;
            // Jika anak pertama sama dengan anak pertama dari kakek
            if(temp->parent->fs==pdel){
                pdel->parent->fs=temp;
            }
            }
            // Menyambungkan saudara yang lebih tua dari PDEL ke TEMP (Apabila Ada)
            if(nbSearchbefore(pTree->root, pdel)!=NULL){
                nbSearchbefore(pTree->root, pdel)->nb=temp;
            }
            // Menyimpan address brother temp, nanti akan dijadikan FS.
            if(temp->nb!=NULL){
                sonbaru=temp->nb;
                if(temp->fs==NULL){
                    temp->fs=sonbaru;
                } else {
                    ujungbrother=temp->fs;
                    while(ujungbrother->nb!=NULL){
                        ujungbrother=ujungbrother->nb;
                    }
                    ujungbrother->nb=sonbaru;
                }
                temp->nb=NULL;
                sonbaru->parent=temp;
            }
            // Menyambungkan saudara yang lebik muda dari PDEL ke TEMP (Apabila Ada)
            if(pdel->nb!=NULL){
                temp->nb=pdel->nb;
                pdel->nb=NULL;
            }
            pdel->fs=NULL;
            while(sonbaru->nb!=NULL){
                sonbaru->parent=temp;
                sonbaru=sonbaru->nb;
            }
		}
		else if(pdel->fs==NULL){
            // Menyimpan Parent dari Node yang akan dihapus.
			temp=pdel->parent;
			if(temp->fs==pdel){
			    // Apabila yang didelete adalah anak pertama.
			    // FS atau Anak pertama dari Node diubah ke NextBrother.
				temp->fs=pdel->nb;
			}
			else{
				temp=temp->fs;
				// Memindahkan temp ke anak pertama dari suatu node.
				while(temp->nb != NULL ){
					if(temp->nb==pdel){
                        // Memindahkan pointer ke anak sesudah sesudahnya.
						temp->nb = temp->nb->nb;
					}
					else{
						temp=temp->nb;
					}
				}
			}
		}
		free(pdel);
	}
	else{
		printf("Tree Kosong!");
	}
}

/* Modul untuk Update Nilai dari Node */

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

/* Seperangkat Depth */
int nbDepth(nbAddr root){
    int jml=0, jml_temp=0;
    nbAddr gerak, ujung, head=NULL;
    boolean test;

    gerak=root;
    if(gerak==NULL){
        return 0;
    }
    gerak=gerak->fs;
    jml=jml_temp=1;
    ujung=cekujung(gerak);
    test=false;

    while(test!=true){
        if(gerak->fs!=NULL){
            push_stack(&head,gerak);
            gerak=gerak->fs;
            jml++;
            if(jml>jml_temp){
                jml_temp=jml;
            }
        }
        if(isi_stack(head)!=true && gerak->nb==NULL && gerak->fs==NULL){
            gerak=pop_stack(head);
            jml--;
        }
        if(test==false && gerak->nb!=NULL){
            gerak=gerak->nb;
        }
        if(gerak==ujung){
            test=true;
        }
    }

    return jml_temp;
}

nbAddr cekujung(nbAddr root){
    nbAddr ujung;
    ujung=root;
    while(ujung->nb!=NULL){
        ujung=ujung->nb;
    }
    return ujung;
}

void push_stack(nbAddr *head, nbAddr gerak){
    nbAddr bantu;
    if(head==NULL){
        (*head)->parent=gerak;
        (*head)->nb=NULL;
    } else {
        bantu->parent=gerak;
        bantu->nb=(*head);
        (*head)=bantu;
    }
}

nbAddr pop_stack(nbAddr head){
    nbAddr bantu;
    bantu=head;
    head=head->nb;
    return bantu;
}

boolean isi_stack(nbAddr head){
    if(head==NULL){
        return true;
    } else {
        return false;
    }
}

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
		printf("\t%s%s\n",tab,node->nama);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}

