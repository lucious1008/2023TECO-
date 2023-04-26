		#include <stdio.h>
		#include <stdlib.h>
		#include <pthread.h>
		
		#define MAX_QUEUE_SIZE 10
		
			typedef struct {
		    int* items;
		    int front;
		    int rear;
		    int size;
			} Queue;
		
			void init_queue(Queue* q) {
		    q->items = (int*)malloc(sizeof(int) * MAX_QUEUE_SIZE);
		    q->front = 0;
		    q->rear  =-1;
		    q->size  = 0;
			q->size  = 0;       }
		
			void enqueue(Queue* q, int item) {
		    if (q->size == MAX_QUEUE_SIZE) {
		        printf("Error: Queue is full.\n");
		        return ;
		    }
		    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		    q->items[q->rear] = item;
		    q->size++;
		}
		
		int dequeue(Queue* q) {
		    if (q->size == 0) {
		        printf("Error: Queue is empty.\n");
		        return -1;
		    }
		    int item = q->items[q->front];
		    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		    q->size--;
		    return item;
		}
		
			void* producer(void* arg) {
		    Queue* q = (Queue*)arg;
		    int i;
		    for (i = 0; i < 20; i++) {
		        printf("Producer: Enqueuing %d\n", i);
		        enqueue(q, i);
		    }
		    pthread_exit(NULL);
		}
		
			void* consumer(void* arg) {
		    Queue* q = (Queue*)arg;
		    int i, item;
		    for (i = 0; i < 20; i++) {
		        item = dequeue(q);
		        printf("Consumer: Dequeuing %d\n", item);
		    }
		    pthread_exit(NULL);
		}
		
			int main() {
		    pthread_t producer_thread, consumer_thread;
		    Queue q;
		    init_queue(&q);
		
		    pthread_create(&producer_thread, NULL, producer, (void*)&q);
		    pthread_create(&consumer_thread, NULL, consumer, (void*)&q);
		
		    pthread_join(producer_thread, NULL);
		    pthread_join(consumer_thread, NULL);
		
		    return 0;
		}
