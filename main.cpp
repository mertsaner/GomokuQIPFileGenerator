

#include <iostream>
#include <fstream> //for writing to a file

using namespace std;

int main() {

    ofstream myfile; //Defining file name
    myfile.open ("gomoku.qlp"); //Opening the file
    //Initialization of the Variables
    int i=1; //for the x coordinate of the board
    int j=1; //for the y coordinate of the board
    int k=3; //k value
    int count1=0, count2=0, count3=0; //Counter for Existential Constraints
    int cnt1=0, cnt2, cnt3=0; //Count for Universal Constraints
    int cntA1=0, cntA2=0, cntA3=0, cntA4=0, cntA5=0, cntA6=0, cntA7=0, cntA8=0; //Count for Auxiliary  Constraints
    int cntA9=0, cntA10=0, cntA11=0, cntA12=0, cntA13=0, cntA14=0, cntA15=0, cntA16=0; //Count for Auxiliary  Constraints
    int cntA17=0, cntA18=0, cntA19=0, cntA20=0, cntA21=0, cntA22=0, cntA23=0, cntA24=0,cntA25=0,cntA26=0; //Count for Auxiliary  Constraints
    int cntTemp=0;
    int i2=1; //Right-hand side of the equation 6.17

    myfile<< "MAXIMIZE"<<endl;
    myfile<< "w9"<<endl;
    myfile<< "SUBJECT TO"<<endl;
    myfile<< "\\\\Existential Constrains"<<endl;
    myfile<< " "<<endl;

    /*
     * First Existential Constraint Set
   */

    myfile<<"\\\\First Constraint Set of Existential Player 6.11"<<endl;

    for(count1=1 ; count1<25201;count1++)
    {
        //Printing
        myfile<< "E_constraint" + to_string(count1) +": ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-1)+ " + ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 1"<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9,...,225}

        if (k==226 || k==227) // Since k ∈ {3,5,7,9,...,225}
        {
            k=3; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==16)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }

    myfile<< ""<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< ""<<endl;


/*
 * Second Existential Constraint Set
*/

    myfile<<"\\\\Second Constraint Set of Existential Player 6.12"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1;  //for the y coordinate of the board
    k=3; //k value

    for (count2=0 ;count2<25200; count2++)
    {
        //Printing
        myfile<< "E_constraint" + to_string(count1+count2) +": ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-2)+ " - ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 0"<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9,...225}


        if (k==226 || k==227) // Since k ∈ {3,5,7,9,...225}
        {
            k=3; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==16)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }

    myfile<< ""<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< ""<<endl;


/*
 * Third Existential Constraint Set
*/

    myfile<<"\\\\Third Constraint Set of Existential Player 6.13 (Ai_j_k)"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=1; //k value


    for (count3=0 ;count3<113; count3++) { //Until 113 Means until 15x15= 225 with odd numbers
        myfile << "E_constraint" + to_string(count1+ count2+ count3) + ": ";
        for (int d = 0; d<15; d++) { //Two nested For loops Represents increase in i  and j value
            for (int e=0; e<15; e++) {

                if (e==14 && d==14) //This Helps to delete last sum symbol at the end of the equation
                {
                    myfile << "A" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k);
                }
                else
                    myfile << "A" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
            }
        }
        myfile <<" = " + to_string((k/2)+1 );
        k=k+2;     //Increase k value in each step, k ∈ {3,5,7,9}
        myfile<<endl;
    }

    myfile<< ""<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< ""<<endl;

    /*
     * =====================================================================
     * =====================================================================
     * First Universal Constraint Set
   */
    myfile<< " "<<endl;
    myfile<< " "<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< " "<<endl;
    myfile<< " "<<endl;
    myfile<< "\\\\Universal Constraints"<<endl;
    myfile<< " "<<endl;
    myfile<<"\\\\First Constraint Set of Universal Player 6.14"<<endl;
    myfile<< endl;

    i=1; //for the x coordinate of the board
    j=1; //for the y coordinate of the board
    k=2; //k value

    for(cnt1=1 ; cnt1<25201;cnt1++)
    {
        //Printing
        myfile<< "U_constraint" + to_string(cnt1) +": ";
        myfile<<"A" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-1)+ " + ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 1"<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9}

        if (k==226 || k==227) // Since k ∈ {3,5,7,9}
        {
            k=2; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==16)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }



    myfile<< ""<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< "\\\\========================================================================================================="<<endl;
    myfile<< ""<<endl;
