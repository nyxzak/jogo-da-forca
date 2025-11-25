#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
    for(char letra : PALAVRA_SECRETA){
        if(chute == letra){
            return true;
        }

    }
    return false;
}

bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA) {
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
    cout << "*************************" << endl;
    cout << "******JOGO DA FORCA******" << endl;
    cout << "*************************" << endl;
    cout << endl;
}

void imprime_erros(){
            cout << "Chutes Errados: ";
            
        for(char letra: chutes_errados){
            cout << letra << " ";
        }
        cout << endl;
}

void imprime_palavra(){
     for (char letra : PALAVRA_SECRETA){
        if(chutou[letra]) {
          cout << letra << " ";
        } else {
          cout << "_ ";
            }
       }
         cout << endl;
}

void chuta(){
    cout << "Seu chute: ";
        char chute;
    cin >> chute;
        chutou[chute] = true;

        if (letra_existe(chute)){
            cout << "Voce Acertou!! Seu chute esta na palavra." << endl;
        }else{ 
                cout << "Voce errou! Seu chute nao esta na palavra." << endl;
                chutes_errados.push_back(chute);
        }
           cout << endl;
}

int main () {
    imprime_cabecalho();

    while (nao_acertou() && nao_enforcou()) {
        imprime_erros();

        imprime_palavra();
        chuta();
    }

    cout << "Fim de Jogo!" << endl;
    cout << "A Palavra Secreta era: " << PALAVRA_SECRETA << endl;
    if(nao_acertou()) {
        cout << "Voce Perdeu! Tente Novamente." << endl;
    } else {
        cout << "Parabens! Voce Ganhou!!" << endl;
    }
}