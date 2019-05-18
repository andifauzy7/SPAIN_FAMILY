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

struct people{
	nbType nama, fs, nb, pr;
	int usia;
	char jk;
	boolean status;
};

/* Tampilan Menu */
int menu();

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
void AllLevelOrder(nbAddr root, int maxlevel);
void view_traversal(nbAddr root);

/* Delete Node, diasumsikan pada silsilah keluarga statusnya menjadi meninggal */
void delete_node(nbTree *pTree);

/* Modul untuk Update Nilai dari Node */

/* Seperangkat Modul File */
void save_tree(nbAddr root);
void open_filetree();
people move_structure(people data, nbAddr pCur);

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
