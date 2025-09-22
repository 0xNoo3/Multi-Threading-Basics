#include<iostream>
#include<vector>
#include<thread>
#include<algorithm>
#include<cassert>
#include<mutex>

std::mutex cout_mutex; // mutex are global variables for all threads to see that !

void function(int i)
{   
    // std::lock_guard<std::mutex> lock(cout_mutex); // this will prevent the program to execcute this function cuncrrently.
    std::cout << "this is the function " << i << std::endl;
}

int main()
{
    std::vector<std::thread> vec;

    for(int i = 0; i < 10; i++)
    {
        vec.push_back(std::move(std::thread(function, i)));
    }

    std::for_each(vec.begin(), vec.end(), [](std::thread &t){assert(t.joinable()); t.join();})
    ;

    return 0;
}