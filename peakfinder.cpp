#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include <ctime>
using namespace std ;
vector <int> peak ;

void* newmatrix(int h, int w, int size)
{
    int i;
    void **p;

    p =  (void**) new int [h*sizeof(void*) + h*w*size] ;
    for(i = 0; i < h; i++)
        p[i] = ((int*)(p + h)) + i*w*size ;
    return p ;
}

void findpeak(int** data, int row, int col) {
    for (int j=0; j<col; j++) {
        if (j>0) { 
            if (data[row%3][j]<data[row%3][j-1])
                continue ;
        }
        if (j<col-1) { 
            if (data[row%3][j]<data[row%3][j+1])
                continue ;
        }      
        if (data[row%3][j]<data[(row+1)%3][j])
            continue ;         
        if (data[row%3][j]<data[(row+2)%3][j])
            continue ;
        peak.push_back(row+1) ;
        peak.push_back(j+1) ;   
    }
}

int main( int argc, char*argv[] ) {
    //clock_t t;
    //int f;
    //t = clock();

    if (argc != 2) {
        cout << "Input error!\n" ;
        return 1 ;
    }
    string id(argv[1]) ;

    ifstream infile(id + "/matrix.data") ;
    ofstream outfile(id + "/final.peak") ;
    if (!infile) {
        cout << "Can not open file!\n" ;
        return 1 ;
    }

    int row, col, x ;
    infile >> row ;
    infile >> col ;

    int **data = (int**) newmatrix(3, col, sizeof(int)) ;
    for (int j=0; j<col; j++) {
        infile >> x ;
        data[0][j] = x ;
    }  

    if (row == 1) {
        for (int j=0; j<col; j++) {
            if (j>0) {                         //左
                if (data[0][j]<data[0][j-1])
                    continue ;
            }
            if (j<col-1) {                     //右
                if (data[0][j]<data[0][j+1])
                    continue ;
            }
            peak.push_back(1) ;
            peak.push_back(j+1) ;
        }
    }
    else if (row == 2) {
        for (int j=0; j<col; j++) {
            infile >> x ;
            data[1][j] = x ;
        }
        for (int i=0; i<2; i++) {
            for (int j=0; j<col; j++) {
                if (i>0) {                         //上
                    if (data[i][j]<data[i-1][j])
                        continue ;
                }
                if (j>0) {                         //左
                    if (data[i][j]<data[i][j-1])
                        continue ;
                }
                if (i<row-1) {                     //下
                    if (data[i][j]<data[i+1][j])
                        continue ;
                }
                if (j<col-1) {                     //右
                    if (data[i][j]<data[i][j+1])
                        continue ;
                }
                peak.push_back(i+1) ;
                peak.push_back(j+1) ;
            }
        }        
    }
    else {
        for(int i=1; i<row; i++){
            for(int j=0; j<col; j++){
                infile >> x ;
                data[i%3][j] = x ;
            }
            findpeak(data, i-1, col) ;
        }
        findpeak(data, row, col) ;
    }

    outfile << peak.size()/2 << endl ;
    for (int i=0; i<peak.size(); i=i+2) {
        outfile << peak[i] << " " << peak[i+1] << endl ;
    }

    delete [] data ;

    //t = clock() - t;
    //cout << (float)t/CLOCKS_PER_SEC << "seconds" ;

    return 0 ;
}
