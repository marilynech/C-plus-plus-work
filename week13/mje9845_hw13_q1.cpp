//dooodlebug and ant program
#include <iostream>
#include <vector> 
#include <ctime>
#include <cstdlib>

using namespace std; 
//world is initialized with 5 predators and 100 prey, Each time you press enter
//a segment of time passes. 
const int numAnts = 100; 
const int numDoodlebugs = 5; 
const int ROW = 20;//like width
const int COLUMN = 20; //our height
//for types of organisms
const int doodlebug = 1; 
const int ant = 2; 
//breeding time
const int dbBreed = 8; //doodlebug survives 8 time steps, breed interval
const int antBreed = 3; //ant breed interval 
const int dbStarve = 3; //hasnt eaten within three time steps , doodblebug starve interval 
//character symbols 
const char space = '-';
const char antChar = 'o';
const char doodlebugChar = 'X';
//directions 
const int moveUp = 1;
const int moveDown = 2; 
const int moveLeft = 3; 
const int moveRight = 4; 
const int directions = 4; 
//declare classes
class Organism; 
class Area; 
class WorldSize; //size of area
class Ant; 
class Doodelbug; 
struct Coordinate; //keeps track of positions
//functions
void printBoard(WorldSize size); 
int randomNum(int num, int lowerbound = 0); 
//classes: 
class Organism{//make abstract class
    protected: //so we can use for ant and doodlebug classes but mot used in main 
        Area* area; 
        int posRow, posColumn; 
        int breedTime; 
        int orgLife; 
        bool inWorld(int row, int column); 
        void updateCoord(int direction, int& row, int& column); //get the cell its in
    public:
       // Organism(Area* world_, int posRow, int posColumn,  int breedTime, int orgLife){}
        //Organism(); 
        virtual ~Organism(){};
        virtual int getType() const = 0; 
        virtual void move();
        virtual void breed() = 0; 
        virtual bool starving()const {return false;}; 
};

class WorldSize{ //set the environment of the grid and its limits 
    private: 
        int rows, columns; 
    public:
        WorldSize(): rows(ROW),columns(COLUMN){}//row =20 
        WorldSize(int rows_, int columns_): rows(rows_),columns(columns_){}
        int cellLimit()const{return rows * columns;}
        int getRows()const {return rows;}
        int getColumns()const{return columns;}  
};

class Area{
    protected: //so we can use for doodlebug
        int timeStepCount; 
        void initalizeAnts();
        void initalizeDoodle(); 
        WorldSize size; 
    public: 
        Organism* grid[ROW][COLUMN]; //idea from office hours that made it easier
        Area(WorldSize size_): timeStepCount(1), size(size_){
            for(int rows = 0; rows < size.getRows(); rows++){
                for(int columns = 0; columns < size.getColumns(); columns++){
                    grid[rows][columns] = nullptr; //
                }
            }
        }
        //constructors
        //World(): totalAnts(numAnts), totalDoodlebugs(numDoodlebugs), timeStepCount(0) {this->initalize();}
        //World(int doodlebugCount, int antCount): totalDoodlebugs(doodlebugCount), timeStepCount(0), totalAnts(antCount){this->initalize();
        bool startPlay(); 
        void initalize(){
            initalizeAnts();
            initalizeDoodle(); 
        } //initialize grid and ranomly positions the organisms 
        void printWorld(); //prints the objects, empty spaces(characters) 
        void nextGame(); 
        WorldSize getSize(){return size;}
        virtual ~Area(); //destructor
};

class Ant: public Organism{
    public: 
        Ant(Area* world_, int row_, int column_){// area(world_), posRow(row_), posColumn(column_), orgLife(0), breedTime(0){}
            area = world_;
            posRow = row_;
            posColumn = column_;
            orgLife = 0;
            breedTime = 0; 
        }
    int getType()const override{return ant; }
    void breed() override;         
}; 


class Doodlebug: public Organism{
    public: 
        int feedingSteps; //the amount of times doodlebugs are eating and their steps
        Doodlebug(Area* world_, int row_, int column_){
            area = world_;
            posRow = row_;
            posColumn = column_; 
            feedingSteps = 0; 
            orgLife = 0;
            breedTime = 0;
        }
        int getType()const override {return doodlebug;}
        void breed() override; 
        void move() override; 
        bool starving()const override{return feedingSteps >= dbStarve; }
};

struct Coordinate{
   // public:
        int row; 
        int column;
}; 

int main(){
    srand(time(0)); 
    printBoard({ROW, COLUMN});
    return 0; 
}

//Organism::Organism() {}

//Organism::~Organism() {}

//functions: 
void printBoard(WorldSize size){
    Area area(size); 
//checks if all the game settings we have doesnt affect the start of the game
    srand(time(NULL)); 
    if(area.startPlay()){
        area.initalize(); 
        area.printWorld();
    }
}

int randomNum(int num, int lowerbound){
    return(rand() % num) + lowerbound; //takes a random num in range of zero index to n
}

