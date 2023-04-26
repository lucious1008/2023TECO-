package ThreadExample;

public class WaitExample {
        public static void main(String[] args) {

            WorkExample shared = new WorkExample();

            ThreadA threadA = new ThreadA(shared);
            ThreadB threadB = new ThreadB(shared);

            threadA.start();
            threadB.start();


        }
    }


