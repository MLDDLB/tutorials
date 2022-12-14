#include <memory>
#include <iostream>
#include <string>


class Song {
    private:
        std::string ti;
        std::string ar;
    public:
        Song(const std::string title, const std::string artist) : ti {title}, ar {artist} {}

        std::string title()
        {
            return this->ti;
        }

        std::string artist()
        {
            return this->ar;
        }
};


std::unique_ptr<Song> song_factory(const std::string& title, const std::string& artist)
{
    return std::make_unique<Song>(title, artist);
}


int main()
{
    auto p1 = std::make_unique<Song>("First title", "First artist");
    std::cout << "p1 points to:" << p1 << " title: " << p1->title() << " artist: " << p1->artist() << std::endl;
    std::cout << "p2 = move(p1) " << std::endl;
    auto p2 = std::move(p1);
    std::cout << "p2 points to: " << p2 << " title: " << p2->title() << " artist: " << p2->artist() << std::endl;
    std::cout << "p1 points to: " << p1 << std::endl;
    std::cout << "You can't copy p1 to p2 using a constructor and if you try to do it using the raw pointer underneath it will cause a doulbe free() error." << std::endl;
    auto p3 = song_factory("Second title", "Second artist");
    std::cout << "p3 was returned by value from the song_factory(string& title, string& artist) function" << std::endl;
    std::cout << "p3 points to: " << p3 << " title: " << p3->title() << " artist " << p3->artist() << std::endl;
    std::unique_ptr<int> arr[5] {};
    for (int i {0}; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}