#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
using namespace std ;

vector <int> path ;
stack < pair<int, int> > sta ;


void** newmatrix(int h, int w, int size) {
    int i;
    void **p;

    p = (void**) new int [h*sizeof(void*) + h*w*size] ;
    for(i = 0; i < h; i++)
        p[i] = ((int*)(p + h)) + i*w*size ;
    return p ;
}

void distance(int **dist, int x, int y, int n, int m){
    int i, j ;
    int a, b ;
    bool visited[n+2][m+2] ;
    queue<int> que ;
    for(i=1;i<=n;i++) {
        for (j=1; j<=m; j++) {
            visited[i][j] = false ;
        }
    }
    que.push(x); que.push(y) ;
    visited[x][y] = true ;
    //dir[x][y] = 'o' ;
    //dir[x-1][y] = 'l' ; dir[x+1][y] = 'r' ; dir[x][y+1] = 'u' ; dir[x][y-1] = 'd' ;
    while(!que.empty()){
        x = que.front() ; que.pop() ;
        y = que.front() ; que.pop() ;
        pair <int, int> p (x,y);
        sta.push(p) ;
        a = x-1 ; b = y ;
        if (dist[a][b]==0 && visited[a][b]==false) {
            que.push(a) ; que.push(b) ; visited[a][b] = true ;
            dist[a][b] = dist[x][y]+1 ;
            //if (dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
        }
        a = x+1 ; b = y ;
        if (dist[a][b]==0 && visited[a][b]==false) {
            que.push(a) ; que.push(b) ; visited[a][b] = true ;
            dist[a][b] = dist[x][y]+1 ;
            //if (dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
        }
        a = x ; b = y-1 ;
        if (dist[a][b]==0 && visited[a][b]==false) {
            que.push(a) ; que.push(b) ; visited[a][b] = true ;
            dist[a][b] = dist[x][y]+1 ;
            //if (dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
        }
        a = x ; b = y+1 ;
        if (dist[a][b]==0 && visited[a][b]==false) {
            que.push(a) ; que.push(b) ; visited[a][b] = true ;
            dist[a][b] = dist[x][y]+1 ;
            //if (dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
        }
    }
}

void run (int **dist, int x, int y, int n, int m) {
    int i, j ;
    int a, b, d ;
    bool visited[n+2][m+2] ;

    for(i=1;i<=n;i++) {
        for (j=1; j<=m; j++) {
            visited[i][j] = false ;
        }
    }
    while (!sta.empty()) {
        pair <int, int> p ;
        vector <int> road ;
        p = sta.top() ; sta.pop() ;
        a = p.first; b = p.second ;
        if (visited[a][b] == false) {
            road.push_back(a) ; road.push_back(b) ;
            while (dist[a][b] != 0) {
                if (dist[a][b-1] !=-1 && dist[a][b-1]<dist[a][b]) {
                    b-- ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
                else if (dist[a+1][b] !=-1 && dist[a+1][b]<dist[a][b]) {
                    a++ ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
                else if (dist[a][b+1] !=-1 && dist[a][b+1]<dist[a][b]) {
                    b++ ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
                else if (dist[a-1][b] !=-1 && dist[a-1][b]<dist[a][b]) {
                    a-- ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
            }
            for (int i=road.size(); i>0; i-=2) {
                path.push_back(road[i-2]) ;
                path.push_back(road[i-1]) ;
            }
            for (int i=2; i<road.size(); i+=2) {
                path.push_back(road[i]) ;
                path.push_back(road[i+1]) ;
            }
            road.clear() ;
        }
    }
}

int main( int argc, char*argv[] ) {
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    if (argc != 2) {                
        cout << "Input error!\n" ;
        return 1 ;
    }
    string id(argv[1]) ;

    ifstream infile("./" + id + "/floor.data") ;
    ofstream outfile("./" + id + "/final.path") ;
    if (!infile) {
        cout << "Can not open file!\n" ;
        return 1 ;
    }

    int Col, Row, battery ;
    int r1, r2 ;
    char x ;

    infile >> Row ;
    infile >> Col ;
    infile >> battery ;

    int **dist = (int**) newmatrix(Row+2, Col+2, sizeof(int)) ;
    int **dir  = (int**) newmatrix(Row+2, Col+2, sizeof(int)) ;
    for (int j=1; j<=Col; j++) {
        dist[0][j] = -1 ;
        dist[Row+1][j] = -1 ;
    }
    for (int i=1; i<=Row; i++) {
        dist[i][0] = -1 ;
        for (int j=1; j<=Col; j++) {
            infile >> x ;
            if (x == '1')
                dist[i][j] = -1 ;
            else if (x == '0') {
                dist[i][j] = 0 ;
            }
            else if (x == 'R'){
                r1 = i ;
                r2 = j ;
                dist[i][j] = 0 ;
            }
        }
        dist[i][Col+1] = -1 ;
    }
    distance(dist, r1, r2, Row, Col) ;
    run (dist, r1, r2, Row, Col) ;
    outfile << path.size()/2 << "\n" ;
    for (int i=0; i<path.size(); i+=2) {
        outfile << path[i] << " " << path[i+1] << "\n" ;
    }

    delete [] dist ;
    return 0 ;
}
