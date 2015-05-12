//
//  NaturalNumber.cpp
//  DMColloquium
//
//  Created by Ilya Kulebyakin on 4/28/15.
//  Copyright (c) 2015 Ilya Kulebyakin. All rights reserved.
//

#include "NaturalNumber.h"
using namespace std;

// put definitions for all methods over here.

NaturalNumber::NaturalNumber() {
    digitBlocks = std::vector<unsigned int>(1);
    digitBlocks[0] = 0;
}

NaturalNumber NaturalNumber:: DIV_NN_Dk(NaturalNumber x1, NaturalNumber x2)
{
	//DIV_NN_Dk
	//Created by Sergei Morozov on 5/09/15
	//Copyright (c) 2015 Sergei Morozov. All rights reserved.
NaturalNumber rez;
if(COM_NN_D(x1,x2)==0) {NaturalNumber k; k.digitBlocks[0]=1; return k;}  //If x1==x2
if(COM_NN_D(x1,x2)==1) {NaturalNumber sw; sw=x1; x1=x2; x2=sw;}// Now x1 > x2

while(MUL_Nk_N(x2,1)<x1) x2=MUL_Nk_N(x2,1); // x2->x2*10^k
NaturalNumber i;
i.digitBlocks[0]=1;
for (i;i.digitBlocks[0]<=9;i=ADD_1N_N(i))
    {if((MUL_NN_N(x2,i)<x1)&&(MUL_NN_N(x2,ADD_1N_N(i))>x1)) {rez.digitBlocks[0]=i.digitBlocks[0]; break;}}
return rez;
}
