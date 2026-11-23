class ProductOfNumbers {
public:
    ProductOfNumbers() {
        pref.push_back(1LL);
    }

    void add(int num) {
        if (num == 0) {
            pref.clear();
            pref.push_back(1LL);
            return;
        }
        long long next = pref.back() * static_cast<long long>(num);
        pref.push_back(next);
    }

    int getProduct(int k) {
        if (k >= static_cast<int>(pref.size())) return 0;
        long long numerator = pref.back();
        long long denominator = pref[pref.size() - k - 1];
        return static_cast<int>(numerator / denominator);
    }

private:
    vector<long long> pref;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */