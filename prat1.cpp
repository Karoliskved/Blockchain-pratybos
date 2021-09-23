#include <iostream>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;
//using std::sort;
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
string ivedimas(){
    string n;
    cout << "iveskite sting" << endl;
    cin >> n;
    return n;
}
void converttoacs(string n, vector<int> & conv){
string s="";
unsigned int sum=0;
int sumtest=0;
int ctoint;
int movedbits;
for (char c : n) {
    conv.push_back(int(c));
}
//cout << sum << endl;
//cout << sumtest << endl;
for(int i=0; i!=conv.size(); ++i){
    s+=to_string(conv[i]);
}
//cout << s << endl;
}


void myHash(vector<int> conv){
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
    cout << finalhash << endl;
 
}


int main(){
string input= ivedimas();


vector<int>  conv;
vector<int>  movedbits;
converttoacs(input, conv);
myHash(conv);



}