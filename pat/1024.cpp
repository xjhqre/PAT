#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	string zs;
	string xs;
	string shi;
	int gs = 0;
	string ling;
	zs = s[1];
	xs = s.substr(3, s.find('E') - 3);
	shi = s.substr(s.find('E') + 2);
	for (int i = 0; i < shi.size(); i++){
		gs += (shi[i] - '0') * (int) pow(10, shi.size() - i - 1);
	}
	if (s[0] == '+'){
		if (s[s.find('E') + 1] == '+'){
			gs -= xs.size();
			if (gs > 0){
				for (int i = 0; i < gs; i++){
					ling += '0';
				}
				cout << zs << xs << ling;
			}
			else{
				xs.insert(xs.size()+gs, "."); 
				if (xs[xs.size() - 1] == '.'){
					cout << zs << xs.substr(0,xs.size()-1);
				}
				else{
					cout << zs << xs;
				}
			}	
		}
		else{
			for (int i = 0; i < gs - 1; i++){
				ling += '0';
			}
			cout << "0." << ling << zs << xs;
		}
	}
	else{
		if (s[s.find('E') + 1] == '+'){
			gs -= xs.size();
			if (gs > 0){
				for (int i = 0; i < gs; i++){
					ling += '0';
				}
				cout << '-' << zs << xs << ling;
			}
			else{
				xs.insert(xs.size()+gs, "."); 
				if (xs[xs.size() - 1] == '.'){
					cout << '-' << zs << xs.substr(0,xs.size()-1);
				}
				else{
					cout << '-' << zs << xs;
				}
			}	
		}
		else{
			for (int i = 0; i < gs - 1; i++){
				ling += '0';
			}
			cout << "-0." << ling << zs << xs;
		}
	}
    system("pause");
    return 0;
}
