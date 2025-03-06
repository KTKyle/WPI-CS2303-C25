#include "Barista.h"

Barista::Barista(){
    ID = -1;
    is_busy = 0;
    task_start = -1;
    task_duration = -1;
    free_time = 0;
}

Barista::Barista(int a, int b, int c, int d, int e){
    ID = a;
    is_busy = b;
    task_start = c;
    task_duration = d;
    free_time = e;
}

void Barista::setID(int num){
    ID = num;
}

void Barista::setBusy(int num){
    is_busy = num;
}

void Barista::setStart(int num){
    task_start = num;
}

void Barista::setDuration(int num){
    task_duration = num;
}

void Barista::setFreeTime(int num){
    free_time = num;
}

void Barista::increaseFree(){
    free_time++;
}

void Barista::printBarista() {
    cout << "ID: " << ID 
         << " Busy: " << is_busy 
         << " Start: " << task_start 
         << " Duration: " << task_duration 
         << " Free Time: " << free_time << endl;
}

int Barista::getBusy(){
    return is_busy;
}

int Barista::getStart(){
    return task_start;
}

int Barista::getDuration(){
    return task_duration;
}

int Barista::getFreeTime(){
    return free_time;
}

int Barista::getID(){
    return ID;
}

ostream& operator<<(ostream& out, Barista barista) {
    out << "ID: " << barista.getID() 
        << " Busy: " << barista.getBusy() 
        << " Start: " << barista.getStart() 
        << " Duration: " << barista.getDuration() 
        << " Free Time: " << barista.getFreeTime();
    return out;
}
