//UNLOCKED SOLUTION
#include <map>
#include <vector>

class RangeModule {
public:
    std::map<int, int> m;

    void addRange(int left, int right) {
        removeRange(left, right);
        m[left] = right;
        auto it = m.find(left);

        if (it != m.begin() && std::prev(it)->second == left) {
            it--;
            it->second = right;
            m.erase(left);
        }

        if (it != std::prev(m.end()) && std::next(it)->first == right) {
            it->second = std::next(it)->second;
            m.erase(std::next(it));
        }
    }

    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (m.empty() || it == m.begin()) {
            return false;
        }
        it--;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        if (m.empty()) return;
        auto it = m.lower_bound(left);
        if (it != m.begin()) it--;

        std::vector<int> v;

        while (it != m.end() && it->first < right) {
            if (it->first < left && it->second > left) {
                int temp = it->second;
                it->second = left;
                if (temp > right) m[right] = temp;
            } else if (it->first >= left) {
                v.push_back(it->first);
                if (it->second > right) m[right] = it->second;
            }
            it++;
        }

        for (int i : v) {
            m.erase(i);
        }
    }
};
