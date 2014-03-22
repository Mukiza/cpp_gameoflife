#include <stdlib.h>
#include <list>
#include<iostream>

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

    bool operator==(const Cell& other) const
    {
        return x_ == other.x_ && y_ == other.y_;
    }

    bool operator!=(const Cell& other) const
    {
        return !(*this == other);
    }

    bool is_neighbour_to(const Cell& other) const
    {
        int x_diff = abs(x_ - other.x_);
        int y_diff = abs(y_ - other.y_);
        return x_diff <= 1 && y_diff <= 1  && *this != other;
    }

    bool will_srvive_in(std::list<Cell> cells) const
    {
        int neighbour_count = count_neighbours(cells);
        if(exists_in(cells)){
            return neighbour_count >= 2 && neighbour_count < 4;
        }
        return neighbour_count == 3;
    }

    bool exists_in(std::list<Cell>& cells) const
    {
        return std::find(cells.begin(), cells.end(), *this) != cells.end();
    }

    int count_neighbours(std::list<Cell>& cells) const
    {
        int count = 0;
        std::list<Cell>::iterator it;
        for(it=cells.begin(); it != cells.end(); it++)
        {
            if(is_neighbour_to(*it)){
                count++;
            }
        }
        return count;
    }
};
