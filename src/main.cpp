#include <iostream>
#include <stdexcept>

#include "Application.hpp"

int main()
{
    try
    {
        Application application{};
        application.run();
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Exception: " << exception.what() << '\n';
    }

    return 0;
}
