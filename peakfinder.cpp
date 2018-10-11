#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std ;
vector <int> peak ;

void** newmatrix(int h, int w, int size)
{
    int i;
    void **p;

    p = (void**) new int [h*sizeof(void*) + h*w*size] ;
    for(i = 0; i < h; i++)
        p[i] = ((int*)(p + h)) + i*w*size ;
    return p ;
}

void findpeak(int** data, int row, int col) {
    int i, j ;

    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            if (i>0) {
                if (data[i][j]<data[i-1][j])
                    continue ;
            }
            if (i<row-1) {
                if (data[i][j]<data[i+1][j])
                    continue ;
            }
            if (j>0) {
                if (data[i][j]<data[i][j-1])
                    continue ;
            }
            if (j<col-1) {
                if (data[i][j]<data[i][j+1])
                    continue ;
            }
            peak.push_back(i+1) ;
            peak.push_back(j+1) ;
        }
    }        
}

int main( int argc, char*argv[] ) {
    //lock_t t;
    //int f;
    //t = clock();

    if (argc != 2) {
        cout << "Input error!\n" ;
        return 1 ;
    }
    string path1 = "/matrix.data" ;
    string path2 = "/final.peak" ;
    path1 = argv[1] + path1 ;
    path2 = argv[1] + path2 ;
    const char *command1 = path1.c_str() ;
    const char *command2 = path2.c_str() ;
    ifstream infile(command1) ;
    ofstream outfile(command2) ;
    if (!infile) {
        cout << "Can not open file!\n" ;
        return 1 ;
    }

    int row, col, x ;
    infile >> row ;
    infile >> col ;

    int **data = (int **)newmatrix(row, col, sizeof(int)) ;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            infile >> x ;
            data[i][j] = x ;
        }
    }
    findpeak(data, row, col) ;

    outfile << peak.size()/2 << endl ;
    for (int i=0; i<peak.size(); i=i+2) {
        outfile << peak[i] << " " << peak[i+1] << endl ;
    }

    delete [] data ;

    //t = clock() - t;
    //cout << (float)t/CLOCKS_PER_SEC << "seconds" ;

    return 0 ;
}
