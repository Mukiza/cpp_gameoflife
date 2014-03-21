#include <stdlib.h>

class Cell{
    int x_;
    int y_;

    public:
    Cell(int x, int y) : x_(x), y_(y)
    {
    }

    int get_x() const
    {
        return x_;
    }

    int get_y() const
    {
        return y_;
    }

    bool is_neighbour_to(const Cell& other) const
    {
        int x_diff = abs(x_ - other.x_);
        int y_diff = abs(y_ - other.y_);
        return x_diff <= 1 && y_diff <= 1 && (x_diff != 0 && y_diff != 0);
    }
};
