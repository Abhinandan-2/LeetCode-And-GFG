class MedianFinder {
    multiset<int> s;
    multiset<int> ::iterator it;
    int n ;
public:
    MedianFinder() {
        n=0;
    }
    void addNum(int num) {
        s.insert(num);
        if(n==0){
            it = s.begin();
            n++;
            return ;
        }
        int val = *it;
        if(n%2!=0&&num<val) it--;
        else if(n%2==0&&num>=val) it++;
        n++;
        return ;
    }
    
    double findMedian() {
        double ans ;
        if(n%2!=0) ans= (double)*it;
        else{
            auto ij = it;
            ij++;
            ans = ((double)*ij+(double)*it)/2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */