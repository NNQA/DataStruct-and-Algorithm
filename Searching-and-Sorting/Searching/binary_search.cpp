#include <iostream>
#include <vector>
#include <chrono>
#include <cstring>



void binary_search(std::vector <int> *arr, int x) {
    int letf = 0; 
    int right = arr->size();
    int mid = 0;
    while(letf <= right) {
        int mid = letf + (right - letf) / 2;
        if((*arr)[mid] == x) {
            return;
        }
        if((*arr)[mid] < x) {
            right = mid - 1;
        } else {
            letf = mid  + 1;
        }
    }
}
void log(const std::vector<int> *arr, std::string text, int x) {
    std::cout << text << std::endl;
    std::cout << "case :" << x << std::endl;
    for(std::vector<int>::const_iterator it = arr->begin(); it != arr->end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector <int> arr = {5, 6, 7, 8, 9, 10, 11, 12};
    
    
    int x = 9; // best caseK
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i != 1e6; i++) {
        binary_search(&arr, x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    log(&arr, "linear_search best case " + std::to_string(diff.count()) + " microseconds", x);
    


    x = 5; // Worst-case
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i != 1e6; i++) {
        binary_search(&arr, x);
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; 
    log(&arr, "linear_search worst-case " + std::to_string(diff.count()) + " microseconds", x);    

}