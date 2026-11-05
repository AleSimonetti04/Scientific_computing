# include <iostream>
# include <algorithm>
# include <cmath>

using namespace std;

int main()
{
    static const int N = 10;
    double arr[N] = {11.0, 3.0, 6.2, 52.5, 1.3, 5.12, 4.0, 31.4, 9.0, 16.8};
    double min_val = arr[0];
    double max_val = arr[0];
    
    // compute min_val, max_val
	for (int i = 1; i < N; i++){
		if (arr[i] <= min_val){
			min_val = arr[i];
			}
	}
    cout << "Il valore minimo dell'array è " << min_val << "\n";

    for (int j = 1; j < N; j++){
        if (arr[j] >= max_val){
            max_val = arr[j];
        }
    }
    cout << "Il valore massimo dell'array è " << max_val << "\n";
    /* otherwise, inside the for loop use the instructions:
    min_val = min(min_val, arr[i]);
    max_val = max(max_val, arr[j]); */

    // compute avg
    double sum = 0.0;
    for (int k = 0; k < N; k++){
        sum = sum + arr[k];
    }
    double avg = sum/N;
    cout << "Il valor medio degli elementi dell'array è " << avg << "\n";

    // compute stdev
    double dev_arr[N];
    for (int i = 0; i < N; i++){
        dev_arr[i] = ((arr[i] - avg)*(arr[i] - avg))/N;
    }

    double dev_sum = 0.0;
    for (int j = 0; j < N; j++){
        dev_sum = dev_sum + dev_arr[j];
    }

    double stdev = sqrt(dev_sum);
    cout << "La deviazione standard è data da " << stdev << "\n";
    
    return 0;
}