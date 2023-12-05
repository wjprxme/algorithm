#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int> mulmx(vector<int> matx1, vector<int> matx2, int k){
    vector<int> matx(4);
    matx[0] = (matx1[0]*matx2[0] + matx1[1]*matx2[2]) % k;
    matx[1] = (matx1[0]*matx2[1] + matx1[1]*matx2[3]) % k;
    matx[2] = (matx1[2]*matx2[0] + matx1[3]*matx2[2]) % k;
    matx[3] = (matx1[2]*matx2[1] + matx1[3]*matx2[3]) % k;
    return matx;
}
vector<int> modmax(map<int, vector<int>> &matxdt, int k, int n){
    if (n == 1) return matxdt[1];
    else {
        if (matxdt.find(n) == matxdt.end()){
            if (n%2 == 0){    
                vector<int> matx1 = modmax(matxdt, k, n/2);
                matxdt[n] = mulmx(matx1, matx1, k);
                return matxdt[n];
            }
            else{
                vector<int> matx1 = modmax(matxdt, k, n/2);
                vector<int> matx2 = modmax(matxdt, k, n/2+1);
                matxdt[n] = mulmx(matx1, matx2, k);
                return matxdt[n];
            }
        }
        else{
            return matxdt[n];
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> matx(4);
    cin >> matx[0] >> matx[1] >> matx[2] >> matx[3];
    map<int, vector<int>> matxdt;
    matxdt[1] = matx;
    matx = modmax(matxdt, k, n);
    for (int i=0; i < 4; i++){
        cout << matx[i] << " ";
    } 
}
