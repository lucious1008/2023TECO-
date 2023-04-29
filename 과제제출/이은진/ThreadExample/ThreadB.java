package ThreadExample;

public class ThreadB extends Thread{

    private WorkExample workExample;

    public ThreadB(WorkExample ob) {
        this.workExample = ob;
    }


    @Override
    public void run() {
        for (int i=0; i<10; i++) {
            workExample.methodB();
        }
    }
}

