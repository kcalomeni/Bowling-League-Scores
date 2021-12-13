// Week6BowlingScores.cpp : This program calculates a bowling league's average bowling scores.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Declare count to count number of bowling league players.

int playerCount = 0;

// Create a function so we can store data from text file to our array.
void GetBowlingData(string filename, string name[100], int score[5][100]) {

	fstream file;
	// This will allow us to open our desired file.
	file.open("BowlingScores.txt", ios::in);

	// If the file is not found, the program will exit.
	if (!file) {
		cout << "File was not found";
		exit(0);
	}

	// Create a loop to scan the files data in the array.
	while (!file.eof()) {
		file >> name[playerCount];
		if (name[playerCount] == "")   break;
		for (int i = 0; i < 5; i++) {
			file >> score[i][playerCount];
		}
		playerCount++;
	}
	// To close our file.
	file.close();
    }
// Create a function to store the average bowling scores.
float *GetAverageScore(int score[5][100]){
	static float average[100];
	for (int i = 0; i << playerCount; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += score[j][i];
		}
		average[i] = float(sum) / 5;
	}

	return average;
}

// Create a function to print the details of the scores.
void PrettyPrintResults(string name[], int score[][100], float average[]) {
	// Create a heading for the output of the program.
	cout << "Name\t\t" << "Score1\t\tScore2\t\tScore3\t\tScore4\t\tScore5\t\tAverage" << endl;

	for (int i = 0; i < playerCount; i++) {
		if (name[i].length() > 7)
			cout << name[i] << "\t" << score[0][i] << "\t\t" << score[1][i] << "\t\t" << score[2][i] << "\t\t" << score[3][i] << "\t\t" << score[4][i] << average[i] << endl;
		else
			cout << name[i] << "\t\t" << score[0][i] << "\t\t" << score[1][i] << "\t\t" << score[2][i] << "\t\t" << score[3][i] << "\t\t" << score [4][i] << average[i] << endl;
	}
}

int main() {
	// Declare the arrays.
	string name[100];
	int score[5][100];
	float *average;

	// Call the functions.
	GetBowlingData("BowlingScores.txt", name, score);

	average = GetAverageScore(score);

	PrettyPrintResults(name, score, average);

	return 0;

}