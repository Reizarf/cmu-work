//
//  DataType.h
//  LinkedList
//
//  Created by Sherine Antoun on 4/13/20.
//  Copyright © 2020 Sherine Antoun. All rights reserved.
//

#ifndef DataType_h
#define DataType_h

#include <string>
using namespace std;

struct DataType
{
    string word;
    int freq;
};


int TreeDataCmp(const DataType&, const DataType&);
//or (const char* char_array,const char* char_array2)

#endif /* DataType_h */

