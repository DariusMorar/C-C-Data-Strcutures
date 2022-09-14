#include<iostream>
#include<vector>
using namespace std;
struct heap{
    vector<int> plane;

    heap(){
        plane.push_back(-1);
    }
    
    void insert(int minutes){
        plane.push_back(minutes);
        int currIndex = plane.size()-1;
        int parent = currIndex/2;
        while(parent>0 && plane[currIndex]<plane[parent]){
            int temp = plane[parent];
            plane[parent] = plane[currIndex];
            plane[currIndex] = temp;
            currIndex = parent;
            parent = currIndex/2;
        }
    }

    void print(){
        for (int i = 1; i < plane.size(); i++){
            cout<<plane[i]<<" ";
        }
        cout<<endl;
    }

    int extract_min(){
        if (plane.size()<=1){
            return -1;
        }
        
        int min = plane[1];
        plane[1] = plane[plane.size()-1];
        plane.pop_back();
        heapify(1);
        return min;
    }

    void heapify(int index){
        int left = 2 * index;
        int right = 2 * index+1;
        int curr = plane[index];
        int minIndex = index;
        if(left< plane.size() && plane[left]<curr){
            minIndex = left;
        }
        if(right< plane.size() && plane[right]<plane[minIndex]){
            minIndex = right;
        }
        swap(plane[index],plane[minIndex]);
        if(minIndex!=index){
            heapify(minIndex);
        }
        return;
    }

};
int main(){
    heap h;
    int choice = 0, minutes;
    while (choice != 4)
    {
        cout << " _________________________________ \n";
        cout << "|         Operations Menu         |\n";
        cout << "|1. Make a landing request        |\n";
        cout << "|2. Land a Plane                  |\n";
        cout << "|3. List all the landing requests |\n";
        cout << "|4. Exit                          |\n";
        cout << "|_________________________________|\n";
        cout << "Enter an option from the menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the estimated time possible before needing to land (in minutes): ";
            cin >> minutes;
            h.insert(minutes);
            break;
        case 2:
            cout << "The plane with original estimated landing wait time of " << h.extract_min() << " minutes has landed." << endl;
            break;
        case 3:
            h.print();
            break;
        case 4:
            cout << "Exiting program" << endl;
            break;
        }

    }
}