#include <iostream>
#include <math.h>
using namespace std;
template <typename T>
class MySet
{
    T* arr;int size;
    public:
    MySet()
    {
        size=10;
        arr=new T[size];
    }
    MySet(int n)
    {
        size=n;
        arr=new T[size];
    }
    void input()
    {
        cout<<"\nEnter array elements\n";
        for(int i=0;i<size;i++)
            cin>>arr[i];
    }
    void display()
    {
        cout<<"\n{";
        for(int i=0;i<size;i++)
        {
            if(i==0)
                cout<<arr[i];
            else
                cout<<","<<arr[i];
        }
        cout<<"}\n";
    }
    void cardinality()
    {
        cout<<"\nCardinality of the given set is : "<<size<<endl;
    }
    void unique()
    {
        int i,j,k;
        for(i=0;i<size;++i)
        {
            for(j=i+1;j<size;)
            {
                if(arr[i]==arr[j])
                 {
                     for(k=j;k<size-1;k++)
                        arr[k]=arr[k+1];
                    --size;
                 }
                else
                ++j;
            }
        }
    }
    void powerset()
    {
        int count,temp;
        count=pow(2,size);
        cout<<"\n{{},";
        for(int i=1;i<count;i++)
        {
            cout<<"{";
            for(int j=0;j<size;j++)
            {
                if(i&(1<<j))
                {
                    cout<<arr[j]<<",";
                }
            }
            cout<<"},";
        }
        cout<<"}";
    }
    void operator = (const MySet &obj)
    {
        size=obj.size;
        for(int i=0;i<size;i++)
        arr[i]=obj.arr[i];
    }
    bool operator == (const MySet &obj)
    {
        if(size!=obj.size)
            return false;
        for(int i=0;i<size;i++)
            if(arr[i]!=obj.arr[i])
                return false;
        return true;
    }
    MySet operator + (MySet obj)
    {
        MySet un(size+obj.size);
        int j=0;
        for(int i=0;i<size;i++)
            un.arr[j++]=arr[i];
        for(int i=0;i<obj.size;i++)
            if(!hasElement(obj.arr[i]))
                un.arr[j++]=obj.arr[i];
        un.size=j;
        return un;
    }
    MySet operator * (MySet obj)
    {
        MySet in(size>obj.size?obj.size:size);
        int j=0;
        for(int i=0;i<size;i++)
            if(obj.hasElement(arr[i]))
                in.arr[j++]=arr[i];
        in.size=j;
        return in;
    }
    MySet operator - (MySet obj)
    {
        MySet diff(size);
        int j=0;
        for(int i=0;i<size;i++)
            if(!obj.hasElement(arr[i]))
                diff.arr[j++]=arr[i];
        diff.size=j;
        return diff;
    }
    MySet operator ^ (MySet obj2)
    {
        MySet diff1 = *this - obj2;
        MySet diff2 = obj2 - *this;
        MySet symdiff = diff1 + diff2;
        return symdiff;
    }
    bool hasElement(T element)
    {
        for(int i=0;i<size;i++)
            if(arr[i]==element)
                return true;
        return false;
    }
};
template <typename T>
void execute(T typevar)
{
        int choice;int size;
        cout<<"\n1. Find cardinality of given set.\n2. Find Powerset of the given set.\n3. Find the union of two sets.\n4. Find the intersection of two sets.\n5. Find A - B.\n6. Find B - A\n7. Find Symmetric Difference.\n";
        cin>>choice;
        cout<<"\nEnter the size of set 1\n";
        cin>>size;
        MySet<T> obj1(size);
        obj1.input();
        obj1.unique();
        if(choice == 1)
        obj1.cardinality();
        else if(choice==2)
        obj1.powerset();
        else
        {
            cout<<"\nEnter the size of set 1\n";
            cin>>size;
            MySet<T> obj2(size);
            obj2.input();
            obj2.unique();
            MySet<T> obj3;
            if(choice==3)
            obj3=obj1+obj2;
            else if(choice==4)
            obj3=obj1*obj2;
            else if(choice==5)
            obj3=obj1-obj2;
            else if(choice ==6)
            obj3=obj2-obj1;
            else if(choice==7)
            obj3=obj1^obj2;
            else
            {
                cout<<"\nWrong Input\n";
            }
            
        }
}
int main()
{
    int type;int integer;char character;double doubl;
    cout<<"\nEnter the type of set\n1. Integer\n2. Double\n3. Character\n";
    cin>>type;
    if(type==1)
    execute(integer);
    else if(type==2)
    execute(doubl);
    else if(type==3)
    execute(character);
    else
    cout<<"\nWrongInput\n";
    return 0;
}