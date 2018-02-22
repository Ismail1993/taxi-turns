#import <iostream>
#import <cmath>
#include <vector>

//IN THIS FUN LITTLE PROJECT WE'RE TRYING TO PREDICT SHARP TURNS NOW WHAT WE means
//BY A SHARP TURN IS A TURN WHOSE ANGLE OF TURNING IS GREATER THAN 45 DEGREES.
//IF A SHARP TURN IS TO HAPPEN THEN WE ALERT THE USER THAT ITS GOING TO HAPPEN AND IN THAT SCENARIO WE WILL ASK THAT THEY CHANGE THEIR COORDINATES.

//ISMAIL ABDULAZIZ IBRAHIM'S FUN LITTLE PROJECT.

using namespace std;

//defining functions.
void read_coords(int &x, int &y, vector<int> &arr);
char calculate(vector<int> &arr);
void clean_array(vector<int> &arr);

int main(){
//defining key variables.
  int T = 0;
  int N = 0;
  vector<int> coords;

//enter the number of test cases T.
  do {
    cout << "Enter test cases: " << endl;
    cin >> T;
}
  while (T < 1 or T > 50);

//enter the number of moments N.
  do {
    cout << "Enter moments: " << endl;
    cin >> N;
}
  while (N < 3 or N > 50);

for(int z = 0; z < T; z++){
  printf("Test case number %d : \n ", (z+1));
  for(int i = 1; i < N+1; i++){
//coordinates to be read in.
    int x;
    int y;
    cin >> x;
    cin >> y;
    read_coords(x, y, coords);
    if (i % 3 == 0){
      char result = calculate(coords);
      cout << result << endl;
//test for a sharp turn, if there is then result = n. Ask input for new coords.
      while(result == 'n'){
        cout << "There's a sharp turn, would you prefer to change coords? (enter in new x,y)" << endl;
        cin >> x;
        cin >> y;
        coords[4] = x;
        coords[5] = y;
        result = calculate(coords);
      }
      cout << result << endl;
      clean_array(coords); //reduce the array size to zero.
    }
  }
}

  return 0;

}

char calculate(vector<int> &array){
  //the turn occurs at the second pair i.e. 2,3.
  //BAC Triangle, we're after the angle BAC, the angle which subtends the line BC.
  //LET BC = a, AC = b, AB = c.
  double a, b, c;
  double phi;
  double theta;

  a = sqrt(pow((array.at(0) - array.at(4)), 2) + pow((array.at(1) - array.at(5)), 2));
  b = sqrt(pow((array.at(2) - array.at(4)), 2) + pow((array.at(3) - array.at(5)), 2));
  c = sqrt(pow((array.at(0) - array.at(2)), 2) + pow((array.at(1) - array.at(3)), 2));

  phi = acos( - (pow(a,2) - pow(b,2) - pow(c,2) )/(2.0 * b * c));
  theta = M_PI - phi;

//check for a sharp turn. y means no sharp turn, n means sharp turn.
  if(theta > M_PI / 4.0){
    return 'n';

}  else {
    return 'y';
}

}


void read_coords(int &x, int &y, vector<int> &array){
//take a single pair of coord, store it in and print it to the console.
  array.push_back(x);
  array.push_back(y);
  cout << x << " " << y << endl;

}

void clean_array(vector<int> &array){
  array.clear();
}
