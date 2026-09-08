class Solution {
public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
//         //minute window
//         //brute force: for every interval we evaluate the final result of satisfaction to max satisfaction
//         // i for loop, as long as i < customers.length() - minutes
//         int n = customers.size();
//         int end = n - (minutes - 1);
//         int maxSat = 0;
//         int regSat = 0;

//         for(int i = 0; i < n; i++){
//             //calculating the regular lvl of satisfaction
//             if(grumpy[i] == 0){
//                 regSat += customers[i];
//             }
//         }

//         for(int i = 0; i < end; i++){

//             int techniqueSat = 0;

//             for(int j = i; j < (i + minutes); j++){

//                 //technique calc, only adding where the dude is grumpy
//                 if(grumpy[j] == 1){
//                     techniqueSat += customers[j];
//                 }
//             }

//             if(techniqueSat > maxSat){
//                     maxSat = techniqueSat;
//             }

//         }
//         //add it together
//         maxSat += regSat;
//         return maxSat;
//     }
// };
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int regSat = 0, window = 0, maxSat = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) regSat += customers[i];
            else                window += customers[i];   // entering on the right

            if (i >= minutes && grumpy[i - minutes] == 1)
                window -= customers[i - minutes];         // leaving on the left

            maxSat = max(maxSat, window);
        }
        return regSat + maxSat;
    }
};