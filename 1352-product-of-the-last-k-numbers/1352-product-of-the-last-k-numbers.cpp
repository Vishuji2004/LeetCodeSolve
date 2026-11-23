class ProductOfNumbers {
private:
    vector<int> pre;
    int i = 0;
    vector<int> zer;
public:
    ProductOfNumbers() {
        pre = {1};
    }
    
    void add(int num) {
        if(num == 0) {zer.push_back(i); pre.push_back(1);}
        else pre.push_back(num*pre.back());
        i++;
    }
    
    int getProduct(int k) {
        int f = this->i - k;
        if(!zer.empty() && f <= zer.back()) return 0;
        return pre.back() / pre[f];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */