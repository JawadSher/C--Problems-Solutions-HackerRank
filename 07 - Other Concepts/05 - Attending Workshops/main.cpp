#include<bits/stdc++.h>

using namespace std;

struct Workshop{
    friend ostream& operator<<(ostream& os, const Workshop& obj);
    int start_time;
    int duration;
    int end_time;
    bool operator<(const Workshop& rhs){
        return (this->end_time < rhs.end_time);
    }
};

ostream& operator<<(ostream& os, const Workshop& obj){
    os<< obj.start_time << ": "<<obj.end_time<<":"<<obj.duration<<"\n";
    return os;
}

struct Available_Workshops{
    int signed_workshops;
    vector<Workshop> vec;
};

Available_Workshops* initialize(int start_time[], int duration[], int num){
   Available_Workshops *avail = new Available_Workshops;
   avail->signed_workshops = num;
   Workshop test;
   for(int i = 0; i < num; i++){
       test.start_time = start_time[i];
       test.duration = duration[i];
       test.end_time = start_time[i] + duration[i];
       avail->vec.push_back(test);
   }
   sort(avail->vec.begin(), avail->vec.end());
   return avail; 
}

int CalculateMaxWorkshops(Available_Workshops *test){
    int w_count = 0;
    int last_end_time = 0; 
    for(int i=0; i < test->signed_workshops; i++){
        if(test->vec[i].start_time >= last_end_time){
            w_count++;
            last_end_time = test->vec.at(i).end_time;
        }
    }
    return w_count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
