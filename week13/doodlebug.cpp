//
// Created by htahir on 2023-04-08.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


class GameBoard; // forward declaration
class Organism;

class Ant;

class DoodleBug;

struct Coordinates;

const int board_width = 20;
const int board_height = 20;

const int num_ants = 100;
const int num_doodlebugs = 5;

const char ant_symbol = 'o';
const char dbug_symbol = 'X';
const char board_symbol = '-';

const int ant_breed_interval = 3;
const int doodlebug_breed_interval = 8;
const int doodlebug_starve_interval = 3;


/**
* class organism
 * x and y pos vars for class
 * virtual move() [doodlebugs first, then ants]
 * virtual breed()
 * child ant, doodlebug
 * doodlebug starve()
 * objc onBoard() bool check
 * keep track of which ones have moved and
 * track timesteps per dbug
 * breed_timer: if 8 timesteps passed -> breed()
 * starve_timer: track timesteps since eaten ant: if 3 passed - then starve
 * if ant on adjacent square -> delete ant object
 *
 * player hits enter -> chars move -> printGameMap()
 * void printGameMap(new details of positions)
 *
*/

// since we don't have handy lists like in Python, we'll create an easily stackable array structure
// otherwise returning coordinates is going to be hard
struct Coordinates {
    int x;
    int y;
};


//# Directions dx, dy
const Coordinates moveUp = {0, -1};
const Coordinates moveDown = {0, 1};
const Coordinates moveLeft = {-1, 0};
const Coordinates moveRight = {1, 0};
const Coordinates DIRECTIONS[4] = {moveUp, moveDown, moveLeft, moveRight};

// a base class for every bug
class Organism {
public:
    Organism(const Coordinates &position);

    Organism();

    virtual ~Organism();

    // returns x,y position of Organism
    Coordinates get_Position() const {
        return grid_position;
    }

    // sets new position of Organism to x,y
    // precondition: position is valid
    void set_Position(Coordinates &pos) {
        grid_position.x = pos.x;
        grid_position.y = pos.y;
    }

    // abstract function
    virtual char get_bugType() = 0;

    // abstract function
    virtual void move(GameBoard &gBoard) = 0;

    // abstract function
    virtual void breed(GameBoard &b) = 0;

    // abstract function
    virtual void starve(GameBoard &b) = 0;

private:
    Coordinates grid_position{}; // an x,y array

};

class Ant : public Organism {
public:
    Ant(const Coordinates &position);

    Ant();

    virtual ~Ant();

    // returns counter for turns since last bred.
    int get_breedCounter() const { return breeding_counter; }

    // returns true if object is able to move
    // changes object position to new position.
    virtual void move(GameBoard &gBoard);

    // generates new Ant at dx,dy on Game board b
    virtual void breed(GameBoard &b);

    // returns bug symbol.
    virtual char get_bugType() {
        return ant_symbol;
    }

    // removes DoodleBug from board
    // calls remove_Organism board function
    virtual void starve(GameBoard &b) {}

private:
    int breeding_counter = 0;
};


class DoodleBug : public Organism {
public:
    DoodleBug(const Coordinates &position);

    DoodleBug();

    virtual ~DoodleBug();


    // returns true if object is able to move
    virtual void move(GameBoard &gBoard);

    // returns bug symbol
    virtual char get_bugType() {
        return dbug_symbol;
    }

    // creates a new DoodleBug object on board.
    virtual void breed(GameBoard &b);

    // removes DoodleBug from board
    // calls remove_Organism board function
    virtual void starve(GameBoard &b);

private:
    int breeding_counter = 0; // if 8 -> breed()
    int feed_counter = 0; // tracker for feeding. If 3 -> starve()
};

// a class to represent our game
// this will help us keep things organized
// and easily link ants and doodlebugs interactions
class GameBoard {
public:
    GameBoard();

    ~GameBoard();

    // update board symbols when character moves.
    void updateBoard(const Coordinates &position, char symbol);

    // allows all characters to move()
    // runs appropriate checks for starving/breeding
    void turnHandler();

    // add character to a spot on board
    // precondition: nothing already placed at desired position.
    void set_OrganismAt(Organism *myBug, Coordinates &pos);

    // increment turns by 1.
    void set_turnIncrement() { turns++; }

    // removes specified Organism at pos x,y from bug vector and removes symbol from board face
    void remove_Organism(Coordinates &position);

