//QLP File Generator for Gomoku game,
//Gomoku is a type of m,n,k game that is played in 15x15 board
// Winning condition is 5 in a row
// So Gomoku is 15,15,5 game
// This program creates .qlp file of the Gomoku game for QIP Solver
// Author Mert Saner
#include <iostream>
#include <fstream> //for writing to a file
using namespace std;

int main() {

    ofstream myfile; //Defining file name
    myfile.open("gomoku.qlp"); //Opening the file
    //Initialization of the Variables
    int i = 1; //for the x coordinate of the board
    int j = 1; //for the y coordinate of the board
    int k = 3; //k value
    int count1 = 0, count2 = 0, count3 = 0; //Counters for Constraints
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    int cntA1 = 0, cntA2 = 0, cntA3 = 0, cntA4 = 0, cntA5 = 0, cntA6 = 0, cntA7 = 0, cntA8 = 0, cntA9 = 0, cntA10 = 0; //Count for First Auxiliary  Constraints
    int cntA11 = 0, cntA12 = 0, cntA13 = 0, cntA14 = 0, cntA15 = 0;

    int cntB1 = 0, cntB2 = 0, cntB3 = 0, cntB4 = 0, cntB5 = 0, cntB6 = 0, cntB7 = 0, cntB8 = 0, cntB9 = 0, cntB10 = 0; //Count for Second Set Auxiliary  Constraints
    int cntB11 = 0, cntB12 = 0, cntB13 = 0, cntB14 = 0, cntB15 = 0;

    int cntC1 = 0, cntC2 = 0, cntC3 = 0;

    int cntD1 = 0, cntD2 = 0, cntD3 = 0, cntD4 = 0, cntD5 = 0, cntD6 = 0, cntD7 = 0, cntD8 = 0, cntD9 = 0, cntD10 = 0; //Count for Fourth Set Auxiliary  Constraints
    int cntD11 = 0, cntD12 = 0, cntD13 = 0, cntD14 = 0, cntD15 = 0;

    int cntE1 = 0, cntE2 = 0, cntE3 = 0, cntE4 = 0, cntE5 = 0, cntE6 = 0, cntE7 = 0, cntE8 = 0, cntE9 = 0, cntE10 = 0; //Count for Fifth Set Auxiliary  Constraints
    int cntE11 = 0, cntE12 = 0, cntE13 = 0, cntE14 = 0, cntE15 = 0;

    int cntF1 = 0, cntF2 = 0;
    int cntTemp = 0;
    int i2 = 1;

    myfile << "MAXIMIZE" << endl;
    myfile << "w225" << endl;
    myfile << "SUBJECT TO" << endl;
    myfile << "\\\\Existential Constrains" << endl;
    /*
     * First Existential Constraint Set
   */
    myfile << "\\\\First Constraint Set of Existential Player 6.11" << endl;

    for (count1 = 1; count1 < 25201; count1++) {
        //Printing
        myfile << "E_constraint" + to_string(count1) + ": ";
        myfile << "B" + to_string(i) + "_" + to_string(j) + "_" + to_string(k - 1) + " + ";
        myfile << "A" + to_string(i) + "_" + to_string(j) + "_" + to_string(k) + " <= 1" << endl;

        k = k + 2; //Increase k value in each step, k ∈ {3,5,7,9,...,225}

        if (k == 226 || k == 227) // Since k ∈ {3,5,7,9,...,225}
        {
            k = 3; //Resetting K value
            j = j + 1; //Increasing J value
            myfile << endl;
        }
        if (j == 16) {
            j = 1; //Resetting j value since board size is 3x3
            i = i + 1; //Increasing i Value in each three step
        }
    }

/*
 * Second Existential Constraint Set
*/
    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Second Constraint Set of Existential Player 6.12" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1;  //for the y coordinate of the board
    k = 3; //k value

    for (count2 = 0; count2 < 25200; count2++) {
        //Printing
        myfile << "E_constraint" + to_string(count1 + count2) + ": ";
        myfile << "A" + to_string(i) + "_" + to_string(j) + "_" + to_string(k - 2) + " - ";
        myfile << "A" + to_string(i) + "_" + to_string(j) + "_" + to_string(k) + " <= 0" << endl;
        k = k + 2; //Increase k value in each step, k ∈ {3,5,7,9,...225}
        
        if (k == 226 || k == 227) // Since k ∈ {3,5,7,9,...225}
        {
            k = 3; //Resetting K value
            j = j + 1; //Increasing J value
            myfile << endl;
        }
        if (j == 16) {
            j = 1; //Resetting j value since board size is 3x3
            i = i + 1; //Increasing i Value in each three step
        }
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
/*
 * Third Existential Constraint Set
*/
    myfile << "\\\\Third Constraint Set of Existential Player 6.13 (Ai_j_k)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    
    for (count3 = 0; count3 < 113; count3++) { //Until 113 Means until 15x15= 225 with odd numbers
        myfile << "E_constraint" + to_string(count1 + count2 + count3) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 15; e++) {

                if (e == 14 && d == 14) //This Helps to delete last sum symbol at the end of the equation
                {
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " = " + to_string((k / 2) + 1);
        k = k + 2;     //Increase k value in each step, k ∈ {3,5,7,9}
        myfile << endl;
    }

    /*
     * First Universal Constraint Set
     *
   */
    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Universal Constraints" << endl;
    myfile << "\\\\First Constraint Set of Universal Player 6.14" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value

    for (cnt1 = 1; cnt1 < 25201; cnt1++) {
        //Printing
        myfile << "U_constraint" + to_string(cnt1) + ": ";
        myfile << "A" + to_string(i) + "_" + to_string(j) + "_" + to_string(k - 1) + " + ";
        myfile << "B" + to_string(i) + "_" + to_string(j) + "_" + to_string(k) + " <= 1" << endl;

        k = k + 2; //Increase k value in each step, k ∈ {3,5,7,9}

        if (k == 226 || k == 227) // Since k ∈ {3,5,7,9}
        {
            k = 2; //Resetting K value
            j = j + 1; //Increasing J value
            myfile << endl;
        }
        if (j == 16) {
            j = 1; //Resetting j value since board size is 3x3
            i = i + 1; //Increasing i Value in each three step
        }
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
/*
 * Second Universal Constraint Set
*/
    myfile << "\\\\Second Constraint Set of Universal Player 6.15" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1;  //for the y coordinate of the board
    k = 4; //k value

    for (cnt2 = 0; cnt2 < 24975; cnt2++) //for 3x3 9 decrease, 15x15 225 decrease compared to initial Existential
    {
        //Printing
        myfile << "U_constraint" + to_string(cnt1 + cnt2) + ": ";
        myfile << "B" + to_string(i) + "_" + to_string(j) + "_" + to_string(k - 2) + " - ";
        myfile << "B" + to_string(i) + "_" + to_string(j) + "_" + to_string(k) + " <= 0 " << endl;

        k = k + 2; //Increase k value in each step, k ∈ {3,5,7,9}
        if (k == 226 || k == 227) // Since k ∈ {3,5,7,9}
        {
            k = 4; //Resetting K value
            j = j + 1; //Increasing J value
            myfile << endl;
        }
        if (j == 16) {
            j = 1; //Resetting j value since board size is 3x3
            i = i + 1; //Increasing i Value in each three step
        }
    }

/*
* Third Universal Constraint Set
*/
    myfile << "\\\\Third Constraint Set of Universal Player 6.16 (Ai_j_k) " << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value

    for (cnt3 = 0; cnt3 < 112; cnt3++) {  //Constraint Number Counter
        myfile << "U_constraint" + to_string(cnt1 + cnt2 + cnt3) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 15; e++) {

                if (e == 14 && d == 14) //This Helps to delete last sum symbol at the end of the equation
                {
                    myfile << "B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k);
                } else
                    myfile << "B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
            }
        }
        myfile << " = " + to_string(k / 2);
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        myfile << endl;
    }

/*
 * First Auxiliary Variables Set
 * 
*/
    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\First Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation


    for (cntA1 = 1; cntA1 < 114; cntA1++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Second Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 2; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA2 = 0; cntA2 < 113; cntA2++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Third Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 3; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA3 = 0; cntA3 < 113; cntA3++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 4; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA4 = 0; cntA4 < 113; cntA4++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3 + cntA4) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 5; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA5 = 0; cntA5 < 113; cntA5++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3 + cntA4 + cntA5) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Sixth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 6; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA6 = 0; cntA6 < 113; cntA6++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3 + cntA4 + cntA5 + cntA6) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Seventh Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 7; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA7 = 0; cntA7 < 113; cntA7++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3 + cntA4 + cntA5 + cntA6 + cntA7) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eighth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 8; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA8 = 0; cntA8 < 113; cntA8++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3 + cntA4 + cntA5 + cntA6 + cntA7 + cntA8) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Ninth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 9; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA9 = 0; cntA9 < 113; cntA9++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntA1 + cntA2 + cntA3 + cntA4 + cntA5 + cntA6 + cntA7 + cntA8 + cntA9) +
                  ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Tenth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 10; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA10 = 0; cntA10 < 113; cntA10++) {  //Constraint Number Counter
        myfile << "A_constraint" +
                  to_string(cntA1 + cntA2 + cntA3 + cntA4 + cntA5 + cntA6 + cntA7 + cntA8 + cntA9 + cntA10) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    cntTemp = cntA1 + cntA2 + cntA3 + cntA4 + cntA5 + cntA6 + cntA7 + cntA8 + cntA9 + cntA10;

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eleventh Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 11; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA11 = 0; cntA11 < 113; cntA11++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntA11) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }


    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Twelveth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 12; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA12 = 0; cntA12 < 113; cntA12++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntA11 + cntA12) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Thirteenth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 13; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA13 = 0; cntA13 < 113; cntA13++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntA11 + cntA12 + cntA13) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourteenth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 14; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA14 = 0; cntA14 < 113; cntA14++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntA11 + cntA12 + cntA13 + cntA14) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifteenth Set of Auxiliary Constraint Set 6.17" << endl;
    myfile << endl;

    i = 15; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntA15 = 0; cntA15 < 113; cntA15++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntA11 + cntA12 + cntA13 + cntA14 + cntA15) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5h" + to_string(i) + "___" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    cntTemp = cntTemp + cntA11 + cntA12 + cntA13 + cntA14 + cntA15;

