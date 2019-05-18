/*
File        : nbtree_d.h
Edited      : Andi Fauzy - 181511007
              Fahmi Widianto - 181511012
Deskripsi   : Program silsilah keluarga kerajaan (Asumsi serupa dengan kerajaan Spanyol).
Kelas       : 1A / D3-T.Informatika (JTK'18)
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef struct nbTreeNode *nbAddr;
typedef char* nbType;

typedef struct nbTreeNode{
	nbType nama;
	int usia;
	char jeniskelamin;
	boolean status;
	nbAddr fs, nb, parent;
}ElmtTree;

struct nbTree{
	nbAddr root;
};

/* Konstruktor Tree */
void nbCreate(nbTree *x);

nbAddr nbCNode(nbType X, char Y,int Z,boolean O);

/* Modul Alokasi untuk sebuah Node. Terdapat Input-an spt (Nama, Usia, JK, Status) */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X, char Y, int Z, boolean O);

/* Tampil Tree Preorder, Inorder, Postorder */
void Postorder(nbAddr root);
void Preorder(nbAddr root);
void Inorder(nbAddr root);
void LevelOrder(nbAddr root,int curLevel, int desLevel);

/* Delete Node, diasumsikan pada silsilah keluarga statusnya meninggal */
void delete_node(nbTree *pTree);

/* Modul untuk Update Nilai dari Node */

/* Modul Pembantu */

/* Seperangkat Depth */
int nbDepth(nbAddr root);
nbAddr cekujung(nbAddr root);
void push_stack(nbAddr *head, nbAddr gerak);
nbAddr pop_stack(nbAddr head);
boolean isi_stack(nbAddr head);

/* Search dengan mengembalikan address Node tertentu */
nbAddr nbSearch(nbAddr root, nbType src);
nbAddr nbSearchbefore(nbAddr root, nbAddr alamat);

/* Cetak Tree */
void nbPrint(nbAddr node, char tab[]);


#endif
