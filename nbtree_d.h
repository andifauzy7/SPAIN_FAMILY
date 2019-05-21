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
typedef char nbType[30];

typedef struct nbTreeNode{
	nbType nama;
	int usia;
	char jeniskelamin;
	boolean status, king;
	nbAddr fs, nb, parent;
}ElmtTree;

struct nbTree{
	nbAddr root;
};

struct people{
	nbType nama, pr;
	int usia;
	char jk;
	boolean status, king;
};

/* Tampilan Menu */
int menu();

/* Konstruktor Tree
By : Fahmi Widianto */

void nbCreate(nbTree *x);
nbAddr nbCNode(nbType X, char Y,int Z,boolean O, boolean P);

/* Modul Alokasi untuk sebuah Node. Terdapat Input-an spt (Nama, Usia, JK, Status)
By : Fahmi Widianto */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X, char Y, int Z, boolean O, boolean P);
nbTree create_tree2(nbTree *Troot, nbAddr temp);
void inputmember(nbTree *root);
nbTree second_tree(nbTree *Troot);

/* Tampil Tree Preorder, Inorder, Postorder
By : Both */
void Postorder(nbAddr root);
void Preorder(nbAddr root);
void Inorder(nbAddr root);
void view_traversal(nbAddr root);

/* Delete Node, diasumsikan pada silsilah keluarga statusnya menjadi meninggal
By : Andi Fauzy D */
void delete_node(nbTree *pTree, nbTree *pTree2, nbType value);
void change_king(nbAddr treesatu, nbAddr treedua);
void change_king2(nbAddr test);

/* Modul untuk Update Nilai dari Node
By : Fahmi Widianto */
void updateTree(nbTree *root, nbTree *root2);

/* Seperangkat Modul File
By : Andi Fauzy D */
void save_tree(nbAddr root);
nbTree open_filetree();
people move_structure(people data, nbAddr pCur);

/* Modul Pembantu */

/* Search dengan mengembalikan address Node tertentu
By : Andi Fauzy D */
nbAddr nbSearch(nbAddr root, nbType src);
nbAddr nbSearchbefore(nbAddr root, nbAddr alamat);
nbAddr SearchKing(nbAddr root);

/* Cetak Tree
By : Both */
void nbPrint(nbAddr node, char tab[]);


#endif
