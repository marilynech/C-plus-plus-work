//brute force 
//backtrack to column -1 means we cannot move anymore can only move down
//we cannot check if its a position on the board can we move right? -1 is not a valid column so cannot move right
//can we backtrack also no. We're just stuck there and end the program we already finished checking everything 
//means we're done, 

//for chest board we use 2D array 64 positions but waste our memory space bc we need to allocate 64 spots in memeory
//but among 64 spots only 8 spots that we put the queen there are important to us. 