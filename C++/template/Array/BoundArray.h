// BoundArray.h
// BoundArray can check the safty of indexes
#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
template<typename T>
class BoundArray : public Array<T>  // inherit template class
{
private:
    int min;
public:
    BoundArray(int low=0, int height=1);
    virtual const T & Entry(int index)const;                // overload virtual function of Array<T>
    virtual void Enter(int index, const T & value);         // overload virtual function of Array<T>
};
template<typename T>
BoundArray<T>::BoundArray(int low, int height):Array<T>(height-low+1)
{
    if(height-low < 0)      // Check the boundary of array
    {
        std::cout<<"Beyond the bounds of Array.\n";
        exit(1);
    }
    min = low;
}
template<typename T>const T & BoundArray<T>::Entry(int index)const
{
    if(index<min || index > (min+Array<T>::size-1) )
    {
        std::cout<<"Beyond the bounds of index.\n";
        exit(1);
    }
    return Array<T>::Entry(index-min);
}
template<typename T>void BoundArray<T>::Enter(int index, const T &value)
{
    if(index<min || index>(min+Array<T>::size-1) )
    {
        std::cout<<"Beyond the bounds of index.\n";
        exit(1);
    }
    Array<T>::Enter(index-min, value);
}


#endif