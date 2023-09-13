// #include <gtest/gtest.h> // doesnt work
#include "mymap.h"
#include <map>
#include "myrandom.h"
#include <vector>

// TO DO: write lots of tests here.
void milestone1and2(){
    mymap<int, int> testMap;
    map<int, int> mapSol;
    int n = 10000;
    for(int i=1; i <= n; i++ ) {
        int key = randomInteger(0, n);
        int val = randomInteger(0, n);
        testMap.put(key, val); // test put
        mapSol[key] = val;
    }
    if(testMap.Size() != mapSol.size()){ // test size 
        cout << "MILESTONE 1 AND 2 FAILED";
    }
    stringstream solution("");
    for(auto pair : mapSol){
        solution << "key: " << pair.first;
        solution << " value: " << pair.second << endl;
        if(!testMap.contains(pair.first)){ // test contains
            cout << "MILESTONE 1 AND 2 FAILED";
        }
        if(testMap.get(pair.first), pair.second){ // test get
            continue;
        }
        else{
            cout << "MILESTONE 1 AND 2 FAILED";
        }
    }
    if(testMap.toString() != solution.str()){ // test tostring
        cout << "MILESTONE 1 AND 2 FAILED";
    }
    cout << "MILESTONE ONE AND TWO PASSED" << endl;
}


void milestone3(){
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    int order[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }
    int i = 0;
    map.begin(); // test begin
    for (auto key : map) {
        if(order[i++] != key){ // test operator[] && iterator++
            cout << "MILESTONE 3 FAILED";
        }
        if(order[0] != 1){ // begin returns 1 so it should match, if not it doesnt work
            cout << "MILESTONE 3 FAILED";
        }
    }
    cout << "MILESTONE 3 PASSED" << endl;
}

void clear(){
    mymap<int, int> testMap;
    map<int, int> mapSol;
    int n = 10000;
    for(int i=1; i <= n; i++ ) {
        int key = randomInteger(0, n);
        int val = randomInteger(0, n);
        testMap.put(key, val); // put 
        mapSol[key] = val; // operator []
    }
    testMap.clear(); // test clear
    if(testMap.Size() != 0){ //  if size != 0, map is not cleared
        cout << "CLEAR FAILED";
    }
    cout << "CLEAR PASSED" << endl;
}

void equals(){
    mymap<int, int> mapOrig;
    mymap<int, int> mapCopy;
    int n = 10000;
    for(int i=0; i<n; i++){
        int key = randomInteger(0, n);
        int val = randomInteger(0, n);
        mapOrig.put(key, val);
    }

    mapCopy = mapOrig; // testing equals 
    if(mapCopy.Size() != mapOrig.Size()){ // if they dont have the same size that means it wasnt copied over
        cout << "OPERATOR EQUALS FAILED" << endl;
    }
    cout << "OPERATOR EQUALS PASSED" << endl;
}

void copy(){
    mymap<int, int> mapOrig;
    int n = 10000;
    for(int i=0; i<n; i++){
        int key = randomInteger(0, n);
        int val = randomInteger(0, n);
        mapOrig.put(key, val);
    }

    mymap<int, int> mapCopy = mapOrig; // testing copy constructor
    if(mapCopy.Size() != mapOrig.Size()){ // if they dont have the same size that means it wasnt copied over
        cout << "COPY CONSTRUCTOR FAILED";
    }
    cout << "COPY CONSTRUCTOR PASSED" << endl;
}

void toVector(){
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }
    vector<pair<int, int> > solution = {{1,1}, {2,2}, {3,3}};
    if(solution != map.toVector()){ // testing to vector, comparing tovector to a solution
        cout << "TOVECTOR FAILED" << endl;
    }
    cout << "TOVECTOR PASSED" << endl;
}

void checkBalance(){
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
    for (int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }
    string sol = "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    if(map.checkBalance() != sol){ // test check balance
        cout << "CHECK BALANCE FAILED";
    }
    cout << "CHECK BALANCE PASSED" << endl;
}

int main()
{
    milestone1and2();
    milestone3();
    clear();
    equals();
    copy();
    toVector();
    checkBalance();
}