using namespace std;
#include<iostream>

class GrowArray
{
   private:
   
   int* array;
   int size;		//Holds the current number of elements
   int capacity;	// maximum number of elements allowed

   public:

   GrowArray(int amount);
   ~GrowArray();
   void ExpandArray();
   void SetArray(int start);
   void AddElement(int element);
   int getElementAt(int index);
   void RemoveElementAt(int index);   
   void pop();		//Removes an element from the end of the array
   void Display();
   

};

GrowArray::GrowArray(int amount)
{
   capacity = amount;
   size = 0;
   array = new int[capacity];
  
   for(int i = 0; i < size; i++)
     array[i] = 0;
}

void GrowArray::ExpandArray()
{
   int* newArray;
   capacity *=2;
   newArray = new int[capacity];

   for(int i = 0; i < size; i++)
      newArray[i] = array[i]; 
    
   //We must delete the original array and reassign 
   //The new array
   delete[] array;
   array = newArray; 

   SetArray(size);
}

void GrowArray::AddElement(int element)
{
   if(size >= capacity)
     ExpandArray();    
   
   array[size++] = element;
}
int GrowArray::getElementAt(int index)
{
   if(index < 0 || index >= size)
   {
      cout<<"Invalid location"<<endl;
      return index;
   }
   
   else
   {
     cout<<"Element selected from position "<<index<<endl;
     return array[index];
   }
}

void GrowArray::RemoveElementAt(int index)
{
   if(index < 0 || index >= size)
      cout<<"Invalid location. No element removed"<<endl;
   
   else
   {
     cout<<"Element removed from position "<<index<<endl;
     array[index] = 0;
   }

}

void GrowArray::SetArray(int start)
{
   for(int i = start; i < capacity; i++)
      array[i] = 0;
}

void GrowArray::Display()
{
   for(int i = 0; i < size; i++)
      cout<<array[i]<< " ";
   cout<<endl;
}
void GrowArray::pop()
{
   if(size == 0)
      cout<<"The array is empty"<<endl;
   
   else
      array[--size] = 0;

   cout<<"Remove the last element"<<endl;
}

GrowArray::~GrowArray()
{
   cout<<"Freeing all of the memory\n";
   delete[] array;

}


int main()
{
  int numelements;
  int value = -1;	//Initializing to start while loop to enter elements into the array 
  int position;
  cout<<"How many array elements would you like?";
  cin>>numelements;

  while(numelements < 0)
  {
     cout<<"This must be positive ";
     cin>>numelements;
  }

  GrowArray array(numelements);

  while(value != 0)
  {
     cout<<"Add an element to the array(Enter 0 to stop)"<<endl;
     cin>>value;
     
     if(value != 0)
       array.AddElement(value);
  }
  
  array.Display();

  cout<<"Choose an element to locate"<<endl;
  cin>>position;
  cout<<array.getElementAt(position)<<endl;
  cout<<"Choose an element to remove"<<endl;
  cin>>position;
  array.RemoveElementAt(position);
  array.Display();
  array.pop();
  array.Display();
  return 0;
  
}
