#include <iostream>
using namespace std;

int R, P;

bool isSafe(int available[R], int maxNeed[P][R], int alloc[P][R]){
    int need[P][R];
    for(int i = 0; i < P; i++){
        for(int j = 0; j < R; j++){
            need[i][j] = maxNeed[i][j] - alloc[i][j];
        }
    }

    bool finished[P] = {false};
    int safeSeq[P];
    int index = 0;
    int work[R];

    for(int i = 0; i < R; i++){
        work[i] = available[i];
    }

    for(int x = 0; x < P; x++){
        bool found = false;
        for(int i = 0; i < P; i++){
            if (!finished[i]){
                int j;
                for(j = 0; j < R; j++){
                    if (need[i][j] > work[j]) break;
                }
                
                if (j == R){
                    for(int k = 0; k < R; k++){
                        work[k] += alloc[i][k];
                    }
                    safeSeq[index++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }
        if(!found) return false;
    }

    cout << "\nSAFE SEQUENCE FOUND: ";
    for(int i = 0; i < P; i++){
        cout << "P" << safeSeq[i] << " ";
    }
    cout << endl;
    return true;
}

int main(){

    return 0;
}