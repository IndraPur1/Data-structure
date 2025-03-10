/* File : main.c */
/* Deskripsi :aplikasi driver ADT tree1 berkait dengan representasi fisik pointer */
/* NIM & Nama : Indra Purwanto & 24060123140150*/
/* Tanggal : 22 November 2024*/

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"
#include "pohon1.c"

int main(){
    // kamus lokal
    bintree P; // pohon biner
    bintree R; // pohon biner condong kanan
    bintree L; // pohon biner condong kiri
    infotype A;
    infotype B;
    
    printf("\n===POHON===\n");
    P = Tree('A',Tree('B',NIL,NIL),Tree('C',Tree('D',NIL,NIL),Tree('E',NIL,NIL)));
    R = Tree('I',NIL,Tree('J',NIL,Tree('K',NIL,NIL)));
    L = Tree('R',Tree('S',Tree('T',NIL,NIL),NIL),NIL);
    
    printf("\n===SELEKTOR===\n");
    printf("\nGetAkar\n");
    printf("Akar bintree P : %c\n", GetAkar(P));\
    printf("prefix ");
    PrintPrefix(P);
    printf("\n");

    printf("\nGetLeft\n");
    printf("Left bintree P : %c\n", info(GetLeft(P)));
    printf("prefix ");
    PrintPrefix(GetLeft(P));
    printf("\n");

    printf("\nGetRight\n");
    printf("Right bintree P : %c\n", info(GetRight(P)));
    printf("prefix ");
    PrintPrefix(GetRight(P));
    printf("\n");

    printf("\n===PREDIKAT===\n");
    printf("\nIsEmptyTree\n");
    printf("pohon P merupakan pohon kosong : %d\n", IsEmptyTree(P));

    printf("\nIsDaun\n");
    printf("pohon P merupakan daun : %d\n", IsDaun(P));

    printf("\nIsBiner\n");
    printf("pohon P merupakan pohon biner : %d\n", IsBiner(P));

    printf("\nIsunerLeft\n");
    printf("\npohon P hanya punya satu anak kiri saja : %d\n", IsUnerLeft(P));

    printf("\nIsunertRight\n");
    printf("pohon P hanya punya satu anak kanan saja : %d\n", IsUnerRight(P));

    printf("\n===PENELUSURAN===\n");
    printf("\nPrintPrefix\n");
    printf("prefix P : ");
    PrintPrefix(P);
    printf("\n");

    printf("\nNbElm\n");
    printf("Jumlah elemen pohon P : %d\n",NbElm(P));

    printf("\nNbDaun\n");
    printf("Jumlah daun pohon P : %d\n",NbDaun(P));

    printf("\nTinggi\n");
    printf("tinggi dari pohon P : %d\n",Tinggi(P));

    printf("\n===PENCARIAN===\n");
    printf("\nSearchX\n");
    printf("prefix P : ");
    PrintPrefix(P);
    printf("\n");
    printf("apakah elemen C ada pada pohon P : %d\n", SearchX(P, 'C'));

    printf("\nUpdateX\n");
    printf("prefix P : ");
    PrintPrefix(P);
    printf("\n");
    printf("elemen C pada pohon P diganti A\n");
    UpdateX(&P, 'C', 'A');
    printf("prefix P : ");
    PrintPrefix(P);
    printf("\n");

    printf("\nCountX\n");
    UpdateX(&P, 'E', 'C');
    printf("prefix P : ");
    PrintPrefix(P);
    printf("\n");
    printf("Jumlah elemen A pada pohon P : %d\n", CountX(P, 'D'));

    printf("\nIsSkewLeft\n");
    printf("Pohon P condong ke kiri : %d\n", IsSkewLeft(P));

    printf("\nIsSkewRight\n");
    printf("Pohon P condong ke kanan : %d\n", IsSkewRight(P));

    printf("\nPrintSurfix\n");
    printf("surfix P : ");
    PrintSurfix(P);
    printf("\n");

    printf("\nLevelX\n");
    printf("node E berada pada level : %d", LevelX(P, 'D'));
    printf("\n");

    printf("\nCountLevelT\n");
    printf("prefix P : ");
    PrintPrefix(P);
    printf("\n");
    printf("jumlah node pada level 2 : %d", CountLevelT(P, 2));
    printf("\n");

    printf("\nGetDaunTerkiri\n");
    printf("daun paling kiri pada pohon P : %c\n", GetDaunTerkiri(P));

    printf("\nFrekuensiX\n");
    printf("frekuensi elemen A pada pohon P : %f", FrekuensiX(P, 'A'));
    printf("\n");

    printf("\nCountVocal\n");
    printf("prefix P : ");
    PrintPrefix(P);
    printf("\n");
    printf("elemen vocal pada pohon P berjumlah : %d\n", CountVocal(P));

    printf("\nModus\n");
    UpdateX(&P, 'D', 'B');
    UpdateX(&P, 'C', 'B');
    UpdateX(&P, 'B', 'E');
    UpdateX(&P, 'B', 'E');
    UpdateX(&P, 'B', 'E');
    PrintSurfix(P);
    printf("\n");
    printf("modus pada pohon P adalah : %c", Modus(P));
    return 0;
}