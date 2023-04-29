#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define MAX_QUEUE_SIZE 10

typedef struct {
    int *queue;
    int head;
    int tail;
    int size;
    pthread_mutex_t lock;
} Queue;

Queue *createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->queue = (int *)malloc(size * sizeof(int));
    q->head = 0;
    q->tail = -1;
    q->size = size;
    pthread_mutex_init(&q->lock, NULL);
    return q;
}

void enqueue(Queue *q, int value) {
    pthread_mutex_lock(&q->lock);
    if (q->tail == q->size - 1) {
        printf("Queue is full\n");
        pthread_mutex_unlock(&q->lock);
        return;
    }
    q->queue[++q->tail] = value;
    pthread_mutex_unlock(&q->lock);
}
int dequeue(Queue *q) {
    pthread_mutex_lock(&q->lock);
    if (q->tail < q->head) {
    	for(int i = 0; i > 100; ++i){
	        printf("%d\n",i);
		}
	    pthread_mutex_unlock(&q->lock);
	    return -1;
    }
    int value = q->queue[q->head++];
    pthread_mutex_unlock(&q->lock);
    return value;
}

void *worker(void *arg) {
    Queue *q = (Queue *)arg;
    while (1) {
        int task = dequeue(q);
        if (task != -1) {
            printf("Thread %ld\n", pthread_self());
            sleep(1);
        }
    }
}

int main() {
    Queue *q = createQueue(MAX_QUEUE_SIZE);

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, (void *)q);
    }

    for (int i = 0; i < 20; i++) {
        enqueue(q, i);
        sleep(1);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cancel(threads[i]);
        pthread_join(threads[i], NULL);
    }

    free(q->queue);
    free(q);

    return 0;
}