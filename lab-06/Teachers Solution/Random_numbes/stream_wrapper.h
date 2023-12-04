#pragma once

#include <fstream>
#include <iostream>
class stream_wrapper
{
private:
    std::ofstream os_;
    std::streambuf *buf_ = nullptr;

public:
    stream_wrapper(char* file_name = nullptr)
    {
        if (!file_name)
            return;
        os_.open(file_name);
        if (!os_.is_open())
        {
            std::cout << "Cannot open file " << file_name << std::endl;
            std::cout << "Writing to standard output" << std::endl;
            return;
        }
        buf_ = std::cout.rdbuf(os_.rdbuf());
    }
    ~stream_wrapper()
    {
        if (buf_)
        {   std::cout.flush();
            std::cout.rdbuf(buf_);
            os_.close();
        }
    }
};
