#include <iostream>
#include <math.h>
using namespace std;

class site_loc;
class user_loc;

class user_loc
{
  private:
    double longitude;
    double latitude;

  public:
    user_loc(double lon, double lat)
    {
        longitude = lon;
        latitude = lat;
    };
    friend double distance(user_loc u, site_loc s);
};

class site_loc
{
  private:
    double longitude;
    double latitude;

  public:
    site_loc(double lon, double lat)
    {
        longitude = lon;
        latitude = lat;
    };
    friend double distance(user_loc u, site_loc s);
};

double distance(user_loc u, site_loc s)
{
    double dlon = u.longitude - s.longitude;
    double dlat = u.latitude - s.latitude;
    return sqrt(pow(dlon * 40000 / 360, 2) + pow(dlat * 40000 * cos(35.68 * 3.1416 / 180) / 360, 2));
};

int main()
{
    user_loc user = user_loc(36.086167, 140.105784);    //春日エリア
    site_loc library = site_loc(36.109065, 140.101438); //中央図書館
    cout << distance(user, library) << "km";
}