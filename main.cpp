//#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int inputArrays(int *_A, int *_B, int N) {
  cout << "1. Vvedenya z consoli" << endl;
  cout << "2. Vvedenya z faily" << endl;
  cout << "3. Vvedenya randomom" << endl;
  cout << "Vvedit potribne" << endl;
  short int input;
  cin >> input;
  switch (input) {
  case 1: {
    cout << "Vvedit A\n";
    cout << "Input " << N << " numbers" << endl;
    for (int i = 0; i < N; i++) {
      cin >> _A[i];
    }
    cout << "Vvedit B\n";
    cout << "Input " << N << " numbers" << endl;
    for (int i = 0; i < N; i++) {
      cin >> _B[i];
    }
  } break;
  case 2: {
    ifstream inputA, inputB;
    inputA.open("/home/ober0n/Desktop/inputA");
    inputB.open("/home/ober0n/Desktop/inputB");
    if (!inputA.is_open()) {
      cout << "Error reading file A def!" << endl;
      return -1;
    }
    if (!inputB.is_open()) {
      cout << "Error reading file B def!" << endl;
      return -1;
    }
    cout << "Reading first " << N << " numbers from A file..." << endl;
    for (int i = 0; i < N; i++) {
      inputA >> _A[i];
    }
    for (int i = 0; i < N; i++) {
      inputB >> _B[i];
    }
  } break;
  case 3: {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
      _A[i] = (rand() % 10) - 5;
    }
    for (int i = 0; i < N; i++) {
      _B[i] = (rand() % 10) - 5;
    }
  } break;
  }
}
int inputArrays(vector<int> &_A, vector<int> &_B, const int N) {
  cout << "1. Vvedenya z consoli" << endl;
  cout << "2. Vvedenya z faily" << endl;
  cout << "3. Vvedenya randomom" << endl;
  cout << "Vvedit potribne" << endl;
  short int input;
  cin >> input;
  switch (input) {
  case 1: {
    cout << "Vvedit A\n";
    for (int i = 0; i < N; i++) {
      int temp;
      cin >> temp;
      _A.push_back(temp);
    }
    cout << "Vvedit B\n";
    for (int i = 0; i < N; i++) {
      int temp;
      cin >> temp;
      _B.push_back(temp);
    }
  } break;
  case 2: {
    ifstream inputA, inputB;
    inputA.open("/home/ober0n/Desktop/inputA");
    inputB.open("/home/ober0n/Desktop/inputB");
    if (!inputA.is_open()) {
      cout << "Error reading file A vect!" << endl;
      return -1;
    }
    if (!inputB.is_open()) {
      cout << "Error reading file B vect!" << endl;
      return -1;
    }
    cout << "Reading first " << N << " numbers from A file..." << endl;
    for (int i = 0; i < N; i++) {
      inputA >> _A[i];
    }
    for (int i = 0; i < N; i++) {
      inputB >> _B[i];
    }
  } break;

  case 3: {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
      _A.push_back((rand() % 10) - 5);
    }
    for (int i = 0; i < N; i++) {
      _B.push_back((rand() % 10) - 5);
    }
  } break;
  }
}
void printArrs(const int *_A, const int *_B, const int N) {
  cout << "Printing arrays\n";
  cout << "Printing A\n";
  for (int i = 0; i < N; i++) {
    cout << _A[i] << "\t";
  }
  cout << endl;
  cout << "Printing B\n";
  for (int i = 0; i < N; i++) {
    cout << _B[i] << "\t";
  }
  cout << endl;
}

void printArrs(const vector<int> &_A, const vector<int> &_B, const int N) {
  cout << "Printing arrays\n";
  cout << "Printing A\n";
  for (int i = 0; i < N; i++) {
    cout << _A[i] << "\t";
  }
  cout << endl;
  cout << "Printing B\n";
  for (int i = 0; i < N; i++) {
    cout << _B[i] << "\t";
  }
  cout << endl;
}

void changeArrs(int *_A, int *_B, const int N) {
  cout << "Changing.." << endl << endl;
  ;
  for (int i = 0; i < N; i++) {
    if (_A[i] > 0)
      _A[i] = _B[i];
  }
}

void changeArrs(vector<int> &_A, const vector<int> &_B, const int N) {
  cout << "Changing.." << endl << endl;
  ;
  for (int i = 0; i < N; i++) {
    if (_A[i] > 0)
      _A[i] = _B[i];
  }
}

int main() {
  int N;
  cout << "Vvedit N: ";
  cin >> N;
  if (N >= 100) {
    cout << "N < 100!" << endl;
    return -1;
  }

  cout << "1. Using default arrays\n";
  cout << "2. Using pointer malloc arrays\n";
  cout << "3. Using pointer new arrays\n";
  cout << "4. Using vectors\n";
  cout << "Vvedit potribne: ";
  short int input;
  cin >> input;
  switch (input) {
  case 1: {
    int A[100], B[100];
    int check = inputArrays(A, B, N);
    if (check == -1) {
      cout << "Shutdown" << endl;
      //_getch();
      return -1;
    }
    printArrs(A, B, N);
    changeArrs(A, B, N);
    printArrs(A, B, N);
  } break;
  case 2: {
    int *Apoint, *Bpoint;
    Apoint = (int *)malloc(N);
    Bpoint = (int *)malloc(N);
    int check = inputArrays(Apoint, Bpoint, N);
    if (check == -1) {
      cout << "Shutdown" << endl;
      // _getch();
      return -1;
    }
    printArrs(Apoint, Bpoint, N);
    changeArrs(Apoint, Bpoint, N);
    printArrs(Apoint, Bpoint, N);
    // free(Apoint); free(Bpoint);
  } break;
  case 3: {
    int *Apoint = new int[N];
    int *Bpoint = new int[N];
    int check = inputArrays(Apoint, Bpoint, N);
    if (check == -1) {
      cout << "Shutdown" << endl;
      //   _getch();
      return -1;
    }
    printArrs(Apoint, Bpoint, N);
    changeArrs(Apoint, Bpoint, N);
    printArrs(Apoint, Bpoint, N);
    delete[] Apoint;
    delete[] Bpoint;
  } break;
  case 4: {
    vector<int> Avect;
    vector<int> Bvect;
    int check = inputArrays(Avect, Bvect, N);
    if (check == -1) {
      cout << "Shutdown" << endl;
      //    _getch();
      return -1;
    }
    printArrs(Avect, Bvect, N);
    changeArrs(Avect, Bvect, N);
    printArrs(Avect, Bvect, N);
  } break;
  }

  cout << "Done" << endl;
  // _getch();
  return 0;
}
