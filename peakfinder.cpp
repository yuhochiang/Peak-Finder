#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std ;
vector <int> peak ;
int Row ;

void* newmatrix(int h, int w, int size) {
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
        if (row != Row-1) {
            if (data[row%3][j]<data[(row+1)%3][j])
            continue ;
        }
        if (row != 0) {
            if (data[row%3][j]<data[(row+2)%3][j])
            continue ;
        }         
        peak.push_back(row+1) ;
        peak.push_back(j+1) ;
    }
}

int main( int argc, char*argv[] ) {

    if (argc != 2) {
        cout << "Input error!\n" ;
        return 1 ;
    }
    string id(argv[1]) ;

    ifstream infile("./" + id + "/matrix.data") ;
    ofstream outfile("./" + id + "/final.peak") ;
    if (!infile) {
        cout << "Can not open file!\n" ;
        return 1 ;
    }

    int Col, x ;
    infile >> Row ;
    infile >> Col ;

    int **data = (int**) newmatrix(3, Col, sizeof(int)) ;
    for (int j=0; j<Col; j++) {
        infile >> x ;
        data[0][j] = x ;
    }  

    if (Row == 1) {
        for (int j=0; j<Col; j++) {
            if (j>0) {                         //左
                if (data[0][j]<data[0][j-1])
                    continue ;
            }
            if (j<Col-1) {                     //右
                if (data[0][j]<data[0][j+1])
                    continue ;
            }
            peak.push_back(1) ;
            peak.push_back(j+1) ;
        }
    }
    else if (Row == 2) {
        for (int j=0; j<Col; j++) {
            infile >> x ;
            data[1][j] = x ;
        }
        for (int i=0; i<2; i++) {
            for (int j=0; j<Col; j++) {
                if (i>0) {                         //上
                    if (data[i][j]<data[i-1][j])
                        continue ;
                }
                if (j>0) {                         //左
                    if (data[i][j]<data[i][j-1])
                        continue ;
                }
                if (i<Row-1) {                     //下
                    if (data[i][j]<data[i+1][j])
                        continue ;
                }
                if (j<Col-1) {                     //右
                    if (data[i][j]<data[i][j+1])
                        continue ;
                }
                peak.push_back(i+1) ;
                peak.push_back(j+1) ;
            }
        }        
    }
    else {
        for(int i=1; i<Row; i++){
            for(int j=0; j<Col; j++){
                infile >> x ;
                data[i%3][j] = x ;
            }
            findpeak(data, i-1, Col) ;
        }
        findpeak(data, Row-1, Col) ;
    }

    outfile << peak.size()/2 << "\n" ;
    for (int i=0; i<peak.size(); i=i+2) {
        outfile << peak[i] << " " << peak[i+1] << "\n" ;
    }

    delete [] data ;
    return 0 ;
}
