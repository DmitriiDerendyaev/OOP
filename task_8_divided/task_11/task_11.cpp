#include <iostream>
#include "expanded_queue.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    coordinates source_coord{ 10, 20 };
    coordinates target_coord;
    pairStack current_pair;

    current_pair.push(source_coord);
    cout << "Положили в стакан: " << source_coord.x << " - " << source_coord.y << endl;

    target_coord = current_pair.pop();

    cout << "Вытащили из стакана: " << target_coord.x << " - " << target_coord.y << endl;

    return 0;
}