/*
 * Second Universal Constraint Set
*/

    myfile<<"\\\\Second Constraint Set of Universal Player 6.15"<<endl;
    myfile<<endl;

    i=1; //for the x coordinate of the board
    j=1;  //for the y coordinate of the board
    k=4; //k value

    for (cnt2=0 ;cnt2<24975; cnt2++) //for 3x3 9 decrease, 15x15 225 decrease compared to initial Existential
    {
        //Printing
        myfile<< "U_constraint" + to_string(cnt1+cnt2) +": ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k-2)+ " - ";
        myfile<<"B" + to_string(i)+ "_"+to_string(j)+ "_"+to_string(k)+ " <= 0 "<< endl;

        k=k+2; //Increase k value in each step, k ∈ {3,5,7,9}

        if (k==226 || k==227) // Since k ∈ {3,5,7,9}
        {
            k=4; //Resetting K value
            j=j+1; //Increasing J value
            myfile<<endl;
        }
        if (j==16)
        {
            j=1; //Resetting j value since board size is 3x3
            i=i+1; //Increasing i Value in each three step
        }
    }
/*
* Third Universal Constraint Set
*/
//
//    myfile<<"\\\\Third Constraint Set of Universal Player 6.16 (Ai_j_k) "<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=2; //k value
//
//    for (cnt3=0 ;cnt3<4; cnt3++) {  //Constraint Number Counter
//        myfile << "U_constraint" + to_string(cnt1 + cnt2 + cnt3) + ": ";
//        for (int d = 0; d<3; d++) { //Two nested For loops Represents increase in i  and j value
//            for (int e=0; e<3; e++) {
//
//                if (e==2 && d==2) //This Helps to delete last sum symbol at the end of the equation
//                {
//                    myfile << "B" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k);
//                }
//                else
//                    myfile << "B" + to_string(i+e) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
//            }
//        }
//        myfile <<" = "+ to_string(k/2);
//        k=k+2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        myfile<<endl;
//    }