/*
 * Second Auxiliary Variables Set (6.17.2)
 *
*/
    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\First Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB1 = 0; cntB1 < 113; cntB1++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Second Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 2; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB2 = 0; cntB2 < 113; cntB2++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1 + cntB2) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Third Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 3; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB3 = 0; cntB3 < 113; cntB3++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1 + cntB2 + cntB3) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 4; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB4 = 0; cntB4 < 113; cntB4++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1 + cntB2 + cntB3 + cntB4) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }


    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 5; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB5 = 0; cntB5 < 113; cntB5++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1 + cntB2 + cntB3 + cntB4 + cntB5) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Sixth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 6; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB6 = 0; cntB6 < 113; cntB6++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1 + cntB2 + cntB3 + cntB4 + cntB5 + cntB6) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Seventh Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 7; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB7 = 0; cntB7 < 113; cntB7++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1 + cntB2 + cntB3 + cntB4 + cntB5 + cntB6 + cntB7) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eighth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 8; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB8 = 0; cntB8 < 113; cntB8++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB1 + cntB2 + cntB3 + cntB4 + cntB5 + cntB6 + cntB7 + cntB8) +
                  ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Ninth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 9; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB9 = 0; cntB9 < 113; cntB9++) {  //Constraint Number Counter
        myfile << "A_constraint" +
                  to_string(cntTemp + cntB1 + cntB2 + cntB3 + cntB4 + cntB5 + cntB6 + cntB7 + cntB8 + cntB9) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Tenth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 10; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB10 = 0; cntB10 < 113; cntB10++) {  //Constraint Number Counter
        myfile << "A_constraint" +
                  to_string(cntTemp + cntB1 + cntB2 + cntB3 + cntB4 + cntB5 + cntB6 + cntB7 + cntB8 + cntB9 + cntB10) +
                  ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }
    
    cntTemp = cntTemp + cntB1 + cntB2 + cntB3 + cntB4 + cntB5 + cntB6 + cntB7 + cntB8 + cntB9 + cntB10;
    
    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eleventh Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 11; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB11 = 0; cntB11 < 113; cntB11++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB11) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }
    
    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Twelfth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 12; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB12 = 0; cntB12 < 113; cntB12++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB11 + cntB12) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Thirteenth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 13; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB13 = 0; cntB13 < 113; cntB13++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB11 + cntB12 + cntB13) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourteenth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 14; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB14 = 0; cntB14 < 113; cntB14++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB11 + cntB12 + cntB13 + cntB14) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifteenth Set of Second Auxiliary Constraint Set, (6.17.2)" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 15; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntB15 = 0; cntB15 < 113; cntB15++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntB11 + cntB12 + cntB13 + cntB14 + cntB15) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";

        }
        myfile << " - 5v__" + to_string(j) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    cntTemp = cntTemp + cntB11 + cntB12 + cntB13 + cntB14 + cntB15;

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\First Set of Third Auxiliary Constraint Set 6.17.3" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntC1 = 0; cntC1 < 113; cntC1++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntC1) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "A" + to_string(i + d) + "_" + to_string(i + d) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string(i + d) + "_" + to_string(k) + " + ";
        }
        myfile << " - 5d" + to_string(1) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\First Set of Fourth Auxiliary Constraint Set  6.17.4" << endl;
    myfile << endl;

    i = 0; //for the x coordinate of the board
    j = 0; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntC2 = 0; cntC2 < 113; cntC2++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntC1 + cntC2) + ": ";
        for (int d = 1; d < 16; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 15)
                myfile << "A" + to_string(i + d) + "_" + to_string((16 - d) + i) + "_" + to_string(k);
            else
                myfile << "A" + to_string(i + d) + "_" + to_string((16 - d) + i) + "_" + to_string(k) + " + ";
        }
        myfile << " - 5d" + to_string(2) + "_" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\First Set of Constraint Set 6.18 " << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    i2 = 1; //Right-hand side of the equation
    for (cntC3 = 0; cntC3 < 113; cntC3++) { //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntC1 + cntC2 + cntC3) + ": ";
        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 15; e++) {

                if (d == 0) { //Printing as much as given by the equation
                    myfile << "h" + to_string(i + e) + "__" + "_" + to_string(k) + " + ";
                } else if (d == 1) { //Printing as much as required by the equation
                    myfile << "v__" + to_string(i + e) + "_" + to_string(k) + " + ";
                } else if (d == 2) { //Printing as much as required by the equation
                    if (e != 0 && e != 1) //Printing only twice
                        continue;
                    else {
                        if (e == 1) {  //Removing one of sum sign after the print
                            myfile << "d" + to_string(i + e) + "_" + to_string(k);
                        } else {
                            myfile << "d" + to_string(i + e) + "_" + to_string(k) + " + ";
                        }
                    }
                }

            }
        }
        myfile << " - w" + to_string(k) + " >= 0 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        // i2++;
        myfile << endl;
    }

    cntTemp = cntTemp + cntC1 + cntC2 + cntC3;

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\First Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD1 = 0; cntD1 < 112; cntD1++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Second Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 2; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD2 = 0; cntD2 < 112; cntD2++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1 + cntD2) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Third Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 3; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD3 = 0; cntD3 < 112; cntD3++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1 + cntD2 + cntD3) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 4; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD4 = 0; cntD4 < 112; cntD4++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1 + cntD2 + cntD3 + cntD4) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 5; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD5 = 0; cntD5 < 112; cntD5++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1 + cntD2 + cntD3 + cntD4 + cntD5) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Sixth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 6; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD6 = 0; cntD6 < 112; cntD6++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1 + cntD2 + cntD3 + cntD4 + cntD5 + cntD6) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Seventh Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 7; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD7 = 0; cntD7 < 112; cntD7++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1 + cntD2 + cntD3 + cntD4 + cntD5 + cntD6 + cntD7) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eighth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 8; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD8 = 0; cntD8 < 112; cntD8++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD1 + cntD2 + cntD3 + cntD4 + cntD5 + cntD6 + cntD7 + cntD8) +
                  ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Ninth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 9; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD9 = 0; cntD9 < 112; cntD9++) {  //Constraint Number Counter
        myfile << "A_constraint" +
                  to_string(cntTemp + cntD1 + cntD2 + cntD3 + cntD4 + cntD5 + cntD6 + cntD7 + cntD8 + cntD9) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Tenth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 10; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD10 = 0; cntD10 < 112; cntD10++) {  //Constraint Number Counter
        myfile << "A_constraint" +
                  to_string(cntTemp + cntD1 + cntD2 + cntD3 + cntD4 + cntD5 + cntD6 + cntD7 + cntD8 + cntD9 + cntD10) +
                  ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    cntTemp = cntTemp + cntD1 + cntD2 + cntD3 + cntD4 + cntD5 + cntD6 + cntD7 + cntD8 + cntD9 + cntD10;

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eleventh Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 11; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD11 = 0; cntD11 < 112; cntD11++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD11) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Twelfth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 12; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD12 = 0; cntD12 < 112; cntD12++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD11 + cntD12) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Thirteenth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 13; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD13 = 0; cntD13 < 112; cntD13++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD11 + cntD12 + cntD13) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourteenth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 14; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD14 = 0; cntD14 < 112; cntD14++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD11 + cntD12 + cntD13 + cntD14) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifteenth Set Auxiliary Constraint Set 6.19" << endl;
    myfile << endl;

    i = 15; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntD15 = 0; cntD15 < 112; cntD15++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntD11 + cntD12 + cntD13 + cntD14 + cntD15) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";

        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8...,224}
        i2++;
        myfile << endl;
    }

    cntTemp = cntTemp + cntD11 + cntD12 + cntD13 + cntD14 + cntD15;

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE1 = 0; cntE1 < 112; cntE1++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...,}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Second Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 2; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE2 = 0; cntE2 < 112; cntE2++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1 + cntE2) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Third Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 3; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE3 = 0; cntE3 < 112; cntE3++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1 + cntE2 + cntE3) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 4; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE4 = 0; cntE4 < 112; cntE4++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1 + cntE2 + cntE3 + cntE4) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 5; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE5 = 0; cntE5 < 112; cntE5++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1 + cntE2 + cntE3 + cntE4 + cntE5) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Sixth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 6; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE6 = 0; cntE6 < 112; cntE6++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1 + cntE2 + cntE3 + cntE4 + cntE5 + cntE6) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,... }
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Seventh Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 7; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE7 = 0; cntE7 < 112; cntE7++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1 + cntE2 + cntE3 + cntE4 + cntE5 + cntE6 + cntE7) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eighth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 8; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE8 = 0; cntE8 < 112; cntE8++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE1 + cntE2 + cntE3 + cntE4 + cntE5 + cntE6 + cntE7 + cntE8) +
                  ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Ninth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 9; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE9 = 0; cntE9 < 112; cntE9++) {  //Constraint Number Counter
        myfile << "A_constraint" +
                  to_string(cntTemp + cntE1 + cntE2 + cntE3 + cntE4 + cntE5 + cntE6 + cntE7 + cntE8 + cntE9) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Tenth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 10; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE10 = 0; cntE10 < 112; cntE10++) {  //Constraint Number Counter
        myfile << "A_constraint" +
                  to_string(cntTemp + cntE1 + cntE2 + cntE3 + cntE4 + cntE5 + cntE6 + cntE7 + cntE8 + cntE9 + cntE10) +
                  ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    cntTemp = cntTemp + cntE1 + cntE2 + cntE3 + cntE4 + cntE5 + cntE6 + cntE7 + cntE8 + cntE9 + cntE10;

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Eleventh Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 11; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE11 = 0; cntE11 < 112; cntE11++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE11) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Twelveth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 12; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE12 = 0; cntE12 < 112; cntE12++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE11 + cntE12) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Thirteenth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 13; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE13 = 0; cntE13 < 112; cntE13++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE11 + cntE12 + cntE13) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fourteenth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 14; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE14 = 0; cntE14 < 112; cntE14++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE11 + cntE12 + cntE13 + cntE14) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Fifteenth Set of Auxiliary Constraint Set 6.19.2" << endl;
    myfile << endl;

    i = 1; //for the x coordinate of the board
    j = 15; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntE15 = 0; cntE15 < 112; cntE15++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntE11 + cntE12 + cntE13 + cntE14 + cntE15) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    cntTemp = cntTemp + cntE11 + cntE12 + cntE13 + cntE14 + cntE15;

    myfile<<"\\\\===================================================="<< endl;
    myfile<<"\\\\===================================================="<< endl;
    myfile << "\\\\Auxiliary Constraint Set 6.19.3" << endl;

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntF1 = 0; cntF1 < 112; cntF1++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntF1) + ": ";
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 14)
                myfile << "B" + to_string(i + d) + "_" + to_string(j + d) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j + d) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }

    myfile << "\\\\Auxiliary Constraint Set 6.19.4" << endl;
    myfile << endl;

    i = 0; //for the x coordinate of the board
    j = 0; //for the y coordinate of the board
    k = 2; //k value
    i2 = 1; //Right-hand side of the equation

    for (cntF2 = 0; cntF2 < 112; cntF2++) {  //Constraint Number Counter
        myfile << "A_constraint" + to_string(cntTemp + cntF1 + cntF2) + ": ";
        for (int d = 1; d < 16; d++) { //Two nested For loops Represents increase in i  and j value
            if (d == 15)
                myfile << "B" + to_string(i + d) + "_" + to_string(j + (16 - d)) + "_" + to_string(k);
            else
                myfile << "B" + to_string(i + d) + "_" + to_string(j + (16 - d)) + "_" + to_string(k) + " + ";
        }
        myfile << " - w" + to_string(k - 1) + " <= 4 ";
        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8,...}
        i2++;
        myfile << endl;
    }
    cntTemp = cntTemp + cntF1 + cntF2;

