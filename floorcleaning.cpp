#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
using namespace std ;

void turn (int **dist, char ** dir, int a, int b, char dir1, char dir2) ;
void another_road (int **dist, char **dir, int a, int b, char d) ;
int c1, c2 ;
vector <int> path ;
vector <int> road ;
stack < pair<int, int> > sta[4] ;
int ur[3] = {0} ; int rd[3] = {0} ; int dl[3] = {0} ;
int lu[3] = {0} ; int ud[3] = {0} ; int rl[3] = {0} ;

void** newmatrix(int h, int w, int size) {
    int i;
    void **p;

    p = (void**) new int [h*sizeof(void*) + h*w*size] ;
    for(i = 0; i < h; i++)
        p[i] = ((int*)(p + h)) + i*w*size ;
    return p ;
}

void distance(int **dist, char **dir, int x, int y, int n, int m){
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
    dir[x][y] = 'o' ;
    if (dist[x-1][y]!=-1) dir[x-1][y] = 'u' ;
    if (dist[x+1][y]!=-1) dir[x+1][y] = 'd' ;
    if (dist[x][y+1]!=-1) dir[x][y+1] = 'r' ;
    if (dist[x][y-1]!=-1) dir[x][y-1] = 'l' ;
    while(!que.empty()){
        int x = que.front() ; que.pop() ;
        int y = que.front() ; que.pop() ;
        pair <int, int> p (x,y);
        if (dir[x][y]=='u') sta[0].push(p) ;
        if (dir[x][y]=='r') sta[1].push(p) ;
        if (dir[x][y]=='d') sta[2].push(p) ;
        if (dir[x][y]=='l') sta[3].push(p) ;
        a = x-1 ; b = y ;
        if (visited[a][b]==false) {
            if (dist[a][b]==0) {
                que.push(a) ; que.push(b) ; visited[a][b] = true ;
                dist[a][b] = dist[x][y]+1 ;
                if (dir[x][y] != 'o' && dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
            }
        }
        else {
            if (dir[x][y]=='r') {
                if (ur[2]==0 && dir[a][b]=='u') { ur[0]=a ; ur[1]=b ; ur[2]=1 ;}
            }
            else if (dir[x][y]=='d') {
                if (ud[2]==0 && dir[a][b]=='u') { ud[0]=a ; ud[1]=b ; ud[2]=1 ;}
                else if (rd[2]==0 && dir[a][b]=='r') { rd[0]=a ; rd[1]=b ; rd[2]=1 ;}
            }
            else if (dir[x][y]=='l') {
                if (lu[2]==0 && dir[a][b]=='u') { lu[0]=a ; lu[1]=b ; lu[2]=1 ;}
                else if (rl[2]==0 && dir[a][b]=='r') { rl[0]=a ; rl[1]=b ; rl[2]=1 ;}
                else if (dl[2]==0 && dir[a][b]=='d') { dl[0]=a ; dl[1]=b ; dl[2]=1 ;}
            }
        }
        a = x+1 ; b = y ;
        if (visited[a][b]==false) {
            if (dist[a][b]==0) {
                que.push(a) ; que.push(b) ; visited[a][b] = true ;
                dist[a][b] = dist[x][y]+1 ;
                if (dir[x][y] != 'o' && dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
            }
        }
        else {
            if (dir[x][y]=='r') {
                if (ur[2]==0 && dir[a][b]=='u') { ur[0]=a ; ur[1]=b ; ur[2]=1 ;}
            }
            else if (dir[x][y]=='d') {
                if (ud[2]==0 && dir[a][b]=='u') { ud[0]=a ; ud[1]=b ; ud[2]=1 ;}
                else if (rd[2]==0 && dir[a][b]=='r') { rd[0]=a ; rd[1]=b ; rd[2]=1 ;}
            }
            else if (dir[x][y]=='l') {
                if (lu[2]==0 && dir[a][b]=='u') { lu[0]=a ; lu[1]=b ; lu[2]=1 ;}
                else if (rl[2]==0 && dir[a][b]=='r') { rl[0]=a ; rl[1]=b ; rl[2]=1 ;}
                else if (dl[2]==0 && dir[a][b]=='d') { dl[0]=a ; dl[1]=b ; dl[2]=1 ;}
            }
        }
        a = x ; b = y-1 ;
        if (visited[a][b]==false) {
            if (dist[a][b]==0) {
                que.push(a) ; que.push(b) ; visited[a][b] = true ;
                dist[a][b] = dist[x][y]+1 ;
                if (dir[x][y] != 'o' && dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
            }
        }
        else {
            if (dir[x][y]=='r') {
                if (ur[2]==0 && dir[a][b]=='u') { ur[0]=a ; ur[1]=b ; ur[2]=1 ;}
            }
            else if (dir[x][y]=='d') {
                if (ud[2]==0 && dir[a][b]=='u') { ud[0]=a ; ud[1]=b ; ud[2]=1 ;}
                else if (rd[2]==0 && dir[a][b]=='r') { rd[0]=a ; rd[1]=b ; rd[2]=1 ;}
            }
            else if (dir[x][y]=='l') {
                if (lu[2]==0 && dir[a][b]=='u') { lu[0]=a ; lu[1]=b ; lu[2]=1 ;}
                else if (rl[2]==0 && dir[a][b]=='r') { rl[0]=a ; rl[1]=b ; rl[2]=1 ;}
                else if (dl[2]==0 && dir[a][b]=='d') { dl[0]=a ; dl[1]=b ; dl[2]=1 ;}
            }
        }
        a = x ; b = y+1 ;
        if (visited[a][b]==false) {
            if (dist[a][b]==0) {
                que.push(a) ; que.push(b) ; visited[a][b] = true ;
                dist[a][b] = dist[x][y]+1 ;
                if (dir[x][y] != 'o' && dir[a][b] != 'o') dir[a][b] = dir[x][y] ;
            }
        }
        else {
            if (dir[x][y]=='r') {
                if (ur[2]==0 && dir[a][b]=='u') { ur[0]=a ; ur[1]=b ; ur[2]=1 ;}
            }
            else if (dir[x][y]=='d') {
                if (ud[2]==0 && dir[a][b]=='u') { ud[0]=a ; ud[1]=b ; ud[2]=1 ;}
                else if (rd[2]==0 && dir[a][b]=='r') { rd[0]=a ; rd[1]=b ; rd[2]=1 ;}
            }
            else if (dir[x][y]=='l') {
                if (lu[2]==0 && dir[a][b]=='u') { lu[0]=a ; lu[1]=b ; lu[2]=1 ;}
                else if (rl[2]==0 && dir[a][b]=='r') { rl[0]=a ; rl[1]=b ; rl[2]=1 ;}
                else if (dl[2]==0 && dir[a][b]=='d') { dl[0]=a ; dl[1]=b ; dl[2]=1 ;}
            }
        }
    }
}
void run_dir (int **dist, char **dir, bool **visited, int k, int n, int m) {
    while (!sta[k].empty()) {
        pair <int, int> p ;
        p = sta[k].top() ; sta[k].pop() ;
        int a = p.first; int b = p.second ;
        if (visited[a][b] == false) {
            road.push_back(a) ; road.push_back(b) ;
            while (dist[a][b] != 0) {
                if (dist[a][b-1]!=-1&&dist[a][b-1]<dist[a][b]&&(dir[a][b-1]==dir[a][b]||dir[a][b-1]=='o')) {
                    b-- ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
                else if (dist[a+1][b]!=-1&&dist[a+1][b]<dist[a][b]&&(dir[a+1][b]==dir[a][b]||dir[a+1][b]=='o')) {
                    a++ ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
                else if (dist[a][b+1]!=-1&&dist[a][b+1]<dist[a][b]&&(dir[a][b+1]==dir[a][b]||dir[a][b+1]=='o')) {
                    b++ ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
                else if (dist[a-1][b]!=-1&&dist[a-1][b]<dist[a][b]&&(dir[a-1][b]==dir[a][b]||dir[a-1][b]=='o')) {
                    a-- ; visited[a][b] = true ;
                    road.push_back(a) ; road.push_back(b) ;
                }
            }
            for (int i=road.size(); i>0; i-=2) {
                path.push_back(road[i-2]) ;
                path.push_back(road[i-1]) ;
            }
            for (int i=2; i<road.size()-2; i+=2) {
                path.push_back(road[i]) ;
                path.push_back(road[i+1]) ;
            }
            road.clear() ;
        }
    }
}
void run (int **dist, char **dir, bool **visited, int x, int y, int n, int m) {
    //u=0, r=1, d=2, l=3
    int turn_exist[4][4] = {{ !sta[0].empty(), ur[2], ud[2], lu[2] },
                            { ur[2], !sta[1].empty(), rd[2], rl[2] },
                            { ud[2], rd[2], !sta[2].empty(), dl[2] },
                            { lu[2], rl[2], dl[2], !sta[3].empty() } } ;

    if (!sta[0].empty()) {
        run_dir(dist, dir, visited, 0, n, m) ;
        if (turn_exist[0][1]==1 && !sta[1].empty()) {
            turn(dist, dir, ur[0], ur[1], 'u', 'r') ; run_dir(dist, dir, visited, 1, n, m) ;
            if (turn_exist[1][2]==1 && !sta[2].empty()) {
                turn(dist, dir, rd[0], rd[1], 'r', 'd') ; run_dir(dist, dir, visited, 2,n, m) ;
                if (turn_exist[2][3]==1 && sta[3].empty()) {
                    turn(dist, dir, dl[0], dl[1], 'd', 'l') ; run_dir(dist, dir, visited, 3, n, m) ;
                } else if (!sta[3].empty()) {
                    turn(dist, dir, rd[0], rd[1], 'd', 'r') ;
                    if (turn_exist[1][3]==1) turn(dist, dir, rl[0], rl[1], 'r', 'l') ;
                    else turn(dist, dir, ur[0], ur[1], 'r', 'u') ;
                    run_dir(dist, dir, visited, 3, n, m) ;
                }
            }
            else {
                if (turn_exist[1][3]==1 && !sta[3].empty()) {
                    turn(dist, dir, rl[0], rl[1], 'r', 'l') ; run_dir(dist, dir, visited, 3, n, m) ;
                    if (turn_exist[3][2] && !sta[2].empty()) {
                        turn(dist, dir, dl[0], dl[1], 'l', 'd') ; run_dir(dist, dir, visited, 2, n, m) ;
                    }
                    else if (!sta[2].empty()) {
                        turn(dist, dir, rl[0], rl[1], 'l', 'r') ; turn(dist, dir, ur[0], ur[1], 'r', 'u') ;
                        turn(dist, dir, ud[0], ud[1], 'u', 'd') ; run_dir(dist, dir, visited, 2, n, m) ;
                    }
                }
                else {
                    turn(dist, dir, ur[0], ur[1], 'r', 'u') ;
                    if (turn_exist[0][3]==1 && !sta[3].empty()) {
                        turn(dist, dir, lu[0], lu[1], 'u', 'l') ; run_dir(dist, dir, visited, 3, n, m) ;
                        if (turn_exist[3][2]==1 && !sta[2].empty()) {
                            turn(dist, dir, dl[0], dl[1], 'l', 'd') ; run_dir(dist, dir, visited, 2, n, m) ;
                        }
                        else if (!sta[2].empty()) {
                            turn(dist, dir, lu[0], lu[1], 'l', 'u') ;
                            turn(dist, dir, ud[0], ud[1], 'u', 'd') ;
                            run_dir(dist, dir, visited, 2, n, m) ;
                        }
                    }
                }
            }
        }
        else if (turn_exist[0][2]==1 && !sta[2].empty()) {  //�W����k�i�H�U
            turn(dist, dir, ud[0], ud[1], 'u', 'd') ; run_dir(dist, dir, visited, 2, n, m) ;
            if (turn_exist[2][1]==1 && !sta[1].empty()) {
                turn(dist, dir, ud[0], ud[1], 'u', 'd') ; run_dir(dist, dir, visited, 1, n, m) ;
                if (turn_exist[1][3]==1 && !sta[3].empty()) {
                    turn(dist, dir, rl[0], rl[1], 'r', 'l') ; run_dir(dist, dir, visited, 3, n, m) ;
                }
                else if (!sta[3].empty()){
                    turn(dist, dir, rd[0], rd[1], 'r', 'd') ;
                    if (turn_exist[2][3]==1) turn(dist, dir, dl[0], dl[1], 'd', 'l') ;
                    else  turn(dist, dir, ud[0], ud[1], 'd', 'u') ;
                    run_dir(dist, dir, visited, 3, n, m) ;
                }
            }
            else {
                if (turn_exist[2][3]==1 && !sta[3].empty()) {
                    turn(dist, dir, dl[0], dl[1], 'd', 'l') ; run_dir(dist, dir, visited, 3, n, m) ;
                    if (turn_exist[3][1]==1 && !sta[1].empty()) {
                        turn(dist, dir, rl[0], rl[1], 'l', 'r') ; run_dir(dist, dir, visited, 1, n, m) ;
                    }
                    else if (!sta[1].empty()) {
                        turn(dist, dir, dl[0], dl[1], 'l', 'd') ; turn(dist, dir, ud[0], ud[1], 'd', 'u') ;
                        turn(dist, dir, ur[0], ur[1], 'u', 'r') ; run_dir(dist, dir, visited, 1, n, m) ;
                    }
                }
                else {
                    turn(dist, dir, ud[0], ud[1], 'd', 'u') ;
                    if (turn_exist[0][3]==1 && !sta[3].empty()) {
                        turn(dist, dir, lu[0], lu[1], 'u', 'l') ; run_dir(dist, dir, visited, 3, n, m) ;
                        if (!sta[2].empty()) {
                            turn(dist, dir, rl[0], rl[1], 'l', 'r') ; run_dir(dist, dir, visited, 1, n, m) ;
                        }
                    }
                }
            }
        }
        else if (turn_exist[0][3]==1 && !sta[3].empty()) { //�W����k����U�i�H��
            turn(dist, dir, lu[0], lu[1], 'u', 'l') ; run_dir(dist, dir, visited, 3, n, m) ;
            if (turn_exist[3][2]==1 && !sta[2].empty()) {
                turn(dist, dir, dl[0], dl[1], 'l', 'd') ; run_dir(dist, dir, visited, 1, n, m) ;
                if (turn_exist[2][1]==1 && !sta[1].empty()) {
                    turn(dist, dir, rd[0], rd[1], 'd', 'r') ; run_dir(dist, dir, visited, 1, n, m) ;
                }
                else if (!sta[1].empty()){
                    turn(dist, dir, dl[0], dl[1], 'd', 'l') ;
                    turn(dist, dir, rl[0], rl[1], 'l', 'r') ;
                    run_dir(dist, dir, visited, 1, n, m) ;
                }
            }
            else {
                if (turn_exist[3][1]==1 && !sta[1].empty()) {
                    turn(dist, dir, rl[0], rl[1], 'l', 'r') ; run_dir(dist, dir, visited, 1, n, m) ;
                    if (turn_exist[1][2]==1 && !sta[2].empty()) {
                        turn(dist, dir, rd[0], rd[1], 'r', 'd') ; run_dir(dist, dir, visited, 2, n, m) ;
                    }
                }
            }
        }
    }

}

void turn (int **dist, char **dir, int a, int b, char dir1, char dir2) {
    another_road(dist, dir, a, b, dir1) ;
    path.push_back(c1), path.push_back(c2) ;
    for (int i=road.size()-2; i>0; i-=2) {
        path.push_back(road[i-2]) ;
        path.push_back(road[i-1]) ;
    }
    path.push_back(a) ; path.push_back(b) ;
    road.clear() ;
    another_road(dist, dir, a, b, dir2) ;
    for (int i=0; i<road.size()-2; i+=2) {
        path.push_back(road[i]) ;
        path.push_back(road[i+1]) ;
    }
    road.clear() ;
}
void another_road (int **dist, char **dir, int a, int b, char d) {
    while (dist[a][b] != 0) {
        if (dist[a][b-1]!=-1&&dist[a][b-1]<dist[a][b]&&(dir[a][b-1]==d||dir[a][b-1]=='o')) {
            b-- ; road.push_back(a) ; road.push_back(b) ;
        }
        else if (dist[a+1][b]!=-1&&dist[a+1][b]<dist[a][b]&&(dir[a+1][b]==d||dir[a+1][b]=='o')) {
            a++ ; road.push_back(a) ; road.push_back(b) ;
        }
        else if (dist[a][b+1]!=-1&&dist[a][b+1]<dist[a][b]&&(dir[a][b+1]==d||dir[a][b+1]=='o')) {
            b++ ; road.push_back(a) ; road.push_back(b) ;
        }
        else if (dist[a-1][b]!=-1&&dist[a-1][b]<dist[a][b]&&(dir[a-1][b]==d||dir[a-1][b]=='o')) {
            a-- ; road.push_back(a) ; road.push_back(b) ;
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
    ofstream outfile("./"+ id + "/final.path") ;
    if (!infile) {
        cout << "Can not open file!\n" ;
        return 1 ;
    }
    int Col, Row, battery ;
    int r1, r2, count=0 ;
    char x ;

    infile >> Row ;
    infile >> Col ;
    infile >> battery ;

    int **dist = (int**) newmatrix(Row+2, Col+2, sizeof(int)) ;
    char **dir  = (char**) newmatrix(Row+2, Col+2, sizeof(char)) ;
    bool **visited  = (bool**) newmatrix(Row+2, Col+2, sizeof(bool)) ;

    for (int j=1; j<=Col; j++) {
        dist[0][j] = -1 ;
        dist[Row+1][j] = -1 ;
    }
    for (int i=1; i<=Row; i++) {
        dist[i][0] = -1 ;
        for (int j=1; j<=Col; j++) {
            infile >> x ;
            if (x == '1'){
                dist[i][j] = -1 ;
                dir[i][j] = '0' ;
            }
            else if (x == '0') {
                dist[i][j] = 0 ;
                count ++ ;
            }
            else if (x == 'R'){
                r1 = i ; r2 = j ;
                c1 = i ; c2 = j ;
                dist[i][j] = 0 ;
            }
        }
        dist[i][Col+1] = -1 ;
    }
    for(int i=1;i<=Row;i++) {
        for (int j=1; j<=Col; j++) {
            visited[i][j] = false ;
        }
    }
    if (count == 0 ) outfile << 0 ;
    else {
        distance(dist, dir, r1, r2, Row, Col) ;

        run (dist, dir, visited, r1, r2, Row, Col) ;
        outfile << path.size()/2-1 << "\n" ;
        for (int i=2; i<path.size(); i+=2) {
            outfile << path[i]-1 << " " << path[i+1]-1 << "\n" ;
        }
    }
    delete [] dist ;
    return 0 ;
}
