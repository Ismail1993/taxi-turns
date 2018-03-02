#import <iostream>
#import <cmath>
#include <vector>
 
//IN THIS FUN LITTLE PROJECT WE'RE TRYING TO PREDICT SHARP TURNS NOW WHAT WE means
//BY A SHARP TURN IS A TURN WHOSE ANGLE OF TURNING IS GREATER THAN 45 DEGREES.
//IF A SHARP TURN IS TO HAPPEN THEN WE ALERT THE USER THAT ITS GOING TO HAPPEN AND IN THAT SCENARIO WE WILL ASK THAT THEY CHANGE THEIR COORDINATES.
 
//ISMAIL ABDULAZIZ IBRAHIM'S FUN LITTLE PROJECT.
 
using namespace std;
 
//defining functions.
void read_coords(vector<int> &x, vector<int> &y);
void calculate(vector<int> &x, vector<int> &y, vector <double> &phi);
void clean(vector<int> &x, vector<int> &y, vector<double> &phi);
 
int main(){
//defining key variables.
  int T = 0;
  int N = 0;
  vector<int> x;
  vector<int> y;
  vector<double> phi;
  vector<double> dump;
 
//enter the number of test cases T.
  do {
    cin >> T;
}while (T < 1 or T > 50);
 
  for(int z = 0; z < T; z++){
	  //enter the number of moments N.
	  do {
	    cin >> N;
	  }while (N < 3 or N > 50);
 
	  for(int i = 0; i < N; i++){
//coordinates to be read in.
		  read_coords(x, y);
	  }
//lets calculate the angle of turn now and fill phi vector array
	  calculate(x, y, phi);
//lets fill the dump vector array.
	  bool found = false;
	  for(vector<int>::size_type i = 0; i < phi.size(); i++){
		if(phi.at(i) > 0.79 and phi[i + 2] > 0.79){
			dump.push_back(1);//1 = no no
			found = true;
			break;
			}else if(phi.at(i) > 0.79 and phi[i + 2] < 0.79){
				dump.push_back(0);//0 = no yes
				found = true;
				break;
			}
	  }
 
	  if(not found){
		  dump.push_back(-1);//-1 = yes yes.
	  }
	  clean(x, y, phi);
}
 
  //TEST TO SEE WHATS INSIDE DUMP...
 
  for(vector<int>::size_type i = 0; i < dump.size(); i++){
	  if(dump.at(i) == 1){
		  cout << "no" << " " << "no" << endl;
	  }else if(dump.at(i) == 0){
		  cout << "no" << " " << "yes" << endl;
	  }else if(dump.at(i) == -1){
		  cout << "yes" << " " << "yes" << endl;
	  }
  }
  return 0;
 
}
 
 
//**FUNCTION DEFINITIONS**
 
void calculate(vector<int> &x, vector<int> &y, vector<double> &phi){
//let's calculate the angle of turn between two events and fill the array of phi(s).
 
	double phii;
 
	for(vector<int>::size_type i = 1; i < x.size() - 1; i++) {
      		phii = acos(((x[i] - x[i-1])*(x[i+1] - x[i])+(y[i] - y[i-1])*(y[i+1] - y[i]))/sqrt((pow((x[i] - x[i-1]), 2) + pow((y[i] - y[i-1]), 2))*(pow((x[i+1] - x[i]), 2) + pow((y[i+1] - y[i]), 2))));
      		phi.push_back(phii);
  }
 
}
 
 
void read_coords(vector<int> &x, vector<int> &y){
//take a single pair of coord and store it in.
	int x_cord;
	int y_cord;
	cin >> x_cord;
	cin >> y_cord;
 
	x.push_back(x_cord);
	y.push_back(y_cord);
 
}
 
 
void clean(vector<int> &x, vector<int> &y, vector<double> &phi){
 
	x.clear();
	y.clear();
	phi.clear();
}
