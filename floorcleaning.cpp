#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
using namespace std ;

void turn (int **dist, char ** dir, int a, int b, int dir1, int dir2) ;
void another_road (int **dist, char **dir, int a, int b, int d) ;
int r1, r2 ;
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
            for (int i=road.size()-2; i>0; i-=2) { //go, without origin, with corner
                path.push_back(road[i-2]) ; //i=road.size
                path.push_back(road[i-1]) ;
            }
            for (int i=2; i<road.size(); i+=2) { //back, with origin, without corner
                path.push_back(road[i]) ;  //i=road.size-2
                path.push_back(road[i+1]) ;
            }
            road.clear() ;
        }
    }
}
void run (int **dist, char **dir, bool **visited, int k, int x, int y, int n, int m) {
    //u=0, r=1, d=2, l=3 

    int turn_exist[4][4] = {{ !sta[0].empty(), ur[2], ud[2], lu[2] },
                            { ur[2], !sta[1].empty(), rd[2], rl[2] },
                            { ud[2], rd[2], !sta[2].empty(), dl[2] },
                            { lu[2], rl[2], dl[2], !sta[3].empty() } } ;

    int cor[4][8] = { {   0  ,   0  , ur[0], ur[1], ud[0], ud[1], lu[0], lu[1] },
                      { ur[0], ur[1],   1  ,   1  , rd[0], rd[1], rl[0], rl[1] }, 
                      { ud[0], ud[1], rd[0], rd[1],   2  ,   2  , dl[0], dl[1] },
                      { lu[0], lu[2], rl[0], rl[1], dl[0], dl[1],   3  ,   3   } } ;

    if (!sta[k].empty()) {
        run_dir(dist, dir, visited, k, n, m) ;
        if (turn_exist[k][(k+1)%4]==1 && !sta[(k+1)%4].empty()) {
            turn(dist, dir, cor[k][(2*k+2)%8], cor[k][(2*k+3)%8], k, (k+1)%4) ; //ur
            run_dir(dist, dir, visited, (k+1)%4, n, m) ;
            if (turn_exist[(k+1)%4][(k+2)%4]==1 && !sta[(k+2)%4].empty()) {
                turn(dist, dir, cor[(k+1)%4][(2*k+4)%8], cor[(k+1)%4][(2*k+5)%8], (k+1)%4, (k+2)%4) ; //rd
                run_dir(dist, dir, visited, (k+2)%4,n, m) ;
                if (turn_exist[(k+2)%4][(k+3)%4]==1 && !sta[(k+3)%4].empty()) {
                    turn(dist, dir, cor[(k+2)%4][(2*k+6)%8], cor[(k+2)%4][(2*k+7)%8], (k+2)%4, 3) ; //dl
                    run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                } else if (!sta[(k%3)%4].empty()) {
                    turn(dist, dir, cor[(k+2)%4][(2*k+2)%8], cor[(k+2)%4][(2*k+3)%8], (k+2)%4, (k+1)%4) ; //dr
                    if (turn_exist[(k+1)%4][(k+3)%4]==1)
                        turn(dist, dir, cor[(k+1)%4][(2*k+6)%8], cor[(k+1)%4][(2*k+7)%8], (k+1)%4, 3) ; //rl
                    else {
                        turn(dist, dir, cor[(k+1)%4][2*k], cor[(k+1)%4][2*k+1], (k+1)%4, k) ; //ru
                        turn(dist, dir, cor[k][(2*k+6)%8], cor[k][(2*k+7)%8], k, 3) ; //ul
                    }
                    run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                }
            }
            else {
                if (turn_exist[(k+1)%4][(k+3)%4]==1 && !sta[(k+3)%4].empty()) {
                    turn(dist, dir, cor[(k+1)%4][(2*k+6)%8], cor[(k+1)%4][(2*k+7)%8], (k+1)%4, 3) ; //rl 
                    run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                    if (turn_exist[(k+3)%4][(k+2)%4] && !sta[(k+2)%4].empty()) {
                        turn(dist, dir, cor[(k+3)%4][(2*k+4)%8], cor[(k+3)%4][(2*k+5)%8], 3, (k+2)%4) ; //ld
                        run_dir(dist, dir, visited, (k+2)%4, n, m) ;
                    }
                    else if (!sta[(k+2)%4].empty()) {
                        turn(dist, dir, cor[(k+3)%4][(2*k+2)%8], cor[(k+3)%4][(2*k+3)%8], 3, (k+1)%4) ; //lr
                        turn(dist, dir, cor[(k+1)%4][2*k], cor[(k+1)%4][2*k+1], (k+1)%4, k) ; //ru
                        turn(dist, dir, cor[k][(2*k+4)%8], cor[k][(2*k+5)%8], k, (k+2)%4) ; //ud
                        run_dir(dist, dir, visited, (k+2)%4, n, m) ;
                    }
                }
                else {
                    turn(dist, dir, cor[(k+1)%4][2*k], cor[(k+1)%4][2*k+1], (k+1)%4, k) ; //ru
                    if (turn_exist[k][(k+3)%4]==1 && !sta[3].empty()) {
                        turn(dist, dir, cor[k][(2*k+6)%8], cor[k][(2*k+7)%8], k, 3) ; //ul
                        run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                        if (turn_exist[(k+3)%4][(k+2)%4]==1 && !sta[(k+2)%4].empty()) {
                            turn(dist, dir, cor[(k+3)%4][(2*k+4)%8], cor[(k+3)%4][(2*k+5)%8], 3, (k+2)%4) ; //ld
                            run_dir(dist, dir, visited, (k+2)%4, n, m) ;
                        }
                        else if (!sta[(k+2)%4].empty()) {
                            turn(dist, dir, cor[(k+3)%4][2*k], cor[(k+3)%4][2*k+1], 3, k) ; //lu
                            turn(dist, dir, cor[k][(2*k+4)%8], cor[k][(2*k+5)%8], k, (k+2)%4) ; //ud
                            run_dir(dist, dir, visited, (k+2)%4, n, m) ;
                        }
                    }
                }
            }
        }
        else if (turn_exist[k][(k+2)%4]==1 && !sta[(k+2)%4].empty()) {  //down
            turn(dist, dir, cor[k][(2*k+4)%8], cor[k][(2*k+5)%8], k, (k+2)%4) ; //ud
            run_dir(dist, dir, visited, (k+2)%4, n, m) ;
            if (turn_exist[(k+2)%4][(k+1)%4]==1 && !sta[(k+1)%4].empty()) {
                turn(dist, dir, cor[(k+2)%4][(2*k+2)%8], cor[(k+2)%4][(2*k+3)%8], (k+2)%4, (k+1)%4) ; //dr
                run_dir(dist, dir, visited, (k+1)%4, n, m) ;
                if (turn_exist[(k+1)%4][(k+3)%4]==1 && !sta[(k+3)%4].empty()) {
                    turn(dist, dir, cor[(k+1)%4][(2*k+6)%8], cor[(k+1)%4][(2*k+7)%8], (k+1)%4, (k+3)%4) ; //rl 
                    run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                }
                else if (!sta[(k+3)%4].empty()){
                    turn(dist, dir, cor[(k+1)%4][(2*k+4)%8], cor[(k+1)%4][(2*k+5)%8], (k+1)%4, (k+2)%4) ; //rd
                    if (turn_exist[(k+2)%4][(k+3)%4]==1) 
                        turn(dist, dir, cor[(k+2)%4][(2*k+6)%8], cor[(k+2)%4][(2*k+7)%8], (k+2)%4, (k+3)%4) ; //dl
                    else {
                        turn(dist, dir, cor[(k+2)%4][2*k], cor[(k+2)%4][(2*k+1)%8], (k+2)%4, k) ; //du
                        turn(dist, dir, cor[k][(2*k+6)%8], cor[k][(2*k+7)%8], k, (k+3)%4) ; //ul
                    }
                    run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                }
            }
            else {
                if (turn_exist[(k+2)%4][(k+3)%4]==1 && !sta[(k+3)%4].empty()) {
                    turn(dist, dir, cor[(k+2)%4][(2*k+6)%8], cor[(k+2)%4][(2*k+7)%8], (k+2)%4, (k+3)%4) ; //dl
                    run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                    if (turn_exist[(k+3)%4][(k+1)%4]==1 && !sta[(k+1)%4].empty()) {
                        turn(dist, dir, cor[(k+3)%4][(2*k+2)%8], cor[(k+3)%4][(2*k+3)%8], (k+3)%4, (k+1)%4) ; //lr
                        run_dir(dist, dir, visited, (k+1)%4, n, m) ;
                    }
                    /*else if (!sta[(k+1)%4].empty()) {
                        turn(dist, dir, cor[(k+3)%4][(2*k+4)%8], cor[(k+3)%4][(2*k+5)%8], (k+3)%4, (k+2)%4) ; //ld
                        turn(dist, dir, cor[(k+2)%4][2*k], cor[(k+2)%4][(2*k+1)%8], (k+2)%4, k) ; //du
                        turn(dist, dir, cor[k][(2*k+2)%8], cor[k][(2*k+3)%8], k, (k+1)%4) ; //ur
                        run_dir(dist, dir, visited, (k+1)%4, n, m) ;
                    }*/
                }
                else {
                    turn(dist, dir, cor[(k+2)%4][2*k], cor[(k+2)%4][2*k+1], (k+2)%4, k) ; //du
                    if (turn_exist[k][(k+3)%4]==1 && !sta[(k+3)%4].empty()) {
                        turn(dist, dir, cor[k][(2*k+6)%8], cor[k][(2*k+7)%8], k, (k+3)%4) ; //ul 
                        run_dir(dist, dir, visited, (k+3)%4, n, m) ;
                        if (!sta[(k+1)%4].empty()) {
                            turn(dist, dir, cor[(k+3)%4][(2*k+2)%8], cor[(k+3)%4][(2*k+3)%8], (k+3)%4, (k+1)%4) ; //lr
                            run_dir(dist, dir, visited, (k+1)%4, n, m) ;
                        }
                    }
                }
            }
        }
        else if (turn_exist[k][(k+3)%4]==1 && !sta[(k+3)%4].empty()) { //left
            turn(dist, dir, cor[k][(2*k+6)%8], cor[k][(2*k+7)%8], k, (k+3)%4) ; //ul
            run_dir(dist, dir, visited, (k+3)%4, n, m) ;
            if (turn_exist[(k+3)%4][(k+2)%4]==1 && !sta[(k+2)%4].empty()) {
                turn(dist, dir, cor[(k+3)%4][(2*k+4)%8], cor[(k+3)%4][(2*k+5)%8], (k+3)%4, (k+2)%4) ; //ld
                run_dir(dist, dir, visited, (k+2)%4, n, m) ;
                if (turn_exist[(k+2)%4][(k+1)%4]==1 && !sta[(k+1)%4].empty()) {
                    turn(dist, dir, cor[(k+2)%4][(2*k+2)%8], cor[(k+2)%4][(2*k+3)%8], (k+2)%4, (k+1)%4) ; //dr
                    run_dir(dist, dir, visited, (k+1)%4, n, m) ;
                }
                else if (!sta[(k+1)%4].empty()){
                    turn(dist, dir, cor[(k+2)%4][(2*k+6)%8], cor[(k+2)%4][(2*k+7)%8], (k+2)%4, (k+3)%4) ; //dl
                    turn(dist, dir, cor[(k+3)%4][(2*k+2)%8], cor[(k+3)%4][(2*k+3)%8], (k+3)%4, (k+1)%4) ; //lr
                    run_dir(dist, dir, visited, (k+1)%4, n, m) ;
                }
            }
            else {
                if (turn_exist[(k+3)%4][(k+1)%4]==1 && !sta[(k+1)%4].empty()) {
                    turn(dist, dir, cor[(k+3)%4][(2*k+2)%8], cor[(k+3)%4][(2*k+3)%8], (k+3)%4, (k+1)%4) ; //lr
                    run_dir(dist, dir, visited, (k+1)%4, n, m) ;
                    if (turn_exist[(k+1)%4][(k+2)%4]==1 && !sta[(k+2)%4].empty()) {
                        turn(dist, dir,cor[(k+1)%4][(2*k+4)%8], cor[(k+1)%4][(2*k+5)%8], (k+1)%4, (k+2)%4) ; //rd
                        run_dir(dist, dir, visited, (k+2)%4, n, m) ;
                    }
                }
            }
        }
    }

}

