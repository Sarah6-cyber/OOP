#include<iostream>
using namespace std;

class MediaFile{
    protected:
    string filePath;
    int size;
    public:
    MediaFile(string f, int s) : filePath(f) , size(s){}
    void play(){
        cout<<"Playing media from "<<filePath<<endl;
    }
    void stop(){
        cout<<"Media playing stopped"<<endl;
    }
};

class VisualMedia : virtual public MediaFile{
    protected:
    int resolution;
    public:
    VisualMedia(string f, int s, int r) : MediaFile(f,s){
        resolution=r;
    }
    void displayResolution(){
        cout<<"Resolution: "<<resolution<<endl;
    }
};

class AudioMedia : virtual public MediaFile{
    protected:
    int sampleRate;
    public:
    AudioMedia(string f, int s, int rate) : MediaFile(f,s){
        sampleRate=rate;
    }
    void displaySampleRate(){
        cout<<"Sample Rate: "<<sampleRate<<endl;
    }
};

class VideoFile : public VisualMedia , public AudioMedia{
    float duration;
    public:
    VideoFile(string path, int s, int res, int rate, float dur) : MediaFile(path,s), VisualMedia(path,s,res), AudioMedia(path,s,rate){
        duration=dur;
    }
    void showVideoDetails(){
        cout<<"--------VIDEO DETAILS-----------------------"<<endl;
        cout<<"Path: "<<filePath<<endl;
        cout<<"Size: "<<size<<" MB"<<endl;
        cout<<"Resolution: "<<resolution<<endl;
        cout<<"Sample Rate: "<<sampleRate<<endl;
        cout<<"Duration: "<<duration<<endl;
    }
};

int main() {
    VideoFile v("video1.mp4", 300, 1024, 42200, 3.7);
    v.play();
    v.showVideoDetails();
    v.displayResolution();
    v.displaySampleRate();
    v.stop();
    return 0;
}
