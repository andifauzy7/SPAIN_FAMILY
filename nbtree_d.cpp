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

/* Konstruktor Tree */
void nbCreate(nbTree *x){
	(*x).root=NULL;
}

nbAddr nbCNode(nbType X,char Y,int Z,boolean O){
	nbAddr newNode;
	newNode=(nbAddr) malloc(sizeof(ElmtTree));
	if (newNode != NULL){
		newNode->nama=X;
		newNode->jeniskelamin=Y;
		newNode->usia=Z;
		newNode->status=O;
		newNode->fs=NULL;
		newNode->nb=NULL;
		newNode->parent=NULL;
	}
	return newNode;
}

/* Modul Alokasi untuk sebuah Node. Terdapat Input-an spt (Nama, Usia, JK, Status) */


/* Tampil Tree Preorder, Inorder, Postorder */
void Postorder(nbAddr root){
	if (root!=NULL){
		Postorder(root->fs);
		printf("%s ", root->nama);
		Postorder(root->nb);
	}
}

void Preorder(nbAddr root){
	if (root!=NULL){
		printf("%s ", root->nama);
		Preorder(root->fs);
		Preorder(root->nb);
	}
}

void Inorder(nbAddr root){
	if (root!=NULL){
		Inorder(root->fs);
		if (root->fs==NULL) printf("%s ", root->nama);
		if (root->parent !=NULL)
			if (root->parent->fs==root)
				printf("%s ", root->nama);
		Inorder(root->nb);
	}
}

/* Delete Node, diasumsikan pada silsilah keluarga statusnya meninggal */

/* Modul untuk Update Nilai dari Node */

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

/* Mencari kedalaman */
/*
int nbDepth(nbAddr root){
    int jml=0, jml_temp=0;
    nbAddr gerak, ujung, head;
    boolean test;

    gerak=root;
    if(gerak==NULL){
        return 0;
    }
    gerak=gerak->fs;
    jml=1;
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
            if(gerak==ujung){
                test=true;
            }
        }
        if(test==false && gerak->nb!=NULL){
            gerak=gerak->nb;
        }
    }

    return jml_temp;
} */