void turn (int **dist, char **dir, int a, int b, int dir1, int dir2) {
    another_road(dist, dir, a, b, dir1) ;
    for (int i=road.size()-2; i>0; i-=2) { //go, without origin, without (a, b)
        path.push_back(road[i-2]) ;
        path.push_back(road[i-1]) ;
    }
    
    path.push_back(a) ; path.push_back(b) ;
    road.clear() ;
    another_road(dist, dir, a, b, dir2) ;
    for (int i=0; i<road.size()-2; i+=2) { //back, without origin, without (a, b)
        path.push_back(road[i]) ;
        path.push_back(road[i+1]) ;
    }
    path.push_back(r1), path.push_back(r2) ; //print before
    road.clear() ;
}
void another_road (int **dist, char **dir, int a, int b, int c) {
    char d ;
    if (c==0) d = 'u' ; else if (c==1) d = 'r' ;
    else if (c==2) d = 'd' ; else if (c==3) d = 'l' ;
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
    int r1, r2, count=0, k ;
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
        
        for (k=0; k<4; k++) {
            if (!sta[k].empty()) break ;
        }
        run (dist, dir, visited, k, r1, r2, Row, Col) ;
        outfile << path.size()/2 << "\n" ;
        for (int i=0; i<path.size(); i+=2) { //i=2
            outfile << path[i]-1 << " " << path[i+1]-1 << "\n" ;
        }
    }
    delete [] dist ;
    return 0 ;
}
