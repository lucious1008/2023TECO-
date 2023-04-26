		#include <stdio.h>
		#include <pthread.h>
	
		void *print_t1(void *arg) {
			
	    printf("t1\n");
	    pthread_exit(NULL);
	 	pthread_exit(NULL);
		    
		}
	
		void *print_t2(void *arg) {
	    printf("t2\n");
	    pthread_exit(NULL);
			}
		
		int main() {
	    pthread_t thread1, thread2;
	    int rc;
	    // t1 스레드만둘기 
	    rc = pthread_create(&thread1, NULL, print_t1, NULL);
	    if (rc) {
	        printf("Error: Return code from pthread_create() is %d\n", rc);
	        return 1;
	    }
	
	    // t2 스레드  만둘기 
	    rc = pthread_create(&thread2, NULL, print_t2, NULL);
	    if (rc) {
	    	
	        printf("Error: Return code from pthread_create() is %d\n", rc);
	        return 1;
	        	
	    	
	    }
	    pthread_join(thread1, NULL);
	    pthread_join(thread2, NULL);
		
	    return 0;
	    
		}
	
	
	
	
	

