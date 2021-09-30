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
using std::hex;


using namespace std;
string fileName(){
    string name;
    cout << "iveskite file name" << endl;
    cin >> name;
    name+=".txt";
    return name;
}
string ivedimas(){
    string n;
    cout << "iveskite string" << endl;
    cin >> n;
    return n;
}


string myHash(string n){
   
    string finalhash="";
    unsigned int sum=0;
    unsigned int sumreverse=0;
    unsigned int sumfinal=0;
    int movedbits;
    int reversemovedbits;
    for (int i=0; i!=n.length(); i++){
        movedbits = (int(n[i]) << 5);
        sum+=((sum/7+movedbits) << 5);
       reversemovedbits=(int(n[n.size()-1-i]) << 7);
        sumreverse+=((sumreverse/7+reversemovedbits) << 7);
        sumfinal+=sum+sumreverse;
    }
  string hexcode="0123456789abcdef";
    for(int i=1; i!=65; ++i){
        sumfinal+=((/*7**/(sumfinal >> 5))+i);
        finalhash+=hexcode[((sumfinal%113)%16)];
    }
    return finalhash;
 
}
void readfromfile(){
ifstream inputFile;
string n;
int i=0;
inputFile.open(fileName());
while (getline(inputFile, n)){
   cout << myHash(n) << endl;
   i++;
}
if(i==0){
   cout << myHash("") << endl;
}
}

void choice(){
    char n;
    cout << "read from file(1),  comand line input(2), colission test(3), kostitucija test(4), diffrence test(5)" << endl;
    cin >> n;
    while (n!='1' && n!='2' && n!='3' && n!='4' && n!='5'){
        cout << "bankykite vel" << endl;
        cin>> n;
    }
    if(n=='1'){
        readfromfile();
    }
    if(n=='2'){
        string input= ivedimas();
       cout << myHash(input) << endl;
    }
    if(n=='3'){
        ofstream out_fgood("hashcodes.txt");
        ofstream out_fbad("repeatinghashcodes.txt");
        ifstream inputFile;
        string input;
        vector <string> colvector;
        vector <string> colvectorremoved;
        string hashtest;
        int i=0; 
        int counter=0;
        inputFile.open("testcase5.1.txt");

        while (getline(inputFile, input)){
            hashtest=myHash(input); 
           out_fgood << hashtest << " " << input << endl; 
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
        cout << "repeating hashes " <<colvectorremoved.size() << endl; 
        for(int i=0; i!=colvectorremoved.size(); i++){
            out_fbad << i << " " << colvectorremoved[i]<<endl;
        }
    }
    if(n=='4'){
        ifstream inputFile;
        string input;
        vector<string> konsvector;
        std::chrono::duration<double> diff;
       int i=0;
        inputFile.open("konstitucija.txt");
         while (getline(inputFile, input)){
             konsvector.push_back(input);
         }
         
         for(int i=0; i!=konsvector.size(); i++){
            auto start = std::chrono::high_resolution_clock::now();
            myHash(konsvector[i]);
            auto end = std::chrono::high_resolution_clock::now();
            diff+=(end-start);
         }
         
        std::cout << "konstitucijos hash'avimo laikas: " << diff/std::chrono::milliseconds(1) << " ms\n";

    }
    if(n=='5'){
        fstream inputFileA;
        fstream inputFileB;
        string linea;
        string lineb;
        vector <string> hashA;
        vector <string> hashB;
        string tempA;
        string tempB;
        string bitstring1;
        string bitstring2;
        int min=65;
        int max=0;
        int minbit=257;
        int maxbit=0;
        int minimumpair=0;
        double sum=0;
        double allsum=0;
        double bitsum=0;
        double allbitsum =0;
        stringstream ss1;
        stringstream ss2;
        inputFileA.open("testcase6a.txt");
        inputFileB.open("testcase6b.txt");
        ofstream out_fhashes("testcase6hashes.txt");
        for(int i=0; i!=100000; i++){
            getline(inputFileA, linea);
            hashA.push_back(myHash(linea));
            tempA=myHash(linea);
            getline(inputFileB, lineb);
            hashB.push_back(myHash(lineb));
            tempB=myHash(lineb);
            for(int j=0; j!=64; j++){
                if(tempA[j]!=tempB[j]){
                    sum++;
                    ss1 << hex << tempA[j] << endl;
                    unsigned n1;
                    ss1>>n1;
                    bitset<4> b1(n1);
                    bitstring1=b1.to_string();
                    ss2 << hex << tempB[j] << endl;
                    unsigned n2;
                    ss2>>n2;
                    bitset<4> b2(n2);
                    bitstring2=b2.to_string();
                    for(int k=0; k!=4; k++){
                        if(bitstring1[k]!=bitstring2[k]){
                            bitsum++;
                        }
                    }
                }
            }
            allsum+=sum;
            allbitsum+=bitsum;
            if(sum<min){
                min=sum;
                minimumpair=i+1;
            }
            if(sum>max){
                max=sum;
            }
            if(bitsum<minbit){
                minbit=bitsum;
            }
            if(bitsum>maxbit){
                maxbit=bitsum;
            }

            sum=0;
            bitsum=0;
            
        }
        cout << "hex max: " << max << " hex min: " << min << endl;
        cout << "hex average: " <<allsum/100000 << endl;
        cout << "bit max " << maxbit << " bit min " << minbit << endl;
        cout << "bit average: " <<allbitsum/100000 << endl;
        cout << minimumpair << endl;
        for(int i=0; i!=100000; i++){
            out_fhashes <<"pair: " <<i+1 << endl;
            out_fhashes << hashA[i] << endl;
            out_fhashes << hashB[i] << endl;
        }
    }
}
int main(){
choice();
}