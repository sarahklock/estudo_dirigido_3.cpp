#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

using namespace std;

void apostas(int minimo, int maximo, vector <double> price, int &cartelas, vector<int> &dezenas){

    cout << setw(30) << "TABELA DE PREÇOS" << endl << endl
         << "DEZENAS" << setw(35) << "PREÇO" << endl << endl;

    for (int a = minimo, b = 0; a <= maximo; a++, b++){
        cout << a << setw(40) << price[b] << endl;
    }

    cout << endl;

    do{
        cout << "Quantas apostas deseja realizar? ";
        cin >> cartelas;
    }while(cartelas <= 0);

    cout << endl << "Sendo o mínimo " << minimo << " e o máximo " << maximo <<", quantas dezenas deseja apostar na: ";

    for(int j = 0; j < cartelas; j++){

        int dezens;

        cout << j + 1 << "ª cartela?" << endl;

        cin >> dezens;

        dezenas.push_back(dezens);

        while (dezenas[j] < minimo || dezenas[j] > maximo){
            cout << "Insira um valor válido: ";
            cin >> dezenas[j];
        }
    }
}

vector<int> numeros_aleatorios(int dezenas, int comeco, int fim){

    vector<int> numeros;

    vector<int> possiveis_numeros;

    for(int j = comeco; j <= fim; j++){
        possiveis_numeros.push_back(j);

    }



    for(int i = 0; i < dezenas; i++){

        srand(time(NULL));

        int k = rand() % (possiveis_numeros.size() - 1);

        numeros.push_back(possiveis_numeros[k]);

        possiveis_numeros.erase(possiveis_numeros.begin() + k);
    }

    sort(numeros.begin(), numeros.end());

    return numeros;

}

void loterias(int mini, int maxi, int begining, int interval, vector <double> precos){

    int cartela;
    double preco_total = 0;
    vector<int> dezena;
    vector <int> numeros;

    apostas(mini, maxi, precos, cartela, dezena);

    system("cls"); //se seu dispositivo for Windows
    //system("clear"); //se seu dispositivo for Linux

    for(int dez: dezena){

        preco_total += precos[dez - mini];

    }

    cout << endl << "O preço será: R$" << preco_total << endl << endl;

    cout << "Os números gerados foram: ";

    for(int i = 0; i < cartela; i++){

        cout << endl << endl << "CARTELA/APOSTA " << i + 1 << ":" << endl;

        numeros = numeros_aleatorios(dezena[i], begining, interval);

        for(int numero: numeros){
            cout << numero << " ";
        }
    }

    cout << endl << endl << "Boa sorte, você precisará! Mas lembre-se de que tudo que você precisa está dentro de você. A"
         << endl << "felicidade está nas coisas mais simples, e para isso você não precisa ser milhonárie. =)" << endl;
}

int main(){

    setlocale(LC_ALL,"portuguese");

    int jogo;

    cout << fixed << setprecision(2);

    cout << "BEM VINDA(O) AO GERADOR DE APOSTAS!" << endl << endl
         << "Escolha um jogo:" << endl << endl
         << "[1] Mega-Sena" << endl
         << "[2] Quina" << endl
         << "[3] Lotomania" << endl
         << "[4] Lotofácil"<< endl
         << "[0] Sair" << endl << endl;

    cin >> jogo;

    system("cls"); //se seu dispositivo for Windows
    //system("clear"); //se seu dispositivo for Linux

    vector <double> prices;
    prices.clear();

    switch(jogo){

    case 1:

        prices.push_back(3.50);
        prices.push_back(24.50);
        prices.push_back(98);
        prices.push_back(294);
        prices.push_back(735);
        prices.push_back(1617);
        prices.push_back(3234);
        prices.push_back(6006);
        prices.push_back(10510.50);
        prices.push_back(17517.50);

        loterias(6,15,1,50,prices);

        break;

    case 2:

        prices.push_back(1.50);
        prices.push_back(9);
        prices.push_back(31.50);
        prices.push_back(84);
        prices.push_back(189);
        prices.push_back(378);
        prices.push_back(693);
        prices.push_back(1188);
        prices.push_back(1930.50);
        prices.push_back(3003);
        prices.push_back(4504.50);

        loterias(5,15,1,80,prices);

        break;

    case 3:

        prices.push_back(1.50);

        loterias(50,50,0,99,prices);

        break;

    case 4:

        prices.push_back(2);
        prices.push_back(32);
        prices.push_back(272);
        prices.push_back(1632);

        loterias(15,18,1,25,prices);

        break;

    }


	return 0;
}
