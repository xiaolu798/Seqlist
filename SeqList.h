//
// Created by lenovo on 2024/9/10.
//

#ifndef DATASTACK_SEQLIST_H
#define DATASTACK_SEQLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_size 255

typedef struct ElementType{
    int id;
    char name[20];
}ElementType;


///定义顺序表结构
typedef struct {
    ElementType datas[Max_size];
    int length;
}Seqlist;




void SeqListInsert(Seqlist * seqlist,ElementType data,int pos){
    ///插入后的元素空间是否超过Max_size
    ///index是否合法
    if(pos > Max_size || seqlist->length + 1 > Max_size){
        return;
    }
    if(pos < 0 || pos > Max_size - 1){
        return;
    }

    for (int i = seqlist->length - 1; i >= pos; i--) {
        seqlist->datas[i+1].id = seqlist->datas[i].id;
        strcpy(seqlist->datas[i + 1].name,seqlist->datas[i].name);

    }
    seqlist->datas[pos].id = data.id;
    strcpy(seqlist->datas[pos].name,data.name);
    seqlist->length++;

}

void InitList(Seqlist * seqlist,ElementType * data,int length){
    if(length > Max_size){
        printf("Error: Length exceeds maximum size.\n");
        return;
    }
    for (int i = 0; i < length - 1; i++) {
        SeqListInsert(seqlist,data[i],i);

    }


}

void SeqListDetele(Seqlist * seqlist,int pos){
    if(pos > Max_size || seqlist->length + 1 > Max_size){
        return;
    }
    if(pos < 0 || pos > Max_size - 1){
        return;
    }
    for (int i = pos; i < seqlist->length; i++) {
        seqlist->datas[i] = seqlist->datas[i];

    }
    seqlist->length--;
}

int SeqListFind(Seqlist * seqlist,ElementType data){
    int i;
    for (i = 0; i < seqlist->length - 1; i++) {
        if(seqlist->datas[i].id == data.id && (strcmp(seqlist->datas[i].name,data.name) == 0)){
            return i;
        }

    }

    return -1;



}
#endif //DATASTACK_SEQLIST_H
