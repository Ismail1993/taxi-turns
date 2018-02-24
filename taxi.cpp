#import <iostream>
#import <cmath>
#include <string>
#include <vector>

//IN THIS FUN LITTLE PROJECT WE'RE TRYING TO PREDICT SHARP TURNS NOW WHAT WE means
//BY A SHARP TURN IS A TURN WHOSE ANGLE OF TURNING IS GREATER THAN 45 DEGREES.
//IF A SHARP TURN IS TO HAPPEN THEN WE ALERT THE USER THAT ITS GOING TO HAPPEN AND IN THAT SCENARIO WE WILL ASK THAT THEY CHANGE THEIR COORDINATES.

//ISMAIL ABDULAZIZ IBRAHIM'S FUN LITTLE PROJECT.

using namespace std;

//defining functions.
void read_coords(vector<int> &x, vector<int> &y);
void calculate(vector<int> &x, vector<int> &y, vector <double> &phi);
void clean_arrays(vector<int> &x, vector<int> &y, vector<double> &phi);
string inspect(int a, vector <double> &phi);

int main(){
//defining key variables.
  int T = 0;
  int N = 0;
  vector<int> x;
  vector<int> y;
  vector <double> phi;
  //phi.at(0) = NAN;

//enter the number of test cases T.
  do {
    cin >> T;
}
  while (T < 1 or T > 50);

//enter the number of moments N.
  do {
    cin >> N;
}
  while (N < 3 or N > 50);

for(int z = 0; z < T; z++){
  printf("Test case number %d : \n ", (z+1));
  for(int i = 1; i < N+1; i++){
//coordinates to be read in.
    read_coords(x, y);
  }
//lets calculate the angle of turn now and fill phi vector array
  calculate(x, y, phi);
//lets print out the coordinates.
  for(vector<int>::size_type i = 1; i < x.size(); i++) {
	  cout << x.at(i) << " " << y.at(i) << endl;
  }
//see the results of our journey. LAST VALUE IS MEANINGLESS. out of bound problem.
  for(vector<int>::size_type i = 0; i < phi.size() - 1; i++) {
  	cout << inspect(i, phi) << " ";
  }
//finally lets clean our array for the second test phase.
  clean_arrays(x, y, phi);

}

  return 0;

}


string inspect(int a, vector <double> &phi){
		//lets inspect each element in the vector array phi.
	if(phi[a] > (M_PI / 4)){
		return "no";
		} else if(phi[a] < (M_PI / 4)){
			return "yes";
		}
}



void calculate(vector<int> &x, vector<int> &y, vector <double> &phi){
//let's calculate the angle of turn between two events and fill the array of phi(s).

	double phii;

	for(vector<int>::size_type i = 1; i < x.size(); i++) {
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

void clean_arrays(vector<int> &x, vector<int> &y, vector<double> &phi){
  x.clear();
  y.clear();
  phi.clear();
}
