class H2O {
private:
    int h, leftH;
    int o, leftO;
    mutex m;
    condition_variable cvH, cvO;
    bool pairing;
    // this function to be called when pairing is done.
    void reset(){
        leftH = 2;
        leftO = 1;
        pairing = false;
    }
public:
    H2O() {
        h = 0;
        o = 0;
        reset();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(m);
        h++;
        cvH.wait(ul, [&](){
            return (!pairing and o >= 1 and h >= 2) || (pairing and leftH > 0);
        });
        
        // if are the first thread to start bonding three together, mark the process as started
        pairing = true;
        leftH--;
        h--;
        
        // if we need more hydrogen
        if(leftH > 0) cvH.notify_one();
        
        // if we need more oxygen
        if(leftO > 0) cvO.notify_one();
        
        // we are done pairing
        if(leftO == 0 && leftH == 0){
            reset();
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(m);
        o++;
        
        cvO.wait(ul, [&](){
            return (!pairing && h >= 2 && o >= 1) || (pairing && leftO > 0);
        });
        
        // if are the first thread to start bonding three together, mark the process as started
        pairing = true;
        leftO--;
        o--;
        
        // if we need more hydrogen
        if(leftH == 1) cvH.notify_one();
        else if(leftH == 2) cvH.notify_all();
        
        // we are done pairing
        if(leftO == 0 && leftH == 0){
            reset();
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};