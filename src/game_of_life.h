#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H
#include "structs_and_definitions.h"
int surrounding_cells;

/*
    1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    2. Any live cell with two or three live neighbours lives on to the next generation.
    3. Any live cell with more than three live neighbours dies, as if by overpopulation.
    4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

void count_surrounding_cells(bool sim[][WIDTH], int i, int j){
    surrounding_cells=0;
    for(int w=-1;w<2;w++){
    for(int k=-1;k<2;k++){

    // if it's out of bounds
    if(i+w == WIDTH || j+k == WIDTH || i+w <= 0 || j+k <= 0){
        // don't access the grid
    }



    // if it's the middle cell
    else if(w==0 && k==0){ 
        // don't count it
    }
    else if(sim[i+w][j+k]==1){
        surrounding_cells++;
    }

    }
    }
}

void life(bool sim[][WIDTH], bool aux_sim[][WIDTH], int i, int j){ 
    count_surrounding_cells(sim,i,j);
    
    if(surrounding_cells < 2 || surrounding_cells > 3){
        // kill cell
        aux_sim[i][j]=0;
    }

    if(surrounding_cells == 2 || surrounding_cells == 3 ){
        // do not kill cell
        aux_sim[i][j]=1;

    }
}

void death(bool sim[][WIDTH], bool aux_sim[][WIDTH], int i, int j){
    count_surrounding_cells(sim,i,j); 
    if(surrounding_cells == 3){
        aux_sim[i][j]=1;
    }

}

#endif // GAME_OF_LIFE_H