    // move Organism from one spot to another
    // set prior position in board grid to nullptr
    // precondition: Organism coordinates variable is already updated
    void move_Organism(Coordinates &position, Coordinates &newPosition);


    // checks if either ants list or DBug list is empty
    // returns True if so else False
//    bool get_isGameOver();

    // return the number of turns completed.
    int get_turns() { return turns; }

    // return True if dx,dy is a space on the board.
    bool get_isOnBoard(const Coordinates &pos) const {
        if (pos.x >= 0 && pos.x <= 19 && pos.y >= 0 && pos.y <= 19) {
            return true;
        } else {
            return false;
        }
    }

//    // get back vector of all ants
//    vector<Ant *> get_Ants() { return ant_list; }
//
//    // get back vector of all doodlebugs
//    vector<DoodleBug> get_DoodleBugs() { return dbugs_list; }

//    // returns True if square at dx,dy is not empty, else False.
//    bool get_IsSquareOccupied(const int dx, const int dy);

    // returns character at position dx, dy
    char get_CharacterAt(const Coordinates &pos) const;

    // returns a vector of open positions on the board, based around pos.
    // there can only be a max of 4 since no Organism can move diagonally.
    vector<Coordinates> get_available_spots(const Coordinates &pos) const;

    // print out game board grid
    void printGameBoard() const;


private:
    int turns = 0;
    bool ended = false; // game state
//    vector<Ant *> ant_list;
//    vector<DoodleBug *> dbugs_list;
    vector<vector<char>> board_face; // the game board
    vector<vector<Organism *>> board_grid;
};

int main() {
    srand(time(0));
    GameBoard myBoard;
    myBoard.printGameBoard();
    string entry;
    cout << "Press enter to take a turn.";
    getline(cin, entry);

    while (entry.empty()) {
        //myBoard.get_isGameOver();
        myBoard.turnHandler();
        myBoard.printGameBoard();
        cout << endl;
        int turns_comp = myBoard.get_turns();
        cout << turns_comp << " turns completed. Press enter to take a turn.\n";
        getline(cin, entry);
    }
//
//    myBoard.turnHandler();
//    cout << endl;
//    int turns_comp = myBoard.get_turns();
//    cout << turns_comp << " turns completed. Press enter to take a turn.\n";
//    myBoard.printGameBoard();

//    Ant myAnt(0, 1);
//    myBoard.set_CharacterAt(myAnt, myBoard);


//
//    vector<Ant> myAnts;
//
//    for (int i = 0; i < 3; i++) {
//        Ant myAnt(0, i);
//        myAnts.push_back(myAnt);
//    }
//
//    for (unsigned int i = 0; i < myAnts.size(); i++) {
//        myBoard.set_OrganismAt(myAnts[i], myBoard);
//    }

//


    return 0;
}

GameBoard::GameBoard() {

    // set up visual board variable
    for (int i = 0; i < board_height; i++) {
        vector<char> cols;
        for (int j = 0; j < board_width; j++) {
            cols.push_back(board_symbol);
        }
        board_face.push_back(cols);
    }

    // generate the objects grid:
    for (int i = 0; i < board_height; i++) {
        vector<Organism *> cols;
        for (int j = 0; j < board_width; j++) {
            cols.push_back(nullptr);
        }
        board_grid.push_back(cols);
    }

    for (int i = 0; i < num_doodlebugs; i++) {
        int row = rand() % board_height; // random spots for our bugs
        int col = rand() % board_width;

        while (board_grid[row][col] != nullptr) {
            row = rand() % board_height;
            col = rand() % board_width;
        }

        board_grid[row][col] = new DoodleBug({row, col});
        board_face[row][col] = dbug_symbol;
    }

    for (int i = 0; i < num_ants; i++) {
        int row = rand() % board_height;
        int col = rand() % board_width;

        while (board_grid[row][col] != nullptr) {
            row = rand() % board_height;
            col = rand() % board_width;
        }

        board_grid[row][col] = new Ant({row, col});
        board_face[row][col] = ant_symbol;
    }
}

