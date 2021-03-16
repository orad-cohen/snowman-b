#include <string>
#include<array>
#include <iostream>
using namespace std;

#include "snowman.hpp"
const int NUM_OF_INSTRUCTIONS = 8;
const int VARIATION = 4;
const int UP_LIMIT = 5;
const int LOW_LIMIT=0;
const int BASE_10=10;
const int HAT = 0;
const int NOSE = 1;
const int LEYE = 2;
const int REYE = 3;
const int LARM = 4;
const int RARM = 5;
const int TORSO = 6;
const int BASE = 7;


namespace ariel{

    std::string snowman(int n){
        //initalize and fill the building blocks of the snowman
        array<array<string,VARIATION>,NUM_OF_INSTRUCTIONS> snow_shapes;
        snow_shapes[HAT]={" _===_", "  ___\n .....","   _  \n  /_\\ " ,"  ___\n (_*_)"};
        snow_shapes[NOSE]={",",".","_"," "};
        snow_shapes[LEYE]={".","o","O","-"};
        snow_shapes[REYE]={".","o","O","-"};
        snow_shapes[LARM]={"<"," ","/"," "};
        snow_shapes[RARM]={">"," ","\\"," "};
        snow_shapes[TORSO]={"( : )","(] [)","(> <)","(   )"};
        snow_shapes[BASE]={" ( : )"," (\" \")"," (___)"," (   )" };
        
        //disassmbling the instrucions to a convinent array;
        array<int,NUM_OF_INSTRUCTIONS> instructions{};
        
        for (int i = NUM_OF_INSTRUCTIONS-1; i >=0; i--)
        {               
            int lastdigit = n%BASE_10;
            //throw exception if we reached the end of n too soon.
            if(lastdigit==0){
                throw std::out_of_range("Instructions are too short");
            }
            //check if the correct range of instructions, otherwise throw exception
            if((lastdigit>LOW_LIMIT) && (lastdigit < UP_LIMIT)) {
                instructions.at(i) = n%BASE_10-1;
                n=n/BASE_10;
            }
            else{
                throw std::out_of_range("Instructions can be between 1 and 4 only");
            }
        }
        //check if we still have instructions left, than throw exception.
        if(n!=0){
                throw std::out_of_range("Instructions are too long");
            }
        
        string result = snow_shapes[HAT][instructions[HAT]];//initalize result with the head already built
        result+="\n";
        //build the head
        if(instructions[LARM]==1){result.append("\\");}
        else{result.append(" ");}
        result.append("("+snow_shapes[LEYE][instructions[LEYE]]+snow_shapes[NOSE][instructions[NOSE]]+snow_shapes[REYE][instructions[REYE]]+")");
        if(instructions[RARM]==1){result.append("/");}
        else{result.append(" ");}
        result+="\n";
        //build the torso
        result.append(snow_shapes[LARM][instructions[LARM]]+snow_shapes[TORSO][instructions[TORSO]]+snow_shapes[RARM][instructions[RARM]]);
        result+="\n";
        //build the base
        result.append(snow_shapes[BASE][instructions[BASE]]);
        return result;

        
        




       
    }


}
   