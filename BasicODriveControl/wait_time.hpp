#ifndef WAIT_TIME_HPP
#define WAIT_TIME_HPP

class Wait 
{

    private:
        unsigned int _start;
        bool _is_first = true;
    public:
        bool waiting(unsigned int milliseconds);

}

#endif    // WAIT_TIME_HPP