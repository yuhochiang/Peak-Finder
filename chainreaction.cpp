class Student{
    public:
        bool boom (int i, int j, int Record[5][6], int Max[5][6], Color color[5][6], int inputColor, int enemy) {
            if (i==0 && j==0) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[1][0] == enemy && Record[1][0] == 2) ||
                        (color[0][1] == enemy && Record[0][1] == 2) ) )
                        return 1 ;
                }
            }
            else if (i==4 && j==0) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[3][0] == enemy && Record[3][0] == 2) ||
                        (color[4][1] == enemy && Record[4][1] == 2) ) )
                        return 1 ;
                }
            }
            else if (i==0 && j==5) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[0][4] == enemy && Record[0][4] == 2) ||
                        (color[1][5] == enemy && Record[1][5] == 2) ) )
                        return 1 ;
                }
            }
            else if (i==4 && j==5) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[3][5] == enemy && Record[3][5] == 2) ||
                        (color[4][4] == enemy && Record[4][4] == 2) ) )
                        return 1 ;
                }
            }
            else if (i == 0) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[i][j-1] == enemy && Record[i][j-1] == Max[i][j-1]-1) ||
                        (color[i][j+1] == enemy && Record[i][j+1] == Max[i][j+1]-1) ||
                        (color[1][j] == enemy && Record[1][j] == Max[1][j]-1) ) )
                        return 1 ;
                }
            }
            else if (j == 0) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[i-1][j] == enemy && Record[i-1][j] == Max[i-1][j]-1) ||
                        (color[i+1][j] == enemy && Record[i+1][j] == Max[i+1][j]-1) ||
                        (color[i][1] == enemy && Record[i][1] == Max[i][1]-1) ) )
                        return 1 ;
                }
            }
            else if (i == 4){
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[i][j-1] == enemy && Record[i][j-1] == Max[i][j-1]-1) ||
                        (color[i][j+1] == enemy && Record[i][j+1] == Max[i][j+1]-1) ||
                        (color[3][j] == enemy && Record[3][j] == Max[3][j]-1) ) )
                        return 1 ;
                }
            }
            else if (j == 5) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[i-1][j] == enemy && Record[i-1][j] == Max[i-1][j]-1) ||
                        (color[i+1][j] == enemy && Record[i+1][j] == Max[i+1][j]-1) ||
                        (color[i][4] == enemy && Record[i][4] == Max[i][4]-1) ) )
                        return 1 ;
                }
            }
            else if (i>0 && i<4 && j>0 && j<5) {
                if (color[i][j]!=Black && color[i][j] == inputColor) {
                    if (Record[i][j] == Max[i][j]-1 &&
                        ( (color[i-1][j] == enemy && Record[i-1][j] == Max[i-1][j]-1) ||
                        (color[i+1][j] == enemy && Record[i+1][j] == Max[i+1][j]-1) ||
                        (color[i][j-1] == enemy && Record[i][j-1] == Max[i][j-1]-1) ||
                        (color[i][j+1] == enemy && Record[i][j+1] == Max[i][j+1]-1) ) )
                    return 1 ;
                }
            }
            return 0 ;
        }
        bool boom2 (int i, int j, int Record[5][6], int Max[5][6], Color color[5][6], int inputColor, int enemy) {
            int diff = Max[i][j] - Record[i][j] ;
            bool tf = 0 ;
            if (color[i][j] != Black && color[i][j] == inputColor && diff == 1) {
                if (color[i-1][j-1]==enemy &&
                    (color[i-1][j]==inputColor && diff<=Max[i-1][j]-Record[i-1][j]+Max[i-1][j-1]-Record[i-1][j-1]) ||
                    (color[i][j-1]==inputColor && diff<=Max[i][j-1]-Record[i][j-1]+Max[i-1][j-1]-Record[i-1][j-1]) ) {
                        tf = 1 ;
                }
                else if (color[i+1][j-1]==enemy && 
                    (color[i+1][j]==inputColor && diff>=Max[i+1][j]-Record[i+1][j]+Max[i+1][j-1]-Record[i+1][j-1]) ||
                    (color[i][j-1]==inputColor && diff>=Max[i][j-1]-Record[i][j-1]+Max[i+1][j-1]-Record[i+1][j-1]) ) {
                        tf = 1 ;
                }
                else if (color[i-1][j+1]==enemy && 
                    (color[i-1][j]==inputColor && diff>=Max[i-1][j]-Record[i-1][j]+Max[i-1][j+1]-Record[i-1][j+1]) ||
                    (color[i][j+1]==inputColor && diff>=Max[i][j+1]-Record[i][j+1]+Max[i-1][j+1]-Record[i-1][j+1]) ) {
                        tf = 1 ;
                }
                else if (color[i+1][j+1]==enemy && 
                    (color[i+1][j]==inputColor && diff>=Max[i+1][j]-Record[i+1][j]+Max[i+1][j+1]-Record[i+1][j+1]) ||
                    (color[i][j+1]==inputColor && diff>=Max[i][j+1]-Record[i][j+1]+Max[i+1][j+1]-Record[i+1][j+1]) ) {
                        tf = 1 ;
                }
            }
            return tf ;
        }
        bool no (int i, int j, int Record[5][6], int Max[5][6], Color color[5][6], int inputColor, int enemy) {
            int diff = Max[i][j] - Record[i][j] ;
            bool tf = 0 ;
            if (i>0 && i<4 && j>0 && j<5) {
                if (color[i][j]!=Black) {
                    if ((color[i-1][j] == enemy && diff>Max[i+1][j]-Record[i-1][j]) ||
                        (color[i+1][j] == enemy && diff>Max[i+1][j]-Record[i+1][j]) ||
                        (color[i][j-1] == enemy && diff>Max[i][j-1]-Record[i][j-1]) ||
                        (color[i][j+1] == enemy && diff>Max[i][j+1]-Record[i][j+1]) )
                    tf = 1 ;
                }
            }
            else if (i==0 && j==0) {
                if (color[i][j]!=Black) {
                    if ((color[1][0] == enemy && diff>Max[1][0]-Record[1][0]) ||
                        (color[0][1] == enemy && diff>Max[0][1]-Record[0][1]) )
                        tf = 1 ;
                }
            }
            else if (i==4 && j==0) {
                if (color[i][j]!=Black) {
                    if ((color[3][0] == enemy && diff>Max[3][0]-Record[3][0]) ||
                        (color[4][1] == enemy && diff>Max[4][1]-Record[4][1]) ) 
                        tf = 1 ;
                }
            }
            else if (i==0 && j==5) {
                if (color[i][j]!=Black) {
                    if ((color[0][4] == enemy && diff>Max[0][4]-Record[0][4]) ||
                        (color[1][5] == enemy && diff>Max[1][5]-Record[1][5]) ) 
                        tf = 1 ;
                }
            }
            else if (i==4 && j==5) {
                if (color[i][j]!=Black) {
                    if ((color[3][5] == enemy && diff>Max[3][5]-Record[3][5]) ||
                        (color[4][4] == enemy && diff>Max[4][4]-Record[4][4]) )
                        tf = 1 ;
                }
            }
            else if (i == 0) {
                if (color[i][j]!=Black) {
                    if ((color[i][j-1] == enemy && diff>Max[i][j-1]-Record[i][j-1]) ||
                        (color[i][j+1] == enemy && diff>Max[i][j+1]-Record[i][j+1]) ||
                        (color[1][j] == enemy && diff>Max[1][j]-Record[1][j]) )
                        tf = 1 ;
                }
            }
            else if (j == 0) {
                if (color[i][j]!=Black) {
                    if ((color[i-1][j] == enemy && diff>Max[i-1][j]-Record[i-1][j]) ||
                        (color[i+1][j] == enemy && diff>Max[i+1][j]-Record[i+1][j]) ||
                        (color[i][1] == enemy && diff>Max[i][1]-Record[i][1]) )
                        tf = 1 ;
                }
            }
            else if (i == 4){
                if (color[i][j]!=Black) {
                    if ((color[i][j-1] == enemy && diff>Max[i][j-1]-Record[i][j-1]) ||
                        (color[i][j+1] == enemy && diff>Max[i][j+1]-Record[i][j+1]) ||
                        (color[3][j] == enemy && diff>Max[3][j]-Record[3][j]) )
                        tf = 1 ;
                }
            }
            else if (j == 5) {
                if (color[i][j]!=Black) {
                    if ((color[i-1][j] == enemy && diff>Max[i-1][j]-Record[i-1][j]) ||
                        (color[i+1][j] == enemy && diff>Max[i+1][j]-Record[i+1][j]) ||
                        (color[i][4] == enemy && diff>Max[i][4]-Record[i][4]) )
                        tf = 1 ;
                }
            }
            /*if (tf == 0) {
                if (i!=0 && color[i-1][j] == enemy && diff == Max[i-1][j]-Record[i-1][j]) {
                    if((color[i-2][j] == inputColor && Record[i-2][j] == Max[i-2][j]-1) ||
                       (color[i-1][j+1] == inputColor && Record[i-1][j+1] == Max[i-1][j+1]-1) ||
                       (color[i-1][j-1] == inputColor && Record[i-1][j-1] == Max[i-1][j-1]-1) ) {
                        tf = 1 ;
                    }
                }
                if (j!=0 && color[i][j-1] == enemy && diff == Max[i][j-1]-Record[i][j-1]) {
                    if((color[i][j-2] == inputColor && Record[i][j-2] == Max[i][j-2]-1) ||
                       (color[i+1][j-1] == inputColor && Record[i+1][j-1] == Max[i+1][j-1]-1) ||
                       (color[i-1][j-1] == inputColor && Record[i-1][j-1] == Max[i-1][j-1]-1) ) {
                        tf = 1 ;
                    }
                }
                if (i!=4 && color[i+1][j] == enemy && diff == Max[i+1][j]-Record[i+1][j]) {
                    if((color[i+2][j] == inputColor && Record[i+2][j] == Max[i+2][j]-1) ||
                       (color[i+1][j+1] == inputColor && Record[i+1][j+1] == Max[i+1][j+1]-1) ||
                       (color[i+1][j-1] == inputColor && Record[i+1][j-1] == Max[i+1][j-1]-1) ) {
                        tf = 1 ;
                    }
                }
                if (j!=5 && color[i][j+1] == enemy && diff == Max[i][j+1]-Record[i][j+1]) {
                    if((color[i][j+2] == inputColor && Record[i][j+2] == Max[i][j+2]-1) ||
                       (color[i+1][j+1] == inputColor && Record[i+1][j+1] == Max[i+1][j+1]-1) ||
                       (color[i-1][j+1] == inputColor && Record[i-1][j+1] == Max[i-1][j+1]-1) ) {
                        tf = 1 ;
                    }
                }
            }*/
            
            return tf ;
        }
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            // Your Code
            int enemy ;
            if (inputColor == Red) enemy = Blue ;
            else if (inputColor == Blue) enemy = Red ;
            int hor[6] = {1, 3, 5, 0, 2, 4} ;
            int ver[5] = {2, 4, 0, 1, 3} ;
            int up[4] = {2, 4, 1, 3} ;
            int rl[3] = {2, 1, 3} ;
            bool done=0 ;
            if (color[0][0]==White ) { x = 0 ; y = 0 ; return ; }
            if (color[4][0]==White ) { x = 4 ; y = 0 ; return ; }
            if (color[0][5]==White ) { x = 0 ; y = 5 ; return ; }
            if (color[4][5]==White ) { x = 4 ; y = 5 ; return ; }

            for (int i=0; i<5; i++) {
                for (int j=0; j<6; j++) {
                    if ( boom(i, j, Record, Max, color, inputColor, enemy) == true) {
                        x = i ; y = j ; return ;
                    }
                }
            }
            for (int j=0; j<4; j++) { //1, up
                if (color[0][up[j]]!=Black && color[0][up[j]]==inputColor && Record[0][up[j]]==1) 
                    if ( (color[0][up[j]-1]==enemy && Record[0][up[j]-1]==1 && Max[0][up[j]-1]!=2) ||
                         (color[0][up[j]+1]==enemy && Record[0][up[j]+1]==1 && Max[0][up[j]+1]!=2) ||
                         (color[1][up[j]]==enemy && Record[1][up[j]]==1 ) ) { x = 0 ; y = up[j] ; return ; }
            }
            for (int i=0; i<3; i++) { //1, left
                if (color[rl[i]][0]!=Black && color[rl[i]][0]==inputColor && Record[rl[i]][0]==1)
                    if ( (color[rl[i]-1][0]==enemy && Record[rl[i]-1][0]==1 && Max[rl[i]-1][0]!=2) ||
                         (color[rl[i]+1][0]==enemy && Record[rl[i]+1][0]==1 && Max[rl[i]+1][0]!=2) ||
                         (color[rl[i]][1]==enemy && Record[rl[i]][1]==1) ) { x = rl[i] ; y = 0 ; return ; }
            }
            for (int j=0; j<4; j++) { //1, down
                if (color[4][up[j]]!=Black && color[4][up[j]]==inputColor && Record[4][up[j]]==1)
                    if ( (color[4][up[j]-1]==enemy && Record[4][up[j]-1]==1 && Max[4][up[j]-1]!=2) ||
                         (color[4][up[j]+1]==enemy && Record[4][up[j]+1]==1 && Max[4][up[j]+1]!=2) ||
                         (color[3][up[j]]==enemy && Record[3][up[j]]==1 ) ) { x = 4 ; y = up[j] ; return ; }
            }
            for (int i=0; i<3; i++) { //1, right
                if (color[rl[i]][5]!=Black && color[rl[i]][5]==inputColor && Record[rl[i]][5]==1)
                    if ( (color[rl[i]-1][5]==enemy && Record[rl[i]-1][5]==1 && Max[rl[i]-1][5]!=2) ||
                         (color[rl[i]+1][5]==enemy && Record[rl[i]+1][5]==1 && Max[rl[i]+1][5]!=2) ||
                         (color[rl[i]][4]==enemy && Record[rl[i]][4]==1 ) ) { x = rl[i] ; y = 5 ; return ; }
            }
            for (int j=0; j<4; j++) { //1, up
                if (color[0][up[j]]!=Black && color[0][up[j]]==inputColor && Record[0][up[j]]==1) 
                    if ( color[0][up[j]-1]==White && color[0][up[j]+1]==White) { 
                        x = 0 ; y = up[j] ; return ;
                    }
            }
            for (int i=0; i<3; i++) { //1, left
                if (color[rl[i]][0]!=Black && color[rl[i]][0]==inputColor && Record[rl[i]][0]==1)
                    if ( color[rl[i]-1][0]==White && color[rl[i]+1][0]==White) { 
                        x = rl[i] ; y = 0 ; return ;
                    }
            }
            for (int j=0; j<4; j++) { //1, down
                if (color[4][up[j]]!=Black && color[4][up[j]]==inputColor && Record[4][up[j]]==1)
                    if ( color[4][up[j]-1]==White && color[4][up[j]+1]==White) { 
                        x = 4 ; y = up[j] ; return ;
                    }
            }
            for (int i=0; i<3; i++) { //1, right
                if (color[rl[i]][5]!=Black && color[rl[i]][5]==inputColor && Record[rl[i]][5]==1)
                    if ( color[rl[i]-1][5]==White && color[rl[i]+1][5]==White) { 
                        x = rl[i] ; y = 5 ; return ;
                    }
            }
            for (int j=0; j<2; j++) { //0, up
                if (color[0][up[j]]!=Black && color[0][up[j]]==White)
                    if ( color[0][up[j]-1]!=enemy && color[0][up[j]+1]!=enemy ) { x = 0 ; y = up[j] ; return ; }
            }
            for (int i=0; i<1; i++) { //0, left
                if (color[rl[i]][0]!=Black && color[rl[i]][0]==White)
                    if ( color[rl[i]-1][0]!=enemy && color[rl[i]][0]!=enemy ) { x = rl[i] ; y = 0 ; return ; }
            }
            for (int j=0; j<2; j++) { //0, down
                if (color[4][up[j]]!=Black && color[4][up[j]]==White) 
                    if ( color[4][up[j]-1]!=enemy && color[4][up[j]+1]!=enemy ) { x = 4 ; y = up[j] ; return ; }
            }
            for (int i=0; i<1; i++) { //0, right
                if (color[rl[i]][5]!=Black && color[rl[i]][5]==White)
                    if ( color[rl[i]-1][5]!=enemy && color[rl[i]][5]!=enemy ) { x = rl[i] ; y = 5 ; return ; }
            }
            for (int j=2; j<4; j++) { //0, up
                if (color[0][up[j]]!=Black && color[0][up[j]]==White) 
                    if ( color[0][up[j]-1]!=enemy && color[0][up[j]+1]!=enemy ) { x = 0 ; y = up[j] ; return ; }
            }
            for (int i=1; i<3; i++) { //0, left
                if (color[rl[i]][0]!=Black && color[rl[i]][0]==White)
                    if ( color[rl[i]-1][0]!=enemy && color[rl[i]][0]!=enemy ) { x = rl[i] ; y = 0 ; return ; }
            }
            for (int j=2; j<4; j++) { //0, down
                if (color[4][up[j]]!=Black && color[4][up[j]]==White)
                    if ( color[4][up[j]-1]!=enemy && color[4][up[j]+1]!=enemy ) { x = 4 ; y = up[j] ; return ; }
            }
            for (int i=1; i<3; i++) { //0, right
                if (color[rl[i]][5]!=Black && color[rl[i]][5]==White)
                    if ( color[rl[i]-1][5]!=enemy && color[rl[i]][5]!=enemy ) { x = rl[i] ; y = 5 ; return ; }
            }
            for (int i=0; i<5; i++) {
                for (int j=0; j<6; j++) {
                    if (color[i][j] != Black && (color[i][j] == inputColor || color[i][j] == White)) {
                        if ( no(i, j, Record, Max, color, inputColor, enemy) == false) {
                            x = i ; y = j ; return ;
                        }
                    }
                }
            }/*
            for (int i=0; i<5; i++) {
                for (int j=0; j<6; j++) {
                    if ( boom2(i, j, Record, Max, color, inputColor, enemy) == true) {
                        x = i ; y = j ; return ;
                    }
                }
            }*/
            for (int i=0; i<5; i++) {
                for (int j=0; j<6; j++) {
                    if (color[ver[i]][hor[j]]!=Black){
                        if ( (color[ver[i]][hor[j]] == White || color[ver[i]][hor[j]] == inputColor) &&
                              Record[ver[i]][hor[j]] != Max[ver[i]][hor[j]]-1 ) {
                            x = ver[i] ; y = hor[j] ; return ;
                        }
                    }
                }
            }
            for (int i=0; i<5; i++) {
                for (int j=0; j<6; j++) {
                    if (color[ver[i]][hor[j]]!=Black){
                        if (color[ver[i]][hor[j]]==White || color[ver[i]][hor[j]]==inputColor) {
                            x = ver[i] ; y = hor[j] ; done = 1 ; break ;
                        }
                    }
                }
                if (done == 1) break ;
            }
        }
        // Any Code You Want to Add
        int getX(){
            return x ;
        }
        int getY(){
            return y ;
        }
    private:
        int x;
        int y;
};