bool Area::startPlay(){
    if(size.cellLimit() < numAnts){
        cout<<"Error: "<<numAnts<<" is greater than cell limit ("<<size.getRows()<<" * "<<size.getColumns()
        <<" = "<<size.cellLimit()<<")";
        return false; 
    }
    else if(size.cellLimit() < numDoodlebugs){
        cout<<"Error: "<<numDoodlebugs<<" is greater than cell limit ("<<size.getRows()<<" * "<<size.getColumns()
        <<" = "<<size.cellLimit()<<")";
        return false; 
    }
    else{
        return true; 
    }
}

void Area::printWorld() {
    cout<<"Game: "<<timeStepCount++<<endl; 

    for(int row = 0; row<size.getRows(); row++){
        for(int col = 0; col < size.getColumns(); col++){
            if(grid[row][col] != nullptr){
                if(grid[row][col] -> getType() == ant){ 
                    cout<<antChar;
                }else if(grid[row][col] -> getType() == doodlebug){
                    cout<<doodlebugChar; 
                }
            }
            else{
                cout<<space; 
                }
            if(col != size.getRows() - 1){
                    cout<<" "; 
                }
            }
            cout<<endl;
        }
    cout<<endl;
    cout<<"Press enter to move to the next step, or any other key to stop the simulation.";

    char tempo; 
    cin.get(tempo); 

    if(tempo != '\n'){
        cout<<endl; 
        cout<<"Game stopped"<<endl;
            exit(1);
        }
    else{
        cout<<endl;
        nextGame(); 
    }
}
void Area::initalizeAnts(){
    int ants = 0; 
    while (ants < numAnts) {
        int row = randomNum(size.getRows());
        int column = randomNum(size.getColumns());

        if (grid[row][column] == nullptr) {
            grid[row][column] = new Ant(this, row, column);
            ants++;
        }
    }
}

void Area::initalizeDoodle(){
    int doodleb = 0; 
    while (doodleb < numDoodlebugs)
    {
        int row = randomNum(size.getRows());
        int column = randomNum(size.getColumns());
        if (grid[row][column] == nullptr) {
            grid[row][column] = new Doodlebug(this, row, column);
            doodleb++;
        }
    }
}

void Area::nextGame(){
    //moves doodles, checks them for starve or breed, moves ants, checks ants for breed, checks if game is valid
    //this moves the doodlebugs after hitting enter again
    for(int row = 0; row < size.getColumns(); row++){
        for(int col = 0; col < size.getRows(); col++){
            if(grid[row][col] != nullptr){
                if(grid[row][col] -> getType() == doodlebug){
                    grid[row][col] -> move(); 
                }
            }
        }
    }
    //this moves the ants
    for(int row = 0; row < size.getColumns(); row++){
        for(int col = 0; col < size.getRows(); col++){
            if(grid[row][col] != nullptr){
                if(grid[row][col] -> getType() == ant){
                    grid[row][col] -> move(); 
                }
            }
        }
    }
    //breeds
    for (int row = 0; row < size.getColumns(); row++) {
        for (int col = 0; col < size.getRows(); col++) {
            if (grid[row][col] != nullptr) {
                grid[row][col]->breed();
            }
        }
    }
    //the starving doodlebugs die if they havent eaten yet
    for (int row = 0; row < size.getColumns(); row++) {
        for (int col = 0; col < size.getRows(); col++) {
            if(grid[row][col] != nullptr){
                if(grid[row][col] -> getType() == doodlebug){
                   grid[row][col] -> starving(); 
                }
            }
        }
    }
    printWorld();
}

Area::~Area(){
    for(int row = 0; row < size.getColumns(); row++){
        for(int col = 0; col < size.getRows(); col++){
                grid[row][col] = nullptr;
        }
    }
}

void Organism::move(){
    int direction = randomNum(directions, 1); 
    int newRow = posRow;
    int newCol = posColumn;
    ++orgLife; 
    ++breedTime; 
    updateCoord(direction, newRow, newCol); 

    if(inWorld(newRow, newCol)){
        if (area-> grid[newRow][newCol] == nullptr) {
            area-> grid[newRow][newCol] = this;
            area-> grid[posRow][posColumn] = nullptr;
            posRow = newRow;
            posColumn = newCol;
        }else {
            return;
        }
    } 
}

