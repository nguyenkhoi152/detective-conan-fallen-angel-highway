#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
double calculateAverageSpeed(int speed[], int size){
    double averageSpeed = 0;
    for (int i = 0; i < size; ++i) {
        averageSpeed += speed[i];
        }
    averageSpeed /= size;  
    return averageSpeed;  
    }
    

int findMaxSpeed(int speed[], int size){
    double maxspeed = 0;
    for (int i = 0; i < size; ++i) {
         speed[i] > maxspeed ? maxspeed = speed[i] : maxspeed = maxspeed;
        }
    return maxspeed;  
    }

double calculateSuspicion(int suspectSpeed, double blackRiderSpeed, int 
cameraMatch, int vehicleMatch, int evidence, int alibi){

}
int findPrimeSuspect(double suspicion[], int evidence[], int cameraMatch[], 
int size){

}
int findCriticalSegment(int segmentSpeed[], int speedLimit[], int danger[], 
int size){

}




void scene1(int segmentSpeed[], int speedLimit[], int danger[], int M){
    double overSpeed[5] = {};
    double riskScore[5] = {};
    string status[5];
    double highestRiskScore = 1;
    for (int i = 0; i < M; ++i) {
    overSpeed[i] = segmentSpeed[i] - speedLimit[i];
    if (overSpeed[i] < 0){
        overSpeed[i] = 0;}
    }
    for (int i = 0; i < 5; ++i) {
    if (overSpeed[i] <= 0){
        status[i] = "SAFE";
    }else if (overSpeed[i] > 0 && overSpeed[i] <= 20) {
        status[i] = "SPEEDING";
    } else if (overSpeed[i] > 20 && overSpeed[i] <= 50) {
        status[i] = "DANGEROUS";
    } else {
        status[i] = "EXTREME DANGER.";
    }
}
    for (int i = 0; i < M; ++i) {
        riskScore[i] = overSpeed[i]*2 + 5*danger[i];
    }
double tempRiskScore = riskScore[0];

for (int i = 1; i < M; ++i) {
    if (riskScore[i] > tempRiskScore) {
        tempRiskScore = riskScore[i]; 
        highestRiskScore = i + 1;
    }
}
    cout << "[Scene 1] Critical segment: " << highestRiskScore << '\n';    
}

void scene2(int segmentSpeed[], int N){
    double blackRiderSpeed = calculateAverageSpeed(segmentSpeed, N)*0.4 + findMaxSpeed(segmentSpeed, N)*0.6;
    cout << "[Scene 2] Estimated Black Rider Speed " << fixed << setprecision(1) << blackRiderSpeed << " km/h" ;
}


int main()
{ 

int M;
int segmentSpeed[5] = {};
int speedLimit[5] = {};
int danger[5] = {};
double riskScore[5] = {};


int N;
int speed[5] = {};
int alibi[5] = {};
int cameraMatch[5] = {};
int vehicleMatch[5];
int evidence[5] = {};
double suspicion[5] = {};


double blackRiderSpeed = 0;
int criticalSegment = 0;
int primeSuspect = 0;

cin >> M;


for (int i = 0; i < M; ++i)
{
    cin >> segmentSpeed[i] >> speedLimit[i] >> danger[i];
}


cin >> N;


for (int i = 0; i < N; ++i)
{
    cin >> speed[i] >> alibi[i] >> cameraMatch[i]
        >> vehicleMatch[i] >> evidence[i];
}
scene1(segmentSpeed, speedLimit, danger, M);
scene2(segmentSpeed, M);
return 0;
}


