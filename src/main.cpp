#include <iostream>
#include <chrono>
#include <thread>

const std::chrono::minutes default_work_interval{25};
const std::chrono::minutes default_break_interval{5};

static void show_usage(const std::string& name)
{
    std::cerr << name << " - Pomodoro timer." << std::endl;
    std::cerr << "Usage: " << name << " [<options>]" << std::endl;
    std::cerr << R"(
Options:

-w | --work-interval    Work interval in minutes
-b | --break-interval   Break interval in minutes
-h | --help             Show this help message)" << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "Hi there! I am a pomodoro timer." << std::endl;

    auto work_interval{default_work_interval};
    auto break_interva{default_break_interval};

    for (int i = 1; i < argc; ++i)
    {
        std::string arg{argv[i]};
        if (arg == "-w" || arg == "--work-interval")
        {
            work_interval = std::chrono::minutes{std::stoi(argv[i + 1])};
        }
        else if (arg == "-b" || arg == "--break-interval")
        {
            break_interva = std::chrono::minutes{std::stoi(argv[i + 1])};
        }
        else if (arg == "--help" || arg == "-h")
        {
            show_usage(argv[0]);
        }
    }

    while (true)
    {
        std::cout << "Work interval has started. You have " << work_interval.count()
                  << " min to work."  << std::endl;
        std::this_thread::sleep_for(work_interval);

        std::cout << "It's time to relax. You have " << break_interva.count() << " min to relax."
                  << std::endl;
        std::this_thread::sleep_for(break_interva);
    }
}
