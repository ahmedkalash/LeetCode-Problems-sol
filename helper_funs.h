//
// Created by Kalash on ٤/٢٩/٢٠٢٢.
//
#ifndef HELPER_FUNS_CPP
#define HELPER_FUNS_CPP
#include <iostream>
#include <string>
#include "cmath"
#include "vector"
#include "list"
#include "iterator"
using namespace std;
#define nn   <<endl
#define ss   <<" "<<
#define s    <<" "
template<typename T>
void swap(T *xp, T *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// ---------------------------------------------------------------
void sumStrDigits(const string& s1, string& s2, string& result)
{
    /* Pre-conditions:
            s1 must be longer or equal to s2
    */

    s2 += string((s1.size()-s2.size()),'0');

    // now s1.size() is equal to s2.size()
    int  fullResult=0;
    int carry=0;
    for (int i = 0; i < s2.size(); ++i)
    {
        fullResult = charToInt(s1.at(i)) + charToInt(s2.at(i)) + carry;
        result.push_back(intToChar(fullResult%10));
        carry = fullResult/10;
    }

    if(carry)
        result += to_string(carry);
}
void printWithoutL0s(const string& string1)
{
    int i = 0;
    for (; (i<string1.size()) && (string1[i] == '0'); ++i) ;
    for (int j = i; j < string1.size(); ++j)
        cout << string1[j];
}



double moD(double a, double d)
{
    /*
     * this function evaluates (a mod d).
     */
    if(a<d && a>=0)
        return 0;
    if (a<0)
        return d - moD(abs(a),d);
    double r,q;
    q= floor(a/d);
    r = a-d * q;
    return r;

}
double moD(int a, double d)
{
    /*
    * this overloading function evaluates (a mod d) in another way.
    */
    if(a<d && a>=0)
        return 0;
    if (a<0)
        return d - moD(abs(a),d);
    double r,q;
    q= floor(a/d);
    r = ((double)a/d - q ) *  d;
    return r;

}

string revers(string str )
{
    if(str.length()==0 || str.length()==1)
        return str;
    char curr=str[0];
    return revers(str.substr(1,str.length()-1) )+curr ;
}
long long findMin(vector<long long>& values)
{
    long long min=values[0];
    for (long long& i:values)
        if(i<min)
            min=i;
    return min;
}
long long findMax(vector<long long>& values)
{
    long long max=values[0];
    for (long long& i:values)
        if(i>max)
            max=i;
    return max;
}
void permute (string str, string p)
{
    if (str.length () == 0)
        cout << p<<" ";
    else{
        for (int i = 0; i < str.length(); i++){
            swap (str[0], str[i]);
            permute ( str.substr (1,str.length()-1), p + str.substr (0, 1));
        }
    }
}

bool isPrime(int num)
{
    if(num==2)
        return true;
    if (num<=1)
        return 0;
    static int div= 1;
    div++;
    if(num%div==0) {
        div = 1;
        return false;
    }
    if(div>= floor(sqrt(num))) {
        div = 1;
        return true;
    }
    isPrime(num);

}

// =======================================================================================================================

template<typename T>
void swap(T arr[],long long firstIndex, long long secondIndex)
{
    T temp =arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=temp;
}
template<typename T>
void partitioning(T arr[], long long left, long long& midIndex, long long right, char mode='a')  // the fun will tell us what is the value of midIndex, not we, so it was passed by ref.
{
    /*
     * we have 2 sets set1 and set2:
     * set1 is (the less than subArray). If it is not empty, It starts with left+1.
     * set2 is (the greater than subArray). 's2' points to the 1st item in set2.
     */
    long long i=left+1,
            pivotIndex=left,
            s2=left+1; // it always points to the 1st item in set2 (the greater than subArray).if set2 is empty then 's2' points to 'right+1'. So 's2-1' points to the last item in set1(the less than subArray)
    while (i<=right)
    {
        if(mode=='a')
        {
            if (arr[i].matches < arr[pivotIndex].matches) {
                swap(arr, i, s2);
                s2++;
            }
        }
        else if(mode=='d')
        {
            if (arr[i].matches  > arr[pivotIndex].matches ) {
                swap(arr, i, s2);
                s2++;
            }
        }
        i++;
    }
    swap(arr,pivotIndex,s2-1);
    pivotIndex=s2;
    midIndex=pivotIndex;  // midIndex=s2
}
template<typename T>
void quicksort(T arr[],long long left,long long right,char mode='a')
{
    if(left>=right)
        return;
    long long mid;
    partitioning(arr,left,mid,right,mode);
    long long leftSubArrEnd= mid - 1;
    long long RightSubArrStart= mid + 1;
    quicksort(arr, left, leftSubArrEnd,mode);
    quicksort(arr, RightSubArrStart, right,mode);
}








#endif //  HELPER_FUNS_CPP