void Doodlebug::move(){
    //update doodlebug position
    int newRow = posRow;
    int newColumn = posColumn;
    int direction = randomNum(directions, 1);

    ++orgLife;
    ++breedTime;
    ++feedingSteps;
    updateCoord(direction, newRow, newColumn);

    //look for adjacent ants 
    vector<Coordinate> nextAnts;
    for (int i = 1; i <= directions; i++) {
        int _row = posRow;
        int _column = posColumn;

        updateCoord(i, _row, _column);

        if (inWorld(_row, _column) && (area->grid[_row][_column] != nullptr) && (area->grid[_row][_column]->getType() == ant)) {
            nextAnts.push_back({ _row, _column });
        }
    }
    //If ants are nearby eat one and move 
    if (!nextAnts.empty()) {
        int randomPlace = randomNum(nextAnts.size(),0);

        area->grid[nextAnts[randomPlace].row][nextAnts[randomPlace].column] = this;
        area->grid[posRow][posColumn] = nullptr;
        posRow = nextAnts[randomPlace].row;
        posColumn = nextAnts[randomPlace].column;
        feedingSteps = 0;
    }
    else {
        //we move to the next free adjacent grid/cell
        if (inWorld(newRow, newColumn)) {
            if (area->grid[newRow][newColumn] == nullptr) {
                area->grid[newRow][newColumn] = this;
                area->grid[posRow][posColumn] = nullptr;
                posRow = newRow;
                posColumn = newColumn; //might need to change
            }
        }
    }
}

void Ant::breed(){
    vector<Coordinate> nextCells = {
        { posRow,     posColumn - 1 }, // Up
        { posRow,     posColumn + 1 }, // Down
        { posRow - 1, posColumn }, // Left
        { posRow + 1, posColumn } // Right
    };

    if (breedTime >= antBreed) {
        // Purges vector of coordinates not in world
        for (int i = 0; i < nextCells.size(); i++) {
            if (!inWorld(nextCells[i].row, nextCells[i].column)) {
                nextCells.erase(nextCells.begin() + i);
            }
        }
        for (Coordinate nextCell : nextCells) {
            if (area-> grid[nextCell.row][nextCell.column] == nullptr) {
                area-> grid[nextCell.row][nextCell.column] = new Ant(area, nextCell.row, nextCell.column);
                breedTime = 0;
                break;
            }
        }
    }
}

/*void Ant::breed() {
    const vector<Coordinate> directions = {
        { posRow,     posColumn - 1 }, // Up
        { posRow,     posColumn + 1 }, // Down
        { posRow - 1, posColumn }, // Left
        { posRow + 1, posColumn } // Right
    };

    if (breedTime < antBreed) {
        return;
    }

    vector<Coordinate> availableDirections;
        for (const auto& dir : directions) {
            const int row = posRow + dir.row;
            const int col = posColumn + dir.column;
            if (inWorld(row, col) && area->grid[row][col] == nullptr) {
            availableDirections.push_back({ row, col });
        }
    }

    if (availableDirections.empty()) {
        return;
    }

    const Coordinate& targetDirection = availableDirections[rand() % availableDirections.size()];
    area->grid[targetDirection.row][targetDirection.column] = new Ant(area, targetDirection.row, targetDirection.column);
    breedTime = 0;
}*/

void Doodlebug::breed(){
     vector<Coordinate> nextCells = {
            { posRow,     posColumn - 1 }, // Up
            { posRow,     posColumn + 1 }, // Down
            { posRow - 1, posColumn }, // Left
            { posRow + 1, posColumn } // Right
    };

    if (breedTime >= dbBreed) {
        for (int i = 0; i < nextCells.size(); i++) {
            // Purges vector of coordinates not in world
            if (!inWorld(nextCells[i].row, nextCells[i].column)) {
                nextCells.erase(nextCells.begin() + i); 
            }
        }
        for (Coordinate nextCell : nextCells) {
            if (area->grid[nextCell.row][nextCell.column] == nullptr) {
                area->grid[nextCell.row][nextCell.column] = new Doodlebug(area, nextCell.row, nextCell.column);
                breedTime = 0;
                break;
            }
        }
    }
}
/*void Doodlebug::breed() {
    const vector<Coordinate> directions = {
        { posRow,     posColumn - 1 }, // Up
        { posRow,     posColumn + 1 }, // Down
        { posRow - 1, posColumn }, // Left 
        { posRow + 1, posColumn } 
    };

    if (breedTime < dbBreed) {
        return;
    }

    vector<Coordinate> availableDirections;
    for (const auto& dir : directions) {
        const int row = posRow + dir.row;
        const int col = posColumn + dir.column;
        if (inWorld(row, col) && area->grid[row][col] == nullptr) {
            availableDirections.push_back({ row, col });
        }
    }

    if (availableDirections.empty()) {
        return;
    }

    const Coordinate& targetDirection = availableDirections[rand() % availableDirections.size()];
    area->grid[targetDirection.row][targetDirection.column] = new Doodlebug(area, targetDirection.row, targetDirection.column);
    breedTime = 0;
} */
//check to see if it 
bool Organism:: inWorld(int row, int column){
    return((row >= 0) && (row < area ->getSize().getColumns()) && (column >= 0) && (column < area -> getSize().getRows()));
}

void Organism::updateCoord(int direction, int& row, int& column) {
    //int direction = rand() % 
    switch (direction) {
        case moveUp:
            row--;
            break;
        case moveDown:
            row++;
            break;
        case moveLeft:
            column--;
            break;
        case moveRight:
            column++;
            break;
        default:
            break; 
    }
}