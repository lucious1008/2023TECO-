			#include <pthread.h>
	
		pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	
		void* print_t1(void* arg) {
	    	pthread_mutex_lock(&mutex);
	    	printf("t1\n");
	    	pthread_mutex_unlock(&mutex);
	    	return NULL;
		}
		
		void* print_t2(void* arg) {
	    	pthread_mutex_lock(&mutex);
	    	printf("t2\n");
	    	pthread_mutex_unlock(&mutex);
	    	return NULL;
		}
	
		int main() {
	    	pthread_t thread1, thread2;
	
	    	pthread_create(&thread1, NULL, &print_t1, NULL);
	    	pthread_create(&thread2, NULL, &print_t2, NULL);
	
	    	pthread_join(thread1, NULL);
	    	pthread_join(thread2, NULL);
		
	   	 return 0;
		}
	
	
	

