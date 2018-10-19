#include <iostream>
#include <chrono>
#include <thread>

namespace {
const std::chrono::minutes default_work_interval{25};
const std::chrono::minutes default_break_interval{5};
}

int main(int argc, char** argv)
{
    std::cout << "Hi there! I am a pomodoro timer." << std::endl;

    //auto start{std::chrono::system_clock::now()};

    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv: " << argv[i] << std::endl;
    }

    // start the timer
    std::this_thread::sleep_for(default_work_interval);

    std::cout << "The time span has passed. It's time to relax." << std::endl;
}
