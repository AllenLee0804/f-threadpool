
#ifndef _ASYNC_EVENTFD_QUEUE_H_
#define _ASYNV_EVENTFD_QUEUE_H_

#include "queue.h"

typedef struct async_queue
{
    int efd; //event fd
    int epollfd; // epoll fd
    queue_t* queue;
    
    /* ���Ա��� */
    long long        tasked;  // �Ѿ����������������
} async_queue_t;

async_queue_t* async_queue_create(int size);

bool async_queue_push_tail(async_queue_t* q, void* data);

/*
 * @param q,       the target queue  
 * @param timeout, specifies the number of milliseconds that pop will block.
 */
void* async_queue_pop_head(async_queue_t* q, int timeout);

void async_queue_free(async_queue_t* q);

bool async_queue_is_empty(async_queue_t* q);

bool async_queue_wakeup(async_queue_t* q);

#endif
