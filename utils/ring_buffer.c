//
// Created by JKerving on 2019/4/22.
//

#include <stdlib.h>
#include "ring_buffer.h"
#include "lib.h"

//已分配的ring_buf数量
int alloc_rbufs = 0;
//已释放的ring_buf数量
int free_rbufs = 0;

/**
 * 为环形缓冲区分配内存空间
 * @param size
 * @return
 */
struct ring_buf *alloc_rbuf(int size){
    struct ring_buf* rbuf;
    rbuf = calloc(1,sizeof(*rbuf)+size);//因为ring_buf数据结构中存在长度为0的数组，其为可变数组。内存空间与struct ring_buf连续
    rbuf->head = rbuf->tail = 0;
    rbuf->size = size;
    alloc_rbufs++;
    return rbuf;
}

/**
 * 释放环形缓冲区占用的内存空间
 * @param rbuf
 */
void free_rbuf(struct ring_buf* rbuf){
    if (rbuf!=NULL){
        free(rbuf);
        free_rbufs++;
    }
}

int rbuf_write(struct ring_buf* rbuf,char* data,int size){
    int len,wlen,onelen;
    if(rbuf==NULL)
        return 0;
    len = wlen = min(RBUFUNUSED(rbuf),size);//获取环形缓冲区中的剩余可写空间，与想要写入的size值比较并取最小值
    while (len>0){

    }
}