package ThreadExample;

public class ThreadA extends Thread{

    private WorkExample workExample;


    public ThreadA(WorkExample ob) {
        this.workExample = ob;

    }

    @Override
    public void run() {
     for (int i=0; i<10; i++) {
         workExample.methodA();
     }
    }
}
