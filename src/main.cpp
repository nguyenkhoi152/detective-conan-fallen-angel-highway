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

double scene2(int segmentSpeed[], int N){
    double blackRiderSpeed = calculateAverageSpeed(segmentSpeed, N)*0.4 + findMaxSpeed(segmentSpeed, N)*0.6;
        cout << "[Scene 2] Estimated Black Rider Speed " << fixed << setprecision(1) << blackRiderSpeed << " km/h" <<'\n' ;
    return blackRiderSpeed;
    }

void scene3(double blackRiderSpeed, int speed[], int N,
            double suspicion[], int cameraMatch[], int vehicleMatch[],
            int evidence[], int alibi[]) {
    double speedDiff[5];

    for (int i = 0; i < N; i++) {
        suspicion[i] = 0;
        speedDiff[i] = abs(speed[i] - blackRiderSpeed);

        if (speedDiff[i] <= 10) { suspicion[i] += 30; }
        else if (speedDiff[i] <= 30) { suspicion[i] += 15; }

        if (cameraMatch[i] >= 80) { suspicion[i] += 30; }
        else if (cameraMatch[i] >= 50) { suspicion[i] += 15; }

        if (vehicleMatch[i] >= 80) { suspicion[i] += 25; }
        else if (vehicleMatch[i] >= 50) { suspicion[i] += 10; }

        suspicion[i] += evidence[i] * 10;

        if (alibi[i] == 1) { suspicion[i] -= 40; }

        if (suspicion[i] < 0) { suspicion[i] = 0; }
        else if (suspicion[i] > 100) { suspicion[i] = 100; }

        string status;
        if (suspicion[i] >= 80) { status = "PRIME SUSPECT"; }
        else if (suspicion[i] >= 60) { status = "HIGHLY SUSPICIOUS"; }
        else if (suspicion[i] >= 40) { status = "SUSPICIOUS"; }
        else if (suspicion[i] >= 20) { status = "PERSON OF INTEREST"; }
        else { status = "LOW SUSPICION"; }

        cout << "[Scene 3] Suspect " << i + 1 << ": "
             << fixed << setprecision(1)
             << suspicion[i] << " - " << status << '\n';
    }
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
blackRiderSpeed = scene2(segmentSpeed, M);
scene3(blackRiderSpeed, speed, N, suspicion,
       cameraMatch, vehicleMatch, evidence, alibi);
return 0;
}


