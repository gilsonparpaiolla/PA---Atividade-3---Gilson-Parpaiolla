#include <iostream>
#include <string>
#include "tInvestimento.cpp"

using namespace std;

bool verificadorString(string valores){
  int point = 0;
  for (int i = 0; i < valores.length(); i++){
    if ((((valores[i] < 48) || (valores[i] > 57)) && (valores[i] != 46)) || (point > 1)){
      return false;
    }else if (valores[i] == 46){
      point++;
    }
  }
  return true;
}

int main() {
  tInvestimento invest;
  bool is_playing = true;
  char choice;

  while (is_playing){
    bool is_choosing = true;
    string montante, juro, periodo;

    cout << "Digite o montante investido:" << endl;
    cin >> montante;
    cout << "Digite a taxa de juros ao ano: (%)" << endl;
    cin >> juro;
    cout << "Digite o periodo em anos que o dinheiro ficará investido:" << endl;
    cin >> periodo;


    if ((verificadorString(montante) == false) || (verificadorString(juro) == false) || (verificadorString(periodo) == false)){
      cout << "\033[2J\033[1;1H";
      cout << "Números invalidos" << endl;
      continue;
    }

    invest.montInvestido = stof(montante);
    invest.juroAno = stof(juro);
    invest.periodoAno = stof(periodo);

    invest.calculoJuros();
    invest.conversorJuro();
    invest.imprimirValores();

    cout << "\nDeseja calcular mais algum valor? s para sim, n para não" << endl;
    cin >> choice;

    while (is_choosing){
      if (choice == 'n'){
        is_playing = false;
        is_choosing = false;
      }else if(choice == 's'){
        cout << "\033[2J\033[1;1H";
        is_choosing = false;
      }else{
        cout << "Opção invalida, tente de novo, s para sim n para não" << endl;
        cin >> choice;
      }
    }

  }

  return 0;
}