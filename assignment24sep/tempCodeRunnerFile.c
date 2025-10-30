#include<stdio.h>
//this function check if each sub 3x3 grid hs sum eqaul to 45 or not
int sub_sdku_check(int sdku[9][9], int ia, int ib, int ja, int jb){
    int sub_grid_validator = 0;     
    for(int i = ia; i < ib; i++){    
        for(int j = ja; j < jb; j++){   
            sub_grid_validator += sdku[i][j];
        }   
    }    
    if(sub_grid_validator == 45) return 1;
    else return 0;          
}          
                        
int main(){                    
    int sdku[9][9];            
    int count = 0;             
    //this loops takes input of sudoku and also at the same time check if each element is less than 9
    // or not                               
    for(int i = 0; i < 9; i++){            
        for(int j = 0; j < 9; j++){         
            scanf("%d", &sdku[i][j]);         
            if(sdku[i][j] > 9){             
                printf("Invalid Sudoku");         
                return 0;      
            } 
        }
    }        
    // these loops check if each row and each column and sum eqaul to 45 or not                           
    for(int i = 0; i < 9; i++){              
        int row_validator = 0;          
        for(int j = 0; j < 9; j++){          
            row_validator += sdku[i][j];       
        }               
        if(row_validator  == 45){ count++; }         
    }               

    for(int j = 0; j < 9; j++){
        int col_validator = 0;
        for(int i = 0; i < 9; i++){
            col_validator += sdku[i][j];
        }
        if(col_validator == 45){ count++; }    
    }
// check each subgring woth help of the function written above
    count += sub_sdku_check(sdku, 0, 3, 0, 3);
    count += sub_sdku_check(sdku, 0, 3, 3, 6);
    count += sub_sdku_check(sdku, 0, 3, 6, 9);
    count += sub_sdku_check(sdku, 3, 6, 0, 3);
    count += sub_sdku_check(sdku, 6, 9, 0, 3);
    count += sub_sdku_check(sdku, 3, 6, 3, 6);
    count += sub_sdku_check(sdku, 3, 6, 6, 9);
    count += sub_sdku_check(sdku, 6, 9, 3, 6);
    count += sub_sdku_check(sdku, 6, 9, 6, 9);

// if all the above checks passes then count would have be eqaul to 27
//so this function checks if all checks are passed or not 
//if all the checks are passed then its sure that that will be a valid sudoku 
// because i have constraints like 
//1. all elements less than 9 
//2. if all column element sun is equal to 45
//3. if all rows elements sum is equal to 45
//4. if all sub grids have sum of there elements equal to 45 or not 
//5. i can have checked for duplicate element in row,column and sub grids but if there 
//   is any duplicate element it will fail ahead in some other test for sure so
//   checcking for duplicate was not required
    if(count == 27){ printf("Valid Sudoku");}
    else {printf("Invalid Sudoku");}

    return 0;
}