//*
// *=====================================================================
// *=====================================================================
// * First Auxiliary Variables Set
// *
//*/
//    myfile<<endl;
//    myfile<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<<endl;
//    myfile<<"\\\\First Set of Auxiliary Constraint Set 6.17"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//
//    for (cntA1 = 1; cntA1 < 6; cntA1++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntA1) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k)+ " + ";
//        }
//        myfile <<" - 3h" + to_string(i) + "___" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//    myfile<<endl;
//    myfile<<"\\\\Second Set of Auxiliary Constraint Set 6.17"<<endl;
//    myfile<<endl;
//
//    i=2; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA2 = 0; cntA2 < 5; cntA2++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntA1+cntA2) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k)+ " + ";
//        }
//        myfile <<" - 3h" + to_string(i) + "___" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//    myfile<<endl;
//    myfile<<"\\\\Third Set of Auxiliary Constraint Set 6.17"<<endl;
//    myfile<<endl;
//
//    i=3; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA3 = 0; cntA3 < 5; cntA3++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntA1+cntA2+cntA3) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i) + "_" + to_string(j + d) + "_" + to_string(k)+ " + ";
//
//        }
//        myfile <<" - 3h" + to_string(i) + "___" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//    /*
// *=====================================================================
// *=====================================================================
// * Second Auxiliary Variables Set (6.17.2)
// *
//*/
//    myfile<<endl;
//    myfile<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<<endl;
//    myfile<<"\\\\First Set of Second Auxiliary Constraint Set, (6.17.2)"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA4 = 0; cntA4 < 5; cntA4++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntA1+cntA2+cntA3+cntA4) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "A" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k)+ " + ";
//
//        }
//        myfile <<" - 3v__" + to_string(j) + "_" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//    myfile<<endl;
//    myfile<<"\\\\Second Set Auxiliary Constraint Set 6.17.2"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=2; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA5 = 0; cntA5 < 5; cntA5++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntA1+cntA2+cntA3+cntA4+cntA5) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "A" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k)+ " + ";
//        }
//        myfile <<" - 3v__" + to_string(j) + "_" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//    myfile<<endl;
//    myfile<<"\\\\Third Set of Second Auxiliary Constraint Set, (6.17.2)"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=3; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA6 = 0; cntA6 < 5; cntA6++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntA1+cntA2+cntA3+cntA4+cntA5+cntA6) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "A" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k)+ " + ";
//        }
//        myfile <<" - 3v__" + to_string(j) + "_" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//
//    //Counting Temporary Sum of Counts
//    cntTemp=cntA1 + cntA2 + cntA3 + cntA4 + cntA5 + cntA6;
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<<endl;
//    myfile<<"\\\\First Set of Third Auxiliary Constraint Set 6.17.3"<<endl;
//    myfile<<endl;
//
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA7 = 0; cntA7 < 5; cntA7++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA7) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "A" + to_string(i+d) + "_" + to_string(i+d) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i+d) + "_" + to_string(i+d) + "_" + to_string(k)+ " + ";
//        }
//        myfile <<" - 3d" + to_string(1) + "_" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<<endl;
//    myfile<<"\\\\First Set of Fourth Auxiliary Constraint Set  6.17.4"<<endl;
//    myfile<<endl;
//
//
//    i=0; //for the x coordinate of the board
//    j=0; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA8 = 0; cntA8 < 5; cntA8++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA7+cntA8) + ": ";
//        for (int d = 1; d < 4; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==3)
//                myfile << "A" + to_string(i+d) + "_" + to_string((4-d)+i) + "_" + to_string(k);
//            else
//                myfile << "A" + to_string(i+d) + "_" + to_string((4-d)+i) + "_" + to_string(k)+ " + ";
//        }
//        myfile <<" - 3d" + to_string(2) + "_" + to_string(k) + " >= 0 " ;
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<<endl;
//    myfile<<"\\\\First Set of Second Auxiliary Constraint Set 6.18 "<<endl;
//    myfile<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    i2=1; //Right hand side of the equation
//    for (cntA9 = 0; cntA9 < 5; cntA9++) { //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA7+cntA8+cntA9) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            for (int e = 0; e < 3; e++) {
//
//                if (d==0) { //Printing as much as required given by the equation
//                    myfile << "h" + to_string(i + e) + "__" + "_" + to_string(k) + " + ";
//                }
//                else if (d==1)  { //Printing as much as required given by the equation
//                    myfile << "v__" + to_string(i+e) + "_" + to_string(k) + " + ";
//                }
//
//                else if(d==2) { //Printing as much as required given by the equation
//                    if (e==2) //Printing only twice
//                        continue;
//                    else{
//                        if (e==1) {  //Removing one of sum sign after the print
//                            myfile << "d" + to_string(i + e) + "_" + to_string(k);
//                        }
//                        else{
//                            myfile << "d" + to_string(i + e) + "_" + to_string(k) + " + ";
//                        }
//                    }
//                }
//
//            }
//        }
//        myfile << " - w" + to_string(k) + " >= 0 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        // i2++;
//        myfile << endl;
//    }
//
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<<endl;
//    myfile<<endl;
//    myfile<<"\\\\First Set Auxiliary Constraint Set 6.19"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA10 = 0; cntA10 < 4; cntA10++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA7+cntA8+cntA9+cntA10) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "B" + to_string(i) + "_" + to_string(j+d) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
//
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//    myfile<<endl;
//    myfile<<"\\\\Second Set Auxiliary Constraint Set 6.19"<<endl;
//    myfile<<endl;
//
//    i=2; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA11 = 0; cntA11 < 4; cntA11++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA7+cntA8+cntA9+cntA10+cntA11) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "B" + to_string(i) + "_" + to_string(j+d) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//    myfile<<endl;
//    myfile<<"\\\\Third Set Auxiliary Constraint Set 6.19"<<endl;
//    myfile<<endl;
//
//    i=3; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA12 = 0; cntA12 < 4; cntA12++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA7+cntA8+cntA9+cntA10+cntA11+cntA12) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "B" + to_string(i) + "_" + to_string(j+d) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//
//    cntTemp=cntTemp+cntA7+cntA8+cntA9+cntA10+cntA11+cntA12;
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<<"\\\\Auxiliary Constraint Set 6.19.2"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA13 = 0; cntA13 < 4; cntA13++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA13) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "B" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<<"\\\\Second Set of Auxiliary Constraint Set 6.19.2"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=2; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA14 = 0; cntA14 < 4; cntA14++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA13+cntA14) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "B" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
//
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<<"\\\\Third Set of  Constraint Set 6.19.2"<<endl;
//    myfile<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=3; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA15 = 0; cntA15 < 4; cntA15++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA13+cntA14+cntA15) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "B" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i+d) + "_" + to_string(j) + "_" + to_string(k) + " + ";
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//
//
//
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<<"\\\\Auxiliary Constraint Set 6.19.3"<<endl;
//    myfile<<endl;
//
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA16 = 0; cntA16 < 4; cntA16++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA13+cntA14+cntA15+cntA16) + ": ";
//        for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==2)
//                myfile << "B" + to_string(i+d) + "_" + to_string(j+d) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i+d) + "_" + to_string(j+d) + "_" + to_string(k) + " + ";
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//
//    myfile<<endl;
//    myfile<<endl;
//    myfile<<"\\\\Auxiliary Constraint Set 6.19.4"<<endl;
//    myfile<<endl;
//
//    i=0; //for the x coordinate of the board
//    j=0; //for the y coordinate of the board
//    k=2; //k value
//    i2=1; //Right hand side of the equation
//
//    for (cntA17 = 0; cntA17 < 4; cntA17++) {  //Constraint Number Counter
//        myfile << "A_constraint" + to_string(cntTemp+cntA13+cntA14+cntA15+cntA16+cntA17) + ": ";
//        for (int d = 1; d < 4; d++) { //Two nested For loops Represents increase in i  and j value
//            if (d==3)
//                myfile << "B" + to_string(i+d) + "_" + to_string(j+(4-d)) + "_" + to_string(k);
//            else
//                myfile << "B" + to_string(i+d) + "_" + to_string(j+(4-d)) + "_" + to_string(k) + " + ";
//        }
//        myfile << " - w" + to_string(k-1) + " <= 2 ";
//        k = k + 2;     //Increase k value in each step, k ∈ {2,4,6,8}
//        i2++;
//        myfile << endl;
//    }
//
//
//
//
//
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<< "\\\\========================================================================================================="<<endl;
//    myfile<<endl;
//
///*  Constraints set is finished
// * Final Part
// *
//*/
//    myfile <<"BOUNDS"<<endl;
//    myfile<<endl;
//
//    myfile <<"\\\\First Bound Set for A"<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//
//    myfile << endl;
//    myfile <<"\\\\Second Bound Set for A"<<endl;
//
//    //myfile << "0 <= A1_1_1 <= 1" << endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=3; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//
//
//    myfile << endl;
//    myfile <<"\\\\Third Bound Set for A"<<endl;
//
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=5; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//
//
//    myfile << endl;
//    myfile <<"\\\\Fourth Bound Set for A"<<endl;
//
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=7; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//
//    myfile << endl;
//    myfile <<"\\\\Fifth Bound Set for A"<<endl;
//
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=9; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= A" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//    myfile << endl;
//    myfile<<endl;
//
//
//
//
//
//
//    myfile <<"\\\\First Bound Set for B"<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=2; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//
//    myfile << endl;
//    myfile <<"\\\\Second Bound Set for B"<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=4; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//    myfile << endl;
//    myfile <<"\\\\Third Bound Set for B"<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=6; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//
//    myfile << endl;
//    myfile <<"\\\\Fourth Bound Set for B"<<endl;
//
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=8; //k value
//    for (int d = 0; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= B" + to_string(i + e) + "_" + to_string(j + d) + "_" + to_string(k)+ " <= 1";
//            myfile<<endl;
//        }
//    }
//
//    myfile<<endl;
//    myfile<<"\\\\Bound Set for h"<< endl;
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    for (int d = 0; d < 5; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= h" + to_string(i + e) + "___" + to_string(k) + " <= 1";
//            myfile<<endl;
//        }
//        k=k+2;
//    }
//
//
//    myfile<<endl;
//    myfile<<"\\\\Bound Set for v"<< endl;
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    for (int d = 0; d < 5; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 3; e++) {
//            myfile << "0 <= v__" + to_string(i + e) + "_" + to_string(k) + " <= 1";
//            myfile<<endl;
//        }
//        k=k+2;
//    }
//
//
//    myfile<<endl;
//    myfile<<"\\\\Bound Set for d"<< endl;
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    for (int d = 1; d < 3; d++) { //Two nested For loops Represents increase in i  and j value
//        for (int e = 0; e < 5; e++) {
//            myfile << "0 <= d" + to_string(d) + "_" + to_string(k) + " <= 1";
//            myfile<<endl;
//            k=k+2;
//        }
//        k=1;
//    }
//
//    myfile<<endl;
//    myfile<<"\\\\Bound Set for w"<< endl;
//    i=1; //for the x coordinate of the board
//    j=1; //for the y coordinate of the board
//    k=1; //k value
//    for (int d = 1; d < 6; d++) { //Two nested For loops Represents increase in i  and j value
//        myfile << "0 <= w" + to_string(k) + " <= 1";
//        myfile << endl;
//        k=k+2;
//    }
//
//    myfile<<endl;
//    myfile<<"BINARIES"<< endl;
//    myfile <<"A1_1_1 A2_1_1 A3_1_1 A1_2_1 A2_2_1 A3_2_1 A1_3_1 A2_3_1 A3_3_1"
//             " A1_1_3 A2_1_3 A3_1_3 A1_2_3 A2_2_3 A3_2_3 A1_3_3 A2_3_3 A3_3_3"
//             " A1_1_5 A1_2_5 A1_3_5 A2_1_5 A2_2_5 A2_3_5 A3_1_5 A3_2_5 A3_3_5"
//             " A1_1_7 A1_2_7 A1_3_7 A2_1_7 A2_2_7 A2_3_7 A3_1_7 A3_2_7 A3_3_7"
//             " A1_1_9 A1_2_9 A1_3_9 A2_1_9 A2_2_9 A2_3_9 A3_1_9 A3_2_9 A3_3_9"
//           <<endl;
//
//
//    myfile <<"B1_1_2 B2_1_2 B3_1_2 B1_2_2 B2_2_2 B3_2_2 B1_3_2 B2_3_2 B3_3_2"
//             " B1_1_4 B2_1_4 B3_1_4 B1_2_4 B2_2_4 B3_2_4 B1_3_4 B2_3_4 B3_3_4"
//             " B1_1_6 B2_1_6 B3_1_6 B1_2_6 B2_2_6 B3_2_6 B1_3_6 B2_3_6 B3_3_6"
//             " B1_1_8 B2_1_8 B3_1_8 B1_2_8 B2_2_8 B3_2_8 B1_3_8 B2_3_8 B3_3_8"
//           <<endl; //Defining Variables  B the .qlp
//
//    myfile <<"h1___1 h2___1 h3___1 h1___3 h2___3 h3___3 h1___5 h2___5 h3___5 "
//             "h1___7 h2___7 h3___7 h1___9 h2___9 h3___9"
//           <<endl; //Defining Variable h in the .qlp
//
//    myfile <<"v__1_1 v__2_1 v__3_1 v__1_3 v__2_3 v__3_3 v__1_5 v__2_5 v__3_5"
//             " v__1_7 v__2_7 v__3_7 v__1_9 v__2_9 v__3_9"
//           <<endl; //Defining Variable v in the .qlp
//
//    myfile <<"d1_1 d2_1 d1_3 d2_3 d1_5 d2_5 d1_7 d2_7 d1_9 d2_9"
//           <<endl; //Defining Variable d in the .qlp
//
//    myfile <<"w1 w3 w5 w7 w9"
//           <<endl; //Defining Variable w in the .qlp
//    myfile << endl;
//
//    myfile <<"EXISTS"<<endl;
//
//    myfile <<"A1_1_1 A2_1_1 A3_1_1 A1_2_1 A2_2_1 A3_2_1 A1_3_1 A2_3_1 A3_3_1 "
//             " A1_1_3 A2_1_3 A3_1_3 A1_2_3 A2_2_3 A3_2_3 A1_3_3 A2_3_3 A3_3_3"
//             " A1_1_5 A1_2_5 A1_3_5 A2_1_5 A2_2_5 A2_3_5 A3_1_5 A3_2_5 A3_3_5"
//             " A1_1_7 A1_2_7 A1_3_7 A2_1_7 A2_2_7 A2_3_7 A3_1_7 A3_2_7 A3_3_7"
//             " A1_1_9 A1_2_9 A1_3_9 A2_1_9 A2_2_9 A2_3_9 A3_1_9 A3_2_9 A3_3_9"
//           <<endl; //Defining Variable A in the .qlp
//
//
//    myfile <<"h1___1 h2___1 h3___1 h1___3 h2___3 h3___3 h1___5 h2___5 h3___5 "
//             "h1___7 h2___7 h3___7 h1___9 h2___9 h3___9"
//           <<endl; //Defining Variable h in the .qlp
//
//    myfile <<"v__1_1 v__2_1 v__3_1 v__1_3 v__2_3 v__3_3 v__1_5 v__2_5 v__3_5"
//             " v__1_7 v__2_7 v__3_7 v__1_9 v__2_9 v__3_9"
//           <<endl; //Defining Variable v in the .qlp
//
//    myfile <<"d1_1 d2_1 d1_3 d2_3 d1_5 d2_5 d1_7 d2_7 d1_9 d2_9"
//           <<endl; //Defining Variable d in the .qlp
//
//    myfile <<"w1 w3 w5 w7 w9"
//           <<endl; //Defining Variable w in the .qlp
//    myfile<<endl;
//
//
//    myfile <<"ALL"<<endl;
//
//    myfile <<"B1_1_2 B2_1_2 B3_1_2 B1_2_2 B2_2_2 B3_2_2 B1_3_2 B2_3_2 B3_3_2"
//             " B1_1_4 B2_1_4 B3_1_4 B1_2_4 B2_2_4 B3_2_4 B1_3_4 B2_3_4 B3_3_4"
//             " B1_1_6 B2_1_6 B3_1_6 B1_2_6 B2_2_6 B3_2_6 B1_3_6 B2_3_6 B3_3_6"
//             " B1_1_8 B2_1_8 B3_1_8 B1_2_8 B2_2_8 B3_2_8 B1_3_8 B2_3_8 B3_3_8"
//           <<endl; //Defining Variables  B the .qlp
//    myfile<<endl;
//
//
//
//    myfile <<"ORDER"<<endl;
//
//    myfile <<"A1_1_1 A2_1_1 A3_1_1 A1_2_1 A2_2_1 A3_2_1 A1_3_1 A2_3_1 A3_3_1"
//             " h1___1 h2___1 h3___1"
//             " v__1_1 v__2_1 v__3_1"
//             " d1_1 d2_1"
//             " w1"
//           <<endl;
//
//
//    myfile <<" B1_1_2 B2_1_2 B3_1_2 B1_2_2 B2_2_2 B3_2_2 B1_3_2 B2_3_2 B3_3_2"
//           <<endl;
//    myfile <<" A1_1_3 A2_1_3 A3_1_3 A1_2_3 A2_2_3 A3_2_3 A1_3_3 A2_3_3 A3_3_3"
//             " h1___3 h2___3 h3___3"
//             " v__1_3 v__2_3 v__3_3"
//             " d1_3 d2_3"
//             " w3"
//           <<endl;
//    myfile <<" B1_1_4 B2_1_4 B3_1_4 B1_2_4 B2_2_4 B3_2_4 B1_3_4 B2_3_4 B3_3_4"
//           <<endl;
//    myfile <<" A1_1_5 A1_2_5 A1_3_5 A2_1_5 A2_2_5 A2_3_5 A3_1_5 A3_2_5 A3_3_5"
//             " h1___5 h2___5 h3___5 "
//             " v__1_5 v__2_5 v__3_5 "
//             " d1_5 d2_5"
//             " w5"
//           <<endl;
//
//    myfile <<" B1_1_6 B2_1_6 B3_1_6 B1_2_6 B2_2_6 B3_2_6 B1_3_6 B2_3_6 B3_3_6"
//           <<endl;
//    myfile <<" A1_1_7 A1_2_7 A1_3_7 A2_1_7 A2_2_7 A2_3_7 A3_1_7 A3_2_7 A3_3_7"
//             " h1___7 h2___7 h3___7"
//             " v__1_7 v__2_7 v__3_7"
//             " d1_7 d2_7"
//             " w7"
//           <<endl;
//    myfile <<" B1_1_8 B2_1_8 B3_1_8 B1_2_8 B2_2_8 B3_2_8 B1_3_8 B2_3_8 B3_3_8"
//           <<endl;
//    myfile <<" A1_1_9 A1_2_9 A1_3_9 A2_1_9 A2_2_9 A2_3_9 A3_1_9 A3_2_9 A3_3_9"
//             " h1___9 h2___9 h3___9"
//             " v__1_9 v__2_9 v__3_9"
//             " d1_9 d2_9"
//             " w9"
//           <<endl; //Defining Variable A in the .qlp

    myfile <<"END";   //End of the .qlp file Code
    myfile.close();
    cout<<"Writing is successful!"<<endl;
    return 0;
    //THE END
}
