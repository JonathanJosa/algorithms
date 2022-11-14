#include <iostream>

int main(){
    std::vector<int> our_vector{3, 5, 4, 1, 2};
    std::sort(our_vector.begin(), our_vector.end());
    for (auto& elem : our_vector)
        std::cout << elem << " - " << std::endl;
    getchar();
    return 0;
}
