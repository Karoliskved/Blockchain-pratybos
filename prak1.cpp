#include <iostream>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>


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
#include <vector>
#include <string>

using namespace std;



int main(){
string input;
string hex="0000000000000000000000000000000000000000000000000000000000000000";
bitset<8> temp;
vector<bitset<8>> hextobin(64, temp);
vector<bitset<8>> bincode;
cout << "input" << endl;
cout<< hex << endl;
cin >>input;
for(int i=0; i!=input.length(); i++){
    bitset<8> output(input[i]);
    cout << output << endl;
    bincode.push_back(output);
}
/*cout << "hex to bin" << endl;
for(int i=0; i!=hextobin.size(); i++){
    cout << hextobin[i] << endl;
}*/
cout << "vector" << endl;
for(int i=0; i!=bincode.size(); i++){
    cout << bincode[i] << endl;
}
for(int i=0; i!=bincode.size(); i++){
    hextobin[i]=bincode[i];
}
cout <<"acsII input" << endl;
for(int i=0; i!=bincode.size(); i++){
    cout << bincode[i].to_ulong() << endl;
    int laik =bincode[i].to_ulong();
    cout << "test "<<laik << endl;
}
cout <<"acsII output" << endl;
for(int i=0; i!=hextobin.size(); i++){
    cout << hextobin[i].to_ulong() << endl;
}
}