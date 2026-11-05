# include <iostream>
# include <fstream>
using namespace std;

int main(int argc, const char *argv[]){
    string filename = argv[1];
    ifstream ifs(filename);
    if (argc == 2){
        if ( ifs.is_open() ) {
            for (int i = 0; i < 3; i++){
                string city;
                double temp1;
                double temp2;
                double temp3;
                double temp4;
                double avg;
                ifs >> city >> temp1 >> temp2 >> temp3 >> temp4;
                avg = (temp1+temp2+temp3+temp4)/4;
                cout << "La temperatura media di " << city << " è di " << avg <<  " gradi " << "\n";
            }
        }
        else {
            cerr << "Il file non è stato aperto correttamente\n";
        } 
    } 
    else{
            cerr << "Non è stato specificato il parametro\n";
    }
    return 0;
}