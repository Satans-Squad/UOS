public class threads_prime_odd_even {

    public static void main(String[] args) {
        Thread evenThread = new Thread(new EvenPrinter());
        Thread oddThread = new Thread(new OddPrinter());
        Thread primeThread = new Thread(new PrimePrinter());

        Thread mythread = new Thread(new MyThread());

        evenThread.start();
        mythread.start();
        oddThread.start();
        primeThread.start();
    }


    static class MyThread implements Runnable{

        @Override
        public void run() {
            for(int i = 1; i<=5; i+=2)
            System.out.println("Hello from Chill Vala Thread");
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    static class EvenPrinter implements Runnable {
        public void run() {
            for (int i = 2; i <= 10; i += 2) {
                System.out.println("Even: " + i);
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class OddPrinter implements Runnable {
        public void run() {
            for (int i = 1; i <= 10; i += 2) {
                System.out.println("Odd: " + i);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class PrimePrinter implements Runnable {
        public void run() {
            for (int i = 2; i <= 10; i++) {
                if (isPrime(i)) {
                    System.out.println("Prime: " + i);
                    try {
                        Thread.sleep(250);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }

        private boolean isPrime(int num) {
            if (num <= 1) {
                return false;
            }
            for (int i = 2; i <= Math.sqrt(num); i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        }
    }


}
