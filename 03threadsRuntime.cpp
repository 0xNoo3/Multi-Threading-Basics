#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
#include<cassert>

void function(int i)
{
    std::cout << "Function running: " << i << std::endl;
}

int main()
{
    std::vector<std::thread> workers;

    auto thread_count = std::thread::hardware_concurrency();
    std::cout << "Total available threads " << thread_count << std::endl;
    
    for(uint32_t i = 0; i < thread_count; i++)
    {
        workers.emplace_back(std::thread(function, i));
    }

    std::for_each(workers.begin(), workers.end(), [](std::thread& t){assert(t.joinable()); t.join();})
    ;

    return 0;
}