GameBoard::~GameBoard() {
    for (int i = 0; i < board_height; i++) {
        for (int j = 0; j < board_width; j++) {
            board_grid[i][j] = nullptr;
        }
    }
}
//int GameBoard::findAntAtPosition(const Coordinates &pos) {
//    int counter = 0;
//    for (auto i: ant_list) {
//        counter++;
//        Coordinates bugPos = i->get_Position();
//        if (bugPos.x == pos.x && bugPos.y == pos.y) {
//            return counter; // found at index counter
//        }
//    }
//    return -1; // should never happen
//}

//int GameBoard::findDoodleBugAtPosition(const Coordinates &pos) {
//    int counter = 0;
//    for (auto i: dbugs_list) {
//        counter++;
//        Coordinates bugPos = i->get_Position();
//        if (bugPos.x == pos.x && bugPos.y == pos.y) {
//            return counter; // found at index counter
//        }
//    }
//    return -1; // should never happen
//}

// only need this one since we're using base class pointer
void GameBoard::set_OrganismAt(Organism *myBug, Coordinates &pos) {

    myBug->set_Position(pos);
    board_grid[pos.x][pos.y] = myBug;
    updateBoard(pos, myBug->get_bugType());

}

//void GameBoard::set_CharacterAt(DoodleBug *myBug, Coordinates &pos) {
//
//    myBug->set_Position(pos);
//    board_grid[pos.x][pos.y] = myBug;
//    updateBoard(pos, dbug_symbol);
//
//}

void GameBoard::updateBoard(const Coordinates &pos, char symbol) {
    board_face[pos.x][pos.y] = symbol;
}

void GameBoard::printGameBoard() const {
    for (int i = 0; i < board_face.size(); i++) {

        for (int j = 0; j < board_face[i].size(); j++) {
            cout << board_face[i][j] << "\t";
        }
        cout << endl;
    }
}

char GameBoard::get_CharacterAt(const Coordinates &pos) const {
    int x_val = pos.x;
    int y_val = pos.y;
    return board_face[x_val][y_val];
}

void GameBoard::remove_Organism(Coordinates &position) {

    // change game board to blank symbol
    updateBoard(position, board_symbol);

    // remove from our bugs vector
    board_grid[position.x][position.y] = nullptr;

}


void GameBoard::move_Organism(Coordinates &position, Coordinates &newPosition) {
    // copy ptr to new position
    board_grid[newPosition.x][newPosition.y] = board_grid[position.x][position.y];
    board_grid[position.x][position.y] = nullptr;
}


vector<Coordinates> GameBoard::get_available_spots(const Coordinates &pos) const {
    vector<Coordinates> available_spots;
    vector<Coordinates> potentials;
    for (auto i:  DIRECTIONS){
        potentials.push_back({pos.x+i.x,pos.y+i.y});
    }

    for (auto cell: potentials) {
        // check if valid spot:
        if (get_isOnBoard(cell)) {
            if (get_CharacterAt(cell) == board_symbol) {
                available_spots.push_back(cell);
            }
        }
    }


    return available_spots;
}


void GameBoard::turnHandler() {

    // moves dbugs
    // checks dbug starve or breed condition
    // then moves ants (remaining ants)
    // checks ants breed condition
    // checks game_state is false (game not over)?

    // move DoodleBugs
    for (int row = 0; row < board_width; row++) {
        for (int column = 0; column < board_width; column++) {
            if (board_grid[row][column] != nullptr) {
                if (board_grid[row][column]->get_bugType() == dbug_symbol) {
                    board_grid[row][column]->move(*this);
                }
            }
        }
    }
    // breed DoodleBugs
    for (int row = 0; row < board_width; row++) {
        for (int column = 0; column < board_width; column++) {
            if (board_grid[row][column] != nullptr) {
                if (board_grid[row][column]->get_bugType() == dbug_symbol) {
                    board_grid[row][column]->breed(*this);
                }
            }
        }
    }
    // starve DoodleBugs
    for (int row = 0; row < board_width; row++) {
        for (int column = 0; column < board_width; column++) {
            if (board_grid[row][column] != nullptr) {
                if (board_grid[row][column]->get_bugType() == dbug_symbol) {
                    board_grid[row][column]->starve(*this);
                }
            }
        }
    }
    // move ants
    for (int row = 0; row < board_width; row++) {
        for (int column = 0; column < board_width; column++) {
            if (board_grid[row][column] != nullptr) {
                if (board_grid[row][column]->get_bugType() == ant_symbol) {
                    board_grid[row][column]->move(*this);
                }
            }
        }
    }
    // breed ants
    for (int row = 0; row < board_width; row++) {
        for (int column = 0; column < board_width; column++) {
            if (board_grid[row][column] != nullptr) {
                if (board_grid[row][column]->get_bugType() == ant_symbol) {
                    board_grid[row][column]->breed(*this);
                }
            }
        }
    }

    turns++; // increment game turns

}

