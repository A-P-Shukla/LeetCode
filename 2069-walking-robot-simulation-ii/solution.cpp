#include <vector>
#include <string>

using namespace std;

class Robot {
private:
    int w, h, p;
    int idx;
    bool moved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        p = 2 * (w - 1) + 2 * (h - 1);
        idx = 0;
        moved = false;
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % p;
    }
    
    vector<int> getPos() {
        if (idx < w) {
            // Bottom edge: x from 0 to w-1, y = 0
            return {idx, 0};
        } else if (idx < w + h - 1) {
            // Right edge: x = w-1, y from 1 to h-1
            return {w - 1, idx - (w - 1)};
        } else if (idx < 2 * w + h - 2) {
            // Top edge: x from w-2 to 0, y = h-1
            return {w - 1 - (idx - (w + h - 2)), h - 1};
        } else {
            // Left edge: x = 0, y from h-2 to 1
            return {0, h - 1 - (idx - (2 * w + h - 3))};
        }
    }
    
    string getDir() {
        // Special case for (0,0) after any movement
        if (idx == 0 && moved) return "South";
        
        // Ranges determined by the boundary-turning logic
        if (idx >= 1 && idx <= w - 1) return "East";
        if (idx >= w && idx <= w + h - 2) return "North";
        if (idx >= w + h - 1 && idx <= 2 * w + h - 3) return "West";
        return "South"; // idx >= 2w + h - 2 or idx == 0 (initial)
    }
};