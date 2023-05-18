package BlockingQueue;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class MultiThreadQueue {
    public static void main(String[] args) {
        // b2블로킹큐생성
        BlockingQueue<String> queue = new ArrayBlockingQueue<>(10);

        // producer스레드 생성
        Thread producer = new Thread(() -> {
            try {
                for (int i = 1; i <= 10; i++) { // 10번만 반복
                    String task = produceTask();
                    queue.put(task);
                    System.out.println("Produced: " + task);
                    Thread.sleep(1000); // 대기
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        producer.start();

        // consumer스레드 생성
        Thread consumer = new Thread(() -> {
            try {
                for (int i = 1; i <= 10; i++) { // 10번만 반복
                    String task = queue.take();
                    consumeTask(task);
                    System.out.println("Consumed: " + task);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        consumer.start();
    }

    // 생성
    private static String produceTask() {
        return "Task " + System.nanoTime();
    }

    // 소비
    private static void consumeTask(String task) {
        System.out.println("Task " + task + " is consumed");
    }
}