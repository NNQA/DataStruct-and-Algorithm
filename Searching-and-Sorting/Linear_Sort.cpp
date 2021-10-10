#include <iostream>
#include <vector>
#include <chrono>
#include <cstring>

void linear_search(std::vector<int> *arr, int x) {
    for(std::vector<int>::iterator it = arr->begin(); it != arr->end(); ++it) {
       if(*it == x) return;
    }
}
void log(const std::vector<int> *arr, std::string text) {
    std::cout << text << std::endl;
    for(std::vector<int>::const_iterator it = arr->begin(); it != arr->end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector <int> arr = {12, 5, 7, 9, 3, 5, 10};
    

    int x = 12; // best caseK
    auto start = std::chrono::high_resolution_clock::now();
    linear_search(&arr, x);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    log(&arr, "linear_search best case " + std::to_string(diff.count()) + " microseconds");

    x = 10; // Worst-case
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i != 1e6; i++) {
        linear_search(&arr, x);
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; 
    log(&arr, "linear_search worst-case " + std::to_string(diff.count()) + " microseconds");    

}