/*  Constraints set is finished
 * Final Part
 *
*/
    myfile << "BOUNDS" << endl;
   //Bound Set for A

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    int z = 1;
    for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            for (z = 1; z < 226; z++) {

                myfile << "0 <= A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(z) + " <= 1";
                myfile << endl;
                z = z + 1;
            }
        }
    }

    //Bound Set for B
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    z = 2;
    for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            for (z = 2; z < 226; z++) {

                myfile << "0 <= B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(z) + " <= 1";
                myfile << endl;
                z = z + 1;
            }
        }
    }

    //Bound Set for h
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            myfile << "0 <= h" + to_string(i + e) + "___" + to_string(k) + " <= 1";
            myfile << endl;
        }
        k = k + 2;
    }

    //Bound Set for v
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            myfile << "0 <= v__" + to_string(i + e) + "_" + to_string(k) + " <= 1";
            myfile << endl;
        }
        k = k + 2;
    }

   //Bound Set for d
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 1; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 113; e++) {
            myfile << "0 <= d" + to_string(d) + "_" + to_string(k) + " <= 1";
            myfile << endl;
            k = k + 2;
        }
        k = 1;
    }

    //Bound Set for w
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) {
        myfile << "0 <= w" + to_string(k) + " <= 1";
        myfile << endl;
        k = k + 2;
    }

    myfile << " "<< endl;
    myfile << "BINARIES" << endl;
    //Defining Variable  A in the .qlp

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    z = 1;
    for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            for (z = 1; z < 226; z++) {

                myfile << " A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(z) + " ";
                z = z + 1;
            }
        }
    }

    //Defining Variable  B in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    z = 2;
    for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            for (z = 2; z < 226; z++) {

                myfile << " B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(z) + " ";
                z = z + 1;
            }
        }
    }

    //Defining Variable h in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            myfile << " h" + to_string(i + e) + "___" + to_string(k) + " ";
        }
        k = k + 2;
    }

    //Defining Variable v in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            myfile << " v__" + to_string(i + e) + "_" + to_string(k) + " ";
        }
        k = k + 2;
    }

    //Defining Variable d in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 1; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 113; e++) {
            myfile << " d" + to_string(d) + "_" + to_string(k) + " ";
            k = k + 2;
        }
        k = 1;
    }

    //Defining Variable w in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) {
        myfile << " w" + to_string(k) + " ";
        k = k + 2;
    }

    myfile << " "<< endl;
    myfile << "EXISTS" << endl;
    //Same Structure with Binaries but B does exist here
    //Defining Variable  A in the .qlp

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    z = 1;
    for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            for (z = 1; z < 226; z++) {

                myfile << " A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(z) + " ";
                z = z + 1;
            }
        }
    }

    //Defining Variable h in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            myfile << " h" + to_string(i + e) + "___" + to_string(k) + " ";
        }
        k = k + 2;
    }

    //Defining Variable v in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            myfile << " v__" + to_string(i + e) + "_" + to_string(k) + " ";
        }
        k = k + 2;
    }

    //Defining Variable d in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 1; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 113; e++) {
            myfile << " d" + to_string(d) + "_" + to_string(k) + " ";
            k = k + 2;
        }
        k = 1;
    }

    //Defining Variable w in the .qlp
    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    for (int d = 0; d < 113; d++) {
        myfile << " w" + to_string(k) + " ";
        k = k + 2;
    }

    myfile << " "<< endl;
    myfile << "ALL" << endl;
    //Defining Variable  B in the .qlp

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    z = 2;
    for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
        for (int e = 0; e < 15; e++) {
            for (z = 2; z < 226; z++) {

                myfile << " B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(z) + " ";
                z = z + 1;
            }
        }
    }

    myfile << " "<< endl;
    myfile << "ORDER" << endl;
    //Printing  A in the .qlp

    i = 1; //for the x coordinate of the board
    j = 1; //for the y coordinate of the board
    k = 1; //k value
    z = 1;

    for (k = 1; k < 226; k++) { //Two nested For loops Represents increase in i  and j value
        for (int d = 0; d < 15; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e = 0; e < 15; e++) {
                if (k % 2!=0) {
                    myfile << " A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " ";
                }
                else {
                myfile << " B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k) + " ";
                }

                z = z + 1;
                }
            }
        i = 1; //for the x coordinate of the board
        j = 1; //for the y coordinate of the board
        for (int e = 0; e < 15; e++) {
            myfile << " h" + to_string(i + e) + "___" + to_string(k) + " ";
        }
        i = 1; //for the x coordinate of the board
        j = 1; //for the y coordinate of the board
        for (int e = 0; e < 15; e++) {
            myfile << " v__" + to_string(i + e) + "_" + to_string(k) + " ";
        }
        i = 1; //for the x coordinate of the board
        j = 1; //for the y coordinate of the board
        for (int d = 1; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
            myfile << " d" + to_string(d) + "_" + to_string(k) + " ";
        }
        i = 1; //for the x coordinate of the board
        j = 1; //for the y coordinate of the board
        myfile << " w" + to_string(k) + " ";
}
    myfile<<endl;
    //myfile<<"\\\\Total number of constraint is " + to_string(count1+ count2+ count3+ cnt1 + cnt2 + cnt3+ cntTemp) <<endl;
    myfile <<"END";   //End of the .qlp file Code
    myfile.close();
    cout<<"Writing is successful!"<<endl;
    //cout<<"CntTemp is: "+ to_string(cntTemp)<<endl;
    //Total number of constraint is 108003
    // cout<<"Total number of constraint is " + to_string(count1+ count2+ count3+ cnt1 + cnt2 + cnt3+ cntTemp) <<endl;
    return 0;
    //THE END
}