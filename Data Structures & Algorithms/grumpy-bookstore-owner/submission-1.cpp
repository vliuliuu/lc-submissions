class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //minute window
        //brute force: for every interval we evaluate the final result of satisfaction to max satisfaction
        // i for loop, as long as i < customers.length() - minutes
        int end = customers.size() - (minutes - 1);

        int maxSat = 0;
        int regSat = 0;

        for(int i = 0; i < customers.size(); i++){
            //calculating the regular lvl of satisfaction
            if(grumpy[i] == 0){
                regSat += customers[i];
            }
        }

        for(int i = 0; i < end; i++){

            int techniqueSat = 0;

            for(int j = i; j < (i + minutes); j++){

                //technique calc, only adding where the dude is grumpy
                if(grumpy[j] == 1){
                    techniqueSat += customers[j];
                }

            }
            if(techniqueSat > maxSat){
                    maxSat = techniqueSat;
                }

        }
        //add it together
        maxSat += regSat;
        return maxSat;
    }
};