#include <igloo/igloo_alt.h>

#include <list>
using namespace igloo;

#include "./../lib/board.h"

Describe(A_Board)
{
    It(Should_spawn_empty_if_empy){
        Board board;
        Assert::That(board.spawn().live_cells(), HasLength(0));
    }

    It(Should_be_empty_if_seeded_empy){
        Board board;
        board.seed(std::list<Cell>());
        Assert::That(board.spawn().live_cells(), HasLength(0));
    }

    It(Should_handle_blinker_formation){
        Board board;
        std::list<Cell> seed;
        seed.push_back(Cell(0, 1));
        seed.push_back(Cell(1, 1));
        seed.push_back(Cell(2, 1));

        board.seed(seed);
        Board new_gen = board.spawn();
        Assert::That(new_gen.live_cells(), HasLength(3));
        Assert::That(new_gen.live_cells(), Contains(Cell(1, 1)));
        Assert::That(new_gen.live_cells(), Contains(Cell(1, 0)));
        Assert::That(new_gen.live_cells(), Contains(Cell(1, 2)));
    }
};
