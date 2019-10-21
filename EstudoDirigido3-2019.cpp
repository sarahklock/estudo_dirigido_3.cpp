#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

using namespace std;

void apostas(int minimo, int maximo, vector <double> price, int &cartelas, int &dezenas){

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

    cout << endl << "Sendo o mínimo " << minimo << " e o máximo " << maximo <<", quantas dezenas deseja apostar? ";
    cin >> dezenas;

    while (dezenas < minimo || dezenas > maximo){
        cout << "Insira um valor válido: ";
        cin >> dezenas;
    }
}

vector <int> numeros_aleatorios(int intervalo, int dezenas){

    vector <int> numeros;

    for(int i = 0; i < dezenas; i++){
        
        srand(time(NULL));
        numeros.push_back(rand() % intervalo + 1);

        for(int x = 0; x < numeros.size(); x++){
            if((numeros[numeros.size() - 1] == numeros[x]) && (x != numeros.size() - 1)){
                    numeros.pop_back();
		    i--;
            }
        }
    }

    sort(numeros.begin(), numeros.end());

    return numeros;

}

void loterias(int mini, int maxi, int interval, vector <double> precos){

    int cartela, dezena;
    vector <int> numeros;

    apostas(mini, maxi, precos, cartela, dezena);

    system("cls"); //se seu dispositivo for Windows
    //system("clear"); //se seu dispositivo for Linux

    cout << endl << "O preço será: R$" << precos[dezena - mini] * cartela << endl << endl;

    cout << "Os números gerados foram: ";

    for(int i = 1; i <= cartela; i++){

        cout << endl << endl << "CARTELA/APOSTA " << i << ":" << endl;

        numeros = numeros_aleatorios(interval ,dezena);

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

        loterias(6,15,50,prices);

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

        loterias(5,15,80,prices);

        break;

    case 3:

        prices.push_back(1.50);

        loterias(50,50,100,prices);

        break;

    case 4:

        prices.push_back(2);
        prices.push_back(32);
        prices.push_back(272);
        prices.push_back(1632);

        loterias(15,18,25,prices);

        break;

    }


	return 0;
}
