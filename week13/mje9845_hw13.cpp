//dooodlebug and ant program
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std; 
//world is initialized with 5 predators and 100 prey, Each time you press enter
//a segment of time passes. 
const int numAnts = 100; 
const int numDoodlebugs = 5; 
const int ROW = 20;//like width
const int COLUMN = 20; //our height
const int WORLD = 20; 
//the types we have 
const int doodlebug = 0; 
const int ant = 1; 
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
class WorldSize; 
class Ant; 
class Doodelbug; 
struct Coordinate; 
//functions
void boardGenerator(WorldSize size); 
int randomNum(int n, int lowerbound = 0); //=0); 
//classes: 
class Organism{
    protected: //so we can use for ant and doodlebug classes but mot used in main 
        Area* area; 
        int posRow, posColumn; 
        int breedTime; 
        int orgLife; 
        bool inWorld(int row, int column); 
        void updateCoord(int direction, int& row, int& column); //get the cell its in
    public:
        //Organism(): world(nullptr), posRow(0), posColumn(0), breedTime(0), orgLife(0){}
        virtual int getType() = 0; 
        virtual void move();
        virtual void breed() = 0; 
        virtual bool starving() {return false;}; 
    
};

class WorldSize{ //set the environment of the grid and its limits 
    private: 
        int rows, columns; 
    public:
        int cellLimit()const{return rows * columns;}
        WorldSize(): rows(ROW),columns(COLUMN){}//row =20 columns =20
        WorldSize(int rows_, int columns_): rows(rows_),columns(columns_){}
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
        void nextGame();  
        void initalize(){
            initalizeAnts();
            initalizeDoodle(); 
        } //initialize grid and ranomly positions the organisms 
        void printWorld(); //prints the objects, empty spaces(characters)
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
    void breed() override;
    int getType()override{return ant;}       
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
        } //override from the base class organism from virtual functions 
        int getType() override {return doodlebug;} //returns doodlebug =1 
        void move() override; 
        void breed() override; 
        bool starving() override{return dbStarve <= feedingSteps;}
};

struct Coordinate{
   // public:
        int row; 
        int column;
}; 

int main(){
    boardGenerator({ROW, COLUMN}); //takes care of the game play 
    return 0; 
}
//functions: 
void boardGenerator(WorldSize size){
    Area area(size); 
//checks if all the game settings we have doesnt affect the start of the game
    srand(time(NULL)); 
    if(area.startPlay()){
        area.initalize(); 
        area.printWorld();
    }
}

int randomNum(int n, int lowerbound) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(nullptr));
        initialized = true;
    }
    return rand() % n + lowerbound;
}

bool Area::startPlay(){//if area is in bound start play 
    if(size.cellLimit() < numAnts){
        return false; 
    }
    else if(size.cellLimit() < numDoodlebugs){
        return false; 
    }
    else{
        return true; 
    }
}

void Area::printWorld(){
    cout<<"Game Number: "<<timeStepCount++<<endl; 

    for(int row = 0; row<size.getRows(); row++){
        for(int col = 0; col < size.getColumns(); col++){
            if(grid[row][col] != nullptr){
                if(grid[row][col] -> getType() == ant){ //if its 0 return ant char
                    cout<<antChar;
                }else if(grid[row][col] -> getType() == doodlebug){ //if 1 return doodlebug char
                    cout<<doodlebugChar; 
                }
            }
            else{
                cout<<space; //else return space char
                }
            if(col != size.getRows() - 1){
                    cout<<" "; 
                }
            }
            cout<<endl;
        }
    cout<<endl;
    cout<<"Press enter to move to the next game, or another key to stop the game.";

    string input;
    getline(cin, input);

    if (!input.empty()) {
        cout << endl;
        cout << "Game stopped" << endl;
        exit(1);
    }
    else {
        cout << endl;
        nextGame();
    }
}

void Area::initalizeAnts(){
    int ants = 0; 
    while (ants < numAnts) {
        int i = randomNum(size.getRows());
        int j = randomNum(size.getColumns());

        if (grid[i][j] == nullptr) {
            grid[i][j] = new Ant(this, i, j);
            ants++;
        }
    }
}

