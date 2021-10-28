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
std::vector <int> Inserttion_Sort(std::vector<int> * vect) {
    std::vector<int>::iterator Begin = vect->begin();
   
    for(std::vector<int>::iterator it = vect->begin(); it != vect->end(); it++) {
        auto const Ponit_iter = std::upper_bound(vect->begin(), it, (*it));
        std::rotate(Ponit_iter, it, it + 1);
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
    Inserttion_Sort(&vect);
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i != 1e6; i++) {
        Inserttion_Sort(&vect);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    log(&vect, "Bubblue sort and Time Complexity " + std::to_string(diff.count()) + " microseconds");
    return 0;
}