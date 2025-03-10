/* File : main.c */
/* Deskripsi :aplikasi driver ADT tree1 berkait dengan representasi fisik pointer */
/* NIM & Nama : Indra Purwanto & 24060123140150*/
/* Tanggal : 22 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.c"


int main(){
    //KAMUS LOKAL
    bintree T;
    infotype X = ' ';

    // Algoritma
    printf("Pembuatan BinTree\n");
    T = BuildBalanceTree(7);
    printf("Pohon Seimbang (Pre-order): ");
    PrintPrefix(T);
    printf("\n");

    // Cek apakah pohon seimbang
    printf("IsBalanceTree? %s \n", IsBalanceTree(T) == 1 ? "True" : "False");
    printf("\n");

    // Mencetak elemen pada level 2
    printf("PrintLevel (Level 2): ");
    PrintLevel(T, 2);
    printf("\n");

    // Menambahkan daun terkiri dengan nilai 'E'
    printf("AddDaunTerkiri (Tambah daun terkiri dengan nilai 'E'):\n");
    AddDaunTerkiri(T, 'E');
    PrintPrefix(T);
    printf("\n\n");

    // Menambahkan daun dengan nilai 'Z' sebagai anak kiri dari simpul dengan nilai 'E'
    printf("AddDaun (Tambah daun dengan nilai 'Y'):\n");
    AddDaun(T, 'E', 'Y', 1);  // true berarti anak kiri
    PrintPrefix(T);
    printf("\n\n");

    // Menyisipkan nilai baru 'F' ke dalam pohon
    printf("InsertX (Menyisipkan nilai 'F'):\n");
    InsertX(&T, 'F');
    PrintPrefix(T);
    printf("\n\n");

    // Menghapus daun terkiri dan mencetak nilai yang dihapus
    printf("DelDaunTerkiri (Hapus daun terkiri):\n");
    DelDaunTerkiri(&T, &X);  // Pastikan X sudah diinisialisasi sebelumnya
    printf("Daun terkiri yang dihapus: %c\n", X);  // Sekarang X sudah memiliki nilai
    PrintPrefix(T);
    printf("\n\n");

    // Menghapus daun dengan nilai 'F'
    printf("DelDaun (Hapus daun dengan nilai 'F'):\n");
    DelDaun(&T, 'F');
    PrintPrefix(T);
    printf("\n\n");

    // Menghapus simpul dengan nilai 'B'
    printf("DeleteX (Hapus simpul dengan nilai 'B'):\n");
    DeleteX(&T, 'B');
    PrintPrefix(T);
    printf("\n\n");

    // Mengganti semua elemen dengan nilai 'C' menjadi 'D'
    printf("UpdateAllX (Ganti semua nilai 'C' menjadi 'D'):\n");
    UpdateAllX(&T, 'C', 'D');
    PrintPrefix(T);
    printf("\n\n");

    // Menampilkan nilai maksimal dalam pohon
    printf("MaxTree = %c\n", maxTree(T));
    printf("\n");

    // Menampilkan nilai minimal dalam pohon
    printf("MinTree = %c\n", minTree(T));
    printf("\n");

    // Mencari apakah nilai 'E' ada dalam pohon
    printf("BSearch (Apakah nilai 'E' ada dalam pohon?): %s \n", BSearch(T, 'E') == 1 ? "True" : "False");
    printf("\n");

    // Menyisipkan nilai 'F' ke dalam pohon Binary Search Tree
    printf("InsSearch (Menyisipkan nilai 'F' pada Binary Search Tree):\n");
    T = InsSearch(T, 'F');
    PrintPrefix(T);
    printf("\n\n");

    // Menghapus simpul dengan nilai 'F' dalam Binary Search Tree
    printf("DelBTree (Menghapus nilai 'F' dalam Binary Search Tree):\n");
    DelBtree(&T, 'F');
    PrintPrefix(T);
    printf("\n\n");
    return 0;
}