void Area::initalizeDoodle(){
    int doodleb = 0; 
    while (doodleb < numDoodlebugs)
    {
        int i = randomNum(size.getRows());
        int j = randomNum(size.getColumns());
        if (grid[i][j] == nullptr) {
            grid[i][j] = new Doodlebug(this,i,j);
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
    //the starving doodlebugs die if they havent eaten yet
    for (int row = 0; row < size.getColumns(); row++) {
        for (int col = 0; col < size.getRows(); col++) {
            if(grid[row][col] != nullptr){
                if(grid[row][col] -> getType() == doodlebug && grid[row][col]->starving()){
                    grid[row][col] = nullptr;
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
        Organism* target = area -> grid[newRow][newCol];
        if(target == nullptr){
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
    int direction = randomNum(directions, 1);
    int newRow = posRow, newColumn = posColumn;
    updateCoord(direction, newRow, newColumn);

    ++orgLife;
    ++breedTime;
    ++feedingSteps;

    //look for adjacent ants that are next 
    vector<Coordinate> nextAnts;
    for (int dir = 1; dir <= directions; dir++) {
        int _row = posRow;
        int _column = posColumn;

        updateCoord(dir, _row, _column);

        bool isAntsNextPosition = (inWorld(_row, _column)
            && area->grid[_row][_column] != nullptr
            && (area->grid[_row][_column]->getType() == ant));
        if(isAntsNextPosition){
            nextAnts.push_back({_row, _column});
        }
    }
    //If the next ants exist eat one and move to the place that ant is in
    if (!nextAnts.empty()) {
        int randomPlace = randomNum(nextAnts.size());
        //Coordinate randomAntPos = nextAnts(randomNum);

        area->grid[nextAnts[randomPlace].row][nextAnts[randomPlace].column] = this;
        area->grid[posRow][posColumn] = nullptr;
        posRow = nextAnts[randomPlace].row;
        posColumn = nextAnts[randomPlace].column;
        feedingSteps = 0;//reset feeding steps to 0 since ant moved 
    }
    else {
        //we move to the next free grid/cell
        if (inWorld(newRow, newColumn)) {
            Organism* target = area -> grid[newRow][newColumn];
                if(target == nullptr){
                area->grid[newRow][newColumn] = this;
                area->grid[posRow][posColumn] = nullptr;
                posRow = newRow;
                posColumn = newColumn; //
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


void Ant::breed(){
    vector<Coordinate> targetDirection = {
            { posRow,     posColumn - 1 }, 
            { posRow,     posColumn + 1 }, 
            { posRow - 1, posColumn }, 
            { posRow + 1, posColumn } 
    };

    if (breedTime >= antBreed) {
        // Purges vector of coordinates not in world
        for (int i = 0; i < targetDirection.size(); i++) {
            if (!inWorld(targetDirection[i].row, targetDirection[i].column)) {
                targetDirection.erase(targetDirection.begin() + i);
            }
        }
        for (Coordinate nextCell : targetDirection) {
            if (area-> grid[nextCell.row][nextCell.column] == nullptr) {
                area-> grid[nextCell.row][nextCell.column] = new Ant(area, nextCell.row, nextCell.column);
                breedTime = 0;
                break;
            }
        }
    }
}

void Doodlebug::breed(){
     vector<Coordinate> targetDirection = {
            { posRow,     posColumn - 1 }, // Up
            { posRow,     posColumn + 1 }, // Down
            { posRow - 1, posColumn }, // Left
            { posRow + 1, posColumn } // Right
    };

    if (breedTime >= dbBreed) {
        /*targetDirection.erase(
            std::remove(targetDirection.begin(), targetDirection.end(),
                [this](const Coordinate& c){return !inWorld(c.row, c.column); }, targetDirection.end()); 
        )*/
        for (int i = 0; i < targetDirection.size(); i++) {
            // Purges vector of coordinates not in world
            if (!inWorld(targetDirection[i].row, targetDirection[i].column)) {
                targetDirection.erase(targetDirection.begin() + i); 
            }
        }
        //breeds in target position or next cell 
        for (const Coordinate& nextCell : targetDirection) {
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


//check to see if it is in bounds or not
bool Organism::inWorld(int row, int col){
    if(row < 0 || row >= WORLD|| col < 0 || col >= WORLD)
        return false;
    return true;  
}
//updates spots based on which case of direction 
void Organism::updateCoord(int direction, int& row, int& column) {
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