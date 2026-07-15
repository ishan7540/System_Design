#include <bits/stdc++.h>
using namespace std;

class AudioFile
{
protected:
    string filename;

public:
    AudioFile(string fname) : filename(fname) {}
    virtual void play() = 0;
    virtual double getDuration() = 0;
    virtual ~AudioFile()
    {
        cout << "Destroying: " << filename << endl;
    }
};

class MP3File : public AudioFile
{
    double duration;

public:
    MP3File(string fname, int dur) : AudioFile(fname), duration(dur) {}
    void play() override
    {
        cout << 'MP3 file playing: ' << filename << endl;
    }
    double getDuration() override
    {
        return duration;
    }
};

class FLACFile : public AudioFile
{
    double duration;

public:
    FLACFile(string fname, int dur) : AudioFile(fname), duration(dur) {}
    void play() override
    {
        cout << 'FLAC file playing: ' << filename << endl;
    }
    double getDuration() override
    {
        return duration;
    }
};
class WAVFile : public AudioFile
{
    double duration;

public:
    WAVFile(string fname, int dur) : AudioFile(fname), duration(dur) {}
    void play() override
    {
        cout << 'WAV file playing: ' << filename << endl;
    }
    double getDuration() override
    {
        return duration;
    }
};

class Playlist
{
    vector<AudioFile *> tracks;

public:
    void addTrack(AudioFile *file)
    {
        tracks.push_back(file);
    }
    void playAll()
    {
        for (auto track : tracks)
        {
            track->play();
        }
    }
    double totalDuration()
    {
        double sum = 0;
        for (auto track : tracks)
        {
            sum += track->getDuration();
        }
        return sum;
    }
    ~Playlist()
    {
        for (auto track : tracks)
        {
            delete track;
        }
    }
};

int main()
{
    Playlist playlist;
    playlist.addTrack(new MP3File("song.mp3", 210.5));
    playlist.addTrack(new WAVFile("track.wav", 180.0));
    playlist.addTrack(new FLACFile("album.flac", 305.2));

    playlist.playAll();
    cout << "Total duration: " << playlist.totalDuration() << " seconds" << endl;

    cout << "--- Playlist going out of scope ---" << endl;
    return 0;
}