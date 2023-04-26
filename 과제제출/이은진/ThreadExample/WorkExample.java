package ThreadExample;

public class WorkExample {
    public synchronized void methodA()
    {
        System.out.println("ThreadA의 methodA() 실행");
        notify();
        try{
            wait();
        }catch (InterruptedException e) {

        }
    }

    public synchronized void methodB() {
        System.out.println("ThreadB의 methodB() 실행");
        notify();
        try{
            wait();
        }catch (InterruptedException e) {

        }
    }
}
