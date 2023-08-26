class FooBar {
private:
    int n;
    mutex m;
    int i;
    condition_variable cv;
public:
    FooBar(int n) {
        this->i=0;
        this->n=n;
    }

    void foo(function<void()> printFoo) {
        for(int j=0; j<n; j++){
            unique_lock<mutex> ul(m);
            while((i&1)==1){
                cv.wait(ul);
            }
            printFoo();
            i++;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for(int j=0; j<n; j++){
            unique_lock<mutex> ul(m);
            while((i&1)==0){
                cv.wait(ul);
            }
            printBar();
            i++;
            cv.notify_all();
        }
    }
};