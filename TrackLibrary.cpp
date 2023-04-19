#include "TrackLibrary.h"

/*
    Load tracks from a file and add them to the TrackLibrary
    @param filename the name of the file containing track information
*/

/*
TrackLibrary.cpp
 Author: M00847153
 Updated: 20/04/2023
 */

void TrackLibrary::loadFromFile(const std::string& filename) {
    std::ifstream input(filename);
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string artist, title, length_str;
        if (std::getline(iss, artist, '\t') && std::getline(iss, title, '\t') && std::getline(iss, length_str)) {
            int length_seconds = std::stoi(length_str);
            addTrack(artist, title, length_seconds);
        }
    }
    input.close();
}

/*
    Save track information to a file from the TrackLibrary
    @param filename the name of the file to save the track information
*/
void TrackLibrary::saveToFile(const std::string& filename) {
    std::ofstream output(filename);
    for (const auto& pair : tracks_) {
        output << pair.second.artist << '\t' << pair.second.title << '\t'
        << pair.second.length_seconds << std::endl;
    }
    output.close();
}

/*
    Add a track to the TrackLibrary
    @param artist the name of the artist of the track
    @param title the title of the track
    @param length_seconds the length of the track in seconds
*/
void TrackLibrary::addTrack(const std::string& artist, const std::string& title, int length_seconds) {
    Track track = { artist, title, length_seconds };
    std::string key = artist + "|" + title;
    tracks_[key] = track;
}

/*
    Search for tracks in the TrackLibrary by artist name
    @param artist the name of the artist to search for
    @return a vector of tracks by the specified artist
*/
std::vector<Track> TrackLibrary::searchByArtist(const std::string& artist) {
    std::vector<Track> result;
    for (const auto& pair : tracks_) {
        if (pair.second.artist == artist) {
            result.push_back(pair.second);
        }
    }
    return result;
}


/*
    Remove a track from the TrackLibrary
    @param artist the name of the artist of the track to remove
    @param title the title of the track to remove
*/
void TrackLibrary::removeTrack(const std::string& artist, const std::string& title) {
    std::string key = artist + "|" + title;
    tracks_.erase(key);
}