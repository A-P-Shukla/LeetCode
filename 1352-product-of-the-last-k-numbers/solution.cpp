class ProductOfNumbers {
public:
    ProductOfNumbers() {
        // sentinel product for empty prefix
        pref.push_back(1LL);
    }

    void add(int num) {
        if (num == 0) {
            // reset on zero: subsequent products crossing this zero are zero
            pref.clear();
            pref.push_back(1LL);
            return;
        }
        // multiply previous prefix product by num, store as new prefix
        long long next = pref.back() * static_cast<long long>(num);
        pref.push_back(next);
    }

    int getProduct(int k) {
        // If k reaches beyond current non‑zero segment, zero is included
        if (k >= static_cast<int>(pref.size())) return 0;
        long long numerator = pref.back();
        long long denominator = pref[pref.size() - k - 1];
        return static_cast<int>(numerator / denominator);
    }

private:
    // pref[i] = product of all numbers after the last zero up to index i-1
    std::vector<long long> pref;
};