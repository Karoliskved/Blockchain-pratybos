#include <iostream>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::getline;
using std::to_string;
using std::exception;
using std::bitset;
//using std::partition;#include <iostream>
using std::hex;


using namespace std;
string fileName(){
    string stuff;
    cout << "iveskite file name" << endl;
    cin >> stuff;
    stuff+=".txt";
    return stuff;
}
string ivedimas(){
    string n;
    cout << "iveskite sting" << endl;
    cin >> n;
    return n;
}

string readfromfile (){
ifstream inputFile;
string n;
inputFile.open(fileName());
getline(inputFile, n);
return n;
}


void converttoacs(string n, vector<int> & conv){

for (char c : n) {
    conv.push_back(int(c));
}
/*//cout << sum << endl;
//cout << sumtest << endl;
for(int i=0; i!=conv.size(); ++i){
    s+=to_string(conv[i]);
}
//cout << s << endl;*/
}


string myHash(vector<int> conv){
    string s="";
    string finalhash="";
    unsigned int sum=0;
    unsigned int sumreverse=0;
    unsigned int sumfinal=0;
    int movedbits;
    int reversemovedbits;
    for(int i=0; i!=conv.size(); ++i){
        movedbits = (conv[i] << 5);
       // cout << conv[i] << " "<< movedbits <<endl;
        sum=((sum/7+movedbits) << 5);
       reversemovedbits=(conv[conv.size()-1-i] << 7);
       // cout << conv[conv.size()-1-i] << endl;
        //cout << conv[conv.size()-1-i] << " "<< reversemovedbits <<endl;
        sumreverse=((sumreverse/7+reversemovedbits) << 7);
        sumfinal=sum+sumreverse;
      // cout << sumfinal << endl;
      //  cout << (sumfinal%16) << endl;
    }
  string hexcode="0123456789abcdef";
    for(int i=1; i!=65; ++i){
        sumfinal+=((7*(sumfinal >> 5))+i);
        finalhash+=hexcode[((sumfinal%113)%16)];
    }
   // cout << finalhash << endl;
    return finalhash;
 
}
void choice(){
    char n;
    cout << "read from file(1),  comand line input(2), colission test(3), kostitucija test(4)" << endl;
    cin >> n;
    while (n!='1' && n!='2' && n!='3' && n!='4'){
        cout << "bankykite vel" << endl;
        cin>> n;
    }
    if(n=='1'){
        string input= readfromfile();
        vector<int>  conv;
        vector<int>  movedbits;
        converttoacs(input, conv);
      cout <<  myHash(conv) <<endl;
    }
    if(n=='2'){
        string input= ivedimas();
        vector<int>  conv;
        vector<int>  movedbits;
        converttoacs(input, conv);
       cout << myHash(conv) << endl;
    }
    if(n=='3'){
        ofstream out_fgood("hashcodes.txt");
        ofstream out_fbad("repeatinghashcodes.txt");
        ifstream inputFile;
        string input;
        vector <string> colvector;
        vector <string> colvectorremoved;
        string hashtest;
        int i=0, counter=0;
        inputFile.open("testcase5.1.txt");
        auto start = std::chrono::high_resolution_clock::now();
        while (getline(inputFile, input)){
          // cout << i << " ";
            vector<int>  conv;
            converttoacs(input, conv);
            hashtest=myHash(conv); 
           // cout << hashtest << endl;
           out_fgood << hashtest << " " << input << endl; 
           // i++;
            for(int i=0; i!=colvector.size(); i++){
                if(hashtest==colvector[i]){
                    counter++; 
                    colvectorremoved.push_back(hashtest);
                    break;
                }
            }
            if(counter==0){
                colvector.push_back(hashtest);
            }
            counter=0;
            
        }
        cout << colvector.size() << endl; 
        for(int i=0; i!=colvectorremoved.size(); i++){
            out_fbad << i << " " << colvectorremoved[i]<<endl;
        }
       // string input= ivedimas();
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
        std::cout << "Failo nuskaitymas į buferį užtruko: " << diff.count() << " s\n";
    }
    if(n=='4'){
        ifstream inputFile;
        string input;
        vector<int>  conv;
        vector<string> konsvector;
        
       int i=0;
        inputFile.open("konstitucija.txt");
        /*auto start = std::chrono::high_resolution_clock::now();
         while (getline(inputFile, input)){
            converttoacs(input, conv);
           //cout << i <<" "<<myHash(conv) << endl;
            //i++;
            myHash(conv);
         }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
        std::cout << "Failo nuskaitymas į buferį užtruko: " << diff.count() << " s\n";*/
         while (getline(inputFile, input)){
             konsvector.push_back(input);
         }
         auto start = std::chrono::high_resolution_clock::now();
         for(int i=0; i!=konsvector.size(); i++){
             converttoacs(konsvector[i], conv);
             myHash(conv);
            
         }
         std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
        std::cout << "Failo nuskaitymas į buferį užtruko: " << diff.count() << " s\n";

    }
}

int main(){
choice();




}