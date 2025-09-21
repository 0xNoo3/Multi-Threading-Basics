#include<iostream>
#include<thread>

void background()
{
    while (true)
    {
        std::cout << "Thread started running\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::cout << "Main func\n";

    std::thread t1(background);

    t1.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    return 0;
}