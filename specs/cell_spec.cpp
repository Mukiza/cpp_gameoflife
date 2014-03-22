#include <igloo/igloo_alt.h>
#include <list>

using namespace igloo;

#include "./../lib/cell.h"

Describe(A_Cell)
{

    It(Should_be_the_same_cell_if_x_and_y_are_equal){
        Cell cell(1, 1);
        Cell same_cell(1, 1);
        Assert::That(cell, Is().EqualTo(same_cell));
    }

    It(Should_not_be_the_same_cell_if_x_and_y_are_equal){
        Cell cell(1, 2);
        Cell same_cell(1, 1);
        Assert::That(cell, !Equals(same_cell));
    }

    It(Should_have_coordinates){
        Cell cell(2, 3);
        Assert::That(cell.get_x(), Equals(2));
        Assert::That(cell.get_y(), Equals(3));
    }

    It(Can_detect_if_its_a_neighbour){
        Cell cell(1, 5);
        Cell neighbour(2, 4);
        Assert::That(cell.is_neighbour_to(neighbour), IsTrue());
    }

    It(Can_detect_if_its_not_a_neighbour){
        Cell cell(4, 7);
        Cell neighbour(2, 12);
        Assert::That(cell.is_neighbour_to(neighbour), IsFalse());
    }

    It(Does_not_consider_its_self_a_aneighbour){
        Cell cell(4, 7);
        Assert::That(cell.is_neighbour_to(cell), IsFalse());
    }

    It(Knows_it_has_no_neighbours){
        std::list<Cell> not_neighbours;
        Cell cell(5, 5);
        not_neighbours.push_back(cell);
        Assert::That(cell.count_neighbours(not_neighbours), Equals(0));
    }

    It(Knows_it_has_neighbours){
        std::list<Cell> neighbours;
        neighbours.push_back(Cell(2, 3));
        neighbours.push_back(Cell(3, 3));
        neighbours.push_back(Cell(12, 3));
        Cell cell(2,2);
        Assert::That(cell.count_neighbours(neighbours), Equals(2));
    }

    It(Knows_it_will_survive_in_the_environment){
        std::list<Cell> neighbours;
        neighbours.push_back(Cell(2, 3));
        neighbours.push_back(Cell(3, 3));
        neighbours.push_back(Cell(12, 3));
        neighbours.push_back(Cell(2, 1));
        Cell cell(2,2);
        Assert::That(cell.will_srvive_in(neighbours), IsTrue());
    }

    It(Knows_it_will_not_survive){
        std::list<Cell> few_neighbours;
        Cell cell(2, 2);
        few_neighbours.push_back(cell);
        Cell neighbour(2, 3);
        Assert::That(neighbour.will_srvive_in(few_neighbours), IsFalse());
    }

    It(Knows_it_will_not_survive_if_it_has_four_or_more_neighbours){
        std::list<Cell> few_neighbours;
        few_neighbours.push_back(Cell(0, 0));
        few_neighbours.push_back(Cell(0, 1));
        few_neighbours.push_back(Cell(1, 1));
        few_neighbours.push_back(Cell(0, 2));
        few_neighbours.push_back(Cell(1, 0));
        Cell neighbour(0, 1);
        Assert::That(neighbour.will_srvive_in(few_neighbours), IsFalse());
    }

    It(Knows_it_will_survive_if_it_has_three_neighbours){
        std::list<Cell> few_neighbours;
        few_neighbours.push_back(Cell(0, 0));
        few_neighbours.push_back(Cell(0, 1));
        few_neighbours.push_back(Cell(1, 1));
        few_neighbours.push_back(Cell(0, 2));
        Cell neighbour(0, 1);
        Assert::That(neighbour.will_srvive_in(few_neighbours), IsTrue());
    }

    It(Will_not_spawn_if_it_has_two_neighbours){
        std::list<Cell> few_neighbours;
        few_neighbours.push_back(Cell(0, 0));
        few_neighbours.push_back(Cell(0, 2));
        Cell neighbour(0, 1);
        Assert::That(neighbour.will_srvive_in(few_neighbours), IsFalse());
    }

    It(Will_spawn_if_it_has_three_neighbours){
        std::list<Cell> few_neighbours;
        few_neighbours.push_back(Cell(0, 0));
        few_neighbours.push_back(Cell(0, 2));
        few_neighbours.push_back(Cell(1, 0));
        Cell neighbour(0, 1);
        Assert::That(neighbour.will_srvive_in(few_neighbours), IsTrue());
    }
};
