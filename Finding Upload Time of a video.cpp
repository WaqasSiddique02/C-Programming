#include <iostream>
using namespace std;

int main()
{
	double duration, size, speed, durationSeconds, sizeBits, uploadTime;

	cout << "Enter the duration of the video in minutes: ";
	cin >> duration;

	cout << "Enter the size of the video in gigabytes: ";
	cin >> size;
	cout << "Enter the internet speed in megabits per second: ";
	cin >> speed;

	durationSeconds = duration * 60;
	sizeBits = size * 8;

	uploadTime = sizeBits / speed;

	cout << "The upload time is " << uploadTime << " seconds." << endl;
	return 0;
}
