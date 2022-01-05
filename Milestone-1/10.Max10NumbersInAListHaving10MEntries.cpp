//Ques.  Find max 10 numbers in a list having 10M entries.

/* If we simply sort the list, it will take O(10M * log(10M)) time complexity. The better way is to cretae a min heap with first 10 elements.
Then we will create a loop starting from 11th element. Compare it with root(minimum element). If it is greater than root then delete the root element and insert the element in minheap.
After iterating the whole list, the minheap of 10 entries will be the max 10 numbers of the list. It will take O(10M*log(10)) */

//Let ll be a linked list having 1M entries.

#include <bits/stdc++.h>
using namespace std;
vector<int> heapArr;

void insertHeap(int val)
{
    auto i = heapArr.size();
    heapArr.emplace_back(val);
    
    while (i > 0 && val < heapArr[i % 2 == 0 ? (i/2)-1 : i/2]){
        heapArr[i] = heapArr[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    heapArr[i] = val;
}

void func(list <int> ll)
{
    list<int> :: iterator p=ll.begin();
    
    for(int i=0; i<10; i++)
    {
        insertHeap(*p);
        p++;
    }
    
    while(p!=ll.end())
    {
        if(heapArr[0]<*p)
        {
            //delete root element and add *p to heap.
            heapArr[0]=*p;
            int i=0, j=2*i+1;
            while(j<10)
            {
                if(j+1<10 && heapArr[j+1]<heapArr[j])
                j=j+1;
                if(heapArr[i]>heapArr[j])
                {
                    swap(heapArr[i], heapArr[j]);
                    i=j;
                    j=2*j+1;
                }
                else break;
            }
        }
        p++;
    }
    
}

int main()
{
    //This ll is just an example to show that code is working. We may take 10M elements in this list.
    list <int> ll {10, 1, 23, 18, 98, 24, 190, 22, 32, 10000, 234, 16789, 700, 102, 18279, 36894, 2346};
    func(ll);
    
    for(int i=0; i<heapArr.size(); i++)
    {
        cout<<heapArr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
