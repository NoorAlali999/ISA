#include <iostream>
#include <fstream>
#include<cstdlib>
#include <string>
#include<cmath>
#include <stdlib.h>   
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)

{
   //Registers initialization

    int R0=0 ;
    int R1=1 ;
    int R2=2 ;
    int R3=3 ;
    int R4=4 ;
    int R5=5 ;
    int R6=6 ;
    int R7=7 ;
    int R8=8 ;
    int R9=9 ;
    int R10=10 ;
    int R11=11 ;
    int R12=12 ;
    int R13=13 ;
    int R14=14 ;
    int R15=15 ;



    //Memory initialization

    int Memo [1280] ;

    for (int i= 0 ; i<1280 ; i++)
    {
        Memo[i]= 5;
    }

    //Read The assembly program from text file and store the content in array of strings


    int k=0;

    string* arr = NULL;   // Pointer to int, initialize to nothing.

    int size;           // Size needed for array

     fstream newfile1, newfile2;

     string file= argv[1];

     int n = file.length();

 

    // declaring character array

    char char_array[n + 1];


    // copying the contents of the string to char array

    strcpy(char_array, file.c_str());

     newfile1.open(char_array,ios::in); 

     if (newfile1.is_open()) 
     { 

      string t1;    

      while(getline(newfile1, t1))
      { 

         size++;

      }


      string t2;

      arr = new string[size];

      newfile2.open(char_array,ios::in); 

      while(getline(newfile2, t2))

      {
         arr[k]=t2;
         k++;

      }

      newfile1.close();

   }

     //print the program

      for (int j = 0; j < size; j++)
      {
        cout<<arr[j]<<"\n";

      }


      //perform the instructions in the program


   for (int j = 0; j < size; j++)

   {
    if (arr[j].find("R") ==4 && arr[j].find("Add") ==0)
		R0 = R0 + R1;
   
   	else if (arr[j].find("R") ==4  && arr[j].find("Mul") ==0)
   	R0 = R0 * R1;

	else if (arr[j].find("R")  ==4 && arr[j].find("Div") ==0)
		R0 = R0 / R1;

	else if (arr[j].find("R") ==4  && arr[j].find("And") ==0)
		R0 = R0 & R1;

	else if (arr[j].find("R")  ==4  && arr[j].find("Orr") ==0) 
		R0 = R0 | R1;

	else if (arr[j].find("R")  ==4  && arr[j].find("Eql")  ==0)
	{	if (R0 == R1)
           R0 = 1; 

          else
              R0 = 0; 
    }

    else if (arr[j].find("R")  ==4  && arr[j].find("Les") == 0)
	{		if (R0 < R1)
         R0 = 1; 

          else
              R0 = 0; 
	}

	else if (arr[j].find("R") ==4 && arr[j].find("Ldd")  ==0)
		R0 = R1;

	else if (arr[j].find("R") ==4  && arr[j].find("Stt")  ==0)
		R1 = R0;

    else if ((arr[j].find("#")  == 4)  && ((int)arr[j].find("Add") == 0) )
    {     R0 = R0 + (arr[j][5]-48);

    }



	else if (arr[j].find("#") ==4  && arr[j].find("Mul")  ==0)
		R0 = R0 * (arr[j][5]-48);

	else if (arr[j].find("#")  ==4 && arr[j].find("Div") ==0)
		R0 = R0 / (arr[j][5]-48);

	else if (arr[j].find("#")  ==4 && arr[j].find("And") ==0)
		R0 = R0 & (arr[j][5]-48);

	else if (arr[j].find("#")  ==4 && arr[j].find("Orr") ==0) 
		R0 = R0 | (arr[j][5]-48);

	else if (arr[j].find("#")  ==4 && arr[j].find("Eql")  ==0)
	{	if (R0 == (arr[j][5]-48))
           R0 = 1; 

          else
              R0 = 0; 
    }

    else if (arr[j].find("#") ==4  && arr[j].find("Les")  ==0)
	{
		if (R0 < arr[j][5])
      R0 = 1; 

          else
              R0 = 0; 

	}

	else if (arr[j].find("#") ==4  && arr[j].find("Ldd") ==0)
		R0 = (arr[j][5]-48);

	else if (arr[j].find("Add")  ==0)
		R0 = R0 + Memo[arr[j][4]];

	else if (arr[j].find("Mul") ==0)
		R0 = R0 * Memo[arr[j][4]];

	else if ( arr[j].find("Div") ==0)
		R0 = R0 / Memo[arr[j][4]];

	else if (arr[j].find("And") ==0)
		R0 = R0 & Memo[arr[j][4]];

	else if ( arr[j].find("Orr")  ==0) 
		R0 = R0 | Memo[arr[j][4]];

	else if ( arr[j].find("Eql")  ==0)
	{	if (R0 == Memo[arr[j][4]])
           R0 = 1; 
          else
              R0 = 0; 
    }

    else if ( arr[j].find("Les")  ==0)
	{
		if (R0 < Memo[arr[j][4]])
         R0 = 1; 
          else
              R0 = 0; 
	}


	else if ( arr[j].find("Ldd")  ==0)
		R0 = Memo[arr[j][4]];

	else if ( arr[j].find("Stt") ==0)
		Memo[arr[j][4]] = R0;

    else if ( arr[j].find("Hlt")  ==0)
    {
       cout<<"Stop CPU operations"<<endl ;
      break;
    }


   }


  //print the final value of R0
    cout<<"R0 = "<<R0;


    return 0;



}