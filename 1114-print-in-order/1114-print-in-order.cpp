class Foo {
    mutex m;
    int i;
    condition_variable cv;
public:
    Foo() {
        this->i=0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        i=1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> ul(m);
        while(i!=1){
            cv.wait(ul);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        i=2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        unique_lock<mutex> ul(m);
        while(i!=2){
            cv.wait(ul);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printThird();
    }
};