Organism::Organism(const Coordinates &position) : grid_position(position) {}

Organism::Organism() {}

Organism::~Organism() {}

Ant::Ant(const Coordinates &position) : Organism(position) {}

Ant::Ant() : Organism() {}

Ant::~Ant() {}


DoodleBug::DoodleBug(const Coordinates &position) : Organism(position) {}

DoodleBug::DoodleBug() : Organism() {}

DoodleBug::~DoodleBug() {}

void Ant::move(GameBoard &gBoard) {

    // pick a spot
    // ants only move to an empty spot
    Coordinates curr_pos = get_Position();
    // get open spots
    vector<Coordinates> spots = gBoard.get_available_spots(curr_pos);

    if (!spots.empty()) {
        // spots left to move
        int direction = rand() % spots.size(); // 0-3 max
        set_Position(spots[direction]);
        // update board face
        gBoard.updateBoard(spots[direction], ant_symbol);
        gBoard.updateBoard(curr_pos, board_symbol);
        // update board ptr vectors
        gBoard.move_Organism(curr_pos, spots[direction]);
    }
    breeding_counter++;
}

void Ant::breed(GameBoard &b) {

    if (breeding_counter >= ant_breed_interval) {
        // find available spots
        vector<Coordinates> spots = b.get_available_spots(get_Position());
        if (!spots.empty()) {
            // will breed if spot available, else will breed next turn
            int i = rand() % spots.size();
            // create a new Ant at spot
            b.set_OrganismAt(new Ant(), spots[i]);
            breeding_counter = 0;
        }
    }
}


void DoodleBug::move(GameBoard &b) {

    // pick a spot with nearby ants!
    vector<Coordinates> antSpots;
    Coordinates curr_pos = get_Position();

    vector<Coordinates> maybeAnts;
    for (auto i:  DIRECTIONS){
        Coordinates someDirection = {curr_pos.x+i.x,curr_pos.y+i.y};
        maybeAnts.push_back(someDirection);
    }
    // check if valid spots TBD
    // check if ant exists on these spots:
    for (auto a: maybeAnts) {
        if (b.get_isOnBoard(a)) {
            if (b.get_CharacterAt(a) == ant_symbol) {
                antSpots.push_back(a);
            }
        }
    }
    if (!antSpots.empty()) { // there are ants!
        int direction = rand() % antSpots.size();
        b.remove_Organism(antSpots[direction]); // kill off ant
        set_Position(antSpots[direction]);
        // update board vectors
        b.move_Organism(curr_pos, antSpots[direction]);
        b.updateBoard(antSpots[direction], dbug_symbol);
        b.updateBoard(curr_pos, board_symbol); // reset_board face
        feed_counter = 0; // reset to 0 steps since feeding
    } else { // no ants, move elsewhere
        feed_counter++; // increment steps since feeding
        // get open spots
        vector<Coordinates> spots = b.get_available_spots(curr_pos);

        if (!spots.empty()) {
            // spots left to move
            int direction = rand() % spots.size(); // 0-3 max
            set_Position(spots[direction]);
            // update board vectors
            b.updateBoard(spots[direction], dbug_symbol);
            b.updateBoard(curr_pos, board_symbol); // reset_board face
            b.move_Organism(curr_pos, spots[direction]);
        }
    }
    breeding_counter++;
}

void DoodleBug::breed(GameBoard &b) {

    if (breeding_counter >= doodlebug_breed_interval) {
        // find available spots
        Coordinates curr_post = get_Position();
        vector<Coordinates> spots = b.get_available_spots(curr_post);
        if (!spots.empty()) {
            int i = rand() % spots.size();
            // create a new DoodleBug at spot
            b.set_OrganismAt(new DoodleBug(), spots[i]);
            breeding_counter = 0;
        }
    }
}

void DoodleBug::starve(GameBoard &b) {

    if (feed_counter >= doodlebug_starve_interval) {
        Coordinates curr_pos = get_Position();
        b.remove_Organism(curr_pos);
    }
} 