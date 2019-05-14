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
