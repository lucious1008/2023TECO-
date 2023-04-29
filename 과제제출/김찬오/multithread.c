	#include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	#include <unistd.h>
	
	#define QUEUE_SIZE 10
	
	// 큐 구조체 정의
	typedef struct {
	    int items[QUEUE_SIZE];
	    int front;
	    int rear;
	    int size;
	    pthread_mutex_t lock;
	} Queue;
	
	// 큐 초기화 함수
	void initQueue(Queue *queue) {
	    queue->front = 0;
	    queue->rear = -1;
	    queue->size = 0;
	    pthread_mutex_init(&queue->lock, NULL);
	}
	
	// 큐 비어있는지 확인하는 함수
	int isQueueEmpty(Queue *queue) {
	    return queue->size == 0;
	}
	
	// 큐 가득차있는지 확인하는 함수
	int isQueueFull(Queue *queue) {
	    return queue->size == QUEUE_SIZE;
	}
	
	// 큐에 아이템 추가하는 함수
	void enqueue(Queue *queue, int item) {
	    pthread_mutex_lock(&queue->lock);
	
	    if (!isQueueFull(queue)) {
	        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
	        queue->items[queue->rear] = item;
	        queue->size++;
	    }
	
	    pthread_mutex_unlock(&queue->lock);
	}
	
	// 큐에서 아이템 가져오는 함수
		int dequeue(Queue *queue) {
	    int item = -1;
	    pthread_mutex_lock(&queue->lock);
	
	    if (!isQueueEmpty(queue)) {
	        item = queue->items[queue->front];
	        queue->front = (queue->front + 1) % QUEUE_SIZE;
	        queue->size--;
	    }
	
	    pthread_mutex_unlock(&queue->lock);
	    return item;
	}
	
	// 프로듀서 스레드 함수
	void *producer(void *arg) {
	    Queue *queue = (Queue *)arg;
	
	    while (1) {
	        int item = rand() % 100; // 0 ~ 99 사이의 랜덤한 수 생성
	        enqueue(queue, item);
	        printf("Producer produced item %d\n", item);
	        sleep(1);
	    }
	}
		// 배타적 제어 함수
	
		
		
	// 컨슈머 스레드 함수
	void *consumer(void *arg) {
	    Queue *queue = (Queue *)arg;
	
	    while (1) {
	        int item = dequeue(queue);
	
	        if (item != -1) {
	            printf("Consumer consumed item %d\n", item);
	            sleep(2);
	        }
	    }
	}
	
	int main() {
	    pthread_t prod_thread, cons_thread;
	    Queue queue;
	
	    // 큐 초기화
	    initQueue(&queue);
	
	    // 프로듀서 스레드 생성
	    if (pthread_create(&prod_thread, NULL, producer, (void *)&queue)) {
	        fprintf(stderr, "Error creating producer thread\n");
	        return 1;
	    }
	
	    // 컨슈머 스레드 생성
	    if (pthread_create(&cons_thread, NULL, consumer, (void *)&queue)) {
	        fprintf(stderr, "Error creating consumer thread\n");
	        return 1;
	    }
	
	    // 스레드 종료 대기
	    pthread_join(prod_thread, NULL);
	    pthread_join(cons_thread, NULL);
	
	    return 0
