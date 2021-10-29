#include <iostream>
#include <cstring>
#include <algorithm>
#include <chrono>
#include <vector>


void log(const std::vector<int> *vect, std::string text) {
    std::cout << text << std::endl;
    for(std::vector<int>::const_iterator it = vect->begin(); it != vect->end(); ++it) {
        std::cout << *it << " ";
    }
}
std::vector <int> Selection_sort(std::vector<int> * vect) {
    int min, tick;
    for(std::vector<int>::iterator it = vect->begin(); it != vect->end(); it++) {
        tick = min = *it;
        std::vector<int>::iterator temp = vect->end();
        for(std::vector<int>::iterator ittt = it; ittt != vect->end(); ittt++) {
            if((*ittt)  < min) {
                min = *ittt;
                temp = ittt;
            }
        }
        if(temp != vect->end()) {
            *it = min;
            *temp = tick;
        }
    }
    return *vect;
}

int main() { 
    int n;
    std::vector <int> vect;

    std::cin >> n;
    while(n--) {
        int k;
        std::cin >> k;
        vect.push_back(k);
    }
    // Inserttion_Sort(&vect);
    // log(&vect);
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i != 1e6; i++) {
        Selection_sort(&vect);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    log(&vect, "Selection sort and Time Complexity " + std::to_string(diff.count()) + " microseconds");
    return 0;
}