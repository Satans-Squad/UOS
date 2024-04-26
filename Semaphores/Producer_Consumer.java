import java.util.concurrent.Semaphore;

class ProducerConsumer {
    private static final int BUFFER_SIZE = 5;
    private static int[] buffer = new int[BUFFER_SIZE];
    private static int in = 0, out = 0;

    private static Semaphore empty = new Semaphore(BUFFER_SIZE);
    private static Semaphore full = new Semaphore(0);
    private static Semaphore mutex = new Semaphore(1);

    static class Producer implements Runnable {
        public void run() {
            int item = 0;
            while (true) {
                try {
                    empty.acquire();
                    mutex.acquire();

                    buffer[in] = item;
                    System.out.println("Produced: " + item);
                    in = (in + 1) % BUFFER_SIZE;

                    mutex.release();
                    full.release();

                    item++;
                    Thread.sleep(3000); // Simulate some work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Consumer implements Runnable {
        public void run() {
            while (true) {
                try {
                    full.acquire();
                    mutex.acquire();

                    int item = buffer[out];
                    System.out.println("Consumed: " + item);
                    out = (out + 1) % BUFFER_SIZE;

                    mutex.release();
                    empty.release();

                    Thread.sleep(1000); // Simulate some work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        Thread producerThread = new Thread(new Producer());
        Thread consumerThread = new Thread(new Consumer());

        producerThread.start();
        consumerThread.start();
    }
}
