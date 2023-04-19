#ifndef TRACK_LIBRARY_H
#define TRACK_LIBRARY_H
#pragma

#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 TrackLibrary.h
 Author: M00847153
 Updated: 20/04/2023
 */

struct Track {
    std::string title;
    std::string artist;
    int length_seconds;
};

class TrackLibrary {
private:
    std::unordered_map<std::string, Track> tracks_;
public:
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void addTrack(const std::string& artist, const std::string& title, int length_seconds);
    std::vector<Track> searchByArtist(const std::string& artist);
    void removeTrack(const std::string& artist, const std::string& title);
};

// TRACK_LIBRARY_H
#endif 

