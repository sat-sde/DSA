class Semaphore {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;

public:
    Semaphore() : count(0) {}

    void setCount(int c) {
        count = c;
    }

    void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        while (count == 0) {
            cv.wait(lock);
        }
        --count;
    }

    void signal() {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }
};

class DiningPhilosophers {
    Semaphore fork[5];
    std::mutex m;

public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        {
            std::lock_guard<std::mutex> lock(m);
            fork[(philosopher + 1) % 5].wait();
            fork[philosopher].wait();
        }

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        fork[(philosopher + 1) % 5].signal();

        putRightFork();
        fork[philosopher].signal();
    }
};