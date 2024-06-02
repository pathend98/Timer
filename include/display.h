#include "timer.h"

class Display
{
    private:
        Timer& timer;

        void print() const;
        void clear() const;

    public:
        Display(Timer& timer);

        void start() const;
};
