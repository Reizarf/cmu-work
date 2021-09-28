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
}data;


int TreeDataCmp(const DataType&, const DataType&);

#endif /* DataType_h */

