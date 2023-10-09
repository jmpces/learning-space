#include <iostream>
#include <future>
#include <chrono>
#include <thread>

int mulx2(int x, size_t id) {
    std::cout << "thread started : input " << id << "\n";
    int res = x * 2;
    std::this_thread::sleep_for(std::chrono::seconds(res));
    std::cout << "input " << id << " done\n";
    return res;
}

int main() {
    std::cout << "start\n";
    auto asyncFun1 = std::async(&mulx2, 2, 0);
    auto asyncFun2 = std::async(&mulx2, 3, 1);

    std::cout << "gets\n";
    int res1 = asyncFun1.get();
    int res2 = asyncFun2.get();

    std::cout << "prints\n";
    std::cout << "The async thread has returned!\n";
    std::cout << "Result = " << res1 << "\n";
    std::cout << "Result = " << res2 << "\n";
}