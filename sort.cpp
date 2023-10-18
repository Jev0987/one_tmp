#include <iostream>
#include <vector>

using namespace std;
void insertsort(vector<int> &arr){
    int n = arr.size();

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void shellsort(vector<int> &arr){
    int n = arr.size();

    int gap = n / 2;

    while(gap > 0){
        for(int i = gap; i < n; i++){
            int tmp = arr[i];
            int j = i;

            while(j >= gap && arr[j - gap] > tmp){
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
        gap /= 2;
    }
    return;
}


int main(){
    vector<int> test = {32,54,656,23,213,5,446,1,4,0};
    shellsort(test);

    for(int num : test){
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}