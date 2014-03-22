#include <list>

#include "./cell.h"
class Board{
    std::list<Cell> cells_;
public:
    Board spawn() const
    {
        Board board;
        std::list<Cell> next_generation;
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                Cell cell(x, y);
                if(cell.will_srvive_in(cells_))
                {
                    next_generation.push_back(cell);
                }
            }
        }
        board.seed(next_generation);
        return board;
    }

    void seed(const std::list<Cell>& cells){
        cells_ = cells;
    }

    std::list<Cell> live_cells(){
        return cells_;
    }
};
