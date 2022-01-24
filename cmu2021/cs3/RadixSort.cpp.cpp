/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void printArray(int array[],int n){

    
    for (int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}

void setArray(int array[],int n){
    for (int i=0;i<n;i++){
        array[i]=0;
    }
}


int main()
{
    int array[10] = {318,418,719,717,928,635,863,271,192,999};
    
    int bin0[10],index0=0;
    int bin1[10],index1=0;
    int bin2[10],index2=0;
    int bin3[10],index3=0;
    int bin4[10],index4=0;
    int bin5[10],index5=0;
    int bin6[10],index6=0;
    int bin7[10],index7=0;
    int bin8[10],index8=0;
    int bin9[10],index9=0;
    
    setArray(bin0,10);
    setArray(bin1,10);
    setArray(bin2,10);
    setArray(bin3,10);
    setArray(bin4,10);
    setArray(bin5,10);
    setArray(bin6,10);
    setArray(bin7,10);
    setArray(bin8,10);
    setArray(bin9,10);
    

    
    for (int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        int digit = 0;
        digit = array[i]%10;
        if (digit==0){
            bin0[index0]=array[i];
            index0++;
        }
        if (digit==1){
            bin1[index1]=array[i];
            index1++;
        }
        if (digit==2){
            bin2[index2]=array[i];
            index2++;
        }
        if (digit==3){
            bin3[index3]=array[i];
            index3++;
        }
        if (digit==4){
            bin4[index4]=array[i];
            index4++;
        }
        if (digit==5){
            bin5[index5]=array[i];
            index5++;
        }
        if (digit==6){
            bin6[index6]=array[i];
            index6++;
        }
        if (digit==7){
            bin7[index7]=array[i];
            index7++;
        }
        if (digit==8){
            bin8[index8]=array[i];
            index8++;
        }
        if (digit==9){
            bin9[index9]=array[i];
            index9++;
        }

        
    }
    printArray(array,10);
    cout<<endl<<endl;
    
    
    printArray(bin0,10);
    cout<<endl;
    printArray(bin1,10);
    cout<<endl;
    printArray(bin2,10);
    cout<<endl;
    printArray(bin3,10);
    cout<<endl;
    printArray(bin4,10);
    cout<<endl;
    printArray(bin5,10);
    cout<<endl;
    printArray(bin6,10);
    cout<<endl;
    printArray(bin7,10);
    cout<<endl;
    printArray(bin8,10);
    cout<<endl;
    printArray(bin9,10);
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if (bin0[j]!=0){
                array[i]=bin0[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin1[j]!=0){
                //cout<<endl;
                //cout<<"71"<<endl;
                array[i]=bin1[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin2[j]!=0){
                array[i]=bin2[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin3[j]!=0){
                array[i]=bin3[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin4[j]!=0){
                array[i]=bin4[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin5[j]!=0){
                array[i]=bin5[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin6[j]!=0){
                array[i]=bin6[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin7[j]!=0){
                array[i]=bin7[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin8[j]!=0){
                array[i]=bin8[j];
                i++;
            }
        }
        for(int j=0;j<10;j++){
            if (bin9[j]!=0){
                array[i]=bin9[j];
                i++;
            }
            
        }
    }
    cout<<endl;
    printArray(array,10);
    
    setArray(bin0,10);
    setArray(bin1,10);
    setArray(bin2,10);
    setArray(bin3,10);
    setArray(bin4,10);
    setArray(bin5,10);
    setArray(bin6,10);
    setArray(bin7,10);
    setArray(bin8,10);
    setArray(bin9,10);
    
    index0=0;
    index1=0;
    index2=0;
    index3=0;
    index4=0;
    index5=0;
    index6=0;
    index7=0;
    index8=0;
    index9=0;
    
    for (int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        int digit = 0;
        digit = (array[i]/10)%10;
        if (digit==0){
            bin0[index0]=array[i];
            index0++;
        }
        if (digit==1){
            bin1[index1]=array[i];
            index1++;
        }
        if (digit==2){
            bin2[index2]=array[i];
            index2++;
        }
        if (digit==3){
            bin3[index3]=array[i];
            index3++;
        }
        if (digit==4){
            bin4[index4]=array[i];
            index4++;
        }
        if (digit==5){
            bin5[index5]=array[i];
            index5++;
        }
        if (digit==6){
            bin6[index6]=array[i];
            index6++;
        }
        if (digit==7){
            bin7[index7]=array[i];
            index7++;
        }
        if (digit==8){
            bin8[index8]=array[i];
            index8++;
        }
        if (digit==9){
            bin9[index9]=array[i];
            index9++;
        }
    }
    
    printArray(bin0,10);
    cout<<endl;
    printArray(bin1,10);
    cout<<endl;
    printArray(bin2,10);
    cout<<endl;
    printArray(bin3,10);
    cout<<endl;
    printArray(bin4,10);
    cout<<endl;
    printArray(bin5,10);
    cout<<endl;
    printArray(bin6,10);
    cout<<endl;
    printArray(bin7,10);
    cout<<endl;
    printArray(bin8,10);
    cout<<endl;
    printArray(bin9,10);
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if (bin0[j]!=0){
                array[i]=bin0[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin1[j]!=0){
                //cout<<endl;
                //cout<<"71"<<endl;
                array[i]=bin1[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin2[j]!=0){
                array[i]=bin2[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin3[j]!=0){
                array[i]=bin3[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin4[j]!=0){
                array[i]=bin4[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin5[j]!=0){
                array[i]=bin5[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin6[j]!=0){
                array[i]=bin6[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin7[j]!=0){
                array[i]=bin7[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin8[j]!=0){
                array[i]=bin8[j];
                i++;
            }
        }
        for(int j=0;j<10;j++){
            if (bin9[j]!=0){
                array[i]=bin9[j];
                i++;
            }
            
        }
    }
    cout<<endl;
    printArray(array,10);
    
    setArray(bin0,10);
    setArray(bin1,10);
    setArray(bin2,10);
    setArray(bin3,10);
    setArray(bin4,10);
    setArray(bin5,10);
    setArray(bin6,10);
    setArray(bin7,10);
    setArray(bin8,10);
    setArray(bin9,10);
    
    index0=0;
    index1=0;
    index2=0;
    index3=0;
    index4=0;
    index5=0;
    index6=0;
    index7=0;
    index8=0;
    index9=0;
    
    for (int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        int digit = 0;
        digit = (array[i]/100)%10;
        if (digit==0){
            bin0[index0]=array[i];
            index0++;
        }
        if (digit==1){
            bin1[index1]=array[i];
            index1++;
        }
        if (digit==2){
            bin2[index2]=array[i];
            index2++;
        }
        if (digit==3){
            bin3[index3]=array[i];
            index3++;
        }
        if (digit==4){
            bin4[index4]=array[i];
            index4++;
        }
        if (digit==5){
            bin5[index5]=array[i];
            index5++;
        }
        if (digit==6){
            bin6[index6]=array[i];
            index6++;
        }
        if (digit==7){
            bin7[index7]=array[i];
            index7++;
        }
        if (digit==8){
            bin8[index8]=array[i];
            index8++;
        }
        if (digit==9){
            bin9[index9]=array[i];
            index9++;
        }
    }
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if (bin0[j]!=0){
                array[i]=bin0[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin1[j]!=0){
                //cout<<endl;
                //cout<<"71"<<endl;
                array[i]=bin1[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin2[j]!=0){
                array[i]=bin2[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin3[j]!=0){
                array[i]=bin3[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin4[j]!=0){
                array[i]=bin4[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin5[j]!=0){
                array[i]=bin5[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin6[j]!=0){
                array[i]=bin6[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin7[j]!=0){
                array[i]=bin7[j];
                i++;
            }
            
        }
        for(int j=0;j<10;j++){
            if (bin8[j]!=0){
                array[i]=bin8[j];
                i++;
            }
        }
        for(int j=0;j<10;j++){
            if (bin9[j]!=0){
                array[i]=bin9[j];
                i++;
            }
            
        }
    }
    cout<<endl;
    printArray(array,10);
    
    

    return 0;
}
