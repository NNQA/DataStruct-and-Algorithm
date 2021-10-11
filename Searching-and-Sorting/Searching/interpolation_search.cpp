#include <iostream>
#include <vector>
#include <chrono>
#include <cstring>



void interpolation_search(std::vector <int> *arr, int x) {
    int letf = 0; 
    int right = arr->size();
    int mid = letf + (right - letf) * (x - (*arr)[letf]) / ((*arr)[right] - (*arr)[letf]);
    while(letf <= right) {
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
    
    
    int x = 8;// best caseK
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i != 1e6; i++) {
        interpolation_search(&arr, x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    log(&arr, "linear_search best case " + std::to_string(diff.count()) + " microseconds", x);
    
    return 0;
}