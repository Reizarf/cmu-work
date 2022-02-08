
#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType  

#include "arrayListType.h" 
 
class unorderedArrayListType: public arrayListType
{
public:
    virtual void insertAt(int location, int insertItem);
    virtual void insertEnd(int insertItem);
    virtual void replaceAt(int location, int repItem);
    virtual int seqSearch(int searchItem) const;
    virtual void remove(int removeItem);

    unorderedArrayListType(int size = 100);
      //Constructor
}; 


#endif
