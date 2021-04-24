#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Station {
private:
    double x0, y0, z0, R;
    map<long int, vector<long int>> objects;
public:
    Station(double x, double y, double z, double R) : x0(x), y0(y), z0(z), R(R) {}

    bool Check(double x, double y, double z) const {
        return (sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0) + (z - z0) * (z - z0)) <= this->R);
    }

    void Handle(long int &id, long int &time, double x, double y, double z) {
        if (Check(x, y, z)) {
            objects[id].push_back(time);
            sort(objects[id].begin(), objects[id].end());
        }
    }

    void Show() {
        map<long int, long int> show;
        for (auto it = objects.begin(); it != objects.end(); ++it) {
            show[it->second[0]] = it->first;
        }
        for (auto jt = show.begin(); jt != show.end(); ++jt)
            cout << jt->second << endl;
    }
};


int main() {
    double X, Y, Z, R;
    cin >> X >> Y >> Z >> R;
    Station space = Station(X, Y, Z, R);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long int id, time;
        double x, y, z;
        cin >> id >> time >> x >> y >> z;
        space.Handle(id, time, x, y, z);
    }
    space.Show();
    return 0;
}