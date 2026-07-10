#include <iostream> 
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int min_x1 = min(x1, x2), max_x1 = max(x1,x2);
    int min_y1 = min(y1,y2), max_y1 = max(y1, y2);

    int min_x2 = min(x3, x4), max_x2 = max(x3, x4);
    int min_y2 = min(y3, y4), max_y2 = max(y3, y4);

    int s1 = (max_x1 - min_x1) * (max_y1 - min_y1);
    int s2 = (max_x2 - min_x2) * (max_y2 - min_y2);

    int left = max(min_x1, min_x2);
    int right = min(max_x1, max_x2);
    int bottom = max(min_y1, min_y2);
    int top = min(max_y1, max_y2);

    int result = s1 + s2;

    if((left < right) && (bottom < top)) {
        int s_intersection = (right - left) * (top - bottom);
        result -= s_intersection;
    }
    cout << result << "\n";

    return 0;
}
