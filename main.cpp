#include <iostream>
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    DramaMovie m1(10, "me", "bird", 1974);
    DramaMovie m2(10, "me", "cat", 1975);
    DramaMovie m3(10, "me", "dog", 1976);
    DramaMovie m4(10, "you", "bird", 1974);
    DramaMovie m5(10, "me", "bird", 1975);

    cout << "m1 < m2: " << (m1 < m2) << endl;
    cout << "m1 > m2: " << (m1 > m2) << endl;
    cout << "m1 == m2: " << (m1 == m2) << endl;
    cout << "m2 < m3: " << (m2 < m3) << endl;
    cout << "m2 > m3: " << (m2 > m3) << endl;
    cout << "m2 == m3: " << (m1 == m2) << endl;
    cout << "m1 == m4: " << (m1 == m4) << endl;
    cout << "m1 < m4: " << (m1 < m4) << endl;
    cout << "m1 > m4: " << (m1 > m4) << endl;
    cout << "m1 > m5: " << (m1 > m5) << endl;
    cout << "m1 == m5: " << (m1 == m5) << endl;
    cout << "m1 < m5: " << (m1 < m5) << endl;



    return 0;
}