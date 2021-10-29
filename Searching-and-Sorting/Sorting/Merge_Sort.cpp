#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <random>
#include <functional>
#include <chrono>


void log(const std::vector<int> *vect, std::string text) {
    std::cout << text << std::endl;
    for(std::vector<int>::const_iterator it = vect->begin(); it != vect->end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void log(const std::vector<int> *vect) {
    for(std::vector<int>::const_iterator it = vect->begin(); it != vect->end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}




std::vector<int>  Merge_Sort(std::vector<int> * vect) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 12);
 
    std::vector<int> v1(12), v2(12);
    std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
    std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));
    std::cout << "Array 1: ";
    log(&v1);
    std::cout << "Array 2: ";
    log(&v2);
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
 
 
    // merge    ;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(*vect));
 
    return *vect;
}

int main() { 
    std::vector <int> vect;

    // Merge_Sort(&vect);
    // log(&vect);
    auto start = std::chrono::high_resolution_clock::now();
    Merge_Sort(&vect);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    log(&vect, "Merge sort and Time Complexity " + std::to_string(diff.count()) + " microseconds");
    return 0;
}